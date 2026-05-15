#include "GameEngine.h"
#include "Collidable.h"
#include "Level1.h"
#include "Level2.h"
#include <vector>
 

//CONSTRUCTOR
//Only sets up UI elements and window.no level objects here.

GameEngine::GameEngine()
    : m_window(sf::VideoMode::getDesktopMode(), "Fireboy & Watergirl", sf::State::Fullscreen),
      m_font("GAMERIA.ttf"),
      
      m_bgTexture("startscreen.jpg"),
      m_bgSprite(m_bgTexture),
      m_title(m_font, "AAG LARKA PANI LARKI", 90),
      m_playTexture("play.png"),
      m_playSprite(m_playTexture),
      m_exitTexture("exit.png"),
      m_exitSprite(m_exitTexture),
      
      m_promptText(m_font, "", 45),
      m_inputText(m_font, "", 40),
      m_fireboyName(""),
      m_watergirlName(""),
      m_enteringFireboy(true),
     
      m_levelSelectTitle(m_font, "SELECT LEVEL", 70),
      m_level1Text(m_font, "LEVEL 1", 40),
      m_level2Text(m_font, "LEVEL 2", 40),
      
      m_levelBgTexture("levelbg.png"),
      m_levelBgSprite(m_levelBgTexture),
      m_fireboy(sf::Vector2f(30.f, 800.f)),
      m_watergirl(sf::Vector2f(10.f, 750.f)),
      m_currentLevel(nullptr),

      m_fireDeathText(m_font, "Fireboy Died", 40),
      m_waterDeathText(m_font, "Watergirl Died", 40),
      m_tryAgainText(m_font, "Try Again", 32)
{
    sf::Vector2u winSize = m_window.getSize();
 
    //backgrounds
    sf::Vector2u bgSz = m_bgTexture.getSize();
    m_bgSprite.setScale({(float)winSize.x / bgSz.x, (float)winSize.y / bgSz.y});
 
    bgSz = m_levelBgTexture.getSize();
    m_levelBgSprite.setScale({(float)winSize.x / bgSz.x, (float)winSize.y / bgSz.y});
 
    //title
    m_title.setFillColor(sf::Color(255, 240, 80));
    m_title.setOutlineColor(sf::Color::Black);
    m_title.setOutlineThickness(6.f);
    m_title.setCharacterSize(110);
    sf::FloatRect tb = m_title.getLocalBounds();
    m_title.setOrigin({tb.position.x + tb.size.x / 2.f, tb.position.y + tb.size.y / 2.f});
    m_title.setPosition({winSize.x / 2.f, winSize.y / 3.f});
 
    //play button
    sf::FloatRect pb = m_playSprite.getLocalBounds();
    m_playSprite.setOrigin({pb.size.x / 2.f, pb.size.y / 2.f});
    m_playSprite.setPosition({winSize.x / 2.f, winSize.y / 2.f + 50.f});
    m_playSprite.setScale({0.4f, 0.4f});
 
    //exit button
    sf::FloatRect eb = m_exitSprite.getLocalBounds();
    m_exitSprite.setOrigin({eb.size.x / 2.f, eb.size.y / 2.f});
    m_exitSprite.setPosition({winSize.x / 2.f, winSize.y / 2.f + 220.f});
    m_exitSprite.setScale({0.5f, 0.4f});
 
    //name input
    m_promptText.setString("TYPE NAME BELOW AND PRESS ENTER");
    m_promptText.setFillColor(sf::Color::White);
    sf::FloatRect pt = m_promptText.getLocalBounds();
    m_promptText.setOrigin({pt.position.x + pt.size.x / 2.f, pt.position.y + pt.size.y / 2.f});
    m_promptText.setPosition({winSize.x / 2.f, winSize.y / 2.f - 60.f});
 
    m_inputBox.setSize({500.f, 65.f});
    m_inputBox.setFillColor(sf::Color(50, 50, 50));
    m_inputBox.setOutlineThickness(2.f);
    m_inputBox.setOutlineColor(sf::Color::White);
    m_inputBox.setOrigin({250.f, 32.5f});
    m_inputBox.setPosition({winSize.x / 2.f, winSize.y / 2.f});
 
    m_inputText.setFillColor(sf::Color::Cyan);
    m_inputText.setPosition({winSize.x / 2.f - 230.f, winSize.y / 2.f - 20.f});
 
    //level select
    m_levelSelectTitle.setFillColor(sf::Color(255, 215, 0));
    sf::FloatRect lt = m_levelSelectTitle.getLocalBounds();
    m_levelSelectTitle.setOrigin({lt.position.x + lt.size.x / 2.f, lt.position.y + lt.size.y / 2.f});
    m_levelSelectTitle.setPosition({winSize.x / 2.f, winSize.y / 3.f});
 
    m_level1Button.setSize({250.f, 80.f});
    m_level1Button.setFillColor(sf::Color(180, 80, 80));
    m_level1Button.setOrigin({125.f, 40.f});
    m_level1Button.setPosition({winSize.x / 2.f - 180.f, winSize.y / 2.f + 50.f});
    sf::FloatRect l1 = m_level1Text.getLocalBounds();
    m_level1Text.setOrigin({l1.position.x + l1.size.x / 2.f, l1.position.y + l1.size.y / 2.f});
    m_level1Text.setFillColor(sf::Color::White);
    m_level1Text.setPosition(m_level1Button.getPosition());
 
    m_level2Button.setSize({250.f, 80.f});
    m_level2Button.setFillColor(sf::Color(80, 80, 180));
    m_level2Button.setOrigin({125.f, 40.f});
    m_level2Button.setPosition({winSize.x / 2.f + 180.f, winSize.y / 2.f + 50.f});
    sf::FloatRect l2 = m_level2Text.getLocalBounds();
    m_level2Text.setOrigin({l2.position.x + l2.size.x / 2.f, l2.position.y + l2.size.y / 2.f});
    m_level2Text.setFillColor(sf::Color::White);
    m_level2Text.setPosition(m_level2Button.getPosition());
 
    //death popup
    m_popupBox.setSize({400.f, 200.f});
    m_popupBox.setFillColor(sf::Color(50, 50, 50));
    m_popupBox.setOrigin({200.f, 100.f});
    m_popupBox.setPosition({winSize.x / 2.f, winSize.y / 2.f});
 
    sf::FloatRect fd = m_fireDeathText.getLocalBounds();
    m_fireDeathText.setOrigin({fd.position.x + fd.size.x / 2.f, fd.position.y + fd.size.y / 2.f});
    m_fireDeathText.setPosition({winSize.x / 2.f, winSize.y / 2.f - 40.f});
    m_fireDeathText.setFillColor(sf::Color::White);
 
    sf::FloatRect wd = m_waterDeathText.getLocalBounds();
    m_waterDeathText.setOrigin({wd.position.x + wd.size.x / 2.f, wd.position.y + wd.size.y / 2.f});
    m_waterDeathText.setPosition({winSize.x / 2.f, winSize.y / 2.f - 40.f});
    m_waterDeathText.setFillColor(sf::Color::White);
 
    m_tryAgainButton.setSize({200.f, 60.f});
    m_tryAgainButton.setFillColor(sf::Color(160, 200, 100));
    m_tryAgainButton.setOrigin({100.f, 30.f});
    m_tryAgainButton.setPosition({winSize.x / 2.f, winSize.y / 2.f + 50.f});
    sf::FloatRect ta = m_tryAgainText.getLocalBounds();
    m_tryAgainText.setOrigin({ta.position.x + ta.size.x / 2.f, ta.position.y + ta.size.y / 2.f});
    m_tryAgainText.setPosition(m_tryAgainButton.getPosition());
    m_tryAgainText.setFillColor(sf::Color::Black);

    sf::View view(sf::FloatRect({0.f, 0.f}, {1920.f, 1080.f}));
    m_window.setView(view);
 
    //start state
    m_window.setFramerateLimit(60);
    m_states.push(GameState::Menu);


}
 

