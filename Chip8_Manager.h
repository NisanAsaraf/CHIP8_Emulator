#ifndef CHIP8_MANAGER_H
#define CHIP8_MANAGER_H

#include <fstream>
#include <vector>
#include "Display.h"
#include "Memory.h"
#include "Instructions.h"
#include "Decoder.h"

namespace chip8_emulator
{
class Chip8_Manager
{
public:
	Chip8_Manager() = default;
	bool loadROM(const std::string& filename);
	bool fetch();
	bool decode();
	bool execute();
private:
	CHIP8_Memory v_memory;
	CHIP8_Display v_display;
	Chip8_Instructions v_instructions;
	Chip8_Decoder v_decoder;
};
}// namespace chip8_emulator
#endif