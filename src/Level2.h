#pragma once
#include "Levels.h"

class Level2 : public Levels{
public:
    Level2();
    int getLevelNumber();
    void load() override; // defines all level 1 platforms, pools, gems etc
};