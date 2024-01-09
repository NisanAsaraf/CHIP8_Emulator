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
	opcodesMap[opcodes::SKIPX] = &Chip8_Instructions::SkipX;
	opcodesMap[opcodes::SKIPNX] = &Chip8_Instructions::SkipNX;
	opcodesMap[opcodes::SKIPXY] = &Chip8_Instructions::SkipXY;
	opcodesMap[opcodes::SKIPNXY] = &Chip8_Instructions::SkipNXY;

	opcodesMap[opcodes::SETXY] = &Chip8_Instructions::SetXY;
	opcodesMap[opcodes::SETXOY] = &Chip8_Instructions::SetXOY;
	opcodesMap[opcodes::SETXAY] = &Chip8_Instructions::SetXAY;
	opcodesMap[opcodes::SETXRY] = &Chip8_Instructions::SetXRY;
	opcodesMap[opcodes::ADDYTX] = &Chip8_Instructions::AddYtX;
	opcodesMap[opcodes::ADDMYTX] = &Chip8_Instructions::AddMYtX;
	opcodesMap[opcodes::BITOPR] = &Chip8_Instructions::BitOpR;
	opcodesMap[opcodes::BITOPL] = &Chip8_Instructions::BITOpL;
	opcodesMap[opcodes::SETXYMX] = &Chip8_Instructions::SetXYMX;

	opcodesMap[opcodes::JUMPZ] = &Chip8_Instructions::JumpZ;

	opcodesMap[opcodes::KEYX] = &Chip8_Instructions::KeyX;
	opcodesMap[opcodes::KEYNX] = &Chip8_Instructions::KeyNX;

	opcodesMap[opcodes::GETDELAY] = &Chip8_Instructions::GetDelay;
	opcodesMap[opcodes::GETKEY] = &Chip8_Instructions::GetKey;
	opcodesMap[opcodes::SETDELAY] = &Chip8_Instructions::SetDelay;
	opcodesMap[opcodes::SETSOUND] = &Chip8_Instructions::SetSound;

	opcodesMap[opcodes::ADDXTI] = &Chip8_Instructions::AddXTI;
	opcodesMap[opcodes::SETITSPRITE] = &Chip8_Instructions::SetIsprite;
	opcodesMap[opcodes::BCD] = &Chip8_Instructions::SetBCD;
	opcodesMap[opcodes::REGDUMP] = &Chip8_Instructions::RegDump;
	opcodesMap[opcodes::REGLOAD] = &Chip8_Instructions::RegLoad;

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
	std::cout << "called to " << std::hex << static_cast<int>(address) << std::endl;
}

void Chip8_Instructions::Return(uint16_t a_data)
{
	chipMemory.jumpToAddress(chipMemory.popStack());
	std::cout << "returned " << std::hex << static_cast<int>(a_data) << std::endl;
}

void Chip8_Instructions::SkipX(uint16_t a_data)
{
	uint8_t X = (a_data & 0x0F00) >> 8;
	uint8_t data = a_data & 0x00FF;
	if (chipMemory.getRegister(X) == data)
	{
		chipMemory.incrementCounter();
	}
	std::cout << "SkipX " << std::endl;
}

void Chip8_Instructions::SkipNX(uint16_t a_data)
{
	uint8_t X = (a_data & 0x0F00) >> 8;
	uint8_t data = a_data & 0x00FF;
	if (chipMemory.getRegister(X) != data)
	{
		chipMemory.incrementCounter();
	}
	std::cout << "SkipNX " << std::endl;
}

void Chip8_Instructions::SkipXY(uint16_t a_data)
{
	uint8_t X = (a_data & 0x0F00) >> 8;
	uint8_t Y = (a_data & 0x00F0) >> 4;
	if (chipMemory.getRegister(X) == chipMemory.getRegister(Y))
	{
		chipMemory.incrementCounter();
	}
	std::cout << "SkipXY " << std::endl;
}

void Chip8_Instructions::SkipNXY(uint16_t a_data)
{
	uint8_t X = (a_data & 0x0F00) >> 8;
	uint8_t Y = (a_data & 0x00F0) >> 4;
	if (chipMemory.getRegister(X) != chipMemory.getRegister(Y))
	{
		chipMemory.incrementCounter();
	}
	std::cout << "SkipNXY " << std::endl;
}

void Chip8_Instructions::Chip8_Instructions::SetXY(uint16_t a_data)
{
	uint8_t X = (a_data & 0x0F00) >> 8;
	uint8_t Y = (a_data & 0x00F0) >> 4;
	uint8_t VY = chipMemory.getRegister(Y);
	chipMemory.setRegister(X, static_cast<uint8_t>(VY) );
	std::cout << "SetXY " << std::endl;
}

