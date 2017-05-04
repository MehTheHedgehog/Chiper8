#ifndef _SUBSYSTEM_EMULATOR_HPP
#define _SUBSYSTEM_EMULATOR_HPP

//Byte access operators 
#define HIBYTE(dbyte) (unsigned __int8)((dbyte & 0xFF00) >> 8)
#define MIDBYTE(dbyte) (unsigned __int8)((dbyte & 0x0FF0) >> 4)
#define LOBYTE(dbyte) (unsigned __int8)(dbyte & 0x00FF)
#define ADDRBYTE(dbyte) (unsigned __int16)(dbyte & 0x0FFF)

#define HINIBBLE(byte) (unsigned __int8)((byte & 0xF0) >> 4)
#define LONIBBLE(byte) (unsigned __int8)(byte & 0x0F)

#define MAKEDBYTE(bytea, byteb) (unsigned __int16)((((unsigned __int16)(bytea)) << 8) | (unsigned __int16)(byteb))

#include <stack>
#include <exception>

class Emulator{
	private:
		typedef bool bit;
		typedef unsigned __int8 byte;
		typedef unsigned __int16 dbyte;

		byte byteRandomAccessMemory[4096];
		byte byteVx[16];
		dbyte dbyteVI;
		dbyte dbyteProgramCounter;
		bit bitFrameBuffer[64][64];
		std::stack<dbyte> progStack;

	protected:
		void initMem();
		void clearFrameBuff();

		//Core CPU methods
		void nextStep();
		void proceed(const dbyte& inst);

		//Util Functions
		void call(const byte& byteAddr){
			if (progStack.size() >= 16)
				throw std::exception("Stack Overflow");

			progStack.push(dbyteProgramCounter);
			dbyteProgramCounter = byteAddr;
		};

		void ret(){
			if(progStack.empty())
				throw std::exception("End of Program");

			dbyteProgramCounter = progStack.top();
			progStack.pop();
		};

	public:
		void run();

		// I/O Handling 
		const bool** getFrameBuff();
		void setInput(const byte& cuiInput);

		// Access to VM Data
		//Read
		byte getVx(const byte&);
		byte getVI();
		dbyte getProgramCounter();
		//Write
		//void loadFile(const byte* byteData, const byte& byteSize);
		void setRAM(const byte& byteAddr, byte* byteData, const byte& size);

		

};

#endif