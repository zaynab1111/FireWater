#include "Character.h"

Character::Character(sf::Vector2f startPos, const std::string& texturePath) : GameObject(startPos, texturePath), m_velocity(0.f,0.f), m_isOnGround(false){
    sf::Vector2u texSize = m_texture.getSize();
    
    float targetHeight = 170.f;
    float scale = targetHeight/ texSize.y;
    m_sprite.setScale({scale, scale});
    m_sprite.setPosition(startPos);
    float hitboxHeight = 100.f;
    float offsetY = 0.f;
    m_shape.setSize({60.f, hitboxHeight});
    m_shape.setPosition({startPos.x + 20.f, startPos.y +30.f});

    m_shape.setFillColor(sf::Color::Transparent);
    m_shape.setOutlineColor(sf::Color::Transparent);
    m_shape.setOutlineThickness(2.f);
}

Character::Character(const Character& other) : GameObject(other.m_position), m_velocity(other.m_velocity), m_shape(other.m_shape), m_isOnGround(other.m_isOnGround), m_name(other.m_name), m_numGems(other.m_numGems), m_isDead(other.m_isDead), m_jumpKeyReleased(other.m_jumpKeyReleased){}

sf::Vector2f Character::getPosition() const{
    return m_position;
}

void Character::collectGem(){
    m_numGems++;
}

bool Character::operator > (const Character& other) const{
    return m_numGems > other.m_numGems;
}

bool Character::operator == (const Character& other) const{
    return m_numGems == other.m_numGems;
}

std::string Character::getNameAsString()const{
    if(m_name==NameOption::FireBoy){
        return "Fireboy";
    }else{
        return "Watergirl";
    }
}

NameOption Character::getNameAsEnum()const{
    return m_name;
}

int Character::getNumGems()const{
    return m_numGems;
}

sf::RectangleShape& Character::getShape(){
    return m_shape;
}

sf::Vector2f Character::getVelocity()const{
    return m_velocity;
}

void Character::setVelocity(sf::Vector2f vel){
    m_velocity = vel;
}

void Character::setOnGround(bool value){
    m_isOnGround = value;
}

void Character::setDead(bool value){
    m_isDead = value;
}

bool Character::dead()const{
    return m_isDead;
}
void Character::respawn(sf::Vector2f startPos){
    m_position = startPos;
    m_velocity = sf::Vector2f(0.f,0.f);
    m_isOnGround = false;
    m_isDead = false;
    m_shape.setPosition({startPos.x + 80.f, startPos.y + 40.f});
    m_sprite.setPosition(startPos);
}