#include "Level2.h"

Level2::Level2() {
  m_fireboyStart   = sf::Vector2f(1820.f, 655.f);
  m_watergirlStart = sf::Vector2f(-50.f,655.f);
  
  // door positions are fixed for this level
  m_redDoor  = new Door(sf::Vector2f(20.f, 70.f),  DoorType::Red);
  m_blueDoor = new Door(sf::Vector2f(1800.f, 70.f), DoorType::Blue);
  load();
}

void Level2::load() {
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
  m_platforms.push_back(Platform(sf::Vector2f(0.f, 190.f),   sf::Vector2f(270.f, 25.f)));
  m_gems.push_back(new Gem(sf::Vector2f(150.f, 145.f), GemType::Red));
  
  m_platforms.push_back(Platform(sf::Vector2f(370.f, 190.f),   sf::Vector2f(440.f, 25.f)));
  m_waterPools.push_back(new WaterPool(sf::Vector2f(460.f, 115.f), sf::Vector2f(45.f, 85.f)));
  m_waterPools.push_back(new WaterPool(sf::Vector2f(660.f, 115.f), sf::Vector2f(45.f, 85.f)));
  
  m_platforms.push_back(Platform(sf::Vector2f(1010.f, 190.f), sf::Vector2f(440.f, 25.f)));
  m_firePools.push_back(new FirePool(sf::Vector2f(1100.f, 105.f), sf::Vector2f(45.f, 85.f)));
  m_firePools.push_back(new FirePool(sf::Vector2f(1300.f, 105.f), sf::Vector2f(45.f, 85.f)));
  
  m_platforms.push_back(Platform(sf::Vector2f(1550.f, 190.f), sf::Vector2f(370.f, 25.f)));
  m_gems.push_back(new Gem(sf::Vector2f(1670.f, 145.f), GemType::Blue));

  //MID SECTION
  //ushape with green pool(left)
  m_gems.push_back(new Gem(sf::Vector2f(225.f, 450.f), GemType::Red));
  m_platforms.push_back(Platform(sf::Vector2f(225.f, 490.f), sf::Vector2f(25.f, 125.f)));
  m_waterPools.push_back(new WaterPool(sf::Vector2f(250.f, 510.f), sf::Vector2f(150.f, 85.f)));
  m_platforms.push_back(Platform(sf::Vector2f(250.f, 590.f), sf::Vector2f(150.f, 25.f)));
  m_gems.push_back(new Gem(sf::Vector2f(400.f, 450.f), GemType::Blue));
  m_platforms.push_back(Platform(sf::Vector2f(400.f, 490.f), sf::Vector2f(25.f, 125.f)));
  
  //ushape with green pool(right)
  m_gems.push_back(new Gem(sf::Vector2f(1400.f, 450.f), GemType::Red));
  m_platforms.push_back(Platform(sf::Vector2f(1400.f, 490.f), sf::Vector2f(25.f, 125.f)));
  m_firePools.push_back(new FirePool(sf::Vector2f(1425.f, 510.f), sf::Vector2f(150.f, 85.f)));
  m_platforms.push_back(Platform(sf::Vector2f(1425.f, 592.f), sf::Vector2f(150.f, 25.f)));
  m_gems.push_back(new Gem(sf::Vector2f(1575.f, 450.f), GemType::Blue));
  m_platforms.push_back(Platform(sf::Vector2f(1575.f, 490.f), sf::Vector2f(25.f, 125.f)));

  //diamond shape mein floating platforms
  m_gems.push_back(new Gem(sf::Vector2f(870.f, 290.f), GemType::Red));
  m_gems.push_back(new Gem(sf::Vector2f(940.f, 290.f), GemType::Blue));
  m_platforms.push_back(Platform(sf::Vector2f(810.f, 340.f), sf::Vector2f(200.f, 25.f)));
  m_gems.push_back(new Gem(sf::Vector2f(665.f, 440.f), GemType::Red));
  m_platforms.push_back(Platform(sf::Vector2f(600.f, 490.f), sf::Vector2f(150.f, 25.f)));
  m_gems.push_back(new Gem(sf::Vector2f(1145.f, 440.f), GemType::Blue));
  m_platforms.push_back(Platform(sf::Vector2f(1080.f, 490.f), sf::Vector2f(150.f, 25.f)));
  m_gems.push_back(new Gem(sf::Vector2f(940.f, 590.f), GemType::Red));
  m_gems.push_back(new Gem(sf::Vector2f(870.f, 590.f), GemType::Blue));
  m_platforms.push_back(Platform(sf::Vector2f(810.f, 640.f), sf::Vector2f(200.f, 25.f)));

  m_gems.push_back(new Gem(sf::Vector2f(665.f, 740.f), GemType::Blue));
  m_platforms.push_back(Platform(sf::Vector2f(600.f, 790.f), sf::Vector2f(150.f, 25.f)));
  m_gems.push_back(new Gem(sf::Vector2f(1145.f, 740.f), GemType::Red));
  m_platforms.push_back(Platform(sf::Vector2f(1080.f, 790.f), sf::Vector2f(150.f, 25.f)));


  //BOTTOM SECTION
  m_platforms.push_back(Platform(sf::Vector2f(0.f, 805.f), sf::Vector2f(110.f, 250.f)));//left side wala(watergirl spawn point)
  //choty platforms  
  m_gems.push_back(new Gem(sf::Vector2f(225.f, 920.f), GemType::Red));
  m_platforms.push_back(Platform(sf::Vector2f(200.f, 960.f), sf::Vector2f(100.f, 25.f)));
  m_gems.push_back(new Gem(sf::Vector2f(425.f, 920.f), GemType::Blue));
  m_platforms.push_back(Platform(sf::Vector2f(400.f, 960.f), sf::Vector2f(100.f, 25.f)));

  m_platforms.push_back(Platform(sf::Vector2f(1820.f, 805.f), sf::Vector2f(160.f, 250.f)));//right side wala(fireboy spawn point)
  //choty platforms  
  m_gems.push_back(new Gem(sf::Vector2f(1655.f, 920.f), GemType::Blue));
  m_platforms.push_back(Platform(sf::Vector2f(1630.f, 960.f), sf::Vector2f(100.f, 25.f)));
  m_gems.push_back(new Gem(sf::Vector2f(1455.f, 920.f), GemType::Red));
  m_platforms.push_back(Platform(sf::Vector2f(1430.f, 960.f), sf::Vector2f(100.f, 25.f)));

//ground
  m_greenPools.push_back(new GreenPool(sf::Vector2f(110.f, 935.f), sf::Vector2f(1700.f, 115.f)));
  m_platforms.push_back(Platform(sf::Vector2f(0.f, 1050.f), sf::Vector2f(1920.f, 30.f)));
}

int Level2::getLevelNumber(){
  return 2;
}