#include "AssetManager.h"
#include "assert.h"

/*
 *  Asset Manager
 *
 *  DESC: Handles the loading of textures, ensuring that a texture is
 *        only loaded one time
 *
 *  NOTE: There can only be one instance of Asset Manager at one time
 *
 */

AssetManager* AssetManager::sInstance = nullptr;

AssetManager::AssetManager()
{
    assert(sInstance == nullptr);
    sInstance = this;
}

/*
 *  Get Texture
 *
 *  DESC: Takes the file name of the desired texture, and checks
 *        to see if the texture has already been loaded and stored.
 *
 *        If the texture is contained already pass a reference,
 *        otherwise load and store it
 *
 */

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