GameEngine::~GameEngine() {
    delete m_currentLevel; //Level destructor cleans up its own pools/gems
}
 
//creates the right Level object and resets characters
void GameEngine::loadLevel(int levelNumber) {
    delete m_currentLevel;          //free previous level (nullptr delete is safe)
 
    if (levelNumber == 1)
        m_currentLevel = new Level1();
    else
        m_currentLevel = new Level2();
    //Level constructor already calls load() and sets spawn positions

 
    m_fireboy.respawn(m_currentLevel->m_fireboyStart);
    m_watergirl.respawn(m_currentLevel->m_watergirlStart);
    m_currentLevel->m_redDoor->setOpen(false);
    m_currentLevel->m_blueDoor->setOpen(false);
    m_levelTimer.restart();
}
 
//  RUN main game loop
void GameEngine::run() {
    const sf::Time TimePerFrame     = sf::seconds(1.f / 60.f);
    sf::Time       timeSinceLastUpdate = sf::Time::Zero;
 
    while (m_window.isOpen()) {
        timeSinceLastUpdate += m_clock.restart();
        handleEvents();
        while (timeSinceLastUpdate > TimePerFrame) {
            timeSinceLastUpdate -= TimePerFrame;
            update(TimePerFrame.asSeconds());
        }
        render();
    }
}
 
