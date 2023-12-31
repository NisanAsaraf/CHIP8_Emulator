#include "Memory.h"

namespace chip8_emulator
{
CHIP8_Memory::CHIP8_Memory()
{
    v_ram.fill(0);
    ramCapacity = 0;
    initializeFont();
    v_registers.fill(0);
    v_stack.fill(0);
    program_counter = 0x200; // Start CHIP-8 programs typically at address 0x200
    index_register = 0;
    delay_timer = 0;
    sound_timer = 0;
}

void CHIP8_Memory::initializeFont()
{
    std::array<uint8_t, 16 * 5> chip8Font = 
    {
        0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
        0x20, 0x60, 0x20, 0x20, 0x70, // 1
        0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
        0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
        0x90, 0x90, 0xF0, 0x10, 0x10, // 4
        0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
        0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
        0xF0, 0x10, 0x20, 0x40, 0x40, // 7
        0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
        0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
        0xF0, 0x90, 0xF0, 0x90, 0x90, // A
        0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
        0xF0, 0x80, 0x80, 0x80, 0xF0, // C
        0xE0, 0x90, 0x90, 0x90, 0xE0, // D
        0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
        0xF0, 0x80, 0xF0, 0x80, 0x80  // F
    };

    for(int i = 0; i < 16 * 5; i++)
    {
        v_ram[i] = chip8Font[i];
    }
}

void CHIP8_Memory::jumpToAddress(uint16_t a_address)
{
    program_counter = a_address;
}

uint8_t CHIP8_Memory::getRegister(uint8_t a_pos)
{
    return v_registers[a_pos];
}

uint16_t& CHIP8_Memory::getIndexRegister()
{
    return index_register;
}

size_t CHIP8_Memory::getRAMcapacity()
{
    return ramCapacity;
}
uint16_t CHIP8_Memory::getProgramCounter()
{
    return program_counter;
}

std::array<uint8_t, 4096>& CHIP8_Memory::getRefRAM()
{
    return v_ram;
}

void CHIP8_Memory::setCapacity(size_t a_capacity)
{
    ramCapacity = a_capacity;
}

void CHIP8_Memory::printRAM()
{
    std::cout << ramCapacity << std::endl;

    for (int i = 0x200; i < ramCapacity + 0x200; ++i)
    {
        std::cout << std::hex << static_cast<int>(v_ram[i]) << " ";
    }
    std::cout << std::endl;
}

void CHIP8_Memory::shiftRegisterRight(uint8_t a_x)
{
    v_registers[a_x] >>= 1;
}

void CHIP8_Memory::shiftRegisterLeft(uint8_t a_x)
{
    v_registers[a_x] <<= 1;
}

uint8_t CHIP8_Memory::getDelay()
{
    return delay_timer;
}

void CHIP8_Memory::setDelay(uint8_t a_data) 
{
    delay_timer = a_data;
}

uint8_t CHIP8_Memory::getSound()
{
    return sound_timer;
}

void CHIP8_Memory::setSound(uint8_t a_data) 
{
    sound_timer = a_data;
}

void CHIP8_Memory::insertDataToRam(uint8_t a_data)
{
    v_ram[ramCapacity + 0x200] = a_data;
    ramCapacity++;
}

uint16_t CHIP8_Memory::getRAMdata()
{
    uint16_t data = (static_cast<uint16_t> (v_ram[program_counter]) << 8 | static_cast<uint16_t>(v_ram[program_counter + 1]));
    return data;
}

void CHIP8_Memory::setRAMdata(uint16_t a_index, uint8_t a_data)
{
    if (a_index > 4096)
    {
        return;
    }

    v_ram[a_index] = a_data;
}

uint8_t CHIP8_Memory::getRAMnibble(uint16_t a_address)
{
    return v_ram[a_address];
}

void CHIP8_Memory::incrementCounter()
{
    if (program_counter - 0x200 > ramCapacity)
    {
        return;
    }

    program_counter += 2;
}

void CHIP8_Memory::decrementCounter()
{
    if (program_counter <= 0x200)
    {
        return;
    }

    program_counter -= 2;
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

void CHIP8_Memory::shiftStackRight()
{
    for (int i = 15; i >= 0; --i)
    {
        v_stack[i] = v_stack[i - 1];
    }
    v_stack[0] = 0;
}

void CHIP8_Memory::shiftStackLeft()
{
    for (int i = 0; i < 16; ++i)
    {
        v_stack[i] = v_stack[i + 1];
    }
    v_stack[15] = 0;
}

void CHIP8_Memory::pushStack(uint16_t a_data)
{
    shiftStackRight();
    v_stack[0] = a_data;
}

uint16_t CHIP8_Memory::popStack()
{
    uint16_t data = v_stack[0];
    shiftStackLeft();
    return data;
}

}//namespace chip8_emulator