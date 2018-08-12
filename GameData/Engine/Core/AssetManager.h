#ifndef ENFUSION_ASSETMANAGER_H
#define ENFUSION_ASSETMANAGER_H

#include <SFML/Graphics.hpp>
#include <map>
#include "Engine.h"

class AssetManager {

public:
    AssetManager();
    static sf::Texture& getTexture(std::string const& fileName);

private:
    std::map<std::string, sf::Texture> m_Textures;

    //AssetManager is a singleton, so only one instance can exist at a time
    //sInstance holds static pointer to the single instance
    static AssetManager* sInstance;
};


#endif //ENFUSION_ASSETMANAGER_H
