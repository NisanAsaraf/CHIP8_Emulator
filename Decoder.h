#ifndef DECODER_H
#define DECODER_H
#include <cstdint>
#include "Opcodes.h"

namespace chip8_emulator
{
class Chip8_Decoder
{
public:
	uint8_t getMSB(uint16_t a_code);
	uint8_t getLSB(uint16_t a_code);
	opcodes decode(uint16_t a_code);
};
}//namespace chip8_emulator
#endif