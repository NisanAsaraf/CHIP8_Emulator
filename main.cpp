#include "Chip8_Manager.h"

int main()
{
	chip8_emulator::Chip8_Manager chip8;
	chip8.run("IBM Logo.ch8");
	return 0;
}