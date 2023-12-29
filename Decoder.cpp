#include "Decoder.h"
namespace chip8_emulator
{

uint8_t Chip8_Decoder::getMSB(uint16_t a_code)
{
	return (a_code & 0xF000) >> 12;
}

opcodes Chip8_Decoder::decode(uint16_t a_code)
{
	switch (getMSB(a_code))
	{
	case 0:
		if (a_code == 0x00E0)
		{
			return opcodes::CLEAR_SCREEN;
		}
		else
		{
			return opcodes::JUMP;
		}
		break;
	case 1:
		return opcodes::JUMP;
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		return opcodes::SETREG;
		break;
	case 7:
		return opcodes::ADDREG;
		break;
	case 8:
		break;
	case 9:
		break;
	case 10:
		return opcodes::SETI;
		break;
	case 11:
		break;
	case 12:
		break;
	case 13:
		return opcodes::DRAW;
		break;
	case 14:
		break;
	case 15:
		break;
	default:
		opcodes::UNKNOWN;
		break;
	}
}
}//namespace chip8_emulator