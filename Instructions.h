#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H
#include <cstdint>
#include "Opcodes.h"
#include "Display.h"
#include "Memory.h"

class Instructions
{
public:
	Instructions(CHIP8_Display& disp, CHIP8_Memory& mem) 
	: 
	chipDisplay(disp), 
	chipMemory(mem)
	{
	}

	void clearScreen()
	{
		chipDisplay.clearDisplay();
	}

	void Jump(uint16_t a_data)
	{
		uint16_t address = a_data & 0x0FFF;
		chipMemory.jumpToAddress(address);
	}

	void setRegister(uint16_t a_data)
	{
		uint8_t register_num = a_data & 0x0F00 >> 8;
		uint8_t register_val = a_data & 0x00FF;

		chipMemory.setRegister(register_num, register_val);
	}

	void addRegister(uint16_t a_data)
	{
		uint8_t register_num = a_data & 0x0F00 >> 8;
		uint8_t register_val = a_data & 0x00FF;

		chipMemory.addRegister(register_num, register_val);
	}

	void setIndexRegister(uint16_t a_data)
	{
		uint16_t indexReg = a_data & 0x0FFF;
		chipMemory.setIndexRegister(indexReg);
	}

	void draw(uint16_t a_data)
	{
		uint8_t x_pos, y_pos, n;
		x_pos = (a_data & 0x0F00) >> 8;
		y_pos = (a_data & 0x00F0) >> 4;
		n = a_data & 0x000F;

		chipDisplay.draw(chipMemory.getRegister(x_pos), chipMemory.getRegister(y_pos), n);
	}

private:
	CHIP8_Display& chipDisplay;
	CHIP8_Memory& chipMemory;
};

#endif