void Chip8_Instructions::SetXOY(uint16_t a_data)
{
	uint8_t X = (a_data & 0x0F00) >> 8;
	uint8_t Y = (a_data & 0x00F0) >> 4;
	uint8_t VX = chipMemory.getRegister(X);
	uint8_t VY = chipMemory.getRegister(Y);

	chipMemory.setRegister(X, static_cast<uint8_t> (VX | VY) );
	std::cout << "SetXOY " << std::endl;
}

void Chip8_Instructions::SetXAY(uint16_t a_data)
{
	uint8_t X = (a_data & 0x0F00) >> 8;
	uint8_t Y = (a_data & 0x00F0) >> 4;
	uint8_t VX = chipMemory.getRegister(X);
	uint8_t VY = chipMemory.getRegister(Y);

	chipMemory.setRegister(X, static_cast<uint8_t> (VX & VY) );
	std::cout << "SetXAY " << std::endl;
}

void Chip8_Instructions::SetXRY(uint16_t a_data)
{
	uint8_t X = (a_data & 0x0F00) >> 8;
	uint8_t Y = (a_data & 0x00F0) >> 4;
	uint8_t VX = chipMemory.getRegister(X);
	uint8_t VY = chipMemory.getRegister(Y);

	chipMemory.setRegister(X, static_cast<uint8_t> (VX ^ VY));
	std::cout << "SetXRY " << std::endl;
}

void Chip8_Instructions::AddYtX(uint16_t a_data)
{
	uint8_t X = (a_data & 0x0F00) >> 8;
	uint8_t Y = (a_data & 0x00F0) >> 4;

	uint8_t VX = chipMemory.getRegister(X);
	uint8_t VY = chipMemory.getRegister(Y);

	uint8_t VXY = chipMemory.getRegister(X) + chipMemory.getRegister(Y);

	if (VXY < VX || VXY < VY)
	{
		chipMemory.setRegister(15,1);//VF to 1
	}
	else
	{
		chipMemory.setRegister(15, 0);//VF to 0
	}

	chipMemory.setRegister(X, VXY);
	std::cout << "AddYtX " << std::endl;
}

void Chip8_Instructions::AddMYtX(uint16_t a_data)
{
	uint8_t X = (a_data & 0x0F00) >> 8;
	uint8_t Y = (a_data & 0x00F0) >> 4;

	uint8_t VX = chipMemory.getRegister(X);
	uint8_t VY = chipMemory.getRegister(Y);

	if (VX < VY)
	{
		chipMemory.setRegister(15, 0);//VF to 0
	}
	else
	{
		chipMemory.setRegister(15, 1);//VF to 1
	}

	chipMemory.setRegister(X, static_cast<uint8_t>(VX - VY));
	std::cout << "AddMYtX " << std::endl;
}

void Chip8_Instructions::BitOpR(uint16_t a_data)
{
	uint8_t X = (a_data & 0x0F00) >> 8;
	uint8_t VX = chipMemory.getRegister(X);

	chipMemory.setRegister(15, VX & 1);
	chipMemory.shiftRegisterRight(X);
	std::cout << "BitOpR " << std::endl;
}

void Chip8_Instructions::BITOpL(uint16_t a_data)
{
	uint8_t X = (a_data & 0x0F00) >> 8;
	uint8_t VX = chipMemory.getRegister(X);

	chipMemory.setRegister(15, VX & 1);
	chipMemory.shiftRegisterLeft(X);
	std::cout << "BitOpL " << std::endl;
}

void Chip8_Instructions::SetXYMX(uint16_t a_data)
{
	uint8_t X = (a_data & 0x0F00) >> 8;
	uint8_t Y = (a_data & 0x00F0) >> 4;

	uint8_t VX = chipMemory.getRegister(X);
	uint8_t VY = chipMemory.getRegister(Y);

	if (VX > VY)
	{
		chipMemory.setRegister(15, 0);//VF to 0
	}
	else
	{
		chipMemory.setRegister(15, 1);//VF to 1
	}

	chipMemory.setRegister(X, static_cast<uint8_t>(VY - VX));
	std::cout << "SetXYMX " << std::endl;
}

void Chip8_Instructions::JumpZ(uint16_t a_data)
{
	uint16_t address = a_data & 0x0FFF;
	chipMemory.jumpToAddress(chipMemory.getRegister(0) + address);
	std::cout << "JumpZ " << std::endl;
}

