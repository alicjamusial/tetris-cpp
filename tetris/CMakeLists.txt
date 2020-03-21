set(NAME tetris)

add_subdirectory(assets)

add_executable(${NAME}
        main.cpp
        settings.hpp

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

