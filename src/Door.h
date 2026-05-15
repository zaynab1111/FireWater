#pragma once
#include "Collidable.h"
#include "GameObject.h"
#include "Character.h"
#include <SFML/Graphics.hpp>

enum class DoorType{Red, Blue};

class Door : public GameObject, public Collidable{
  private:
    DoorType m_type;
    bool m_isOpen = false;
  public:
    
    Door(sf::Vector2f position, DoorType type, const std::string& texturePath = "");
    void render(sf::RenderWindow& window);
    DoorType getType() const;
    bool isOpen() const;
    void setOpen(bool value);
    void onCollision(Character& character)override;
    sf::FloatRect getGlobalBounds()const override;
};