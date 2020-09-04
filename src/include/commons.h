// SDL C MinGW64 Template
// 
// https://github.com/rogez/sdl-c-mingw64-template
//
// MIT License - Copyright (C) 2020 Fredy Rogez (rogez.net)
// This file is subject to the terms and conditions defined in
// file "LICENSE", which is part of this source code package.

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
// #include "SDL2/SDL_ttf.h"
// #include "SDL2/SDL_mixer.h"
// #include "SDL2/SDL_net.h"

// MACROS
#define MIN(a,b) ((a)<=(b)?a:b)
#define MAX(a,b) ((a)>=(b)?a:b)

// GAME
#define GAME_VERSION "1.0.0"
#define GAME_NAME "My Game"
#define WINDOW_WIDTH 960
#define WINDOW_HEIGHT 540

typedef struct Game
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    SDL_Surface *icon;
    bool running;
} Game;
