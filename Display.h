#ifndef CHIP8_DISPLAY_H
#define CHIP8_DISPLAY_H
#include <SDL.h>
#include <Array>
namespace chip8_emulator
{

class CHIP8_Display
{
public:
	CHIP8_Display(std::array<uint8_t, 4096>& v_ram);
	void clearDisplay();
	void draw(uint8_t a_x, uint8_t a_y, uint8_t a_n);
	bool renderDisplay();
	void quitDisplay();
	void createGrid();
	void drawPixels(uint8_t a_x, uint8_t a_y, uint8_t a_n);
	void drawPixels();

private:
	SDL_Window* v_window = nullptr;
	SDL_Renderer* v_renderer = nullptr;
	std::array<uint8_t, 4096>& v_ram;

	static constexpr uint8_t v_pixelSize = 8;
	static constexpr uint8_t SCREEN_WIDTH = 64;
	static constexpr uint8_t SCREEN_HEIGHT = 32;
	SDL_Rect v_pixel;

	std::array<std::array<bool, SCREEN_WIDTH>, SCREEN_HEIGHT> v_pixelVector;
	bool v_stop;
};

}//namespace chip8_emulator
#endif
