#include "Watergirl.h"

Watergirl::Watergirl(sf::Vector2f startPos): Character(startPos, "Watergirl.png"){
    // m_shape.setFillColor(sf::Color(0,0,250));
    m_name = NameOption::WaterGirl;
}

void Watergirl::update(float deltaTime, std::vector<Collidable*>& collidables, std::list<Gem*>& allGems){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
        m_velocity.x = 200.f;
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
        m_velocity.x = -200.f;
    }else{
        m_velocity.x = 0.f;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && m_isOnGround &&m_jumpKeyReleased){
        m_velocity.y = -600.f;
        m_isOnGround=false;
        m_jumpKeyReleased=false;
    }
    if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
        m_jumpKeyReleased=true;
    }

    m_velocity.y+=m_gravity*deltaTime;
    m_position += m_velocity * deltaTime;
    // clamp to screen edges(to prevent dono from going off the screen)
    // left edge
    if (m_position.x + 80.f < 0.f){
        m_position.x = -80.f;
    }
    // right edge
    if (m_position.x + 80.f + 60.f > 1920.f){
        m_position.x = 1920.f - 80.f - 60.f;
    }
    // top edge
    if (m_position.y + 40.f < 0.f){
        m_position.y = -40.f;
        m_velocity.y = 0;//so the character immediately comes back down
    }
    // m_shape.setPosition(m_position);
    // update hitbox with offset
    m_shape.setPosition({m_position.x + 80.f, m_position.y + 40.f});
    // m_sprite.setPosition(m_position);
    m_isOnGround = false;//every frame the character is considered to be in the air by default. this only becomes true on collision detection with a platform
    
    //zainab i (abeer) removed the other for loop wala code you had here kyun k wo already platform.cpp mein tha and adding it here too was unecessary. ye neeche wala chota for loop does the same thing, just calls har collidable ka respective onCollision. this is a much cleaner way to hnadle this. lmk if this makes sense

    for(auto* collidable : collidables){
        if(m_shape.getGlobalBounds().findIntersection(collidable->getGlobalBounds())){
            collidable->onCollision(*this);
        }
    }

    //zainab i (abeer) moved collision detection from GameEngine to here. made more sense lmk if it doesn't, i'll change it back
    auto it = allGems.begin(); 

    while (it != allGems.end()) { // Loop until we reach the end of the list.
        Gem* gem = *it; // Dereference the iterator to get the actual Gem pointer.
        bool collected = false;

        // Logic: If the character's hitbox touches the gem's hitbox[cite: 3, 5].
        // .intersects() is an SFML function that checks if two rectangles overlap[cite: 12].
        if (m_shape.getGlobalBounds().findIntersection(gem->getGlobalBounds()) && gem->getType() == GemType::Blue) {
            gem->onCollision(*this);
            collected = true;
        }

        if (collected) {
            //delete gem; // Manual Memory Management: Free the memory used by the Gem[cite: 16].
            
            // it = m_gems.erase(it) removes the item from the Linked List in O(1) time.
            // It returns the 'next' valid item so the loop doesn't break[cite: 16].
            it = allGems.erase(it); 
        } else {
            ++it; // Move to the next gem if this one wasn't picked up.
        }
    }

    // m_shape.setPosition(m_position);//correcting the shape after collision
    m_shape.setPosition({m_position.x + 80.f, m_position.y + 40.f});
    m_sprite.setPosition(m_position);
}

void Watergirl::onCollision(Entity* other){
    //do we really need this anymore????
}

void Watergirl::render(sf::RenderWindow& window){
    window.draw(m_sprite);
    window.draw(m_shape); // remove this line once hitbox is aligned
}