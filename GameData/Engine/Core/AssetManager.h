#ifndef ENFUSION_ASSETMANAGER_H
#define ENFUSION_ASSETMANAGER_H

#include <SFML/Graphics.hpp>
#include <map>
#include "Engine.h"

class AssetManager {

public:
    static AssetManager* Instance();
    sf::Texture& getTexture(std::string const& fileName);
    sf::Texture& getModTexture(const char *modDirectory, const std::string &fileName);

private:
    AssetManager() {};
    std::map<std::string, sf::Texture> m_Textures;

    //AssetManager is a singleton, so only one instance can exist at a time
    //sInstance holds static pointer to the single instance
    static AssetManager* m_Instance;
};


#endif //ENFUSION_ASSETMANAGER_H
