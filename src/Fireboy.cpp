#include "Fireboy.h"

Fireboy::Fireboy(sf::Vector2f startPos): Character(startPos, "Fireboy.png"){
    // m_shape.setFillColor(sf::Color(255, 0, 0));
    m_name = NameOption::FireBoy;
}

void Fireboy::update(float deltaTime, std::vector<Collidable*>& collidables, std::list<Gem*>& allGems){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)){
        m_velocity.x = 200.f;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)){
        m_velocity.x = -200.f;
    } else{
        m_velocity.x = 0.f;
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && m_isOnGround && m_jumpKeyReleased){
        m_velocity.y = -600.f;
        m_isOnGround = false;
        m_jumpKeyReleased = false;
    }
    
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)){
        m_jumpKeyReleased=true;
    }

    m_velocity.y+=m_gravity*deltaTime;
    m_position += m_velocity * deltaTime;
    //clamp to screen edges(to prevent dono from going off the screen)
    //left edge
    if (m_position.x + 80.f < 0.f){
        m_position.x = -80.f;
    }
    //right edge
    if (m_position.x + 80.f + 60.f > 1920.f){
        m_position.x = 1920.f - 80.f - 60.f;
    }
    //top edge
    if (m_position.y + 40.f < 0.f){
        m_position.y = -40.f;
        m_velocity.y = 0;//so the character immediately comes back down
    }
    //m_shape.setPosition(m_position);
    m_shape.setPosition({m_position.x + 80.f, m_position.y + 40.f});
    m_sprite.setPosition(m_position);
    m_isOnGround = false;//every frame the character is considered to be in the air by default. this only becomes true on collision detection with a platform


    for(auto* collidable : collidables){
        if(m_shape.getGlobalBounds().findIntersection(collidable->getGlobalBounds())){
            collidable->onCollision(*this);
        }
    }

    auto it = allGems.begin(); 

    while (it != allGems.end()) { //loop until we reach the end of the list
        Gem* gem = *it; //dereference the iterator to get the actual Gem pointer
        bool collected = false;


        if (m_shape.getGlobalBounds().findIntersection(gem->getGlobalBounds()) && gem->getType() == GemType::Red) {
            gem->onCollision(*this);
            collected = true;
        }

        if (collected) {
            delete gem; //deallocation
            

            it = allGems.erase(it); 
        } else {
            ++it; 
        }
    }

    // m_shape.setPosition(m_position);//correcting the shape after collision
    m_shape.setPosition({m_position.x + 80.f, m_position.y + 40.f});
    m_sprite.setPosition(m_position);
}

void Fireboy::render(sf::RenderWindow& window){//draws fireboy on the screen
    window.draw(m_sprite);
    window.draw(m_shape);//remove this line once hitbox is aligned
}
