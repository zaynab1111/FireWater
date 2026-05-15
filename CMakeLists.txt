cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_COMPILER "C:/msys64/ucrt64/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "C:/msys64/ucrt64/bin/g++.exe")
set(SFML_DIR "C:/msys64/ucrt64/lib/cmake/SFML")

project(FireWater)

find_package(SFML 3 COMPONENTS Graphics Window System Audio REQUIRED)

add_executable(FireWater src/main.cpp src/GameEngine.cpp src/Character.cpp src/Fireboy.cpp src/Watergirl.cpp src/Platform.cpp src/GameObject.cpp src/Gem.cpp src/GameObject.cpp src/Door.cpp src/Hazard.cpp src/FirePool.cpp src/waterPool.cpp src/GreenPool.cpp src/Entity.cpp src/LeaderBoard.cpp src/Level1.cpp src/Level2.cpp src/Levels.cpp )

target_link_libraries(FireWater SFML::Graphics SFML::Window SFML::System SFML::Audio)
file(GLOB ASSETS "assets/*")
file(COPY ${ASSETS} DESTINATION ${CMAKE_BINARY_DIR})