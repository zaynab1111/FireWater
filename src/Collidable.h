#pragma once
#include <SFML/Graphics.hpp>

class Character;

class Collidable{
    public:
    virtual sf::FloatRect getGlobalBounds() const=0;
    virtual void onCollision(Character& character)=0;
    virtual ~Collidable() = default;
};