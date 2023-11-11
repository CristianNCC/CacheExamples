#pragma once

#include "Timer.h"

constexpr int MATRIX_SIZE = 2000;

int** g_matrix1 = nullptr;
int** g_matrix2 = nullptr;
int** g_result = nullptr;

void RandomizeMatrix(int** matrix)
{
    for (int i = 0; i < MATRIX_SIZE; ++i)
    {
        for (int j = 0; j < MATRIX_SIZE; ++j)
        {
            matrix[i][j] = rand() % 10;
        }
    }
}

int** AllocMatrix()
{
    int rows = MATRIX_SIZE, cols = MATRIX_SIZE;

    int** matrix = new int* [rows];
    for (int i = 0; i < rows; ++i)
    {
        matrix[i] = new int[cols];
    }

    RandomizeMatrix(matrix);

    return matrix;
}

void AllocMatrices()
{
    g_matrix1 = AllocMatrix();
    g_matrix2 = AllocMatrix();
    g_result = AllocMatrix();
}

void MultiplyMatrices()
{
    int i, j, k = 0;
    for (i = 0; i < MATRIX_SIZE; i++)
    {
        for (j = 0; j < MATRIX_SIZE; j++)
        {
            g_result[i][j] = 0;
            for (k = 0; k < MATRIX_SIZE; k++)
            {
                g_result[i][j] += g_matrix1[i][k] *
                    g_matrix2[k][j];
            }
        }
    }
}

void TestMultiply()
{
    AllocMatrices();
    TIMER_FROM_NOW;
    MultiplyMatrices();
}