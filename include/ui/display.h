#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
using namespace std;

/**
 * Cross-platform function to clear the terminal screen
 * Uses "cls" command on Windows and "clear" command on Unix-based systems
 */
void clearScreen();

/**
 * Displays the current state of the game board
 * @param spaces Array containing the board state
 */
void drawBoard(string *spaces);

/**
 * Highlights the winning combination of markers on the board
 * @param spaces Array containing the board state
 * @param a First position to highlight
 * @param b Second position to highlight
 * @param c Third position to highlight
 */
void highlightMarker(string *spaces, int a, int b, int c);

/**
 * Displays the game board with highlighted winning markers
 * @param spaces Array containing the board state with highlighted markers
 */
void drawWinningBoard(string *spaces);

/**
 * Displays the current score in single player mode
 * @param win Number of player wins
 * @param tie Number of ties
 * @param loss Number of player losses
 */
void score(int win, int tie, int loss);

/**
 * Displays the current score in multiplayer mode
 * @param win Player 1's wins
 * @param tie Number of ties
 * @param loss Player 2's wins
 */
void scoreM(int win, int tie, int loss);

#endif