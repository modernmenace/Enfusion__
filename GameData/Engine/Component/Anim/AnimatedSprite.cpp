#include "AnimatedSprite.h"
#include "../Base/Position.h"

/************************************************************************
 * FUNCTION :       AnimatedSprite::AnimatedSprite
 *
 * DESCRIPTION :
 *       AnimatedSprite is used for animated character sprites currently
 *
 *  INPUTS:  string_t spriteSheet           | Spritesheet file name
 *           int numberFrames               | Number of frames per direction
 *           sf::IntRect characterSheetSize | Size of the character sheet
 *
 *  OUTPUTS: NONE
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2021.03.12 	    JCB     Documentation Start
 *
 ************************************************************************/

AnimatedSprite::AnimatedSprite(string_t spriteSheet, int numberFrames, sf::IntRect characterSheetSize) : s_scale(3, 3)
{
    this->s_sheet           = spriteSheet;
    this->charRect          = characterSheetSize;
    this->directionalFrames = numberFrames;
}

/************************************************************************
 * FUNCTION :       AnimatedSprite::~AnimatedSprite
 *
 * DESCRIPTION :
 *       Destructor, free manually allocated memory
 *
 *  INPUTS:  NONE
 *
 *  OUTPUTS: NONE
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2021.03.12 	    JCB     Documentation Start
 *
 ************************************************************************/

AnimatedSprite::~AnimatedSprite()
{
    for(int i = 0; i < PROTAGONIST_LAYERS; i++)
    {
        auto *s = s_layerMap[static_cast<Layer_Type>(i)];
        if (s != nullptr)
            delete s;
    }
}

/************************************************************************
 * FUNCTION :       AnimatedSprite::initialize
 *
 * DESCRIPTION :
 *       Initialize components and layers, set initial state
 *
 *  INPUTS:  NONE
 *
 *  OUTPUTS: NONE
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2021.03.12 	    JCB     Documentation Start
 *
 ************************************************************************/

void AnimatedSprite::initialize()
{
    assert(entity->hasComponent<Position>());
    for(int i = 0; i < PROTAGONIST_LAYERS; i++)
        s_layerMap.insert(std::make_pair(static_cast<Layer_Type>(i), nullptr));

    sf::Sprite* base = new sf::Sprite(AssetManager::Instance()->getTexture(s_sheet), charRect);
    base->setPosition(entity->getComponent<Position>().getPosition());
    base->setScale(3,3);
    s_layerMap.at(Layer_Type_BASE) = base;

    switchState(0, 0);
}

/************************************************************************
 * FUNCTION :       AnimatedSprite::setScale
 *
 * DESCRIPTION :
 *       Set the scale for all layers
 *
 *  INPUTS:  NONE
 *
 *  OUTPUTS: NONE
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2021.03.14 	    JCB     Documentation Start
 *
 ************************************************************************/

void AnimatedSprite::setScale(sf::Vector2f scale)
{
    s_scale = scale;
    for(int i = 0; i < PROTAGONIST_LAYERS; i++)
    {
        auto* s = s_layerMap[static_cast<Layer_Type>(i)];
        if (s != nullptr)
            s_layerMap[static_cast<Layer_Type>(i)]->setScale(scale);
    }
}

sf::IntRect AnimatedSprite::bounds()
{
    //todo: return bounds for all layers

    return charRect;
}

/************************************************************************
 * FUNCTION :       AnimatedSprite::addLayer
 *
 * DESCRIPTION :
 *       Add or override the specified visual layer
 *
 *  INPUTS:  string_t spriteSheet | Spritesheet file name for the layer
 *           Layer_Type type      | Layer type to add/override
 *
 *  OUTPUTS: NONE
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2021.03.12 	    JCB     Documentation Start
 *
 ************************************************************************/

void AnimatedSprite::addLayer(string_t spriteSheet, Layer_Type type)
{
    if (s_layerMap.at(type) == nullptr)
    {
        //doesnt exist yet, add to map
        sf::Sprite* layer = new sf::Sprite(AssetManager::Instance()->getTexture(spriteSheet), charRect);
        layer->setPosition(entity->getComponent<Position>().getPosition());
        layer->setScale(s_scale);
        s_layerMap.at(type) = layer;
    }
    else
    {
        //replace
        sf::Sprite* layer = s_layerMap.at(type);
        layer->setTexture(AssetManager::Instance()->getTexture(spriteSheet));
        layer->setTextureRect(charRect);
        layer->setScale(s_scale);
    }
    refreshState();
}

/************************************************************************
 * FUNCTION :       AnimatedSprite::removeLayer
 *
 * DESCRIPTION :
 *       Remove the specified visual layer
 *
 *  INPUTS:  Layer_Type type | Layer type to be removed
 *
 *  OUTPUTS: NONE
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2021.03.12 	    JCB     Documentation Start
 *
 ************************************************************************/

void AnimatedSprite::removeLayer(Layer_Type type)
{
    auto *s = s_layerMap[type];
    if (s != nullptr)
    {
        delete s;
        s_layerMap[type] = nullptr;
    }
    refreshState();
}

/************************************************************************
 * FUNCTION :       AnimatedSprite::setPosition
 *
 * DESCRIPTION :
 *       Set the sprites position (for all layers)
 *
 *  INPUTS:  sf::Vector2f pos | The new position
 *
 *  OUTPUTS: NONE
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2021.03.12 	    JCB     Documentation Start
 *
 ************************************************************************/

void AnimatedSprite::setPosition(sf::Vector2f pos)
{
    for(int i = 0; i < PROTAGONIST_LAYERS; i++)
    {
        auto* s = s_layerMap[static_cast<Layer_Type>(i)];
        if (s != nullptr)
            s_layerMap[static_cast<Layer_Type>(i)]->setPosition(pos);
    }
}

/************************************************************************
 * FUNCTION :       AnimatedSprite::render
 *
 * DESCRIPTION :
 *       Render all layers of the sprite to the window
 *
 *  INPUTS:  sf::RenderWindow *window | Window to render to
 *
 *  OUTPUTS: NONE
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2021.03.12 	    JCB     Documentation Start
 *
 ************************************************************************/

void AnimatedSprite::render(sf::RenderWindow *window)
{
    for(int i = 0; i < PROTAGONIST_LAYERS; i++)
    {
        auto* s = s_layerMap[static_cast<Layer_Type>(i)];
        if (s != nullptr)
            window->draw(*s_layerMap[static_cast<Layer_Type>(i)]);
    }
}

/************************************************************************
 * FUNCTION :       AnimatedSprite::switchState
 *
 * DESCRIPTION :
 *       Switch the current frame state for all layers
 *
 *  INPUTS:  uint8_t row   | The current state's row
 *           uint8_t frame | The current state's frame
 *
 *  OUTPUTS: NONE
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2021.03.12 	    JCB     Documentation Start
 *
 ************************************************************************/

void AnimatedSprite::switchState(uint8_t row, uint8_t frame)
{
    if (row > 4)                   row = 4;
    if (frame > directionalFrames) frame = directionalFrames;

    sf::IntRect texRect;
    texRect.height = charRect.height / 4;
    texRect.width  = charRect.width / directionalFrames;

    texRect.top  = (texRect.height * row);
    texRect.left = (texRect.width * frame);

    for(int i = 0; i < PROTAGONIST_LAYERS; i++)
    {
        auto* s = s_layerMap[static_cast<Layer_Type>(i)];
        if (s != nullptr)
            s->setTextureRect(texRect);
    }

    s_currentState_frame = frame;
    s_currentState_row   = row;
}