#include "Chip8_Manager.h"

int main(int argc, char* argv[])
{
	chip8_emulator::Chip8_Manager chip8;
	chip8.run("test_opcode.ch8");
	return 0;
}