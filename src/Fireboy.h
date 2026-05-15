#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Gem.h"
#include<list>

class Fireboy: public Character{
    private:
    public:
        Fireboy(sf::Vector2f startPos);
        void update(float deltaTime, std::vector<Collidable*>& collidables, std::list<Gem*>& allGems)override;
        void render(sf::RenderWindow& window)override;
}; 