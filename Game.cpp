#include <iostream>
#include "Game.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_log.h"

bool Game::Initialize() {
    int sdlResult = SDL_Init(SDL_INIT_VIDEO);

    if (sdlResult != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return false;
    }

    mWindow = SDL_CreateWindow(
            "Title",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            640,
            800,
            SDL_WINDOW_SHOWN
    );

    if (!mWindow) {
        SDL_Log("Failed to to create window: %s", SDL_GetError());
        return false;
    }

    return true;
}

void Game::ShutDown() {
    SDL_DestroyWindow(mWindow);
    SDL_DestroyRenderer(mRenderer);
    SDL_Log("Shutting down game");
    SDL_Quit();
    exit(1);
}

void Game::RunLoop() {
    SDL_Log("Game loop running");
    while (mWindow) {
        ProcessInput();
        UpdateGame();
        GenerateOutput();
    }
}

void Game::ProcessInput() {

}

void Game::UpdateGame() {

}

void Game::GenerateOutput() {
    mRenderer = SDL_CreateRenderer(mWindow, 1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    SDL_SetRenderDrawColor(
            mRenderer,
            0,
            0,
            255,
            255
    );

    SDL_RenderClear(mRenderer);
    SDL_RenderPresent(mRenderer);
    SDL_Surface *bmp = SDL_LoadBMP("t.bmp");

    if (bmp == nullptr) {
        SDL_Log("SDL_LoadBMP Error: %s", SDL_GetError());
    }

    SDL_BlitSurface(bmp, 0, SDL_GetWindowSurface(mWindow), 0);
    SDL_UpdateWindowSurface(mWindow);

    bool is_quit = false;
    SDL_Event event;
    while (!is_quit) {
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                Game::ShutDown();
                is_quit = true;
            }
        }
    }
}

Game::Game() = default;
