#include "Tetris.hpp"
#include <stdexcept>

using namespace game;

int main(int argc, char* args[])
{
    Tetris tetris;

    try
    {
        tetris.GameInit();
    }
    catch(const std::runtime_error& exception)
    {
        return EXIT_FAILURE;
    }

    tetris.GameRun();
    return 0;
}