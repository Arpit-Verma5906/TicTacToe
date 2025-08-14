#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/**
 * Function declarations for the TicTacToe game
 */

/**
 * Cross-platform function to clear the terminal screen
 * Uses "cls" command on Windows and "clear" command on Unix-based systems
 */
void clearScreen();

/**
 * Displays the current state of the game board
 * @param spaces Array containing the board state
 */
void drawBoard(string *spaces);

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

/**
 * Makes a random move for the computer (Easy difficulty)
 * @param spaces Array containing the board state
 * @param computer Computer's marker (X or O)
 */
void computerMoveEasy(string *spaces, string computer);

/**
 * Makes a strategic move for the computer (Hard difficulty)
 * Blocks player's winning moves and takes winning opportunities
 * @param spaces Array containing the board state
 * @param computer Computer's marker (X or O)
 * @param player Player's marker (X or O)
 */
void computerMoveHard(string *spaces, string computer, string player);

/**
 * Makes an optimal move using the minimax algorithm (Impossible difficulty)
 * @param spaces Array containing the board state
 * @param computer Computer's marker (X or O)
 * @param player Player's marker (X or O)
 * @return The optimal position (0-8) for the computer's move
 */
int computerMoveImpossible(string *spaces, string computer, string player);

/**
 * Implements the minimax algorithm for finding the optimal move
 * @param spaces Array containing the board state
 * @param depth Current depth in the game tree
 * @param isMaximizing True if maximizing player's turn, false otherwise
 * @param player Player's marker (X or O)
 * @param computer Computer's marker (X or O)
 * @return The score for the current board position
 */
int miniMax(string *spacees, int depth, bool isMaximizing, string player, string computer);

/**
 * Resets the game board by filling all spaces with empty strings
 * @param spaces Array containing the board state
 */
void clearBoard(string *spaces);

/**
 * Displays the current score in single player mode
 * @param win Number of player wins
 * @param tie Number of ties
 * @param loss Number of player losses
 */
void score(int win, int tie, int loss);

/**
 * Displays the current score in multiplayer mode
 * @param win Player 1's wins
 * @param tie Number of ties
 * @param loss Player 2's wins
 */
void scoreM(int win, int tie, int loss);

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
 * Evaluates the current board position for the minimax algorithm
 * @param spaces Array containing the board state
 * @param player Player's marker (X or O)
 * @param computer Computer's marker (X or O)
 * @return 10 for computer win, -10 for player win, 0 for no winner
 */
int evaluatePosition(string *spaces, string player, string computer);

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

/**
 * Highlights the winning combination of markers on the board
 * @param spaces Array containing the board state
 * @param a First position to highlight
 * @param b Second position to highlight
 * @param c Third position to highlight
 */
void highlightMarker(string *spaces, int a, int b, int c);

/**
 * Displays the game board with highlighted winning markers
 * @param spaces Array containing the board state with highlighted markers
 */
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

void clearBoard(string *spaces)
{
    fill(spaces, spaces + 9, " ");
}

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

int evaluatePosition(string *spaces, string player, string computer)
{
    char winner = checkWinnerHard(spaces, player, computer);
    if (winner == 'C')
        return 10;
    if (winner == 'P')
        return -10;
    return 0;
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

void score(int win, int tie, int loss)
{
    cout << "Your current score is: " << win << " Wins, " << tie << " Ties and " << loss << " Losses!\n";
}

void scoreM(int win, int tie, int loss)
{
    cout << "Current Score is: Player1: " << win << ", Player2: " << loss << " and Ties: " << tie << '\n';
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