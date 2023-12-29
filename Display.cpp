#include "Display.h"

namespace chip8_emulator
{
CHIP8_Display::CHIP8_Display()
{
	v_stop = false;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		return;
	}

	v_window = SDL_CreateWindow("CHIP-8", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 64, 32, SDL_WINDOW_SHOWN);

	if (v_window == NULL)
	{
		SDL_Quit();
		return;
	}

	v_renderer = SDL_CreateRenderer(v_window, -1, SDL_RENDERER_ACCELERATED);

	if (v_renderer == NULL) {
		SDL_DestroyWindow(v_window);
		SDL_Quit();
		return;
	}
}

void CHIP8_Display::clearDisplay()
{
	SDL_SetRenderDrawColor(v_renderer, 0, 0, 0, 255);
	SDL_RenderClear(v_renderer);
}

void CHIP8_Display::draw(uint8_t a_x, uint8_t a_y, uint8_t a_n)
{
	SDL_SetRenderDrawColor(v_renderer, 255, 255, 255, 255);
	for (int row = 0; row < a_n; ++row)
	{
		for (int col = 0; col < 8; ++col)
		{
			SDL_RenderDrawPoint(v_renderer, a_x + col, a_y + row);
		}
	}
}

void CHIP8_Display::displayLoop()
{
	while (!v_stop)
	{
		SDL_Event e;
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				v_stop = true;
			}
		}

		SDL_SetRenderDrawColor(v_renderer, 255, 255, 255, 255);
		SDL_RenderPresent(v_renderer);
	}

	SDL_DestroyRenderer(v_renderer);
	SDL_DestroyWindow(v_window);
	SDL_Quit();
}

}//namespace chip8_emulator