//  HANDLE EVENTS
void GameEngine::handleEvents() {
    while (const std::optional event = m_window.pollEvent()) {
 
        //window close
        if (event->is<sf::Event::Closed>())
            m_window.close();
 
        //text input 
        if (m_states.top() == GameState::NameInput) {
            if (const auto* te = event->getIf<sf::Event::TextEntered>()) {
                if (te->unicode == 8) { // backspace
                    if (m_enteringFireboy && !m_fireboyName.empty())
                        m_fireboyName.pop_back();
                    else if (!m_enteringFireboy && !m_watergirlName.empty())
                        m_watergirlName.pop_back();
                }
                else if (te->unicode == 13) { //enter
                    if (m_enteringFireboy && !m_fireboyName.empty())
                        m_enteringFireboy = false;           // move to watergirl
                    else if (!m_enteringFireboy && !m_watergirlName.empty())
                        m_states.push(GameState::LevelSelect); // names done then move to pick level
                }
                else if (te->unicode > 31 && te->unicode < 128) { // printable
                    if (m_enteringFireboy) m_fireboyName  += static_cast<char>(te->unicode);
                    else                  m_watergirlName += static_cast<char>(te->unicode);
                }
            }
        }
 
        //keyboard (leaderboard back, level-complete navigation)
        if (const auto* kp = event->getIf<sf::Event::KeyPressed>()) {
            if (kp->code == sf::Keyboard::Key::Escape) {
                if (m_states.top() == GameState::Leaderboard){
                    m_states.pop(); // back to LevelComplete (or wherever)
                    m_states.push(GameState::LevelSelect);}

            }
            if (kp->code == sf::Keyboard::Key::L) {
                if (m_states.top() == GameState::LevelComplete)
                    m_states.push(GameState::Leaderboard);
            }
        }
 
        if (const auto* mp = event->getIf<sf::Event::MouseButtonPressed>()) {
            sf::Vector2f mouse = {(float)mp->position.x, (float)mp->position.y};
 
            // MENU
            if (m_states.top() == GameState::Menu) {
                if (m_playSprite.getGlobalBounds().contains(mouse))
                    m_states.push(GameState::NameInput);
                if (m_exitSprite.getGlobalBounds().contains(mouse))
                    m_window.close();
            }
 
            // LEVEL SELECT
            if (m_states.top() == GameState::LevelSelect) {
                if (m_level1Button.getGlobalBounds().contains(mouse)) {
                    loadLevel(1);
                    m_states.push(GameState::Playing);
                }
                if (m_level2Button.getGlobalBounds().contains(mouse)) {
                    loadLevel(2);
                    m_states.push(GameState::Playing);
                }
                if (m_exitSprite.getGlobalBounds().contains(mouse)) // add this
                    m_window.close();
            }
 
            // TRY AGAIN (player died popup)
            if (m_states.top() == GameState::PlayerDied) {
                if (m_tryAgainButton.getGlobalBounds().contains(mouse)) {
                    // reload the same level from scratch
                    int lvl = m_currentLevel->getLevelNumber(); 
                    m_states.pop();  // remove PlayerDied → back to Playing
                    loadLevel(lvl);  // reset everything
                }
            }
        }
    }
}
 
