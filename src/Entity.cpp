#include "Entity.h"

Entity::Entity(sf::Vector2f startpos) : m_position(startpos), m_active(true){}//sets position at x and y , start veloocity st 0 and sets active to true//(zaynab) i changed the parameters from x,y to startPos (this takes both x n y)(i will change them back to x,y later i had to do this for simplicity right now)

Entity::Entity(const Entity& other) : m_position(other.m_position), m_hitbox(other.m_hitbox),m_active(other.m_active){};//might never need this copy constructor, just a course requirement


sf::Vector2f Entity::getPosition()const{
  return m_position;
}


sf::FloatRect Entity::getHitbox()const{
  return m_hitbox;
}

bool Entity::isActive()const{
  return m_active;
}

void Entity::setPosition(sf::Vector2f pos){
  m_position = pos;
}



void Entity::setActive(bool act){
  m_active = act;
}

bool Entity::operator == (const Entity& other)const{
  return m_position == other.m_position && m_active == other.m_active;
}