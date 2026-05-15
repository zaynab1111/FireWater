#pragma once
#include "Collidable.h"
#include <SFML/Graphics.hpp>

class Entity{
  protected:
    sf::Vector2f m_position;
    sf::FloatRect m_hitbox;
    bool m_active;
  
  public:
    Entity(sf:: Vector2f startpos); //sets position at x and y , start veloocity st 0 and sets active to true
    
    Entity(const Entity& other);
    virtual ~Entity()=default; //virtual default destructor
    virtual void update(float deltaTime, std::vector<Collidable*>& collidables) = 0; //called every single frame of the game to move the game forward in time
    virtual void render(sf::RenderWindow& window) = 0; //called every frame of the game to draw the entity on the screen
    virtual void onCollision(Entity* other){}//are we not using this anymore?
    
    sf::Vector2f getPosition()const;
    sf::FloatRect getHitbox()const;
    
    bool isActive()const;
    bool operator == (const Entity& other)const;
    
    void setPosition(sf::Vector2f pos);
    void setActive(bool act);
};