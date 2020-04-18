#include <iostream>
#include <SDL2/SDL.h>
#include <GLES2/gl2.h>
#include "imgui/imgui.h"
#include "imgui/imgui_impl_sdl.h"
#include "imgui/imgui_impl_opengl2.h"

#define SDL_DELAY 0
#define SWAP_INTERVAL 1

#define WINDOW_TITLE "SDL Program"
#define WINDOW_POS_X SDL_WINDOWPOS_UNDEFINED
#define WINDOW_POS_Y SDL_WINDOWPOS_UNDEFINED
#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 500
#define WINDOW_FLAGS (SDL_WindowFlags)(SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI)

#define RENDERER_FLAGS 0

class Color;

namespace Program
{
    extern bool Run;
    extern SDL_Window* Window;
    extern SDL_Renderer* Renderer;
    extern SDL_GLContext GlContext;
    extern SDL_Color ClearColor;
    void Init();
    void MainLoop();
    void InitImGui();
    void DrawImGui();
    void EventHandler();
    void Render();
    void Shutdown();
}