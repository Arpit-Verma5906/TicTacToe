# TicTacToe

A modular command-line Tic Tac Toe game implemented in C++.

## Features

- Single-player mode (against computer)
- Two-player mode (X vs O)
- Input validation
- Clean modular code structure
- Interactive game board display

## Project Structure

The project follows a modular architecture organized into logical components:

```
TicTacToe/
├── include/               # Header files
│   ├── core/             # Core game mechanics
│   │   ├── board.h       # Game board management
│   │   └── logic.h       # Game rules and win conditions
│   ├── players/          # Player-related components
│   │   ├── player.h      # Base player class
│   │   └── computer.h    # AI player implementation
│   └── ui/               # User interface
│       └── display.h     # Game display functionality
├── src/                  # Source files
│   ├── core/             # Core implementation
│   ├── players/          # Player implementations
│   ├── ui/               # UI implementation
│   └── TicTacToe.cpp    # Main game entry point
├── build/                # Build output directory
└── CMakeLists.txt       # CMake build configuration
```

### Components

1. **Core (core/)**
   - Board management and game state
   - Game logic and win condition checking

2. **Players (players/)**
   - Base player class implementation
   - Computer AI player implementation
   - Handles player moves and turns

3. **User Interface (ui/)**
   - Game board display
   - User input handling
   - Game state visualization

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