set(NAME tetris)

add_executable(${NAME}
        main.cpp
        constants.hpp

        Gameplay.cpp
        Gameplay.hpp

        GraphicInterface.cpp
        GraphicInterface.hpp

        Board.cpp
        Board.hpp

        Piece.cpp
        Piece.hpp

        Tetris.cpp
        Tetris.hpp
)

