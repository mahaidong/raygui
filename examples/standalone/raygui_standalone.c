// gcc ./raygui_standalone.c -lSDL2  -lGL -lpthread -lm

//----------------------------------------------------------------------------------
// Defines and Macros
// TODO: Define input keys required by raygui
//----------------------------------------------------------------------------------
#define BLANK      (Color){ 0, 0, 0, 0 }           // Blank (Transparent)
#define KEY_RIGHT           262
#define KEY_LEFT            263
#define KEY_DOWN            264
#define KEY_UP              265
#define KEY_BACKSPACE       259
#define KEY_ENTER           257
#define MOUSE_LEFT_BUTTON     0
#define KEY_LEFT_CONTROL    341      // Key: Control left
#define KEY_LEFT_SHIFT 340
#define KEY_HOME 268
#define KEY_END 269
#define KEY_DELETE 261



#define RAYGUI_IMPLEMENTATION
#define RAYGUI_STANDALONE
#include "../../src/raygui.h"
#include "./raygui_custom_backend.h"

#include <SDL2/SDL.h>

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main()
{

//Initialize SDL2
SDL_Init(SDL_INIT_VIDEO);

//Create a window using SDL2
const int screenWidth = 800;
const int screenHeight = 450;
SDL_Window* window = SDL_CreateWindow("Raygui with SDL2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);

//Initialize raygui
// GuiLoadStyle("resources/raygui/raygui_dark.rgs");

//Main game loop
while (1)
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            SDL_DestroyWindow(window);
            SDL_Quit();
            return 0;
        }
        //Draw raygui elements
        // GuiLabel((Rectangle){ 0, 0, 100, 20 }, "Hello, world!");
        GuiButton((Rectangle){ screenWidth/2 - 50, screenHeight/2 - 20, 100, 40 }, "Click me!");
    }

    SDL_GL_SwapWindow(window);
}

//Close window and quit SDL2
SDL_DestroyWindow(window);
SDL_Quit();

    return 0;
}