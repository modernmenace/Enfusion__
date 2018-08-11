#include "AssetManager.h"
#include "assert.h"

AssetManager* AssetManager::sInstance = nullptr;

AssetManager::AssetManager()
{
    assert(sInstance == nullptr);
    sInstance = this;
}

sf::Texture &AssetManager::getTexture(std::string const &fileName)
{
    auto &texMap = sInstance->m_Textures;

    //check if already loaded
    auto pairFound = texMap.find(fileName);

    //if yes, return the texture
    if (pairFound != texMap.end())
    {
        return pairFound->second;
    }
    else  // else load the texture and return it
    {
        // create an element in the texture map
        auto &texture = texMap[fileName];
        texture.loadFromFile(RESOURCE_PATH + fileName);
        return texture;
    }
}