#pragma once
#include <SFML/Graphics.hpp>
#include "Collidable.h"

class Platform : public Collidable{
    private:
        sf::RectangleShape m_shape;
    public:
        Platform(sf::Vector2f position, sf::Vector2f size);
        void render(sf::RenderWindow& window);
        sf::FloatRect getGlobalBounds()const override;//returns the platform's boundaries
        void onCollision(Character& character) override;
};