#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//This is a cross-platform function to clear the previous board as to not overwhelm the user with excess boards
// and making it easier to keep track of the actual game
// '#' is known a preprocessor directive which isn't actual c++ code, and is processed before the actual code
// This block of code essentially checks if the code is being compiled on windows, is yes run "cls" command
// else run "clear" command (used to clear the terminal on Linux and macOS)

void clearScreen() {

#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void drawBoard(char *spaces)
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

void playerMove(char *spaces, char player)
{
    int number;
    do
    {
        cout << "Enter a spot to add a marker (1-9): ";
        cin >> number;

        if(cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            number = -1;
        }

        if(number < 1 || number > 9) {
            cout << "Invalid spot! Choose a number between 1 and 9!\n";
            continue;
        }

        number--;
        if (spaces[number] == ' ')
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

void computerMove(char *spaces, char computer)
{
    int number;

    do
    {
        number = rand() % 9;
    } while (spaces[number] != ' ');

    spaces[number] = computer;
}

void clearBoard(char *spaces) {
    clearScreen();
    fill(spaces, spaces + 9, ' ');
    drawBoard(spaces);
}

bool checkWinner(char *spaces, char player, char computer)
{
    if (spaces[0] != ' ' && spaces[0] == spaces[1] && spaces[1] == spaces[2])
    {
        spaces[0] == player ? cout << "YOU WIN!\n" : cout << "YOU LOSE!\n";
    }
    else if (spaces[3] != ' ' && spaces[3] == spaces[4] && spaces[4] == spaces[5])
    {
        spaces[3] == player ? cout << "YOU WIN!\n" : cout << "YOU LOSE!\n";
    }
    else if (spaces[6] != ' ' && spaces[6] == spaces[7] && spaces[7] == spaces[8])
    {
        spaces[6] == player ? cout << "YOU WIN!\n" : cout << "YOU LOSE!\n";
    }

    else if (spaces[0] != ' ' && spaces[0] == spaces[3] && spaces[3] == spaces[6])
    {
        spaces[0] == player ? cout << "YOU WIN!\n" : cout << "YOU LOSE!\n";
    }
    else if (spaces[1] != ' ' && spaces[1] == spaces[4] && spaces[4] == spaces[7])
    {
        spaces[1] == player ? cout << "YOU WIN!\n" : cout << "YOU LOSE!\n";
    }
    else if (spaces[2] != ' ' && spaces[2] == spaces[5] && spaces[5] == spaces[8])
    {
        spaces[2] == player ? cout << "YOU WIN!\n" : cout << "YOU LOSE!\n";
    }

    else if (spaces[0] != ' ' && spaces[0] == spaces[4] && spaces[4] == spaces[8])
    {
        spaces[0] == player ? cout << "YOU WIN!\n" : cout << "YOU LOSE!\n";
    }
    else if (spaces[2] != ' ' && spaces[2] == spaces[4] && spaces[4] == spaces[6])
    {
        spaces[2] == player ? cout << "YOU WIN!\n" : cout << "YOU LOSE!\n";
    }

    else
    {
        return false;
    }

    return true;
}

bool checkTie(char *spaces)
{
    for (int i = 0; i < 9; i++)
    {
        if (spaces[i] == ' ')
        {
            return false;
        }
    }

    cout << "IT'S A TIE!\n";
    return true;
}

int main()
{
    srand(time(NULL));

    char spaces[9] = {
        ' ',
        ' ',
        ' ',
        ' ',
        ' ',
        ' ',
        ' ',
        ' ',
        ' ',
    };
    char player = 'X';
    char computer = 'O';
    bool running = true;
    char choice;

    while (running)
    {
        clearBoard(spaces);
        
        while(true) {
            playerMove(spaces, player);
            clearScreen();
            drawBoard(spaces);
            if (checkWinner(spaces, player, computer) || checkTie(spaces))
                break;

            computerMove(spaces, computer);
            clearScreen();
            drawBoard(spaces);
            if (checkWinner(spaces, player, computer) || checkTie(spaces))
                break;
        }

        cout << "Do you wish to continue playing? (Y/N): ";
        cin >> choice;
        if(choice != 'Y' || choice != 'y') {
            clearBoard(spaces);
            running = false;
        }
    }

    cout << "*******************\n";
    cout << "Thanks for playing!\n";

    return 0;
}