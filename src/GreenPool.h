#pragma once
#include "Character.h"
#include "Hazard.h"
#include "SFML/Graphics.hpp"

class GreenPool : public Hazard{
  public:
    GreenPool(sf::Vector2f startPos, sf::Vector2f size);
    void onCollision(Character& character) override;
};