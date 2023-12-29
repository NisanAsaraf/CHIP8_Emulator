#ifndef DECODER_H
#define DECODER_H
#include <cstdint>

enum class opcodes
{
	CLEAR_SCREEN,	//00E0
	JUMP,			//1NNN
	SETREG,			//6XNN
	ADDVREG,		//7XNN
	SETI,			//ANNN
	DRAW			//DXYN
};

class decoder
{
	decoder();
	uint8_t getMSB(uint16_t a_code)
	{
		return (a_code & 0xF000) >> 12;
	}

	opcodes decode(uint16_t a_code)
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
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		case 10:
			break;
		case 11:
			break;
		case 12:
			break;
		case 13:
			break;
		case 14:
			break;
		case 15:
			break;
		default:
			break;
		}
	}
};
#endif