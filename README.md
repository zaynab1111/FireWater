# FireWater
A two player cooperative platformer game built in C++ using SFML, 
developed as a semester project for CSE142 Object Oriented Programming.

## Course
CSE142: Object Oriented Programming Techniques
Instructor: Dr. Behraj Khan
Semester: Spring 2026

## Team Members
- Zainab Imran ERP: 32469
- Mehdiya Zehra ERP: 33404
- Abeer Sindhu ERP: 32423

## How to Run
1. Make sure SFML is installed
2. Clone the repository
3. Open the project in VS Code
4. Build using CMake:
   cd build
   cmake ..
   cmake --build
5. Run `FireWater.exe` from the build folder

## Assets Required
The following image files must be present in the project root directory 
(same folder as the executable):

| File | Purpose |
|------|---------|
| `startscreen.jpg` | Main menu background 
| `levelbg.png` | In game background 
| `play.png` | Play button on menu 
| `exit.png` | Exit button on menu 
| `Fireboy.png` | Fireboy character sprite |
| `Watergirl.png` | Watergirl character sprite |
| `redDoor.png` | Red door sprite |
| `blueDoor.png` | Blue door sprite |
| `red-gem.png` | Red gem sprite |
| `blue-gem.png` | Blue gem sprite |
| `waterpool.png` | Water pool sprite |
| `firepool.png` | Fire pool sprite |
| `greenpool.png` | Green pool sprite |

## Controls
Fireboy | ← left | → right | ↑ jump |
Watergirl | A left| D right | W jump|

## Game Features
- 2 levels with unique layouts
- Fire, water, and green pools
- Collectible gems
- Pressure plate buttons that open walls
- Leaderboard that saves scores to file and ranks players according to scores
- Name input for both players

## OOP Concepts Used
- Inheritance (Entity -> GameObject -> Character -> Fireboy/Watergirl)
- Polymorphism (virtual update(), render(), onCollision())
- Encapsulation (private members, getters/setters)
- Operator overloading (>, == PlayerEntry)
- Abstract classes (Character, Levels, Collidable)
- Constructors and Destructors

## Data Structures and Algorithms
- Stack for game state
- Insertion sort for sorting player scores
- Dynamic Arrays

## Advanced C++ features
- Friend classes (Levels and GameEngine)
- Exception handling (File found/not found)
- STL containers (vectors of platforms, etc)

## Dependencies
```
- C++20 
- SFML 3.0.2+
- CMake 3.10+
```

## File Structure
```
src/
├── main.cpp
├── GameEngine.h / .cpp
├── Entity.h / .cpp
├── GameObject.h / .cpp
├── Character.h / .cpp
├── Fireboy.h / .cpp
├── Watergirl.h / .cpp
├── Levels.h / .cpp
├── Level1.h / .cpp
├── Level2.h / .cpp
├── Platform.h / .cpp
├── Hazard.h / .cpp
├── FirePool.h / .cpp
├── WaterPool.h / .cpp
├── GreenPool.h / .cpp
├── Door.h / .cpp
├── Gem.h / .cpp
├── Button.h / .cpp
├── MovableWall.h / .cpp
└── Leaderboard.h / .cpp
```

## Known Issues
- Hitboxes are approximate and may feel slightly off near pool edges
