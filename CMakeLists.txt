cmake_minimum_required(VERSION 3.10)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CORE_SOURCES
    src/core/board.cpp
    src/core/logic.cpp
)

set(PLAYER_SOURCES
    src/players/player.cpp
    src/players/computer.cpp
)

set(UI_SOURCES
    src/ui/display.cpp
)

set(SOURCES
    src/TicTacToe.cpp
    ${CORE_SOURCES}
    ${PLAYER_SOURCES}
    ${UI_SOURCES}
)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/include/core
    ${PROJECT_SOURCE_DIR}/include/players
    ${PROJECT_SOURCE_DIR}/include/ui
)

add_executable(tictactoe ${SOURCES})