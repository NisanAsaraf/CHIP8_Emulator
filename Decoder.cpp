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

uint8_t Chip8_Decoder::getRightByte(uint16_t a_code)
{
	return (a_code & 0x00ff);
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
		case 14:
			return opcodes::BITOPL;
			break;
		}
		break;
	case 9:
		return opcodes::SKIPNXY;
		break;
	case 10:
		return opcodes::SETI;
		break;
	case 11:
		return opcodes::JUMPZ;
		break;
	case 12:
		return opcodes::RANDX;
		break;
	case 13:
		return opcodes::DRAW;
		break;
	case 14:
		switch (getLSB(a_code))
		{
		case 1:
			return opcodes::KEYNX;
			break;
		case 14:
			return opcodes::KEYX;
			break;
		}
		break;
	case 15:
		switch (getRightByte(a_code))
		{
		case 7:
			return opcodes::GETDELAY;
			break;
		case 10:
			return opcodes::GETKEY;
			break;
		case 21:
			return opcodes::SETDELAY;
			break;
		case 24:
			return opcodes::SETSOUND;
			break;
		case 30:
			return opcodes::ADDXTI;
			break;
		case 41:
			return opcodes::SETITSPRITE;
			break;
		case 51:
			return opcodes::BCD;
			break;
		case 85:
			return opcodes::REGDUMP;
			break;
		case 101:
			return opcodes::REGLOAD;
			break;
		}
		break;
	default:
		return opcodes::UNKNOWN;
		break;
	}
}
}//namespace chip8_emulator