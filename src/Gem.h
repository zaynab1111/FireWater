#pragma once
#include"GameObject.h"
#include"Collidable.h"
#include <SFML/Graphics.hpp>

enum class GemType{Red, Blue};

class Gem : public GameObject, public Collidable{
  private:
    GemType m_type;
    bool m_collected = false;
  public:
    Gem(sf::Vector2f startPos, GemType type);
    GemType getType() const;
    void update(float fixedDelta);
    void onCollision(Character& character)override;
    sf::FloatRect getGlobalBounds()const override;
    void render(sf::RenderWindow& window) override;
};