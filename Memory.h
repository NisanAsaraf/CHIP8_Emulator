#ifndef CHIP8_MEMORY_H
#define CHIP8_MEMORY_H
#include <array>
#include <cstdint>

class CHIP8_Memory 
{

public:

    CHIP8_Memory()
    {
        v_ram.fill(0);
        v_registers.fill(0);
        v_stack.fill(0);
        program_counter = 0x200; // Start CHIP-8 programs typically at address 0x200
        index_register = 0;
        delay_timer = 0;
        sound_timer = 0;
    }

    void jumpToAddress(uint16_t a_address)
    {
        program_counter = a_address;
    }

    uint8_t getRegister(uint8_t a_pos)
    {
        return v_registers[a_pos];
    }

    void setRegister(uint8_t a_index, uint8_t a_val)
    {
        v_registers[a_index] = a_val;
    }

    void addRegister(uint8_t a_index, uint8_t a_val)
    {
        v_registers[a_index] += a_val;
    }

    void setIndexRegister(uint16_t a_data)
    {
        index_register = a_data;
    }


private:
    std::array<uint8_t, 4096> v_ram;
    std::array<uint8_t, 16> v_registers; 
    std::array<uint16_t, 16> v_stack;
    uint16_t program_counter;
    uint16_t index_register; 
    uint8_t delay_timer; 
    uint8_t sound_timer; 

    static constexpr uint16_t STACK_START = 0xE00; // Start address of the stack
    static constexpr uint16_t STACK_END = 0xFFF; // End address of the stack
    static constexpr uint16_t DISPLAY_START = 0xF00; // Start address of the display memory
};

#endif