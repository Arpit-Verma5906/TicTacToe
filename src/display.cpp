#include "display.h"
#include "board.h"
#include <cstdlib>

void clearScreen()
{

#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void drawBoard(string *spaces)
{

    cout << '\n';

    cout << "     |     |     " << '\n';
    cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << '\n';
    cout << "_____|_____|_____" << '\n';

    cout << "     |     |     " << '\n';
    cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << '\n';
    cout << "_____|_____|_____" << '\n';

    cout << "     |     |     " << '\n';
    cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << '\n';
    cout << "     |     |     " << '\n';
}

void highlightMarker(string *spaces, int a, int b, int c)
{
    for (int i = 0; i < 9; i++)
    {
        if (i == a || i == b || i == c)
        {
            spaces[i] = "[" + spaces[i] + "]";
        }
        else
        {
            spaces[i] = " " + spaces[i] + " ";
        }
    }
    drawWinningBoard(spaces);
    clearBoard(spaces);
}

void drawWinningBoard(string *spaces)
{

    clearScreen();

    cout << '\n';

    cout << "     |     |     " << '\n';
    cout << " " << spaces[0] << " | " << spaces[1] << " | " << spaces[2] << " " << '\n';
    cout << "_____|_____|_____" << '\n';

    cout << "     |     |     " << '\n';
    cout << " " << spaces[3] << " | " << spaces[4] << " | " << spaces[5] << " " << '\n';
    cout << "_____|_____|_____" << '\n';

    cout << "     |     |     " << '\n';
    cout << " " << spaces[6] << " | " << spaces[7] << " | " << spaces[8] << " " << '\n';
    cout << "     |     |     " << '\n';
}


void score(int win, int tie, int loss)
{
    cout << "Your current score is: " << win << " Wins, " << tie << " Ties and " << loss << " Losses!\n";
}

void scoreM(int win, int tie, int loss)
{
    cout << "Current Score is: Player1: " << win << ", Player2: " << loss << " and Ties: " << tie << '\n';
}
