#include "Gem.h"
#include "Character.h"

Gem::Gem(sf::Vector2f startPos, GemType type): GameObject(startPos, (type==GemType::Red? "red-gem.png": "blue-gem.png")), m_type(type){
  float targetHeight = 40.f;
  float scale = targetHeight / m_texture.getSize().y;
  m_sprite.setScale({scale, scale});
  m_sprite.setPosition(startPos);
  // update hitbox to match new size
  m_hitbox = sf::FloatRect(startPos, {m_texture.getSize().x * scale, targetHeight});   
}

void Gem::update(float fixedDelta){
  // static object - no movement or logic needed
  // to avoid sir questioning us on why we have an update here at all, we could tell him we planned to work on floating gems.
}

GemType Gem::getType() const{
  return m_type;
}



void Gem::onCollision(Character& character){
  character.collectGem();

  // if (m_collected) return; // already collected, ignore

  //   // only fireboy can collect red gems, only watergirl can collect blue gems
  //   if (m_type == GemType::Red && character.getNameAsEnum() == NameOption::FireBoy)
  //   {
  //       character.collectGem();
  //       m_collected = true;
  //   }
  //   else if (m_type == GemType::Blue && character.getNameAsEnum() == NameOption::WaterGirl)
  //   {
  //       character.collectGem();
  //       m_collected = true;
  //   }
}

void Gem::render(sf::RenderWindow& window){
  if (!m_collected)
    window.draw(m_sprite);
}

sf::FloatRect Gem::getGlobalBounds()const{//returns the pool's boundaries
  return m_hitbox;
};

