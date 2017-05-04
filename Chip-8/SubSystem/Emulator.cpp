#include "Emulator.hpp"

void Emulator::initMem(){
	//Clear Stack
	while (!progStack.empty())
		progStack.pop();

	memset(byteRandomAccessMemory, 0, sizeof(byteRandomAccessMemory));
	memset(byteVx, 0, sizeof(byteVx));
	dbyteVI = 0;
	dbyteProgramCounter = 0;
	clearFrameBuff();
}

void Emulator::clearFrameBuff(){
	memset(bitFrameBuffer, 0, sizeof(bitFrameBuffer));
}

void Emulator::nextStep(){
	
	if (dbyteProgramCounter >= (0xFFF - 2)){
		throw std::exception("Access Violation");
	}

	dbyteProgramCounter += 2;
	proceed(MAKEDBYTE(byteRandomAccessMemory[dbyteProgramCounter - 2], byteRandomAccessMemory[dbyteProgramCounter - 1]));

};

void Emulator::setRAM(const byte& byteAddr, byte* byteData, const byte& size){
	if (size > (0xFFF - 0x200)){
		throw std::exception("Access Violation");
	}

	memcpy(&byteRandomAccessMemory[0x200], byteData, size);
};

void Emulator::run(){
	dbyteProgramCounter = 0x200;

	try{
		while (true)
			nextStep();
	}catch (...){

	}

}

void Emulator::proceed(const dbyte& inst){

	switch (HINIBBLE(HIBYTE(inst))){
		case 0x0:{
			if (LONIBBLE(HIBYTE(inst)) == 0x0){
				if (LOBYTE(inst) == 0xEE){
					ret();
				}
				else if (LOBYTE(inst) == 0xE0){
					clearFrameBuff();
				}
			}
		}break;

		case 0x1:{
			dbyteProgramCounter = ADDRBYTE(inst);
		}break;

		case 0x2:{
			call(ADDRBYTE(inst));
		}break;

		case 0x3:{
			if (byteVx[LONIBBLE(HIBYTE(inst))] == LOBYTE(inst))
				dbyteProgramCounter += 2;
		}break;

		case 0x4:{
			if (byteVx[LONIBBLE(HIBYTE(inst))] != LOBYTE(inst))
				dbyteProgramCounter += 2;
		}break;

		case 0x5:{
			if (LONIBBLE(LOBYTE(inst)) == 0x0)
				if (byteVx[LONIBBLE(HIBYTE(inst))] == byteVx[HINIBBLE(LOBYTE(inst))])
					dbyteProgramCounter += 2;
		}break;

		case 0x6:{
			byteVx[LONIBBLE(HIBYTE(inst))] = LOBYTE(inst);
		}break;

		case 0x7:{
			byteVx[LONIBBLE(HIBYTE(inst))] += LOBYTE(inst);
		}break;

		case 0x8:{

		}break;

		case 0x9:{
			if (LONIBBLE(LOBYTE(inst)) == 0x0)
				if (byteVx[LONIBBLE(HIBYTE(inst))] != byteVx[HINIBBLE(LOBYTE(inst))])
					dbyteProgramCounter += 2;
		}break;

		case 0xA:{
			dbyteVI = ADDRBYTE(inst);
		}break;

		case 0xB:{
			dbyteProgramCounter = ADDRBYTE(inst) + byteVx[0];
		}break;

		case 0xC:{
			//TODO RAND
			byteVx[LONIBBLE(HIBYTE(inst))] = 125 & LOBYTE(inst);
		}break;

		case 0xD:{
			//TODO Draw
		}break;

		case 0xE:{

			if (LOBYTE(inst) == 0x9E){
			}
			else if (LOBYTE(inst) == 0xA1){
			}
		}break;

		case 0xF:{

		}break;

	}

};