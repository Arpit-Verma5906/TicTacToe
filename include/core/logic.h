#ifndef LOGIC_H
#define LOGIC_H

#include <iostream>
using namespace std;

/**
 * Checks for a winner without highlighting winning markers (used by AI)
 * @param spaces Array containing the board state
 * @param player Player's marker (X or O)
 * @param computer Computer's marker (X or O)
 * @return 'P' for player win, 'C' for computer win, ' ' for no winner
 */
char checkWinnerHard(string *spaces, string player, string computer);

/**
 * Checks for a winner and highlights the winning combination
 * @param spaces Array containing the board state
 * @param player Player's marker (X or O)
 * @param computer Computer's marker (X or O)
 * @return 'P' for player win, 'C' for computer win, ' ' for no winner
 */
char checkWinner(string *spaces, string player, string computer);

/**
 * Checks if the game is a tie
 * @param spaces Array containing the board state
 * @param tie Reference to tie counter
 * @return true if game is tied, false otherwise
 */
bool checkTie(string *spaces, int &tie);

/**
 * Checks if there are any valid moves remaining
 * @param spaces Array containing the board state
 * @return true if moves are available, false otherwise
 */
bool areMovesLeft(string *spaces);

/**
 * Handles the game result in single player mode
 * Updates scores and displays appropriate message
 * @param spaces Array containing the board state
 * @param player Player's marker (X or O)
 * @param computer Computer's marker (X or O)
 * @param win Reference to win counter
 * @param tie Reference to tie counter
 * @param loss Reference to loss counter
 * @return true if game is over, false if game should continue
 */
bool handleResult(string *spaces, string player, string computer, int &win, int &tie, int &loss);

/**
 * Handles the game result in multiplayer mode
 * Updates scores and displays appropriate message
 * @param spaces Array containing the board state
 * @param player Player 1's marker (X or O)
 * @param player2 Player 2's marker (X or O)
 * @param win Reference to Player 1's win counter
 * @param tie Reference to tie counter
 * @param loss Reference to Player 2's win counter
 * @return true if game is over, false if game should continue
 */
bool handleResultM(string *spaces, string player, string player2, int &win, int &tie, int &loss);

#endif