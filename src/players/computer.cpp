#include "computer.h"
#include "logic.h"

void computerMoveEasy(string *spaces, string computer)
{
    int number;

    do
    {
        number = rand() % 9;
    } while (spaces[number] != " ");

    spaces[number] = computer;
}

void computerMoveHard(string *spaces, string computer, string player)
{

    for (int i = 0; i < 9; i++)
    {
        if (spaces[i] == " ")
        {
            spaces[i] = computer;
            if (checkWinnerHard(spaces, player, computer) == 'C')
            {
                return;
            }
            spaces[i] = " ";
        }
    }

    for (int i = 0; i < 9; i++)
    {
        if (spaces[i] == " ")
        {
            spaces[i] = player;
            if (checkWinnerHard(spaces, player, computer) == 'P')
            {
                spaces[i] = computer;
                return;
            }
            spaces[i] = " ";
        }
    }

    computerMoveEasy(spaces, computer);
}

int computerMoveImpossible(string *spaces, string computer, string player)
{
    int bestValue = INT_MIN;
    int bestMove = -1;

    for (int i = 0; i < 9; i++)
    {
        if (spaces[i] == " ")
        {
            spaces[i] = computer;
            int moveValue = miniMax(spaces, 0, false, player, computer);
            spaces[i] = " ";
            if (moveValue > bestValue)
            {
                bestMove = i;
                bestValue = moveValue;
            }
        }
    }
    return bestMove;
}

int miniMax(string *spaces, int depth, bool isMaximizing, string player, string computer)
{
    int score = evaluatePosition(spaces, player, computer);
    if (score == 10)
        return score - depth;
    if (score == -10)
        return score + depth;
    if (!areMovesLeft(spaces))
        return 0;

    if (isMaximizing)
    {
        int best = INT_MIN;
        for (int i = 0; i < 9; i++)
        {
            if (spaces[i] == " ")
            {
                spaces[i] = computer;
                best = max(best, miniMax(spaces, depth + 1, false, player, computer));
                spaces[i] = " ";
            }
        }
        return best;
    }
    else
    {
        int best = INT_MAX;
        for (int i = 0; i < 9; i++)
        {
            if (spaces[i] == " ")
            {
                spaces[i] = player;
                best = min(best, miniMax(spaces, depth + 1, true, player, computer));
                spaces[i] = " ";
            }
        }
        return best;
    }
}
int evaluatePosition(string *spaces, string player, string computer)
{
    char winner = checkWinnerHard(spaces, player, computer);
    if (winner == 'C')
        return 10;
    if (winner == 'P')
        return -10;
    return 0;
}