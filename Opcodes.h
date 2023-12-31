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

	SETXY = 80,
	SETXOY = 81,
	SETXAY = 82,
	SETXRY = 83,
	ADDYTX = 84,
	ADDMYTX = 85,
	BITOPR = 86,
	SETXYMX = 87,

	BITOPL = 88,
	SKIPNXY = 9,		//9XY0
	SETI = 10,			//ANNN
	DRAW = 13,			//DXYN

	RETURN,				//00EE
	UNKNOWN = 99
};
}//namespace chip8_emulator
#endif