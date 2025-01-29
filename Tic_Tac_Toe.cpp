#include <iostream>

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char currentPlayer = 'X';

void drawBoard()
{
    std::cout << "Tic-Tac-Toe\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << board[i][j] << " ";
        }
        std::cout << "\n";
    }
}

bool checkWin()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true; // Rows
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return true; // Columns
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true; // Diagonal
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true; // Diagonal
    return false;
}

bool checkDraw()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
        }
    }
    return true;
}

void switchPlayer()
{
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void makeMove(int cell)
{
    int row = (cell - 1) / 3;
    int col = (cell - 1) % 3;
    if (board[row][col] != 'X' && board[row][col] != 'O')
    {
        board[row][col] = currentPlayer;
    }
    else
    {
        std::cout << "Cell already taken! Try again.\n";
        return;
    }
    if (checkWin())
    {
        drawBoard();
        std::cout << "Player " << currentPlayer << " wins!\n";
        exit(0);
    }
    else if (checkDraw())
    {
        drawBoard();
        std::cout << "It's a draw!\n";
        exit(0);
    }
    switchPlayer();
}

int main()
{
    int cell;
    while (true)
    {
        drawBoard();
        std::cout << "Player " << currentPlayer << ", enter a cell number: ";
        std::cin >> cell;
        if (cell < 1 || cell > 9)
        {
            std::cout << "Invalid cell! Try again.\n";
            continue;
        }
        makeMove(cell);
    }
    return 0;
}