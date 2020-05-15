cmake_minimum_required(VERSION 3.12)
project(Enfusion__)

set(CMAKE_CXX_STANDARD 14)
if (APPLE)
    message("Compiling for MacOS")
endif (APPLE)
#set(CMAKE_BUILD_TYPE Release)

if (WIN32)
    message("Compiling for Windows")
    set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc")
    set(SFML_STATIC_LIBRARIES TRUE)
    set(SFML_DIR "${CMAKE_CURRENT_LIST_DIR}/SFML-2.5.1/lib/cmake/SFML")
    include_directories("C:\\Users\\Jared\\AppData\\Local\\Programs\\Python\\Python38-32\\include")
    set(CMAKE_LIBRARY_PATH "C:\\Users\\Jared\\AppData\\Local\\Programs\\Python\\Python38-32\\lib")
endif (WIN32)

find_package(PythonLibs 3.8.3 EXACT REQUIRED)

find_package(SFML 2.5.1 COMPONENTS graphics audio window system REQUIRED)
link_directories(${CMAKE_CURRENT_LIST_DIR}/lib)

include_directories(${SFML_INCLUDE_DIR})
add_executable(Enfusion__ main.cpp GameData/Game.cpp GameData/Game.h GameData/Engine/Core/Engine.h GameData/Engine/Core/AssetManager.cpp GameData/Engine/Core/AssetManager.h GameData/Engine/Lvl/Level.cpp GameData/Engine/Lvl/Level.h GameData/Data/Levels/Level_1/Level_1.cpp GameData/Data/Levels/Level_1/Level_1.h GameData/Engine/Lvl/LevelManager.cpp GameData/Engine/Lvl/LevelManager.h GameData/Engine/Entity/Entity.cpp GameData/Engine/Entity/Entity.h GameData/Entity/Player.cpp GameData/Entity/Player.h GameData/Engine/Component/Component.h GameData/Engine/Component/Base/Sprite.cpp GameData/Engine/Component/Base/Sprite.h GameData/Engine/Core/ComponentManager.h GameData/Engine/Component/Base/Position.h GameData/Engine/Component/Anim/AnimatedSprite.cpp GameData/Engine/Component/Anim/AnimatedSprite.h GameData/Engine/Component/Motion/AnimatedMovement.cpp GameData/Engine/Component/Motion/AnimatedMovement.h GameData/Engine/Lvl/Tilemap.cpp GameData/Engine/Lvl/Tilemap.h GameData/Engine/Component/Misc/Camera.cpp GameData/Engine/Component/Misc/Camera.h GameData/Entity/UI/Elements/TextDisplay.cpp GameData/Entity/UI/Elements/TextDisplay.h GameData/Entity/UI/Menus/Hotbar.cpp GameData/Entity/UI/Menus/Hotbar.h GameData/Component/Inventory.cpp GameData/Component/Inventory.h GameData/Entity/UI/Menus/InventoryMenu.cpp GameData/Entity/UI/Menus/InventoryMenu.h GameData/Engine/Item/Item.h GameData/Entity/UI/Elements/Slot.cpp GameData/Entity/UI/Elements/Slot.h GameData/Data/Items.h GameData/Engine/Item/ItemRegistry.h GameData/Entity/UI/Elements/Tooltip.cpp GameData/Entity/UI/Elements/Tooltip.h GameData/Entity/UI/Menus/PauseMenu.cpp GameData/Entity/UI/Menus/PauseMenu.h GameData/Entity/UI/Elements/Button.h GameData/Entity/UI/Menus/SettingsMenu.cpp GameData/Entity/UI/Menus/SettingsMenu.h GameData/Engine/Core/Settings.cpp GameData/Engine/Core/Settings.h GameData/Entity/UI/Elements/TickBox.h GameData/Entity/UI/Elements/DropBox.h GameData/Entity/UI/Menus/ControlsMenu.cpp GameData/Entity/UI/Menus/ControlsMenu.h GameData/Lvl/Biome.h GameData/Lvl/BiomeManager.cpp GameData/Lvl/BiomeManager.h GameData/Lvl/Biomes/Biome_Woodland.h GameData/Lvl/MapGenerator.cpp GameData/Lvl/MapGenerator.h GameData/Lvl/Biomes/Biome_Desert.h GameData/Entity/UI/Elements/Minimap.cpp GameData/Entity/UI/Elements/Minimap.h GameData/Engine/Component/Base/Position.cpp GameData/Entity/Level/ItemPickup.cpp GameData/Entity/Level/ItemPickup.h GameData/Engine/Component/Base/Collider.h GameData/Entity/UI/Elements/ScrollArea.cpp GameData/Entity/UI/Elements/ScrollArea.h GameData/Data/Controls.h GameData/Engine/ScriptEngine/ScriptEngine.c GameData/Engine/ScriptEngine/ScriptEngine.h)
target_include_directories(Enfusion__ PRIVATE ${PYTHON_INCLUDE_DIRS})
target_link_libraries(Enfusion__ sfml-graphics sfml-audio sfml-window sfml-system ${PYTHON_LIBRARIES})