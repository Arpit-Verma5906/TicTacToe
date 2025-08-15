#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
using namespace std;

/**
 * Handles a player's move in single player mode
 * @param spaces Array containing the board state
 * @param player The player's marker (X or O)
 */
void playerMove(string *spaces, string player);

/**
 * Handles a player's move in multiplayer mode
 * @param spaces Array containing the board state
 * @param player Current player's marker (X or O)
 * @param firstMove Counter to track whose turn it is
 */
void playerMoveM(string *spaces, string player, int firstMove);

#endif