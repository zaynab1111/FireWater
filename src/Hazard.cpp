#include "Hazard.h"

//GameObject(position) passes position up the chain like Hazard -> GameObject -> Entity which runs Entity::Entity(startpos) and sets the logical position (m_position) that the game uses for physucs, collision math, and getPosition(). its used for collison detection
//m_hazshape.setPosition(position) sets the visual position of the rectangle that gets drawn on the screen
//these are the same thing for hazard. i know it doesnt make any sense kyun k both have the same value
//lekin we need to keep it this way now kyun k its just the way we've built the sysytem now ab it would take too much time and dimagh to clean it up. 
//abhi k liye just understand k both of these stay the same for things that dont move, like hazards and collectibles
Hazard::Hazard(sf::Vector2f position, const std::string& texturePath, sf::Vector2f size, KillType kills, sf::Color color) : GameObject(position, texturePath), m_killType(kills){
  m_hazshape.setSize(size);
  m_hazshape.setPosition(position);
  m_hazshape.setFillColor(color);
  
  // scale sprite to match pool size
  if (m_texture.getSize().x > 0){
    sf::Vector2u texSize = m_texture.getSize();
    m_sprite.setScale({size.x / texSize.x, size.y / texSize.y});
    m_sprite.setPosition(position);
  }
  
  //yahan pe i had the hitbox start a little bit above the platform taky pool and character ki collision detection ho saky
  // m_hitbox = sf::FloatRect(sf::Vector2f(position.x, position.y - 7.f), sf::Vector2f(size.x, size.y + 7.f));
  m_hitbox = sf::FloatRect(sf::Vector2f(position.x + 10.f, position.y+size.y - 20.f), sf::Vector2f(size.x - 20.f, 30.f));


};

void Hazard::render(sf::RenderWindow& window){
  // check if texture loaded successfully
  if (m_texture.getSize().x > 0)
    window.draw(m_sprite); // draw sprite if texture loaded
  else
    window.draw(m_hazshape); // fallback to colored rectangle
};

sf::FloatRect Hazard::getGlobalBounds()const{//returns the pool's boundaries
  return m_hitbox;
};