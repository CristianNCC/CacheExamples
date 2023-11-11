#pragma once

#include "Timer.h"

constexpr int ARRAY_SIZE = static_cast<int>(5e8);

int* g_array = nullptr;

void AllocAndRandomizeArray()
{
    g_array = new int[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        g_array[i] = rand() % 10;
    }
}

int FindMin()
{
    int min = INT_MAX;
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        min = std::min(g_array[i], min);
    }
    return min;
}

int FindMax()
{
    int max = INT_MIN;
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        max = std::max(g_array[i], max);
    }
    return max;
}

void TestFindMinAndMax()
{
    AllocAndRandomizeArray();

    TIMER_FROM_NOW;
    int min = FindMin();
    int max = FindMax();
}