void Chip8_Instructions::RandX(uint16_t a_data)
{
	uint8_t X = (a_data & 0x0F00) >> 8;
	uint16_t data = a_data & 0x00FF;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<uint16_t> dis(0, 255);
	uint8_t random_number = static_cast<uint8_t>(dis(gen)); 
	
	chipMemory.setRegister(X, random_number & data);
	std::cout << "RandX " << std::endl;
}

void Chip8_Instructions::KeyX(uint16_t a_data)
{
	uint8_t X = (a_data & 0x0F00) >> 8;
	if (chipMemory.getRegister(X) < 16)
	{
		chipMemory.incrementCounter();
	}
	std::cout << "KeyX " << std::endl;
}

void Chip8_Instructions::KeyNX(uint16_t a_data)
{
	uint8_t X = (a_data & 0x0F00) >> 8;
	if (chipMemory.getRegister(X) > 16)
	{
		chipMemory.incrementCounter();
	}
	std::cout << "KeyNX " << std::endl;
}


void Chip8_Instructions::GetDelay(uint16_t a_data)
{
	uint8_t X = (a_data & 0x0F00) >> 8;

	chipMemory.setRegister(X, chipMemory.getDelay());
	std::cout << "GetDelay " << std::endl;
}

void Chip8_Instructions::GetKey(uint16_t a_data)
{
	uint8_t X = (a_data & 0x0F00) >> 8;
	uint8_t key = 0xFF;

	if (_kbhit())
	{
		char keyPressed = _getch();
		if (chipDisplay.getKeyFromMap(keyPressed) != 0xFF)
		{
			chipMemory.setRegister(X, key);
		}
	}
	else
	{
		chipMemory.decrementCounter();
	}
	std::cout << "GetKey " << std::endl;
}

void Chip8_Instructions::SetDelay(uint16_t a_data)
{
	uint8_t X = (a_data & 0x0F00) >> 8;
	chipMemory.setDelay(chipMemory.getRegister(X));
	std::cout << "SetDelay " << std::endl;
}

void Chip8_Instructions::SetSound(uint16_t a_data)
{
	uint8_t X = (a_data & 0x0F00) >> 8;
	chipMemory.setSound(chipMemory.getRegister(X));
	std::cout << "SetSound " << std::endl;
}

void Chip8_Instructions::AddXTI(uint16_t a_data)
{
	uint8_t X = (a_data & 0x0F00) >> 8;
	uint8_t VX = chipMemory.getRegister(X);
	chipMemory.setIndexRegister(chipMemory.getIndexRegister() + VX);
	std::cout << "AddXTI " << std::endl;
}

void Chip8_Instructions::SetIsprite(uint16_t a_data)
{
	uint8_t X = (a_data & 0x0F00) >> 8;
	uint8_t VX = chipMemory.getRegister(X);
	chipMemory.setIndexRegister(chipMemory.getRAMnibble((VX & 0x000F) * 5));
	std::cout << "SetIsprite " << std::endl;
}

void Chip8_Instructions::SetBCD(uint16_t a_data)
{
	uint8_t X = (a_data & 0x0F00) >> 8;
	uint8_t VX = chipMemory.getRegister(X);
	uint8_t hundreds, tens, digits;
	uint16_t index = chipMemory.getIndexRegister();

	digits = VX % 10;
	VX /= 10;
	tens = VX % 10;
	VX /= 10;
	hundreds = VX % 10;

	chipMemory.setRAMdata(index, hundreds);
	chipMemory.setRAMdata(index + 1, tens);
	chipMemory.setRAMdata(index + 2, digits);
	std::cout << "SetBCD " << std::endl;
}

void Chip8_Instructions::RegDump(uint16_t a_data)
{
	uint8_t X = (a_data & 0x0F00) >> 8;
	uint16_t index = chipMemory.getIndexRegister();
	for (uint8_t i = 0; i <= X; i++)
	{
		chipMemory.setRAMdata(index + i, chipMemory.getRegister(i));
	}
	std::cout << "RegDump " << std::endl;
}

void Chip8_Instructions::RegLoad(uint16_t a_data)
{
	uint8_t X = (a_data & 0x0F00) >> 8;
	uint16_t index = chipMemory.getIndexRegister();
	for (uint8_t i = 0; i <= X; i++)
	{
		chipMemory.setRegister(i, chipMemory.getRAMnibble(index + i));
	}
	std::cout << "RegLoad " << std::endl;
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