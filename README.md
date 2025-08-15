# TicTacToe

A modular command-line Tic Tac Toe game implemented in C++.

## Features

- Single-player mode (against computer)
- Two-player mode (X vs O)
- Input validation
- Clean modular code structure
- Interactive game board display

## Project Structure

The code is organized into several modules:
- `board.h/cpp`: Game board management
- `player.h/cpp`: Player class implementation
- `computer.h/cpp`: Computer player AI
- `display.h/cpp`: Game display functionality
- `logic.h/cpp`: Game logic and win conditions
- `TicTacToe.cpp`: Main game entry point

## Building and Running

### Prerequisites

#### Windows
- MinGW or Visual Studio C++ compiler
- CMake (version 3.0 or higher)
- Git (optional)

#### Linux
- g++ or clang++ compiler (`sudo apt install build-essential` on Ubuntu/Debian)
- CMake (`sudo apt install cmake` on Ubuntu/Debian)
- Git (optional, `sudo apt install git` on Ubuntu/Debian)

### Build Instructions

1. **Clone the repository**
   ```sh
   git clone https://github.com/Arpit-Verma5906/TicTacToe.git
   cd TicTacToe
   ```

2. **Create and enter build directory**
   ```sh
   mkdir build
   cd build
   ```

3. **Generate build files with CMake**
   
   On Linux:
   ```sh
   cmake ..
   ```
   
   On Windows (with MinGW):
   ```sh
   cmake .. -G "MinGW Makefiles"
   ```

4. **Build the project**
   
   On Linux:
   ```sh
   make
   # or
   cmake --build .
   ```
   
   On Windows:
   ```sh
   cmake --build .
   ```

5. **Run the game**
   
   On Linux:
   ```sh
   ./tictactoe
   ```
   
   On Windows:
   ```sh
   .\tictactoe.exe
   ```

## How to Play

1. Start the game and choose game mode:
   - Enter 1 for Single Player (vs Computer)
   - Enter 2 for Two Players

2. Players take turns placing their marks (X or O) on the board
3. First player to get three marks in a row (horizontal, vertical, or diagonal) wins
4. If no player achieves three in a row and the board is full, the game is a draw

## License

This project is open source and available under the MIT License.