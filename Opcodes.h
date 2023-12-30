#ifndef OPCODES_H
#define OPCODES_H

namespace chip8_emulator
{
enum class opcodes : uint8_t
{
	CLEAR_SCREEN = 0,	//00E0
	JUMP = 1,			//1NNN
	SETREG = 6,			//6XNN
	ADDREG = 7,			//7XNN
	SETI = 10,			//ANNN
	DRAW = 13,			//DXYN
	UNKNOWN = 99
};
}//namespace chip8_emulator
#endif