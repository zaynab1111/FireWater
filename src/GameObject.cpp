#include "GameObject.h"

GameObject::GameObject(sf::Vector2f startpos, const std::string& texturePath)//will remove this after mehdiya's code
  : Entity(startpos), m_sprite(m_texture) {
  //only load if a real path was given no initializer list crash
  if (!texturePath.empty()) {
    if(m_texture.loadFromFile(texturePath)){
      m_sprite.setTexture(m_texture);            // construct Sprite using that Texture
      m_sprite.setTextureRect(sf::IntRect({0, 0}, sf::Vector2i(m_texture.getSize())));
      m_hitbox = sf::FloatRect(startpos, m_sprite.getGlobalBounds().size);
    }
  }
}

//Explaining
//m_hitbox = sf::FloatRect(sf::Vector2f(x, y), sf::Vector2f(m_sprite.getGlobalBounds().size));

//m_sprite.getGlobalBounds() is a built in function that returns the space the sprite occupies on the screen
//sf::FloatRect has a .position() (the x,y coordinates) and .szie() (the width and height)
//m_sprite.getGlobalBounds().size just gets the width and height of the sprite
// sf::Vector2f(x, y) is where the hitbox starts. this is the same x,y that the character was created at
// sf::FloatRect takes two arguements, a position(top left corner) and a size

//so, m_hitbox = sf::FloatRect(sf::Vector2f(x, y), sf::Vector2f(m_sprite.getGlobalBounds().size)); sets the hitbox to a 
//rectangle that starts where the character starts and is exactly the same size as the sprite

//the calculation for teh hitbox is done automatically iss tarha

void GameObject::render(sf::RenderWindow & window){
  window.draw(m_sprite);
}