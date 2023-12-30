#include "Chip8_Manager.h"

namespace chip8_emulator
{
Chip8_Manager::Chip8_Manager()
:
v_memory{},
v_display{},
v_decoder{},
v_instructions{ v_display, v_memory },
v_stop{ false }
{
   
}

bool Chip8_Manager::loadROM()
{
    std::ifstream file(v_filename, std::ios::binary);

    if (!file) 
    {
        std::cout << "file not found!" << std::endl;
        return false;
    }

    std::vector<uint8_t> romData(std::istreambuf_iterator<char>(file), {});

    if (romData.size() > 4096 - 0x200) //first 512 bytes are reserved
    {
        return false;
    }

    for (auto const& value : romData)
    {
        v_memory.insertDataToRam(value);
    }

    return true;
}

uint8_t Chip8_Manager::fetch()
{
    uint16_t data = v_memory.getRAMdata();
    v_memory.incrementCounter();
    return data;
}

opcodes Chip8_Manager::decode(uint8_t a_data)
{
    return v_decoder.decode(a_data);
}

bool Chip8_Manager::execute(uint8_t a_data, opcodes a_code)
{
    std::cout << static_cast<int>(a_code) << "@" << std::endl;
    if (v_instructions.opcodesMap.find(a_code) != v_instructions.opcodesMap.end())
    {
        auto instruction = v_instructions.opcodesMap[a_code];
        instruction(v_instructions,a_data);
        return true;
    }
    return false;
}

void Chip8_Manager::run(std::string a_filename)
{
    uint8_t data;
    v_filename = a_filename;

    if (!loadROM())
    {
        std::cout << "failed loading ROM" << std::endl;
        return;
    }
    v_memory.printRAM();

    while (!v_stop)
    {
        v_stop = v_display.renderDisplay();
        data = fetch();
        //std::cout << std::hex << static_cast<int>(data) << ", ";
        if (!execute(data, decode(data)))
        {
            return;
        }
    }
    v_display.quitDisplay();
}

}// namespace chip8_emulator