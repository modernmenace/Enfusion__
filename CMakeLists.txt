cmake_minimum_required(VERSION 3.12)
project(Enfusion__)

set(CMAKE_CXX_STANDARD 14)

add_executable(Enfusion__ main.cpp GameData/Game.cpp GameData/Game.h GameData/Engine/Core/Engine.h GameData/Engine/Core/AssetManager.cpp GameData/Engine/Core/AssetManager.h GameData/Engine/Lvl/Level.cpp GameData/Engine/Lvl/Level.h GameData/Levels/Level_1/Level_1.cpp GameData/Levels/Level_1/Level_1.h GameData/Engine/Lvl/LevelManager.cpp GameData/Engine/Lvl/LevelManager.h GameData/Engine/Objects/GameObject.cpp GameData/Engine/Objects/GameObject.h GameData/Engine/Objects/Player.cpp GameData/Engine/Objects/Player.h GameData/Engine/AI/Agent.cpp GameData/Engine/AI/Agent.h GameData/Engine/Anim/Animator.cpp GameData/Engine/Anim/Animator.h)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

# On Windows, place SFML folder here
if(WIN32)
    set(SFML_ROOT ${CMAKE_CURRENT_LIST_DIR}/SFML-2.4.2)
endif()

#[[ below line imports all available packages, even non needed ]]
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Enfusion__ ${SFML_LIBRARIES})
endif()