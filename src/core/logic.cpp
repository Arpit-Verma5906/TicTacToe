#include "logic.h"
#include "display.h"

char checkWinnerHard(string *spaces, string player, string computer)
{
    if (spaces[0] != " " && spaces[0] == spaces[1] && spaces[1] == spaces[2])
    {
        if (spaces[0] == player)
        {
            return 'P';
        }
        else
        {
            return 'C';
        }
    }
    else if (spaces[3] != " " && spaces[3] == spaces[4] && spaces[4] == spaces[5])
    {
        if (spaces[3] == player)
        {
            return 'P';
        }
        else
        {
            return 'C';
        }
    }
    else if (spaces[6] != " " && spaces[6] == spaces[7] && spaces[7] == spaces[8])
    {
        if (spaces[6] == player)
        {
            return 'P';
        }
        else
        {
            return 'C';
        }
    }

    else if (spaces[0] != " " && spaces[0] == spaces[3] && spaces[3] == spaces[6])
    {
        if (spaces[0] == player)
        {
            return 'P';
        }
        else
        {
            return 'C';
        }
    }
    else if (spaces[1] != " " && spaces[1] == spaces[4] && spaces[4] == spaces[7])
    {
        if (spaces[1] == player)
        {
            return 'P';
        }
        else
        {
            return 'C';
        }
    }
    else if (spaces[2] != " " && spaces[2] == spaces[5] && spaces[5] == spaces[8])
    {
        if (spaces[2] == player)
        {
            return 'P';
        }
        else
        {
            return 'C';
        }
    }

    else if (spaces[0] != " " && spaces[0] == spaces[4] && spaces[4] == spaces[8])
    {
        if (spaces[0] == player)
        {
            return 'P';
        }
        else
        {
            return 'C';
        }
    }
    else if (spaces[2] != " " && spaces[2] == spaces[4] && spaces[4] == spaces[6])
    {
        if (spaces[2] == player)
        {
            return 'P';
        }
        else
        {
            return 'C';
        }
    }

    else
    {
        return ' ';
    }
}

char checkWinner(string *spaces, string player, string computer)
{
    if (spaces[0] != " " && spaces[0] == spaces[1] && spaces[1] == spaces[2])
    {
        if (spaces[0] == player)
        {
            highlightMarker(spaces, 0, 1, 2);
            return 'P';
        }
        else
        {
            highlightMarker(spaces, 0, 1, 2);
            return 'C';
        }
    }
    else if (spaces[3] != " " && spaces[3] == spaces[4] && spaces[4] == spaces[5])
    {
        if (spaces[3] == player)
        {
            highlightMarker(spaces, 3, 4, 5);
            return 'P';
        }
        else
        {
            highlightMarker(spaces, 3, 4, 5);
            return 'C';
        }
    }
    else if (spaces[6] != " " && spaces[6] == spaces[7] && spaces[7] == spaces[8])
    {
        if (spaces[6] == player)
        {
            highlightMarker(spaces, 6, 7, 8);
            return 'P';
        }
        else
        {
            highlightMarker(spaces, 6, 7, 8);
            return 'C';
        }
    }

    else if (spaces[0] != " " && spaces[0] == spaces[3] && spaces[3] == spaces[6])
    {
        if (spaces[0] == player)
        {
            highlightMarker(spaces, 0, 3, 6);
            return 'P';
        }
        else
        {
            highlightMarker(spaces, 0, 3, 6);
            return 'C';
        }
    }
    else if (spaces[1] != " " && spaces[1] == spaces[4] && spaces[4] == spaces[7])
    {
        if (spaces[1] == player)
        {
            highlightMarker(spaces, 1, 4, 7);
            return 'P';
        }
        else
        {
            highlightMarker(spaces, 1, 4, 7);
            return 'C';
        }
    }
    else if (spaces[2] != " " && spaces[2] == spaces[5] && spaces[5] == spaces[8])
    {
        if (spaces[2] == player)
        {
            highlightMarker(spaces, 2, 5, 8);
            return 'P';
        }
        else
        {
            highlightMarker(spaces, 2, 5, 8);
            return 'C';
        }
    }

    else if (spaces[0] != " " && spaces[0] == spaces[4] && spaces[4] == spaces[8])
    {
        if (spaces[0] == player)
        {
            highlightMarker(spaces, 0, 4, 8);
            return 'P';
        }
        else
        {
            highlightMarker(spaces, 0, 4, 8);
            return 'C';
        }
    }
    else if (spaces[2] != " " && spaces[2] == spaces[4] && spaces[4] == spaces[6])
    {
        if (spaces[2] == player)
        {
            highlightMarker(spaces, 2, 4, 6);
            return 'P';
        }
        else
        {
            highlightMarker(spaces, 2, 4, 6);
            return 'C';
        }
    }

    else
    {
        return ' ';
    }
}

bool areMovesLeft(string *spaces)
{
    for (int i = 0; i < 9; i++)
    {
        if (spaces[i] == " ")
        {
            return true;
        }
    }
    return false;
}

bool handleResult(string *spaces, string player, string computer, int &win, int &tie, int &loss)
{
    char result = checkWinner(spaces, player, computer);
    if (result == 'P')
    {
        win++;
        cout << "You Win!\n";
        score(win, tie, loss);
        return true;
    }
    if (result == 'C')
    {
        loss++;
        cout << "You Lose!\n";
        score(win, tie, loss);
        return true;
    }
    if (checkTie(spaces, tie))
    {
        score(win, tie, loss);
        return true;
    }
    return false;
}

bool handleResultM(string *spaces, string player, string player2, int &win, int &tie, int &loss)
{
    char result = checkWinner(spaces, player, player2);
    if (result == 'P')
    {
        win++;
        cout << "Player1 Wins The Match!\n";
        scoreM(win, tie, loss);
        return true;
    }
    if (result == 'C')
    {
        loss++;
        cout << "Player2 Wins The Match!\n";
        scoreM(win, tie, loss);
        return true;
    }
    if (checkTie(spaces, tie))
    {
        scoreM(win, tie, loss);
        return true;
    }
    return false;
}

bool checkTie(string *spaces, int &tie)
{
    for (int i = 0; i < 9; i++)
    {
        if (spaces[i] == " ")
        {
            return false;
        }
    }

    tie++;
    cout << "It's a Tie!\n";
    return true;
}