#include <climits>
#include "Structs.h"

constexpr int STRUCT_ARRAY_SIZE = static_cast<int>(1e8);

sData* g_arrayStructs = nullptr;

void AllocAndRandomizeStructs()
{
    g_arrayStructs = new sData[STRUCT_ARRAY_SIZE];
    for (int i = 0; i < STRUCT_ARRAY_SIZE; ++i)
    {
        int randNum = rand() % 10;
        g_arrayStructs[i].m_velocity = static_cast<double>(randNum);
        g_arrayStructs[i].m_strength = randNum;
        g_arrayStructs[i].m_health = randNum;
    }
}

int FindMaxStrengthInStructArray()
{
    AllocAndRandomizeStructs();
    TIMER_FROM_NOW;

    int max = INT_MIN;
    for (int i = 0; i < STRUCT_ARRAY_SIZE; i++)
    {
        max = std::max(g_arrayStructs[i].m_strength, max);
    }
    return max;
}
