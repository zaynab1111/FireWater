#pragma once
#include "Hazard.h"
#include "Character.h"
#include "SFML/Graphics.hpp"

class WaterPool : public Hazard{
  public:
    WaterPool(sf::Vector2f position, sf::Vector2f size); 
    void onCollision(Character& character)override;
};