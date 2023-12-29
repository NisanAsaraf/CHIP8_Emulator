#ifndef CHIP8_DISPLAY_H
#define CHIP8_DISPLAY_H
#include <SDL.h>

namespace chip8_emulator
{

class CHIP8_Display
{
public:
	CHIP8_Display();
	void clearDisplay();
	void draw(uint8_t a_x, uint8_t a_y, uint8_t a_n);
	void displayLoop();
private:
	SDL_Window* v_window = NULL;
	SDL_Renderer* v_renderer = NULL;
	bool v_stop;
};

}//namespace chip8_emulator
#endif
