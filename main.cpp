#include "SDL.h"

int main(int argc, char* argv[])
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        // Error handling if SDL initialization fails
        SDL_Log("SDL could not initialize! SDL_Error: %s", SDL_GetError());
        return -1;
    }

    // Create a window
    SDL_Window* window = SDL_CreateWindow(
        "SDL2 Window",                // Window title
        SDL_WINDOWPOS_UNDEFINED,      // Initial x position
        SDL_WINDOWPOS_UNDEFINED,      // Initial y position
        640,                          // Width
        480,                          // Height
        SDL_WINDOW_SHOWN              // Flags - here, the window is shown
    );

    if (window == nullptr) {
        // Error handling if window creation fails
        SDL_Log("Window could not be created! SDL_Error: %s", SDL_GetError());
        return -1;
    }

    // Main loop - keep the window open until user closes it
    bool quit = false;
    SDL_Event e;
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }
        // Add your rendering or game logic here
    }

    // Clean up and quit SDL
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}