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

        src/Point.cpp
        include/Point.hpp
        )

target_include_directories(${NAME} PRIVATE include)
target_link_libraries(${NAME} SDL2-static)

set_property(TARGET ${NAME} PROPERTY CXX_STANDARD 14)
