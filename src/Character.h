#pragma once
#include"GameObject.h"
#include "Collidable.h"
#include <vector>
#include <string>
#include <list>
#include "Gem.h"
#include <SFML/Graphics.hpp>

enum class NameOption{FireBoy, WaterGirl};

class Character : public GameObject{
    protected:
        sf::Vector2f m_velocity;
        sf::RectangleShape m_shape;//shape of the character on the screen
        const float m_gravity = 500.f;   // Downward pull
        const float m_jumpForce = -500.f; // Negative because UP is negative Y
        const float m_speed = 300.f;//horizontal speed
        bool m_jumpKeyReleased=true;
        bool m_isOnGround;
        bool m_isDead = false;
        int m_numGems = 0;
        NameOption m_name;

    public:
        Character(sf::Vector2f startPos, const std::string& texturePath);
        Character(const Character& other); //copy constructor
        virtual ~Character()=default;
        virtual void update(float deltaTime, std::vector<Collidable*>& collidables, std::list<Gem*>& allGems) = 0;
        virtual void render(sf::RenderWindow& window)=0;
        sf::Vector2f getPosition() const;
        sf::RectangleShape& getShape();
        sf::Vector2f getVelocity() const;
        void collectGem();
        bool operator > (const Character& other) const;
        bool operator == (const Character& other) const;
        std::string getNameAsString()const;
        NameOption getNameAsEnum()const;
        int getNumGems()const;
        bool dead()const;
        void setVelocity(sf::Vector2f vel);
        void setOnGround(bool value);
        void setDead(bool value);
        void respawn(sf::Vector2f startPos);//this is for when a character dies and the user clicks try again. without this, the character will stay in the pool that killed it and collision detection baar baar hoti rahy gi and character will keep dying. so we move both characters back to their strating positions when the user clicks try again
};