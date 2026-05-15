#pragma once
#include "Hazard.h"
#include "Character.h"

class FirePool : public Hazard{
  public:
    FirePool(sf::Vector2f position, sf::Vector2f size);
    void onCollision(Character& character) override;
    
};