#include "Level1.h"

Level1::Level1(){
    m_fireboyStart   = sf::Vector2f(30.f, 800.f);
    m_watergirlStart = sf::Vector2f(10.f, 750.f);
    //door positions are fixed for this level
    m_redDoor  = new Door(sf::Vector2f(20.f, 50.f),  DoorType::Red);
   m_blueDoor = new Door(sf::Vector2f(115.f, 50.f), DoorType::Blue);
    load();
}

void Level1::load() {
    //clear anything that might be leftover if load() is ever called again on retr
    m_platforms.clear();
    for (auto* p : m_firePools)  delete p;
    for (auto* p : m_waterPools) delete p;
    for (auto* p : m_greenPools) delete p;
    for (auto* g : m_gems)       delete g;
    m_firePools.clear();
    m_waterPools.clear();
    m_greenPools.clear();
    m_gems.clear();

//top 
    m_platforms.push_back(Platform(sf::Vector2f(0.f, 170.f),   sf::Vector2f(300.f, 25.f)));
    m_gems.push_back(new Gem(sf::Vector2f(200.f, 125.f), GemType::Blue));
    m_gems.push_back(new Gem(sf::Vector2f(250.f, 125.f), GemType::Red));
    m_platforms.push_back(Platform(sf::Vector2f(400.f, 170.f), sf::Vector2f(800.f, 25.f)));
    m_platforms.push_back(Platform(sf::Vector2f(1300.f, 170.f), sf::Vector2f(400.f, 25.f)));

    //choty floatong plats
    m_platforms.push_back(Platform(sf::Vector2f(440.f, 300.f), sf::Vector2f(100.f, 25.f)));
    m_platforms.push_back(Platform(sf::Vector2f(910.f, 335.f), sf::Vector2f(100.f, 25.f)));

    // --- SNAKE ROW ---
    m_platforms.push_back(Platform(sf::Vector2f(225.f,  460.f), sf::Vector2f(1510.f, 25.f)));
    m_platforms.push_back(Platform(sf::Vector2f(660.f,  425.f), sf::Vector2f(100.f,  35.f)));
    m_waterPools.push_back(new WaterPool(sf::Vector2f(395.f,  390.f), sf::Vector2f(200.f, 85.f)));

    m_gems.push_back(new Gem(sf::Vector2f(670.f, 365.f), GemType::Blue));
    m_gems.push_back(new Gem(sf::Vector2f(700.f, 365.f), GemType::Red));

    //small dabbas to the right
    m_platforms.push_back(Platform(sf::Vector2f(1700.f, 375.f), sf::Vector2f(130.f,  85.f)));
    m_platforms.push_back(Platform(sf::Vector2f(1800.f, 290.f), sf::Vector2f(130.f,  85.f)));

    m_greenPools.push_back(new GreenPool(sf::Vector2f(1400.f, 350.f), sf::Vector2f(110.f, 115.f)));
    m_greenPools.push_back(new GreenPool(sf::Vector2f(1150.f, 350.f), sf::Vector2f(110.f, 115.f)));

    m_gems.push_back(new Gem(sf::Vector2f(1500.f, 265.f), GemType::Blue));
    m_gems.push_back(new Gem(sf::Vector2f(1300.f, 265.f), GemType::Red));
    m_firePools.push_back(new FirePool(sf::Vector2f(790.f,  270.f), sf::Vector2f(220.f, 200.f)));

    // --- MID ROW ---
    m_platforms.push_back(Platform(sf::Vector2f(1485.f, 690.f), sf::Vector2f(225.f, 25.f)));//right side pe small
    m_platforms.push_back(Platform(sf::Vector2f(485.f, 690.f), sf::Vector2f(855.f, 25.f)));//beech mein big wala that has the poool and gem chain
    m_platforms.push_back(Platform(sf::Vector2f(115.f, 690.f), sf::Vector2f(225.f, 25.f)));//left pe small wala
    //small floating platform with gems (right pe)
    m_platforms.push_back(Platform(sf::Vector2f(1805.f, 585.f), sf::Vector2f(115.f,  25.f)));
    m_gems.push_back(new Gem(sf::Vector2f(1825.f, 545.f), GemType::Blue));
    m_gems.push_back(new Gem(sf::Vector2f(1845.f, 545.f), GemType::Red));
    //pool and gem chain
    m_waterPools.push_back(new WaterPool(sf::Vector2f(1090.f, 610.f), sf::Vector2f(60.f, 85.f)));
    m_gems.push_back(new Gem(sf::Vector2f(1010.f, 640.f), GemType::Red));
    m_firePools.push_back(new FirePool(sf::Vector2f(915.f, 610.f), sf::Vector2f(60.f, 85.f)));
    m_gems.push_back(new Gem(sf::Vector2f(835.f, 640.f), GemType::Blue));
    m_waterPools.push_back(new WaterPool(sf::Vector2f(740.f, 610.f), sf::Vector2f(60.f, 85.f)));
    //pool gem chain k baad vertical obstical
    m_platforms.push_back(Platform(sf::Vector2f(580.f, 620.f), sf::Vector2f(25.f, 90.f)));//beech mein big wala that has the poool and gem chain
    m_platforms.push_back(Platform(sf::Vector2f(0.f, 575.f), sf::Vector2f(115.f,  90.f)));//left pe block

    // POOL ROW
    m_platforms.push_back(Platform(sf::Vector2f(235.f, 900.f), sf::Vector2f(320.f, 25.f)));
    m_gems.push_back(new Gem(sf::Vector2f(285.f, 850.f), GemType::Blue));
    m_gems.push_back(new Gem(sf::Vector2f(485.f, 850.f), GemType::Blue));
    m_waterPools.push_back(new WaterPool(sf::Vector2f(235.f, 820.f), sf::Vector2f(320.f, 85.f)));
    m_gems.push_back(new Gem(sf::Vector2f(385.f, 995.f), GemType::Red));

    m_platforms.push_back(Platform(sf::Vector2f(750.f, 900.f), sf::Vector2f(320.f, 25.f)));
    m_gems.push_back(new Gem(sf::Vector2f(800.f,  995.f), GemType::Red));
    m_gems.push_back(new Gem(sf::Vector2f(1000.f, 995.f), GemType::Red));
    m_firePools.push_back(new FirePool(sf::Vector2f(750.f,  963.f), sf::Vector2f(320.f, 85.f)));
    m_gems.push_back(new Gem(sf::Vector2f(900.f, 850.f), GemType::Blue));
    
    m_platforms.push_back(Platform(sf::Vector2f(1285.f, 900.f), sf::Vector2f(400.f, 25.f)));
    m_gems.push_back(new Gem(sf::Vector2f(1485.f, 850.f), GemType::Red));
    m_firePools.push_back(new FirePool(sf::Vector2f(1385.f, 820.f), sf::Vector2f(200.f, 85.f)));


    m_gems.push_back(new Gem(sf::Vector2f(1485.f, 993.f), GemType::Blue));
    m_waterPools.push_back(new WaterPool(sf::Vector2f(1325.f, 963.f), sf::Vector2f(320.f, 85.f)));

    m_platforms.push_back(Platform(sf::Vector2f(1820.f, 805.f), sf::Vector2f(160.f, 250.f)));//side wala

    m_platforms.push_back(Platform(sf::Vector2f(0.f, 1050.f), sf::Vector2f(1920.f, 30.f)));
}

int Level1::getLevelNumber(){
    return 1;
}