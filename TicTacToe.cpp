#include "display.h"
#include "player.h"
#include "computer.h"
#include "logic.h"
#include "board.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(NULL));

    string spaces[9] = {
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
    };
    string player;
    string player2;
    string computer;
    char choice;
    bool running = true;
    int win = 0;
    int tie = 0;
    int loss = 0;
    int cnt = 1;

    int gameMode;
    do
    {
        cout << '\n';
        cout << "Select The Number Of Players:\n";
        cout << "1: Single Player\n";
        cout << "2: Multi-Player\n";
        cout << "Enter Your Choice: ";
        cin >> gameMode;
    } while (gameMode != 1 && gameMode != 2);

    if (gameMode == 1)
    {

        int difficulty;
        do
        {
            cout << "\nSelect the difficulty:\n";
            cout << "1: Easy Difficulty\n";
            cout << "2: Hard Difficulty\n";
            cout << "3: Impossible Difficulty\n";
            cin >> difficulty;
        } while (difficulty != 1 && difficulty != 2 && difficulty != 3);

        cout << "Choose Your Marker (X/O): ";
        cin >> player;

        do
        {
            if (player == "x" || player == "X")
            {
                player = "X";
            }
            else if (player == "o" || player == "O")
            {
                player = "O";
            }
            else
            {
                player = " ";
                cout << "Choose Your Marker Only From (X/O): ";
                cin >> player;
            }
        } while (player != "X" && player != "O");

        if (player == "X")
        {
            computer = "O";
        }
        else
        {
            computer = "X";
        }

        while (running)
        {

            clearScreen();
            clearBoard(spaces);
            drawBoard(spaces);

            int firstMove = rand() % 2;

            if (firstMove == 0)
            {
                while (true)
                {
                    playerMove(spaces, player);
                    clearScreen();
                    drawBoard(spaces);
                    if (handleResult(spaces, player, computer, win, tie, loss))
                        break;

                    if (difficulty == 1)
                    {
                        computerMoveEasy(spaces, computer);
                    }
                    else if (difficulty == 2)
                    {
                        computerMoveHard(spaces, computer, player);
                    }
                    else
                    {
                        spaces[computerMoveImpossible(spaces, computer, player)] = computer;
                    }
                    clearScreen();
                    drawBoard(spaces);
                    if (handleResult(spaces, player, computer, win, tie, loss))
                        break;
                }
            }
            else
            {
                while (true)
                {
                    if (difficulty == 1)
                    {
                        computerMoveEasy(spaces, computer);
                    }
                    else if (difficulty == 2)
                    {
                        computerMoveHard(spaces, computer, player);
                    }
                    else
                    {
                        spaces[computerMoveImpossible(spaces, computer, player)] = computer;
                    }
                    clearScreen();
                    drawBoard(spaces);
                    if (handleResult(spaces, player, computer, win, tie, loss))
                        break;

                    playerMove(spaces, player);
                    clearScreen();
                    drawBoard(spaces);
                    if (handleResult(spaces, player, computer, win, tie, loss))
                        break;
                }
            }

            cout << "Do you wish to continue playing? (Y/N): ";
            cin >> choice;
            if (choice != 'Y' && choice != 'y')
            {
                running = false;
            }
        }
    }
    else if (gameMode == 2)
    {
        cout << "Choose a marker for Player1 (X/O): ";
        cin >> player;

        do
        {
            if (player == "x" || player == "X")
            {
                player = "X";
            }
            else if (player == "o" || player == "O")
            {
                player = "O";
            }
            else
            {
                player = " ";
                cout << "Choose Your Marker Only From (X/O): ";
                cin >> player;
            }
        } while (player != "X" && player != "O");
        player == "X" ? player2 = "O" : player2 = "X";

        cout << "Marker for Player2 is: " << player2;

        while (running)
        {
            if (cnt > 1)
            {
                clearScreen();
            }
            clearBoard(spaces);
            drawBoard(spaces);

            int firstMove = rand() % 2;

            if (firstMove == 0)
            {
                cout << "Player1 gets the first move!\n";
                while (true)
                {
                    playerMoveM(spaces, player, firstMove);
                    firstMove++;
                    clearScreen();
                    drawBoard(spaces);
                    if (handleResultM(spaces, player, player2, win, tie, loss))
                        break;

                    playerMoveM(spaces, player2, firstMove);
                    firstMove++;
                    clearScreen();
                    drawBoard(spaces);
                    if (handleResultM(spaces, player, player2, win, tie, loss))
                        break;
                }
            }
            else
            {
                cout << "Player2 gets the first move!\n";
                while (true)
                {
                    playerMoveM(spaces, player2, firstMove);
                    firstMove++;
                    clearScreen();
                    drawBoard(spaces);
                    if (handleResultM(spaces, player, player2, win, tie, loss))
                        break;

                    playerMoveM(spaces, player, firstMove);
                    firstMove++;
                    clearScreen();
                    drawBoard(spaces);
                    if (handleResultM(spaces, player, player2, win, tie, loss))
                        break;
                }
            }

            cout << "Do you wish to continue playing? (Y/N): ";
            cin >> choice;
            if (choice != 'Y' && choice != 'y')
            {
                running = false;
            }

            cnt++;
        }
    }
    else
    {
        cout << "Invalid Choice! Please Enter Either 1 or 2!\n";
    }

    cout << "*******************\n";
    cout << "Thanks for playing!\n";

    return 0;
}