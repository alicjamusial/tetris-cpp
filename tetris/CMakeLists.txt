set(NAME tetris)

add_executable(${NAME}
    main.cpp

    Tetris.cpp
    Tetris.hpp

    Gameplay.cpp
    Gameplay.hpp

    GraphicInterface.cpp
    GraphicInterface.hpp

    Board.cpp
    Board.hpp
        constants.hpp)

