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
	Chip8_Manager();
	bool loadROM();
	uint8_t fetch();
	opcodes decode(uint8_t a_data);
	bool execute(uint8_t a_data, opcodes a_code);
	void run(std::string a_filename);
private:
	CHIP8_Memory v_memory;
	CHIP8_Display v_display;
	Chip8_Instructions v_instructions;
	Chip8_Decoder v_decoder;
	std::string v_filename;
	bool v_stop;
};
}// namespace chip8_emulator
#endif