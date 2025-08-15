#ifndef COMPUTER_H
#define COMPUTER_H

#include <iostream>
using namespace std;

/**
 * Makes a random move for the computer (Easy difficulty)
 * @param spaces Array containing the board state
 * @param computer Computer's marker (X or O)
 */
void computerMoveEasy(string *spaces, string computer);

/**
 * Makes a strategic move for the computer (Hard difficulty)
 * Blocks player's winning moves and takes winning opportunities
 * @param spaces Array containing the board state
 * @param computer Computer's marker (X or O)
 * @param player Player's marker (X or O)
 */
void computerMoveHard(string *spaces, string computer, string player);

/**
 * Makes an optimal move using the minimax algorithm (Impossible difficulty)
 * @param spaces Array containing the board state
 * @param computer Computer's marker (X or O)
 * @param player Player's marker (X or O)
 * @return The optimal position (0-8) for the computer's move
 */
int computerMoveImpossible(string *spaces, string computer, string player);

/**
 * Implements the minimax algorithm for finding the optimal move
 * @param spaces Array containing the board state
 * @param depth Current depth in the game tree
 * @param isMaximizing True if maximizing player's turn, false otherwise
 * @param player Player's marker (X or O)
 * @param computer Computer's marker (X or O)
 * @return The score for the current board position
 */
int miniMax(string *spacees, int depth, bool isMaximizing, string player, string computer);

/**
 * Evaluates the current board position for the minimax algorithm
 * @param spaces Array containing the board state
 * @param player Player's marker (X or O)
 * @param computer Computer's marker (X or O)
 * @return 10 for computer win, -10 for player win, 0 for no winner
 */
int evaluatePosition(string *spaces, string player, string computer);

#endif