#pragma once
#include "Entity.h"
#include "Collidable.h"
#include <SFML/Graphics.hpp>

class GameObject : public Entity{
  protected:
    sf::Texture m_texture;//the actual image of the object(Fire boy, Water girl, gems, platform, wagera)
    sf::Sprite m_sprite;//what holds that picture. it uses the picture(texture) and can be scaled, rotated, and positioned on the screen. the drawable object

  public:
    GameObject();
    GameObject(sf::Vector2f startpos, const std::string& texturePath = "");// takes the starting position of the game object (x and y) and the file path of the texture as parameters
    virtual void render(sf::RenderWindow& window)override;
    virtual void update(float deltaTime, std::vector<Collidable*>& collidables){};//changed this from pure virtual to virtual
};