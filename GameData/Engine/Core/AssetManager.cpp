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

AssetManager* AssetManager::m_Instance = nullptr;

AssetManager* AssetManager::Instance()
{
    if (m_Instance == nullptr)
        m_Instance = new AssetManager();

    return m_Instance;
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
    assert(m_Instance != nullptr);
    auto &texMap = m_Instance->m_Textures;

    auto pairFound = texMap.find(fileName);

    if (pairFound != texMap.end())
    {
        return pairFound->second;
    }
    else
    {
        auto &texture = texMap[fileName];
        texture.loadFromFile(RESOURCE_PATH + fileName);
        return texture;
    }
}