#include "player.h"

void playerMove(string *spaces, string player)
{
    int number;
    do
    {
        cout << "Enter a spot to add a marker (1-9): ";
        cin >> number;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            number = -1;
        }

        if (number < 1 || number > 9)
        {
            cout << "Invalid spot! Choose a number between 1 and 9!\n";
            continue;
        }

        number--;
        if (spaces[number] == " ")
        {
            spaces[number] = player;
            break;
        }
        else
        {
            cout << "That spot is already occupied!\n";
        }
    } while (true);
}

void playerMoveM(string *spaces, string player, int firstMove)
{

    int number;
    do
    {
        if (firstMove % 2 == 0)
        {
            cout << "It is Player1's turn.\n";
        }
        else
        {
            cout << "It is Player2's turn.\n";
        }
        cout << "Enter a spot to add a marker (1-9): ";
        cin >> number;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            number = -1;
        }

        if (number < 1 || number > 9)
        {
            cout << "Invalid spot! Choose a number between 1 and 9!\n";
            continue;
        }

        number--;
        if (spaces[number] == " ")
        {
            spaces[number] = player;
            break;
        }
        else
        {
            cout << "That spot is already occupied!\n";
        }
    } while (true);
}