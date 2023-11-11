#pragma once

#include "Timer.h"

struct sDataTwo
{
    double  m_velocity = 0.f;
    int     m_strength = 0;
    int     m_health = 0;
    char    m_loot[100] = "";
};

void AllocAndRandomizeStructsTwo();
int FindMaxStrengthInStructArrayTwo();