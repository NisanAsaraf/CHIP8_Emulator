#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H
#include <cstdint>
#include <unordered_map>
#include <functional>
#include <random>
#include "Opcodes.h"
#include "Display.h"
#include "Memory.h"

namespace chip8_emulator
{
class Chip8_Instructions
{
public:
	Chip8_Instructions(CHIP8_Display& disp, CHIP8_Memory& mem);
	std::unordered_map<opcodes, std::function<void(Chip8_Instructions&, uint16_t)>> opcodesMap;

	void clearScreen(uint16_t a_data);
	void Jump(uint16_t a_data);
	void Call(uint16_t a_data);
	void SkipX(uint16_t a_data);
	void SkipNX(uint16_t a_data);
	void SkipXY(uint16_t a_data);
	void SkipNXY(uint16_t a_data);

	void SetXY(uint16_t a_data);
	void SetXOY(uint16_t a_data);
	void SetXAY(uint16_t a_data);
	void SetXRY(uint16_t a_data);
	void AddYtX(uint16_t a_data);
	void AddMYtX(uint16_t a_data);
	void BitOpR(uint16_t a_data);
	void SetXYMX(uint16_t a_data);
	void BITOpL(uint16_t a_data);
	void JumpZ(uint16_t a_data);
	void setRegister(uint16_t a_data);
	void addRegister(uint16_t a_data);
	void setIndexRegister(uint16_t a_data);
	void RandX(uint16_t a_data);
	void KeyX(uint16_t a_data);
	void KeyNX(uint16_t a_data);

	void GetDelay(uint16_t a_data);
	void GetKey(uint16_t a_data);
	void SetDelay(uint16_t a_data);
	void SetSound(uint16_t a_data);

	void draw(uint16_t a_data);
	void Return(uint16_t a_data);
private:
	CHIP8_Display& chipDisplay;
	CHIP8_Memory& chipMemory;
};
}
#endif