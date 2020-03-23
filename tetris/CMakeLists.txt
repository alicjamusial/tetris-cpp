set(NAME tetris)

add_subdirectory(assets)

add_executable(${NAME}
        src/main.cpp
        include/settings.hpp

        src/Gameplay.cpp
        include/Gameplay.hpp

        src/GraphicInterface.cpp
        include/GraphicInterface.hpp

        src/Board.cpp
        include/Board.hpp

        src/PieceDefinition.cpp
        include/PieceDefinition.hpp

        src/Tetris.cpp
        include/Tetris.hpp
)

