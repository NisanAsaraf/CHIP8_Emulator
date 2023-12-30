#include "Decoder.h"
namespace chip8_emulator
{

uint8_t Chip8_Decoder::getMSB(uint16_t a_code)
{
	return (a_code & 0xf000) >> 12;
}

opcodes Chip8_Decoder::decode(uint16_t a_code)
{
	switch (getMSB(a_code))
	{
	case 0:
		if (a_code == 0x00e0)
		{
			return opcodes::CLEAR_SCREEN;
		}
		break;
	case 1:
		return opcodes::JUMP;
		break;
	case 2:
		return opcodes::UNKNOWN;
		break;
	case 3:
		return opcodes::UNKNOWN;
		break;
	case 4:
		return opcodes::UNKNOWN;
		break;
	case 5:
		return opcodes::UNKNOWN;
		break;
	case 6:
		return opcodes::SETREG;
		break;
	case 7:
		return opcodes::ADDREG;
		break;
	case 8:
		return opcodes::UNKNOWN;
		break;
	case 9:
		return opcodes::UNKNOWN;
		break;
	case 10:
		return opcodes::SETI;
		break;
	case 11:
		return opcodes::UNKNOWN;
		break;
	case 12:
		return opcodes::UNKNOWN;
		break;
	case 13:
		return opcodes::DRAW;
		break;
	case 14:
		return opcodes::UNKNOWN;
		break;
	case 15:
		return opcodes::UNKNOWN;
		break;
	default:
		return opcodes::UNKNOWN;
		break;
	}
}
}//namespace chip8_emulator