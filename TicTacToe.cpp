#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//This is a cross-platform function to clear the previous board as to not overwhelm the user with excess boards
// and making it easier to keep track of the actual game
// '#' is known a preprocessor directive which isn't actual c++ code, and is processed before the actual code
// This block of code essentially checks if the code is being compiled on windows, is yes run "cls" command
// else run "clear" command (used to clear the terminal on Linux and macOS)

void clearScreen();

void drawBoard(string *spaces);

void playerMove(string *spaces, string player);

void playerMoveM(string *spaces, string player, int firstMove);

void computerMoveEasy(string *spaces, string computer);

void computerMoveHard(string *spaces, string computer, string player);

void clearBoard(string *spaces);

void score(int win, int tie, int loss);

void scoreM(int win, int tie, int loss);

char checkWinnerHard(string *spaces, string player, string computer);

char checkWinner(string *spaces, string player, string computer);

bool checkTie(string *spaces, int &tie);

bool handleResult(string *spaces, string player, string computer, int &win, int &tie, int &loss);

bool handleResultM(string *spaces, string player, string player2, int &win, int &tie, int &loss);

void highlightMarker(string *spaces, int a, int b, int c);

void drawWinningBoard(string *spaces);

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
    do {
    cout << '\n';
    cout << "Select The Number Of Players:\n";
    cout << "1: Single Player\n";
    cout << "2: Multi-Player\n";
    cout << "Enter Your Choice: ";
    cin >> gameMode;
    } while (gameMode != 1 && gameMode != 2);

    if(gameMode == 1) {

        int difficulty;
        do {
            cout << "\nSelect the difficulty:\n";
            cout << "1: Easy Difficulty\n";
            cout << "2: Hard Difficulty\n";
            cout << "3: Impossible Difficulty\n";
            cin >> difficulty;
        } while (difficulty != 1 && difficulty != 2 && difficulty != 3);

        cout << "Choose Your Marker (X/O): ";
        cin >> player;

        do {
            if(player == "x" || player == "X") {
                player = "X";
            } else if(player == "o" || player == "O") {
                player = "O";
            } else {
                player = " ";
                cout << "Choose Your Marker Only From (X/O): ";
                cin >> player;
            }
        } while (player != "X" && player != "O");

        if(player == "X") {
            computer = "O";
        } else {
            computer = "X";
        }

        while (running)
        {
            
            clearScreen();
            clearBoard(spaces);
            drawBoard(spaces);

            int firstMove = rand() % 2;

            if(firstMove == 0) {
                while(true) {
                    playerMove(spaces, player);
                    clearScreen();
                    drawBoard(spaces);
                    if(handleResult(spaces, player, computer, win, tie, loss)) break;

                    if(difficulty == 1) {
                        computerMoveEasy(spaces, computer);
                    } else if(difficulty == 2) {
                        computerMoveHard(spaces, computer, player);
                    } else {
                        
                    }
                    clearScreen();
                    drawBoard(spaces);
                    if(handleResult(spaces, player, computer, win, tie, loss)) break;
                }
            } else {
                while(true) {
                    if(difficulty == 1) {
                        computerMoveEasy(spaces, computer);
                    } else if(difficulty == 2) {
                        computerMoveHard(spaces, computer, player);
                    } else {

                    }
                    clearScreen();
                    drawBoard(spaces);
                    if(handleResult(spaces, player, computer, win, tie, loss)) break;
                    
                    playerMove(spaces, player);
                    clearScreen();
                    drawBoard(spaces);
                    if(handleResult(spaces, player, computer, win, tie, loss)) break;
                }
            }

            cout << "Do you wish to continue playing? (Y/N): ";
            cin >> choice;
            if(choice != 'Y' && choice != 'y') {
                running = false;
            }
        }
    } else if(gameMode == 2) {
        cout << "Choose a marker for Player1 (X/O): ";
        cin >> player;

        do {
            if(player == "x" || player == "X") {
                player = "X";
            } else if(player == "o" || player == "O") {
                player = "O";
            } else {
                player = " ";
                cout << "Choose Your Marker Only From (X/O): ";
                cin >> player;
            }
        } while (player != "X" && player != "O");
        player == "X" ? player2 = "O" : player2 = "X";

        cout << "Marker for Player2 is: " << player2;
        
        while (running)
        {
            if(cnt > 1) {
                clearScreen();
            }
            clearBoard(spaces);
            drawBoard(spaces);

            int firstMove = rand() % 2;

            if(firstMove == 0) {
                cout << "Player1 gets the first move!\n";
                while(true) {
                    playerMoveM(spaces, player, firstMove);
                    firstMove++;
                    clearScreen();
                    drawBoard(spaces);
                    if(handleResultM(spaces, player, player2, win, tie, loss)) break;

                    playerMoveM(spaces, player2, firstMove);
                    firstMove++;
                    clearScreen();
                    drawBoard(spaces);
                    if(handleResultM(spaces, player, player2, win, tie, loss)) break;
                }
            } else {
                cout << "Player2 gets the first move!\n";
                while(true) {
                    playerMoveM(spaces, player2, firstMove);
                    firstMove++;
                    clearScreen();
                    drawBoard(spaces);
                    if(handleResultM(spaces, player, player2, win, tie, loss)) break;
                    
                    playerMoveM(spaces, player, firstMove);
                    firstMove++;
                    clearScreen();
                    drawBoard(spaces);
                    if(handleResultM(spaces, player, player2, win, tie, loss)) break;
                }
            }

            cout << "Do you wish to continue playing? (Y/N): ";
            cin >> choice;
            if(choice != 'Y' && choice != 'y') {
                running = false;
            }

            cnt++;
        }

    } else {
        cout << "Invalid Choice! Please Enter Either 1 or 2!\n";
    }

    cout << "*******************\n";
    cout << "Thanks for playing!\n";

    return 0;
}

