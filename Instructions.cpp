#include "Instructions.h"

namespace chip8_emulator
{

Chip8_Instructions::Chip8_Instructions(CHIP8_Display& disp, CHIP8_Memory& mem)
:
chipDisplay(disp),
chipMemory(mem)
{
	opcodesMap[opcodes::CLEAR_SCREEN] = &Chip8_Instructions::clearScreen;
	opcodesMap[opcodes::JUMP] = &Chip8_Instructions::Jump;
	opcodesMap[opcodes::CALL] = &Chip8_Instructions::Call;
	opcodesMap[opcodes::SETREG] = &Chip8_Instructions::setRegister;
	opcodesMap[opcodes::ADDREG] = &Chip8_Instructions::addRegister;
	opcodesMap[opcodes::SETI] = &Chip8_Instructions::setIndexRegister;
	opcodesMap[opcodes::DRAW] = &Chip8_Instructions::draw;
	opcodesMap[opcodes::RETURN] = &Chip8_Instructions::Return;
}

void Chip8_Instructions::clearScreen(uint16_t a_data)
{
	chipDisplay.clearDisplay();
	std::cout << "screen cleared!" << std::endl;
}

void Chip8_Instructions::Jump(uint16_t a_data)
{
	uint16_t address = (a_data & 0x0FFF);
	chipMemory.jumpToAddress(address);
	std::cout << "jumped to " << std::hex << static_cast<int>(address) << std::endl;
}

void Chip8_Instructions::Call(uint16_t a_data)
{
	uint16_t address = (a_data & 0x0FFF);
	chipMemory.pushStack(chipMemory.getProgramCounter());
	chipMemory.jumpToAddress(address);
	std::cout << "jumped to " << std::hex << static_cast<int>(address) << std::endl;
}

void Chip8_Instructions::Return(uint16_t a_data)
{
	chipMemory.jumpToAddress(chipMemory.popStack());
}

void Chip8_Instructions::setRegister(uint16_t a_data)
{
	uint8_t register_num = (a_data & 0x0F00) >> 8;
	uint8_t register_val = a_data & 0x00FF;
	chipMemory.setRegister(register_num, register_val);
	std::cout << "register set!" << std::endl;
}

void Chip8_Instructions::addRegister(uint16_t a_data)
{
	uint8_t register_num = (a_data & 0x0F00) >> 8;
	uint8_t register_val = a_data & 0x00FF;

	chipMemory.addRegister(register_num, register_val);
	std::cout << "register added!" << std::endl;
}

void Chip8_Instructions::setIndexRegister(uint16_t a_data)
{
	uint16_t indexReg = a_data & 0x0FFF;
	chipMemory.setIndexRegister(indexReg);
	std::cout << "register index set!" << std::endl;
}

void Chip8_Instructions::draw(uint16_t a_data)
{
	uint8_t x_pos, y_pos, n;
	x_pos = (a_data & 0x0F00) >> 8;
	y_pos = (a_data & 0x00F0) >> 4;
	n = a_data & 0x000F;

	x_pos = chipMemory.getRegister(x_pos);
	y_pos = chipMemory.getRegister(y_pos);

	std::cout << "draw! " << static_cast<int>(x_pos) << "," << static_cast<int>(y_pos) << std::endl;
	chipDisplay.draw(x_pos, y_pos, n);
}

}//namespace chip8_emulator