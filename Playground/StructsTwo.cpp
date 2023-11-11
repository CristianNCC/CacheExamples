#include <climits>
#include <cstring>
#include "StructsTwo.h"

constexpr int STRUCT_ARRAY_TWO_SIZE = static_cast<int>(1e7);

sDataTwo* g_arrayStructs_two = nullptr;

void AllocAndRandomizeStructsTwo()
{
    g_arrayStructs_two = new sDataTwo[STRUCT_ARRAY_TWO_SIZE];
    for (int i = 0; i < STRUCT_ARRAY_TWO_SIZE; ++i)
    {
        int randNum = rand() % 10;
        g_arrayStructs_two[i].m_velocity = static_cast<double>(randNum);
        g_arrayStructs_two[i].m_strength = randNum;
        g_arrayStructs_two[i].m_health = randNum;
        strncpy(g_arrayStructs_two[i].m_loot, "Loot", strlen("Loot")+1);
    }
}

int FindMaxStrengthInStructArrayTwo()
{
    AllocAndRandomizeStructsTwo();
    TIMER_FROM_NOW;

    int max = INT_MIN;
    for (int i = 0; i < STRUCT_ARRAY_TWO_SIZE; i++)
    {
        max = std::max(g_arrayStructs_two[i].m_strength, max);
    }
    return max;
}
