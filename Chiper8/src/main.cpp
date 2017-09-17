#ifndef _DEBUG

#include <string>
#include <tclap/CmdLine.h>
#include "SubSystem\SubSystem.hpp"
#include "Utils\binaryFile.hpp"


int main(int argc, char** argv)
{

	TCLAP::CmdLine cmd("Chiper8 emulator", ' ', "0.0.1a");
	TCLAP::UnlabeledValueArg<std::string> fileArg("file", "Patch to executable Chip-8 file", true, "", "path_to_file", cmd);
	TCLAP::SwitchArg dbgArg("d", "debug", "Display debug information about running program", cmd);

	//Parsing Command line arguments
	cmd.parse(argc, argv);

	const bool isDebug = dbgArg.getValue();
	const std::string filename = fileArg.getValue();

	/*std::ifstream file(filename, std::ios_base::in | std::ios_base::binary);

	if (!file.is_open()) {
		std::cerr << "Cannot open file: " << file.pa << " for arg " << e.argId() << std::endl;
	}*/


	/*try {

	}
	catch (TCLAP::ArgException &e) {
	std::cerr << "Exception while parsing args: " << e.error() << " for arg " << e.argId() << std::endl;
	return 1;
	}*/



	/*FILE* progFile;
	fopen_s(&progFile, strFileName.c_str(), "rb");

	if (progFile == NULL) {
	std::cerr << "Cannot open file!" << std::endl;
	return 2;
	}

	fseek(progFile, 0, SEEK_END);
	if (ftell(progFile) > 0xFFF - 0x200)
	return 3;

	unsigned char* buffer;
	unsigned __int8 byteSize = ftell(progFile);
	rewind(progFile);

	// allocate memory to contain the whole file:
	buffer = (unsigned char*)malloc(sizeof(char)*byteSize);
	if (buffer == NULL) { fputs("Memory error", stderr); exit(2); }

	// copy the file into the buffer:
	fread(buffer, 1, byteSize, progFile);

	Emulator Chip8Emu;
	Chip8Emu.setRAM(0x200, buffer, byteSize);
	Chip8Emu.run();

	// terminate
	fclose(progFile);
	free(buffer);*/
}

#endif // !_DEBUG