void clearScreen() {

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

void clearBoard(string *spaces) {
    fill(spaces, spaces + 9, " ");
}

void playerMove(string *spaces, string player)
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

        int spaceIndex = number--;
        if (spaces[spaceIndex] == " ")
        {
            spaces[spaceIndex] = player;
            break;
        }
        else
        {
            cout << "That spot is already occupied!\n";
        }

    } while (true);
}

void playerMoveM(string *spaces, string player, int firstMove) {

    int number;
    do
    {
        if(firstMove % 2 == 0) {
            cout << "It is Player1's turn.\n";
        } else {
            cout << "It is Player2's turn.\n";
        }
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

void computerMoveEasy(string *spaces, string computer)
{
    int number;

    do
    {
        number = rand() % 9;
    } while (spaces[number] != " ");

    spaces[number] = computer;
}

void computerMoveHard(string *spaces, string computer, string player) {

    for (int i = 0; i < 9; i++) {
        if (spaces[i] == " ") {
            spaces[i] = computer;
            if (checkWinnerHard(spaces, player, computer) == 'C') {
                return;
            }
            spaces[i] = " ";
        }
    }

    for(int i = 0; i < 9; i++) {
        if(spaces[i] == " ") {
            spaces[i] = player;
            if(checkWinnerHard(spaces, player, computer) == 'P'){
                spaces[i] = computer;
                return;
            }
            spaces[i] = " ";
        }
    }

    computerMoveEasy(spaces, computer);
}

char checkWinnerHard(string *spaces, string player, string computer)
{
    if (spaces[0] != " " && spaces[0] == spaces[1] && spaces[1] == spaces[2])
    {   
        if(spaces[0] == player) {
            return 'P';
        } else {
            return 'C';
        }
    }
    else if (spaces[3] != " " && spaces[3] == spaces[4] && spaces[4] == spaces[5])
    {
        if(spaces[3] == player) {
            return 'P';
        } else {
            return 'C';
        }
    }
    else if (spaces[6] != " " && spaces[6] == spaces[7] && spaces[7] == spaces[8])
    {
        if(spaces[6] == player) {
            return 'P';
        } else {
            return 'C';
        }
    }

    else if (spaces[0] != " " && spaces[0] == spaces[3] && spaces[3] == spaces[6])
    {
        if(spaces[0] == player) {
            return 'P';
        } else {
            return 'C';
        }
    }
    else if (spaces[1] != " " && spaces[1] == spaces[4] && spaces[4] == spaces[7])
    {
        if(spaces[1] == player) {
            return 'P';
        } else {
            return 'C';
        }
    }
    else if (spaces[2] != " " && spaces[2] == spaces[5] && spaces[5] == spaces[8])
    {
        if(spaces[2] == player) {
            return 'P';
        } else {
            return 'C';
        }
    }

    else if (spaces[0] != " " && spaces[0] == spaces[4] && spaces[4] == spaces[8])
    {
        if(spaces[0] == player) {
            return 'P';
        } else {
            return 'C';
        }
    }
    else if (spaces[2] != " " && spaces[2] == spaces[4] && spaces[4] == spaces[6])
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

char checkWinner(string *spaces, string player, string computer)
{
    if (spaces[0] != " " && spaces[0] == spaces[1] && spaces[1] == spaces[2])
    {   
        if(spaces[0] == player) {
            highlightMarker(spaces, 0, 1, 2);
            return 'P';
        } else {
            highlightMarker(spaces, 0, 1, 2);
            return 'C';
        }
    }
    else if (spaces[3] != " " && spaces[3] == spaces[4] && spaces[4] == spaces[5])
    {
        if(spaces[3] == player) {
            highlightMarker(spaces, 3, 4, 5);
            return 'P';
        } else {
            highlightMarker(spaces, 3, 4, 5);
            return 'C';
        }
    }
    else if (spaces[6] != " " && spaces[6] == spaces[7] && spaces[7] == spaces[8])
    {
        if(spaces[6] == player) {
            highlightMarker(spaces, 6, 7, 8);
            return 'P';
        } else {
            highlightMarker(spaces, 6, 7, 8);
            return 'C';
        }
    }

    else if (spaces[0] != " " && spaces[0] == spaces[3] && spaces[3] == spaces[6])
    {
        if(spaces[0] == player) {
            highlightMarker(spaces, 0, 3, 6);
            return 'P';
        } else {
            highlightMarker(spaces, 0, 3, 6);
            return 'C';
        }
    }
    else if (spaces[1] != " " && spaces[1] == spaces[4] && spaces[4] == spaces[7])
    {
        if(spaces[1] == player) {
            highlightMarker(spaces, 1, 4, 7);
            return 'P';
        } else {
            highlightMarker(spaces, 1, 4, 7);
            return 'C';
        }
    }
    else if (spaces[2] != " " && spaces[2] == spaces[5] && spaces[5] == spaces[8])
    {
        if(spaces[2] == player) {
            highlightMarker(spaces, 2, 5, 8);
            return 'P';
        } else {
            highlightMarker(spaces, 2, 5, 8);
            return 'C';
        }
    }

    else if (spaces[0] != " " && spaces[0] == spaces[4] && spaces[4] == spaces[8])
    {
        if(spaces[0] == player) {
            highlightMarker(spaces, 0, 4, 8);
            return 'P';
        } else {
            highlightMarker(spaces, 0, 4, 8);
            return 'C';
        }
    }
    else if (spaces[2] != " " && spaces[2] == spaces[4] && spaces[4] == spaces[6])
    {
        if(spaces[2] == player) {
            highlightMarker(spaces, 2, 4, 6);
            return 'P';
        } else {
            highlightMarker(spaces, 2, 4, 6);
            return 'C';
        }
    }

    else
    {
        return ' ';
    }
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

void score(int win, int tie, int loss) {
    cout << "Your current score is: " << win << " Wins, " << tie << " Ties and " << loss << " Losses!\n";
}

void scoreM(int win, int tie, int loss) {
    cout << "Current Score is: Player1: " << win << ", Player2: " << loss << " and Ties: " << tie <<'\n';  
}

bool handleResult(string *spaces, string player, string computer, int &win, int &tie, int &loss) {
    char result = checkWinner(spaces, player, computer);
        if(result == 'P') {win++; cout << "You Win!\n"; score(win, tie, loss); return true; }
        if(result == 'C') {loss++; cout << "You Lose!\n"; score(win, tie, loss); return true; }
        if(checkTie(spaces, tie)) {score(win, tie, loss); return true; }
    return false;
}

bool handleResultM(string *spaces, string player, string player2, int &win, int &tie, int &loss) {
    char result = checkWinner(spaces, player, player2);
        if(result == 'P') {win++; cout << "Player1 Wins The Match!\n"; scoreM(win, tie, loss); return true; }
        if(result == 'C') {loss++; cout << "Player2 Wins The Match!\n"; scoreM(win, tie, loss); return true; }
        if(checkTie(spaces, tie)) {scoreM(win, tie, loss); return true; }
    return false;
}

void highlightMarker(string *spaces, int a, int b, int c) {
    for(int i = 0; i < 9; i++) {
        if(i == a || i == b || i == c) {
            spaces[i] = "[" + spaces[i] + "]";
        } else {
            spaces[i] = " " + spaces[i] + " ";
        }
    }
    drawWinningBoard(spaces);
    clearBoard(spaces);
}

void drawWinningBoard(string *spaces) {

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