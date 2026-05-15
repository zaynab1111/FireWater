#pragma once
#include "GameObject.h"
#include "Collidable.h"
#include <SFML/Graphics.hpp>

enum class KillType{KillFire, KillWater, KillAll};

class Hazard : public GameObject, public Collidable{//no diamond problem since Collidable has no data menbers so there's nothing to duplicate. it just has pure virtual function definitions which every class that inherits from it has to implement
  //dont need the animation flag since we're not adding animations
  KillType m_killType;
  sf::RectangleShape m_hazshape;
  public:
    Hazard(sf::Vector2f position, const std::string& texturePath, sf::Vector2f size, KillType kills, sf::Color color);
    virtual void onCollision(Character& character)override = 0;//overrides Collidable's onCollision and is a pure vitual kyun k har pool apna decide kare ga k who it kills on collision
    void render(sf::RenderWindow& window);
    sf::FloatRect getGlobalBounds()const override;//returns the pool's boundaries
};