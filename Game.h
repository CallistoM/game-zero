#ifndef GAMEZERO_GAME_H
#define GAMEZERO_GAME_H

#include "SDL2/SDL.h"

class Game {
public:
    Game();

    bool Initialize();

    void RunLoop();

    void ShutDown();

    void ProcessInput();

    void UpdateGame();

    void GenerateOutput();

    SDL_Window *mWindow;
    SDL_Renderer *mRenderer;
    bool mIsRunning;
};


#endif //GAMEZERO_GAME_H
