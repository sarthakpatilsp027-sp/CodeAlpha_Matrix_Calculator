#include <stdio.h>

#define MAX 10

void inputMatrix(int mat[MAX][MAX], int rows, int cols, char name)
{
    printf("Enter elements of Matrix %c:\n", name);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
        {
            printf("[%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
}

void displayMatrix(int mat[MAX][MAX], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            printf("%4d ", mat[i][j]);
        printf("\n");
    }
}

void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[i][j] = A[i][j] + B[i][j];
}

void multiplyMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rowsA, int colsA, int colsB)
{
    for (int i = 0; i < rowsA; i++)
        for (int j = 0; j < colsB; j++)
            result[i][j] = 0;

    for (int i = 0; i < rowsA; i++)
        for (int j = 0; j < colsB; j++)
            for (int k = 0; k < colsA; k++)
                result[i][j] += A[i][k] * B[k][j];
}

void transposeMatrix(int mat[MAX][MAX], int result[MAX][MAX], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[j][i] = mat[i][j];
}

int main()
{
    int A[MAX][MAX], B[MAX][MAX], result[MAX][MAX];
    int rows, cols, rowsA, colsA, rowsB, colsB;

    // --- Matrix Addition ---
    printf("=== Matrix Addition ===\n");
    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &cols);
    inputMatrix(A, rows, cols, 'A');
    inputMatrix(B, rows, cols, 'B');
    addMatrices(A, B, result, rows, cols);
    printf("\nMatrix A:\n");
    displayMatrix(A, rows, cols);
    printf("Matrix B:\n");
    displayMatrix(B, rows, cols);
    printf("A + B:\n");
    displayMatrix(result, rows, cols);

    // --- Matrix Multiplication ---
    printf("\n=== Matrix Multiplication ===\n");
    printf("Enter rows and cols of A: ");
    scanf("%d %d", &rowsA, &colsA);
    printf("Enter rows and cols of B: ");
    scanf("%d %d", &rowsB, &colsB);
    if (colsA != rowsB)
    {
        printf("Error: Columns of A must equal rows of B!\n");
    }
    else
    {
        inputMatrix(A, rowsA, colsA, 'A');
        inputMatrix(B, rowsB, colsB, 'B');
        multiplyMatrices(A, B, result, rowsA, colsA, colsB);
        printf("\nMatrix A:\n");
        displayMatrix(A, rowsA, colsA);
        printf("Matrix B:\n");
        displayMatrix(B, rowsB, colsB);
        printf("A x B:\n");
        displayMatrix(result, rowsA, colsB);
    }

    // --- Matrix Transpose ---
    printf("\n=== Matrix Transpose ===\n");
    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &cols);
    inputMatrix(A, rows, cols, 'A');
    transposeMatrix(A, result, rows, cols);
    printf("\nMatrix A:\n");
    displayMatrix(A, rows, cols);
    printf("Transpose of A:\n");
    displayMatrix(result, cols, rows);

    return 0;
}