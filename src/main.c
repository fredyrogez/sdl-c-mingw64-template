// SDL C MinGW64 Template
// 
// https://github.com/rogez/sdl-c-mingw64-template
//
// MIT License - Copyright (C) 2020-2021 Fredy Rogez (https://rogez.games)
// This file is subject to the terms and conditions defined in
// file "LICENSE", which is part of this source code package.

#include "commons.h"

Game game;

int main(int argc, char **args)
{
    srand((unsigned int)time(NULL));
    game.running = true;
    game.window = NULL;
    game.renderer = NULL;
    game.texture = NULL;

    SDL_Init(SDL_INIT_VIDEO | SDL_RENDERER_PRESENTVSYNC);

    game.window = SDL_CreateWindow(GAME_NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (game.window == NULL)
    {
        printf("ERROR : SDL_CreateWindow");
        exit(1);
    }

    game.renderer = SDL_CreateRenderer(game.window, -1, SDL_RENDERER_ACCELERATED);
    if (game.renderer == NULL)
    {
        printf("ERROR : SDL_CreateRenderer");
        exit(1);
    }

    SDL_Surface *surface = IMG_Load("assets/texture.jpg");
    game.texture = SDL_CreateTextureFromSurface(game.renderer, surface);
    SDL_FreeSurface(surface);

    while (game.running)
    {
        // EVENTS
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                game.running = false;
                break;
            }
        }

        // UPDATE
        // ...


        // DRAW
        SDL_SetRenderDrawColor(game.renderer, 0, 0, 0, 255);
        SDL_RenderClear(game.renderer);
        SDL_RenderCopy(game.renderer, game.texture, NULL, NULL);
        SDL_RenderPresent(game.renderer);
        SDL_Delay(5);
    }

    SDL_DestroyRenderer(game.renderer);
    SDL_DestroyTexture(game.texture);
    SDL_DestroyWindow(game.window);
    SDL_Quit();
    return 0;
}
