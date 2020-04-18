#include "sdl_program.h"

//Variables
namespace Program
{
    bool Run;
    SDL_Window* Window;
    SDL_Renderer* Renderer;
    SDL_GLContext GlContext;
    SDL_Color ClearColor = { 55, 55, 55, 255 };
}

//Functions

void Program::MainLoop()
{
    EventHandler();
    ImGui_ImplOpenGL2_NewFrame();
    ImGui_ImplSDL2_NewFrame(Window);
    ImGui::NewFrame();
    DrawImGui();
    ImGui::Render();
    Render();
    SDL_Delay(SDL_DELAY);
}

void Program::DrawImGui()
{
    ImGui::Begin("ImGui Window");
    ImGui::End();
}

void Program::EventHandler()
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        ImGui_ImplSDL2_ProcessEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                Run = false;
        }
    }
}

void Program::InitImGui()
{
    ImGui::CreateContext();
    ImGui_ImplSDL2_InitForOpenGL(Window, GlContext);
    ImGui_ImplOpenGL2_Init();
}

void Program::Render()
{
    ImGuiIO& io = ImGui::GetIO();
    glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
    glClearColor((float)ClearColor.r / 255, (float)ClearColor.g / 255, (float)ClearColor.b / 255, (float)ClearColor.a / 255);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
    SDL_GL_SwapWindow(Window);
}

void Program::Init()
{
    Run = SDL_Init(SDL_INIT_EVERYTHING) == 0;
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    Window = SDL_CreateWindow(WINDOW_TITLE, WINDOW_POS_X, WINDOW_POS_Y, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_FLAGS);
    Renderer = SDL_CreateRenderer(Window, -1, RENDERER_FLAGS);
    GlContext = SDL_GL_CreateContext(Window);
    SDL_GL_MakeCurrent(Window, GlContext);
    SDL_GL_SetSwapInterval(SWAP_INTERVAL);

    Run == Run && Window && Renderer && GlContext;

    if(Run)
    {
        InitImGui();
    }

    while(Run)
    {
        MainLoop();
    }

    Shutdown();
}

void Program::Shutdown()
{
    SDL_DestroyRenderer(Renderer);
    SDL_DestroyWindow(Window);
    SDL_Quit();
}