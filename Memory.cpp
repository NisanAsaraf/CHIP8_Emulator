#include "Memory.h"

namespace chip8_emulator
{
CHIP8_Memory::CHIP8_Memory()
{
    v_ram.fill(0);
    v_registers.fill(0);
    v_stack.fill(0);
    program_counter = 0x200; // Start CHIP-8 programs typically at address 0x200
    index_register = 0;
    delay_timer = 0;
    sound_timer = 0;
}

void CHIP8_Memory::jumpToAddress(uint16_t a_address)
{
    program_counter = a_address;
}

uint8_t CHIP8_Memory::getRegister(uint8_t a_pos)
{
    return v_registers[a_pos];
}

void CHIP8_Memory::setRegister(uint8_t a_index, uint8_t a_val)
{
    v_registers[a_index] = a_val;
}

void CHIP8_Memory::addRegister(uint8_t a_index, uint8_t a_val)
{
    v_registers[a_index] += a_val;
}

void CHIP8_Memory::setIndexRegister(uint16_t a_data)
{
    index_register = a_data;
}

}//namespace chip8_emulator