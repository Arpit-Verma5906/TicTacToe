cmake_minimum_required(VERSION 3.10)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    src/TicTacToe.cpp
    src/board.cpp
    src/display.cpp
    src/player.cpp
    src/computer.cpp
    src/logic.cpp
)

include_directories(${PROJECT_SOURCE_DIR}/include)
add_executable(tictactoe ${SOURCES})