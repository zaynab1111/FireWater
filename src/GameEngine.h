#pragma once
#include <SFML/Graphics.hpp>
#include <stack>
#include <list>
#include "Fireboy.h"
#include "Watergirl.h"
#include "Door.h"
#include "Gem.h"
#include "Levels.h"       
#include "Leaderboard.h"
 
class Levels;
enum class GameState {
    Menu,
    NameInput,       
    LevelSelect, //added this for new levels. also need to add another state which can switch from l1 to l2
    Playing,         
    PlayerDied,      
    LevelComplete,   
    Leaderboard      
};
 
class GameEngine {
private:
    //window & timing
    sf::RenderWindow m_window;
    sf::Clock m_clock;
    sf::Clock m_levelTimer; //measures how long a level run takes
 
    sf::Font m_font;
 
    //menu
    sf::Texture m_bgTexture;
    sf::Sprite m_bgSprite;
    sf::Text m_title;
    sf::Texture m_playTexture;
    sf::Sprite m_playSprite;
    sf::Texture m_exitTexture;
    sf::Sprite m_exitSprite;
 
    //name input screen
    sf::Text m_promptText;      
    sf::RectangleShape m_inputBox;
    sf::Text m_inputText;       
    std::string m_fireboyName;
    std::string m_watergirlName;
    bool m_enteringFireboy; 
 
    //level select screen 
    sf::Text m_levelSelectTitle;
    sf::RectangleShape m_level1Button;
    sf::Text m_level1Text;
    sf::RectangleShape m_level2Button;
    sf::Text m_level2Text;
 
    //in game
    sf::Texture m_levelBgTexture;
    sf::Sprite m_levelBgSprite;
    Fireboy m_fireboy;
    Watergirl m_watergirl;
 
    //pointer for current level. makes it easier to deallocate and allocate memory
    //explanation in levels class
    Levels* m_currentLevel; //points to Level1 or Level2
 
    //death popup
    sf::RectangleShape m_popupBox;
    sf::Text m_fireDeathText;
    sf::Text m_waterDeathText;
    sf::RectangleShape m_tryAgainButton;
    sf::Text m_tryAgainText;
 
    //leaderboard
    Leaderboard m_leaderboard;
 
    //game state stack
    std::stack<GameState> m_states;

    float m_stateTimer = 0.f;

    void handleEvents();
    void update(float fixedDelta);
    void render();
    void renderLevel(); 
    void loadLevel(int levelNumber); 
 
public:
    GameEngine();
    ~GameEngine();
    void run();
};