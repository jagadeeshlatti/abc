#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int n, count = 0;

bool isSafe(int **arr, int x, int y)
{
    int row, col;

    for (row = 0; row < x; row++)
    {
        if (arr[row][y] == 1)
        {
            return false;
        }
    }

    for (row = x - 1, col = y - 1; row >= 0 && col >= 0; row--, col--)
    {
        if (arr[row][col] == 1)
        {
            return false;
        }
    }
    for (row = x - 1, col = y + 1; row >= 0 && col < n; row--, col++)
    {
        if (arr[row][col] == 1)
        {
            return false;
        }
    }

    return true;
}

void printSolution(int **arr)
{
    printf("Solution %d:\n", ++count);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void nQueen(int **arr, int x)
{
    if (x >= n)
    {
        printSolution(arr);
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(arr, x, col))
        {
            arr[x][col] = 1;
            nQueen(arr, x + 1);
            arr[x][col] = 0;
        }
    }
}

int main(void)
{
    printf("Enter the size of board: ");
    scanf("%d", &n);

    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }

    nQueen(arr, 0);

    for (int i = 0; i < n; i++)
    {
        free(arr[i]);
    }
    free(arr);
}