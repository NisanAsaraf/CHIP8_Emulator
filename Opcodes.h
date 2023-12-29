#ifndef OPCODES_H
#define OPCODES_H

enum class opcodes
{
	CLEAR_SCREEN,	//00E0
	JUMP,			//1NNN
	SETREG,			//6XNN
	ADDREG,			//7XNN
	SETI,			//ANNN
	DRAW,			//DXYN
	UNKNOWN
};

#endif