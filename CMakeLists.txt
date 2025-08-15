cmake_minimum_required(VERSION 3.10)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    TicTacToe.cpp
    board.cpp
    display.cpp
    player.cpp
    computer.cpp
    logic.cpp
)

add_executable(tictactoe ${SOURCES})