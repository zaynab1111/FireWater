#include "GreenPool.h"

GreenPool::GreenPool(sf::Vector2f startPos, sf::Vector2f size) : Hazard(startPos, "greenpool.png",size, KillType::KillAll, sf::Color(0, 255, 0)) {};
void GreenPool::onCollision(Character& character) {
  if(character.getNameAsEnum() == NameOption::WaterGirl || character.getNameAsEnum() == NameOption::FireBoy){
    character.setDead(true);
  }
}