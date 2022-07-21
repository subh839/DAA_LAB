#include <stdio.h>
#include <stdlib.h>
#define N 5

int isSafe(int board[N][N], int row, int col)
{
    int tempRow = row, tempCol = col;
    while (tempRow >= 0 && tempCol >= 0)
    {
        if (board[tempRow][tempCol] == 1)
            return 0;
        tempRow--;
        tempCol--;
    }
    tempRow = row;
    tempCol = col;
    while (tempCol >= 0)
    {
        if (board[tempRow][tempCol] == 1)
            return 0;
        tempCol--;
    }
    tempRow = row;
    tempCol = col;
    while (tempRow < N && tempCol >= 0)
    {
        if (board[tempRow][tempCol] == 1)
            return 0;
        tempRow++;
        tempCol--;
    }
    return 1;
}

int nQueens(int board[N][N], int col)
{
    int i, j;
    if (col >= N)
        return 1;

    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, i, col))
        {
            board[i][col] = 1;
            if (nQueens(board, col + 1))
                return 1;
            board[i][col] = 0;
        }
    }
    return 0;
}

int main()
{
    int board[N][N] = {0};
    int col = 0;
    int solutionExists = nQueens(board, col);
    if (solutionExists)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                printf("%d ", board[i][j]);
            printf("\n");
        }
    }
    else
        printf("No solution");

    return 0;
}