#include "waterPool.h"
#include <iostream>
using namespace std;

WaterPool::WaterPool(sf::Vector2f position, sf::Vector2f size) : Hazard(position, "waterpool.png", size, KillType::KillFire, sf::Color(0, 0, 255)) {};

void WaterPool::onCollision(Character& charcater){
  if(charcater.getNameAsEnum() == NameOption::FireBoy){
    charcater.setDead(true);
    cout<<"character dead";
  }
};