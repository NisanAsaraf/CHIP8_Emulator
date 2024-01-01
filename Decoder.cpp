#include "Decoder.h"
namespace chip8_emulator
{

uint8_t Chip8_Decoder::getMSB(uint16_t a_code)
{
	return (a_code & 0xf000) >> 12;
}

uint8_t Chip8_Decoder::getLSB(uint16_t a_code)
{
	return (a_code & 0x000f);
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
		else if (a_code == 0x00ee)
		{
			return opcodes::RETURN;
		}
		break;
	case 1:
		return opcodes::JUMP;
		break;
	case 2:
		return opcodes::CALL;
		break;
	case 3:
		return opcodes::SKIPX;
		break;
	case 4:
		return opcodes::SKIPNX;
		break;
	case 5:
		return opcodes::SKIPXY;
		break;
	case 6:
		return opcodes::SETREG;
		break;
	case 7:
		return opcodes::ADDREG;
		break;
	case 8:
		switch (getLSB(a_code))
		{
		case 0:
			return opcodes::SETXY;
			break;
		case 1:
			return opcodes::SETXOY;
			break;
		case 2:
			return opcodes::SETXAY;
			break;
		case 3:
			return opcodes::SETXRY;
			break;
		case 4:
			return opcodes::ADDYTX;
			break;
		case 5:
			return opcodes::ADDMYTX;
			break;
		case 6:
			return opcodes::BITOPR;
			break;
		case 7:
			return opcodes::SETXYMX;
			break;
		case 12:
			return opcodes::BITOPL;
			break;
		}
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