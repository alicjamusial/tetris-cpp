//
// Created by Alicja on 2020-03-20.
//
#include <cstdio>
#include <SDL.h>

#include "Tetris.hpp"

using namespace game;

Tetris::Tetris() : screenHeight(640), screenWidth(480) {
  bool quit = false;
  SDL_Window* window = nullptr;
  SDL_Surface* screenSurface = nullptr;

  //Initialize SDL
  if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
  {
    printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
  }
  else
  {
    //Create window
    window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN );
    if( window == NULL )
    {
      printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
    }
    else
    {
      //Get window surface
      screenSurface = SDL_GetWindowSurface( window );

      //Fill the surface white
      SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );

      //Update the surface
      SDL_UpdateWindowSurface( window );

      //Wait two seconds
      while (!quit) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
          /* handle your event here */

          //User requests quit
          if( event.type == SDL_QUIT )
            quit = true;
        }
        /* do some other stuff here -- draw your app, etc. */
      }
    }
  }

  //Destroy window
  SDL_DestroyWindow( window );

  //Quit SDL subsystems
  SDL_Quit();
}