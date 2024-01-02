#include "Display.h"

namespace chip8_emulator
{

CHIP8_Display::CHIP8_Display(std::array<uint8_t, 4096>& a_ram, uint16_t& a_index_register, uint8_t& a_sound, uint8_t& a_flag)
:
v_pixelArray{},
v_stop{},
v_pixel{},
v_ram{ a_ram },
v_index_register{ a_index_register },
v_sound{ a_sound },
v_flag{a_flag}
{
	v_pixel.w = v_pixelSize;
	v_pixel.h = v_pixelSize;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		return;
	}

	v_window = SDL_CreateWindow("CHIP-8", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH * v_pixelSize, SCREEN_HEIGHT * v_pixelSize , SDL_WINDOW_SHOWN);

	if (v_window == NULL)
	{
		SDL_Quit();
		return;
	}

	v_renderer = SDL_CreateRenderer(v_window, -1, SDL_RENDERER_ACCELERATED);

	if (v_renderer == NULL) 
	{
		SDL_DestroyWindow(v_window);
		SDL_Quit();
		return;
	}
}

void CHIP8_Display::createGrid()
{
	SDL_SetRenderDrawColor(v_renderer, 0, 0, 0, 255);
	for (int i = 1; i < SCREEN_WIDTH; ++i)
	{
		int xPos = v_pixelSize * i;
		SDL_RenderDrawLine(v_renderer, xPos, 0, xPos , SCREEN_HEIGHT * v_pixelSize);
	}

	for (int i = 1; i < SCREEN_HEIGHT; ++i)
	{
		int yPos = v_pixelSize * i;
		SDL_RenderDrawLine(v_renderer, 0, yPos, SCREEN_WIDTH * v_pixelSize, yPos);
	}
	SDL_RenderPresent(v_renderer);
}

void CHIP8_Display::clearDisplay()
{
	SDL_SetRenderDrawColor(v_renderer, 0, 0, 0, 255);
	SDL_RenderClear(v_renderer);
}

void CHIP8_Display::draw(uint8_t a_x, uint8_t a_y, uint8_t a_n)
{	
	a_x %= SCREEN_WIDTH;
	a_y %= SCREEN_HEIGHT;

	for (uint8_t i = 0; i < a_n; ++i)
	{
		for (uint8_t j = 0; j < 8; ++j)
		{
			v_flag = 1;
			int x = a_x + j;
			int y = a_y + i;

			if (x >= SCREEN_WIDTH || y >= SCREEN_HEIGHT)
			{
				break;
			}

			bool pixel = v_ram[v_index_register + i] & (0x80 >> j);
			v_pixelArray[x][y] ^= pixel;
			v_flag = v_pixelArray[x][y];
		}
	}

	for (int x = 0; x < SCREEN_WIDTH; ++x) 
	{
		for (int y = 0; y < SCREEN_HEIGHT; ++y) 
		{
			v_pixel.x = x * (v_pixelSize);
			v_pixel.y = y * (v_pixelSize);

			if (v_pixelArray[x][y])
			{
				SDL_SetRenderDrawColor(v_renderer, 255, 255, 255, 255);
			}
			else 
			{
				SDL_SetRenderDrawColor(v_renderer, 0, 0, 0, 255);
			}
			SDL_RenderFillRect(v_renderer, &v_pixel);
		}
	}
}

bool CHIP8_Display::renderDisplay() 
{
	createGrid();
	SDL_RenderPresent(v_renderer);
	soundHandler();
	SDL_Event e;
	while (SDL_PollEvent(&e) != 0) 
	{
		if (e.type == SDL_QUIT) 
		{
			return true;
		}
	}
	return false;
}

void CHIP8_Display::soundHandler()
{
	if (v_sound)
	{
		Beep(1000, 200);
	}
}



void CHIP8_Display::quitDisplay()
{
	SDL_DestroyRenderer(v_renderer);
	SDL_DestroyWindow(v_window);
	SDL_Quit();
}
}//namespace chip8_emulator