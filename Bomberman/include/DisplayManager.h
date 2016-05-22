#ifndef DISPLAYMANAGER_H
#define DISPLAYMANAGER_H

#include "Display.h"
#include "SDL.h"
#include "KeyboardInput.h"
#include <stack>

class DisplayManager
{
    public:
        DisplayManager(SDL_Texture* texture, SDL_Renderer* renderer, KeyboardInput* keyboard_input, bool* running);
        ~DisplayManager();

        void EnterDisplay(Display* display);
        void LeaveDisplay();
        Display* CurrentDisplay();

        void Update();
        void Draw(SDL_Renderer* renderer);

    protected:

    private:
        std::stack<Display*> m_displays;
        SDL_Renderer*        m_renderer;
};

#endif // DISPLAYMANAGER_H
