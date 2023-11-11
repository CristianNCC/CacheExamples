#pragma once

#include "Timer.h"

struct sData
{
    int     m_strength = 0;
    double  m_velocity = 0.f;
    int     m_health = 0;
};

void AllocAndRandomizeStructs();
int FindMaxStrengthInStructArray();