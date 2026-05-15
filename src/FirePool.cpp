#include "FirePool.h"

FirePool::FirePool(sf::Vector2f position, sf::Vector2f size) : Hazard(position,"firepool.png", size, KillType::KillWater, sf::Color(255, 80, 0)){};
void FirePool::onCollision(Character& character){
  if(character.getNameAsEnum() == NameOption::WaterGirl){//kill watergirl
    character.setDead(true);
  }
};