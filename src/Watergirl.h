#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"
#include <list>
#include "Gem.h"

class Watergirl: public Character{
    public:
        Watergirl(sf::Vector2f startPos);
        void update(float deltaTime, std::vector<Collidable*>& collidables, std::list<Gem*>& allGems) override;
        void onCollision(Entity* other)override; //will work on this once the work on collision detection is done
        void render(sf::RenderWindow& window) override ;
};