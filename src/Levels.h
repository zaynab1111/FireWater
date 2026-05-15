#pragma once
#include "SFML/Graphics.hpp"
#include "Platform.h"
#include "FirePool.h"
#include "WaterPool.h"
#include "GreenPool.h"
#include "Gem.h"
#include "Door.h"
#include "GameEngine.h"
#include <vector>
#include <list>
class Levels{
    friend class GameEngine;
protected:
    std::vector<Platform> m_platforms;
    std::vector<FirePool*> m_firePools;
    std::vector<WaterPool*> m_waterPools;
    std::vector<GreenPool*> m_greenPools;
    std::list<Gem*> m_gems;

    Door* m_redDoor=nullptr;
    Door* m_blueDoor=nullptr;

  

    sf::Vector2f m_fireboyStart;
    sf::Vector2f m_watergirlStart;
public:
    virtual int getLevelNumber()=0;
    virtual void load() = 0;
    virtual ~Levels(); // virtual destructor to clean up pools and gems
};