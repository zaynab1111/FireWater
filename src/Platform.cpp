#include "Platform.h"
#include "Character.h"

Platform::Platform(sf::Vector2f position, sf::Vector2f size){
    //m_shape has type RectangleShape so it has built in size,
    //pos, and colour functions.
    m_shape.setSize(size);
    m_shape.setPosition(position);
    m_shape.setFillColor(sf::Color(139,69,19));
}

void Platform::render(sf::RenderWindow& window){
    window.draw(m_shape);
}

sf::FloatRect Platform::getGlobalBounds() const{
    return m_shape.getGlobalBounds(); //sfml can do the required calculation itself yippie!!!
}

void Platform::onCollision(Character& character){
    //get both rectangles
    sf::FloatRect charBounds = character.getShape().getGlobalBounds();//boundaries of the character
    sf::FloatRect platBounds = m_shape.getGlobalBounds();//boundaries of the platform
    
    //.findIntersection() is a built in function in SFML. It checks if two rectangles overlap.
    //if they do, it returns the overlapping region as another rectangle. returns nothing if they dont overlap
    if(auto intersection = charBounds.findIntersection(platBounds)){
        if(intersection->size.x > intersection->size.y){//if the overlap is wider than it it is tall, then it is a horizontal collision meaning it either hit the top or bottom of the platform
            //vertical collision
            if(character.getVelocity().y > 0){//falling down. checks if the character is moving downward. in SFML +ve y means moving down
                //the charcater has now slightly sunk into the platform. this pushes the chacater back up by exactly the height of the overlap
                character.setPosition({character.getPosition().x, character.getPosition().y - intersection->size.y});// is the height of the overlap
                character.setVelocity({character.getVelocity().x, 0.f});//sets vertical velocity to 0
                character.setOnGround(true);
            }else{//if the character hits the bottom of the platform
                character.setPosition({character.getPosition().x, character.getPosition().y + intersection->size.y});//pushes character back down by the overlapping amount
                character.setVelocity({character.getVelocity().x, 0.f});//again, sets vertical velocity to 0
            }
        }else{//if the overlapping part is taller than it is wide, it hit the side of the platform
            //horizontal collison
            if(character.getVelocity().x > 0){//if the character was moving towards the right
                character.setPosition({character.getPosition().x - intersection->size.x, character.getPosition().y});//pushes it back by the overlapping amount
            }else{//if the character was moving towards the left
                character.setPosition({character.getPosition().x + intersection->size.x, character.getPosition().y});//pushes it forward by the overlapping amount
            }
            character.setVelocity({0.f, character.getVelocity().y});//sets horizontal velocity to 0
        }
    }
    character.getShape().setPosition({character.getPosition().x + 80.f, character.getPosition().y + 40.f});
}