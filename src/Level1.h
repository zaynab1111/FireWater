#pragma once
#include "Levels.h"

class Level1 : public Levels{
public:
    Level1();
    int getLevelNumber() override;
    void load() override; // defines all level 1 platforms, pools, gems etc
};