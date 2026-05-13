#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer;

// Initialize board
void initializeBoard() {

    char ch = '1';

    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {

            board[i][j] = ch++;
        }
    }

    currentPlayer = 'X';
}

// Game title
void showTitle() {

    cout << "\n";
    cout << "=================================================\n";
    cout << "                 TIC TAC TOE GAME                \n";
    cout << "=================================================\n";
    cout << "                  PLAYER X vs O                  \n";
    cout << "=================================================\n";
}

// Instructions
void showInstructions() {

    cout << "\nHOW TO PLAY:\n";
    cout << "---------------------------------------------\n";
    cout << "1. Choose a number from 1 to 9.\n";
    cout << "2. The number represents the board position.\n";
    cout << "3. Player X starts the game.\n";
    cout << "4. First player to match 3 symbols wins.\n\n";

    cout << "BOARD POSITIONS:\n\n";

    cout << "     1 | 2 | 3\n";
    cout << "    ---|---|---\n";
    cout << "     4 | 5 | 6\n";
    cout << "    ---|---|---\n";
    cout << "     7 | 8 | 9\n\n";
}

// Display board
void displayBoard() {

    cout << "\nCURRENT BOARD:\n\n";

    for (int i = 0; i < 3; i++) {

        cout << "     ";

        for (int j = 0; j < 3; j++) {

            cout << board[i][j];

            if (j < 2)
                cout << " | ";
        }

        cout << "\n";

        if (i < 2)
            cout << "    ---|---|---\n";
    }

    cout << "\n";
}

// Check win
bool checkWin() {

    // Rows and columns
    for (int i = 0; i < 3; i++) {

        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2])
            return true;

        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i])
            return true;
    }

    // Diagonals
    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2])
        return true;

    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0])
        return true;

    return false;
}

// Check draw
bool checkDraw() {

    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {

            if (board[i][j] != 'X' &&
                board[i][j] != 'O')
                return false;
        }
    }

    return true;
}

// Make move
void makeMove() {

    int choice;

    cout << "Player " << currentPlayer
         << ", enter your move (1-9): ";

    cin >> choice;

    // Invalid number
    if (choice < 1 || choice > 9) {

        cout << "\nInvalid position! Please try again.\n";
        makeMove();
        return;
    }

    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    // Already occupied
    if (board[row][col] == 'X' ||
        board[row][col] == 'O') {

        cout << "\nPosition already occupied! Try another.\n";
        makeMove();
    }
    else {

        board[row][col] = currentPlayer;
    }
}

// Switch player
void switchPlayer() {

    if (currentPlayer == 'X')
        currentPlayer = 'O';
    else
        currentPlayer = 'X';
}

// Play game
void playGame() {

    initializeBoard();

    bool gameOver = false;

    showTitle();
    showInstructions();

    while (!gameOver) {

        displayBoard();

        makeMove();

        // Winner
        if (checkWin()) {

            displayBoard();

            cout << "=================================================\n";
            cout << "               PLAYER "
                 << currentPlayer
                 << " WINS THE GAME!               \n";
            cout << "=================================================\n";

            gameOver = true;
        }

        // Draw
        else if (checkDraw()) {

            displayBoard();

            cout << "=================================================\n";
            cout << "                    MATCH DRAW                   \n";
            cout << "=================================================\n";

            gameOver = true;
        }

        // Continue
        else {

            switchPlayer();

            cout << "Next Turn: Player "
                 << currentPlayer << "\n";
        }
    }
}

// Main function
int main() {

    char replay;

    do {

        playGame();

        cout << "\nDo you want to play again? (y/n): ";
        cin >> replay;

    } while (replay == 'y' || replay == 'Y');

    cout << "\n=================================================\n";
    cout << "              THANK YOU FOR PLAYING              \n";
    cout << "=================================================\n";

    return 0;
}
