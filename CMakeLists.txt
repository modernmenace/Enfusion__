cmake_minimum_required(VERSION 3.12)
project(Enfusion__)

set(CMAKE_CXX_STANDARD 14)

if (WIN32)
    set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc")
    set(SFML_STATIC_LIBRARIES TRUE)
    set(SFML_DIR "${CMAKE_CURRENT_LIST_DIR}/SFML-2.5.1/lib/cmake/SFML")
endif (WIN32)

find_package(SFML 2.5.1 COMPONENTS graphics audio window system REQUIRED)
link_directories(${CMAKE_CURRENT_LIST_DIR}/lib)

include_directories(${SFML_INCLUDE_DIR})
add_executable(Enfusion__ main.cpp GameData/Game.cpp GameData/Game.h GameData/Engine/Core/Engine.h GameData/Engine/Core/AssetManager.cpp GameData/Engine/Core/AssetManager.h GameData/Engine/Lvl/Level.cpp GameData/Engine/Lvl/Level.h GameData/Levels/Level_1/Level_1.cpp GameData/Levels/Level_1/Level_1.h GameData/Engine/Lvl/LevelManager.cpp GameData/Engine/Lvl/LevelManager.h GameData/Engine/Entity/Entity.cpp GameData/Engine/Entity/Entity.h GameData/Engine/Entity/Player.cpp GameData/Engine/Entity/Player.h GameData/Engine/AI/Agent.cpp GameData/Engine/AI/Agent.h GameData/Engine/Component/Component.h GameData/Engine/Component/Base/Sprite.cpp GameData/Engine/Component/Base/Sprite.h GameData/Engine/Core/ComponentManager.h GameData/Engine/Component/Base/Position.h GameData/Engine/Component/Anim/AnimatedSprite.cpp GameData/Engine/Component/Anim/AnimatedSprite.h GameData/Engine/Component/Motion/AnimatedMovement.cpp GameData/Engine/Component/Motion/AnimatedMovement.h GameData/Engine/Lvl/Tilemap.cpp GameData/Engine/Lvl/Tilemap.h GameData/Engine/Component/Misc/Camera.cpp GameData/Engine/Component/Misc/Camera.h GameData/Engine/Entity/UI/TextDisplay.cpp GameData/Engine/Entity/UI/TextDisplay.h GameData/Engine/Entity/UI/Hotbar.cpp GameData/Engine/Entity/UI/Hotbar.h GameData/Engine/Component/Misc/Inventory.cpp GameData/Engine/Component/Misc/Inventory.h GameData/Engine/Entity/UI/InventoryMenu.cpp GameData/Engine/Entity/UI/InventoryMenu.h GameData/Engine/Misc/Item.h GameData/Engine/Entity/UI/Slot.cpp GameData/Engine/Entity/UI/Slot.h GameData/Data/Items.h GameData/Engine/Misc/ItemRegistry.h GameData/Engine/Entity/UI/Tooltip.cpp GameData/Engine/Entity/UI/Tooltip.h GameData/Engine/Entity/UI/PauseMenu.cpp GameData/Engine/Entity/UI/PauseMenu.h)
target_link_libraries(Enfusion__ sfml-graphics sfml-audio sfml-window sfml-system)
