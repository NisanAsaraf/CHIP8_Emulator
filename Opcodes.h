#ifndef OPCODES_H
#define OPCODES_H

namespace chip8_emulator
{
enum class opcodes : uint8_t
{
	CLEAR_SCREEN = 0,	//00E0
	JUMP = 1,			//1NNN
	CALL = 2,			//2NNN
	SKIPX = 3,			//3XNN
	SKIPNX = 4,			//4XNN
	SKIPXY = 5,			//5XY0
	SETREG = 6,			//6XNN
	ADDREG = 7,			//7XNN

	SETXY = 80,			//8XY0
	SETXOY = 81,		//8XY1
	SETXAY = 82,		//8XY2
	SETXRY = 83,		//8XY3
	ADDYTX = 84,		//8XY4
	ADDMYTX = 85,		//8XY5
	BITOPR = 86,		//8XY6
	SETXYMX = 87,		//8XY7
	BITOPL = 88,		//8XYE

	SKIPNXY = 9,		//9XY0
	SETI = 10,			//ANNN
	JUMPZ = 11,			//BNNN
	RANDX = 12,			//CXNN
	DRAW = 13,			//DXYN

	KEYX = 14,			//EX9E
	KEYNX = 15,			//EXA1

	GETDELAY = 16,		//FX07
	GETKEY = 17,		//FX0A
	SETDELAY = 18,		//FX15
	SETSOUND = 19,		//FX18

	ADDXTI = 20,		//FX1E
	SETITSPRITE = 21,	//FX29
	BCD = 22,			//FX33
	REGDUMP = 23,		//FX55
	REGLOAD = 24,		//FX65

	RETURN,				//00EE
	UNKNOWN = 199
};
}//namespace chip8_emulator
#endif