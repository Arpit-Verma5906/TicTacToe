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

void score(int win, int tie, int loss) {
    cout << "Your current score is: " << win << " Wins, " << tie << " Ties and " << loss << " Losses!\n";
}

char checkWinner(char *spaces, char player, char computer)
{
    if (spaces[0] != ' ' && spaces[0] == spaces[1] && spaces[1] == spaces[2])
    {
        if(spaces[0] == player) {
            return 'P';
        } else {
            return 'C';
        }
    }
    else if (spaces[3] != ' ' && spaces[3] == spaces[4] && spaces[4] == spaces[5])
    {
        if(spaces[3] == player) {
            return 'P';
        } else {
            return 'C';
        }
    }
    else if (spaces[6] != ' ' && spaces[6] == spaces[7] && spaces[7] == spaces[8])
    {
        if(spaces[6] == player) {
            return 'P';
        } else {
            return 'C';
        }
    }

    else if (spaces[0] != ' ' && spaces[0] == spaces[3] && spaces[3] == spaces[6])
    {
        if(spaces[0] == player) {
            return 'P';
        } else {
            return 'C';
        }
    }
    else if (spaces[1] != ' ' && spaces[1] == spaces[4] && spaces[4] == spaces[7])
    {
        if(spaces[1] == player) {
            return 'P';
        } else {
            return 'C';
        }
    }
    else if (spaces[2] != ' ' && spaces[2] == spaces[5] && spaces[5] == spaces[8])
    {
        if(spaces[2] == player) {
            return 'P';
        } else {
            return 'C';
        }
    }

    else if (spaces[0] != ' ' && spaces[0] == spaces[4] && spaces[4] == spaces[8])
    {
        if(spaces[0] == player) {
            return 'P';
        } else {
            return 'C';
        }
    }
    else if (spaces[2] != ' ' && spaces[2] == spaces[4] && spaces[4] == spaces[6])
    {
        if(spaces[2] == player) {
            return 'P';
        } else {
            return 'C';
        }
    }

    else
    {
        return ' ';
    }
}

bool checkTie(char *spaces, int &tie)
{
    for (int i = 0; i < 9; i++)
    {
        if (spaces[i] == ' ')
        {
            return false;
        }
    }

    tie++;
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
    char choice;
    bool running = true;
    int win = 0;
    int tie = 0;
    int loss = 0;

    while (running)
    {
        clearBoard(spaces);

        int move1 = rand() % 2;

        if(move1 == 0) {
            move1 = rand() % 2;
            while(true) {
                playerMove(spaces, player);
                clearScreen();
                drawBoard(spaces);
                char result = checkWinner(spaces, player, computer);
                    if (result == 'P') { win++; cout << "YOU WIN!\n"; score(win, tie, loss); break; }
                    if (result == 'C') { loss++; cout << "YOU LOSE!\n"; score(win, tie, loss); break; }
                    if (checkTie(spaces, tie)) { score(win, tie, loss); break; }

                computerMove(spaces, computer);
                clearScreen();
                drawBoard(spaces);
                result = checkWinner(spaces, player, computer);
                    if (result == 'P') { win++; cout << "YOU WIN!\n"; score(win, tie, loss); break; }
                    if (result == 'C') { loss++; cout << "YOU LOSE!\n"; score(win, tie, loss); break; }
                    if (checkTie(spaces, tie)) { score(win, tie, loss); break; }
            }
        } else {
            move1 = rand() % 2;
            while(true) {
                computerMove(spaces, computer);
                clearScreen();
                drawBoard(spaces);
                char result = checkWinner(spaces, player, computer);
                    if (result == 'P') { win++; cout << "YOU WIN!\n"; score(win, tie, loss); break; }
                    if (result == 'C') { loss++; cout << "YOU LOSE!\n"; score(win, tie, loss); break; }
                    if (checkTie(spaces, tie)) { score(win, tie, loss); break; }
                
                playerMove(spaces, player);
                clearScreen();
                drawBoard(spaces);
                result = checkWinner(spaces, player, computer);
                    if (result == 'P') { win++; cout << "YOU WIN!\n"; score(win, tie, loss); break; }
                    if (result == 'C') { loss++; cout << "YOU LOSE!\n"; score(win, tie, loss); break; }
                    if (checkTie(spaces, tie)) { score(win, tie, loss); break; }
            }
        }

        cout << "Do you wish to continue playing? (Y/N): ";
        cin >> choice;
        if(choice != 'Y' && choice != 'y') {
            running = false;
        }
    }

    cout << "*******************\n";
    cout << "Thanks for playing!\n";

    return 0;
}