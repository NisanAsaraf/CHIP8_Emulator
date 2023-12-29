#include "Chip8_Manager.h"

namespace chip8_emulator
{

bool Chip8_Manager::loadROM(const std::string& filename)
{
    std::ifstream file(filename, std::ios::binary);

    if (!file) 
    {
        return false;
    }

    std::vector<uint8_t> romData(std::istreambuf_iterator<char>(file), {});

    if (romData.size() > v_memory.getRAMsize() - 0x200) //first 512 bytes are reserved
    {
        return false;
    }

    std::copy(romData.begin(), romData.end(), v_memory.getRAMbegin() + 0x200);

    return true;
}

bool Chip8_Manager::fetch()
{

}

bool Chip8_Manager::execute()
{

}

bool Chip8_Manager::execute()
{

}


}// namespace chip8_emulator