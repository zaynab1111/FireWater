#include "Door.h"

Door::Door(sf::Vector2f position, DoorType type, const std::string& texturePath) : GameObject(position, (type == DoorType::Red ? "redDoor.png" : "blueDoor.png")), m_type(type), m_isOpen(false){
  //.loadFromFile wala kaam gameobject k constructor mein hy
  // scale door to a good size
    float targetHeight = 120.f;
    float scale = targetHeight / m_texture.getSize().y;
    m_sprite.setScale({scale, scale});
    m_sprite.setPosition(position);

    float w = m_texture.getSize().x * scale;
    m_hitbox = sf::FloatRect(position, {w, targetHeight});
};


void Door::render(sf::RenderWindow& window) {
  window.draw(m_sprite);
}


DoorType Door::getType() const {
  return m_type;
}

bool Door::isOpen() const {
  return m_isOpen;
}

void Door::setOpen(bool value) {
  m_isOpen = value;
}

sf::FloatRect Door::getGlobalBounds()const{//returns the door's boundaries
  return m_hitbox;
};

void Door::onCollision(Character& character){
  if(m_type == DoorType::Blue && character.getNameAsEnum() == NameOption::WaterGirl || m_type == DoorType::Red && character.getNameAsEnum() == NameOption::FireBoy){
    m_isOpen = true;
  }
}