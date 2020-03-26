#include "Tetris.hpp"
#include <stdexcept>

using namespace game;

int main(int argc, char* args[])
{
    try
    {
        if(SDL_Init(SDL_INIT_VIDEO) < 0)
        {
            return EXIT_FAILURE;
        }

        Tetris tetris;
        tetris.GameInit();
        tetris.GameRun();
    }
    catch(const std::runtime_error& exception)
    {
        return EXIT_FAILURE;
    }

    return 0;
}