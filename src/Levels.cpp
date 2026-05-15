#include "Levels.h"

Levels::~Levels() {
    for (auto* p : m_firePools)  delete p;
    for (auto* p : m_waterPools) delete p;
    for (auto* p : m_greenPools) delete p;
    for (auto* g : m_gems) delete g;
    delete m_redDoor;
    delete m_blueDoor;

}
