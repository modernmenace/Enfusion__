cmake_minimum_required(VERSION 3.12)
project(Enfusion__)

set(CMAKE_CXX_STANDARD 14)

add_executable(Enfusion__ main.cpp GameData/Game.cpp GameData/Game.h GameData/Core/Engine.h GameData/Core/AssetManager.cpp GameData/Core/AssetManager.h GameData/Levels/Level.cpp GameData/Levels/Level.h GameData/Levels/Level_1/Level_1.cpp GameData/Levels/Level_1/Level_1.h GameData/Levels/LevelManager.cpp GameData/Levels/LevelManager.h GameData/Objects/GameObject.cpp GameData/Objects/GameObject.h GameData/Objects/Player.cpp GameData/Objects/Player.h GameData/AI/Agent.cpp GameData/AI/Agent.h GameData/Anim/Animator.cpp GameData/Anim/Animator.h)

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