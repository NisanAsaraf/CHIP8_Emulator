#ifndef CHIP8_MEMORY_H
#define CHIP8_MEMORY_H
#include <array>
#include <cstdint>
#include <iostream>

namespace chip8_emulator
{
class CHIP8_Memory 
{
public:

    CHIP8_Memory();
    void jumpToAddress(uint16_t a_address);
    uint8_t getRegister(uint8_t a_pos);
    uint16_t getRAMdata();
    uint8_t getRAMnibble(uint16_t a_address);
    size_t getRAMcapacity();
    void initializeFont();
    std::array<uint8_t, 4096>& getRefRAM();
    void insertDataToRam(uint8_t a_data);
    void setRAMdata(uint16_t a_index, uint8_t a_data);
    void incrementCounter();
    void decrementCounter();
    uint16_t& getIndexRegister();
    uint16_t getProgramCounter();
    void setCapacity(size_t a_capacity);
    void setRegister(uint8_t a_index, uint8_t a_val);
    void addRegister(uint8_t a_index, uint8_t a_val);
    void setIndexRegister(uint16_t a_data);
    void printRAM();
    void shiftRegisterRight(uint8_t a_x);
    void shiftRegisterLeft(uint8_t a_x);
    void shiftStackRight();
    void shiftStackLeft();
    void pushStack(uint16_t a_data);
    uint16_t popStack();
    uint8_t& getFlag();
    uint8_t getDelay();
    void setDelay(uint8_t a_data);
    uint8_t getSound();
    uint8_t& getRefSound();
    void setSound(uint8_t a_data);

private:
    std::array<uint8_t, 4096> v_ram;
    size_t ramCapacity;
    std::array<uint8_t, 16> v_registers; 
    std::array<uint16_t, 16> v_stack;
    uint16_t program_counter;
    uint16_t index_register; 
    uint8_t delay_timer; 
    uint8_t sound_timer; 

    static constexpr uint16_t DISPLAY_START = 0xF00;    // Start address of the display memory
};
}//namespace chip8_emulator
#endif