void GameEngine::update(float fixedDelta) {
    if (m_states.top() == GameState::LevelComplete) {
        m_stateTimer -= fixedDelta;
        if (m_stateTimer <= 0.f) {
            m_states.pop();
            m_states.push(GameState::Leaderboard);
        }
        return;
    }

    if (m_states.top() != GameState::Playing) return;
    if (!m_currentLevel) return; // safety guard
 
    // build collidables list from current level's objects
    std::vector<Collidable*> collidables;
    for (auto& p  : m_currentLevel->m_platforms)  collidables.push_back(&p);
    for (auto* fp : m_currentLevel->m_firePools)   collidables.push_back(fp);
    for (auto* wp : m_currentLevel->m_waterPools)  collidables.push_back(wp);
    for (auto* gp : m_currentLevel->m_greenPools)  collidables.push_back(gp);
    collidables.push_back(m_currentLevel->m_redDoor);
    collidables.push_back(m_currentLevel->m_blueDoor);
 
    m_fireboy.update(fixedDelta,  collidables, m_currentLevel->m_gems);
    m_watergirl.update(fixedDelta, collidables, m_currentLevel->m_gems);
 
    // check death
    if (m_fireboy.dead() || m_watergirl.dead())
        m_states.push(GameState::PlayerDied);
 
    // check level complete
    if (m_currentLevel->m_redDoor->isOpen() && m_currentLevel->m_blueDoor->isOpen()) {
        float elapsed   = m_levelTimer.getElapsedTime().asSeconds();
        int   totalGems = m_fireboy.getNumGems() + m_watergirl.getNumGems();
        std::string pair = m_fireboyName + " & " + m_watergirlName;
        m_leaderboard.addEntry(pair, elapsed, totalGems); //sorts + saves to file
        m_states.push(GameState::LevelComplete);
    m_stateTimer = 3.f; //stays for 3 seconds

    } 
}
 

void GameEngine::renderLevel() {
    if (!m_currentLevel) return;
    m_window.draw(m_levelBgSprite);
    for (auto& p : m_currentLevel->m_platforms)  p.render(m_window);
    for (auto* fp : m_currentLevel->m_firePools) fp->render(m_window);
    for (auto* wp : m_currentLevel->m_waterPools) wp->render(m_window);
    for (auto* gp : m_currentLevel->m_greenPools) gp->render(m_window);
    for (auto* g : m_currentLevel->m_gems) g->render(m_window);


    m_currentLevel->m_redDoor->render(m_window);
    m_currentLevel->m_blueDoor->render(m_window);
    m_fireboy.render(m_window);
    m_watergirl.render(m_window);
}
 

void GameEngine::render() {
    m_window.clear();
 
    if (m_states.top() == GameState::Menu) {
        m_window.draw(m_bgSprite);
        m_window.draw(m_title);
        m_window.draw(m_playSprite);
        m_window.draw(m_exitSprite);
    }
    else if (m_states.top() == GameState::NameInput) {
        m_window.draw(m_bgSprite);
        //update prompt dynamically based on whose name we're entering
        m_promptText.setString(m_enteringFireboy
            ? "           ENTER FIREBOY NAME "
            : "      ENTER WATERGIRL NAME");
        m_window.draw(m_promptText);
        m_window.draw(m_inputBox);
        m_inputText.setString(
            (m_enteringFireboy ? m_fireboyName : m_watergirlName) + "|");
        m_window.draw(m_inputText);
    }
    else if (m_states.top() == GameState::LevelSelect) {
        m_window.draw(m_bgSprite);
        m_window.draw(m_levelSelectTitle);
        m_window.draw(m_level1Button);
        m_window.draw(m_level1Text);
        m_window.draw(m_level2Button);
        m_window.draw(m_level2Text);
        m_window.draw(m_exitSprite);
    }
    else if (m_states.top() == GameState::Playing) {
        renderLevel();
    }
    else if (m_states.top() == GameState::PlayerDied) {
        renderLevel(); // game frozen in background
        m_window.draw(m_popupBox);
        m_watergirl.dead()
            ? m_window.draw(m_waterDeathText)
            : m_window.draw(m_fireDeathText);
        m_window.draw(m_tryAgainButton);
        m_window.draw(m_tryAgainText);
    }
    else if (m_states.top() == GameState::LevelComplete) {
        m_window.draw(m_bgSprite);

        sf::Text winText(m_font, "LEVEL COMPLETE!", 80);
        winText.setFillColor(sf::Color::Yellow);
        sf::FloatRect wb = winText.getLocalBounds();
        winText.setOrigin({wb.position.x + wb.size.x / 2.f, wb.position.y + wb.size.y / 2.f});
        winText.setPosition({m_window.getSize().x / 2.f, m_window.getSize().y / 2.f - 80.f});
        m_window.draw(winText);
    }
    else if (m_states.top() == GameState::Leaderboard) {
        m_leaderboard.render(m_window, m_font); //leaderboard class handles its own drawing
    }
 
    m_window.display();
}
 