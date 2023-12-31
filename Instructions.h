#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H
#include <cstdint>
#include "Opcodes.h"
#include "Display.h"
#include "Memory.h"
#include <unordered_map>
#include <functional>

namespace chip8_emulator
{
class Chip8_Instructions
{
public:
	Chip8_Instructions(CHIP8_Display& disp, CHIP8_Memory& mem);
	std::unordered_map<opcodes, std::function<void(Chip8_Instructions&, uint16_t)>> opcodesMap;

	void clearScreen(uint16_t a_data);
	void Jump(uint16_t a_data);
	void Call(uint16_t a_data);
	void Return(uint16_t a_data);
	void setRegister(uint16_t a_data);
	void addRegister(uint16_t a_data);
	void setIndexRegister(uint16_t a_data);
	void draw(uint16_t a_data);
private:
	CHIP8_Display& chipDisplay;
	CHIP8_Memory& chipMemory;
};
}
#endif