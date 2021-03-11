#include "AnimatedSprite.h"
#include "../Base/Position.h"

//TODO: documentation
//TODO: generalize this as a animated character, maybe move some shared movement here

AnimatedSprite::AnimatedSprite(string_t spriteSheet, int numberFrames, sf::IntRect characterSheetSize)
{
    this->s_sheet           = spriteSheet;
    this->charRect          = characterSheetSize;
    this->directionalFrames = numberFrames;
}

AnimatedSprite::~AnimatedSprite()
{
    for(int i = 0; i < PROTAGONIST_LAYERS; i++)
    {
        auto *s = s_layerMap[static_cast<Layer_Type>(i)];
        if (s != nullptr)
            delete s;
    }
}

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

void AnimatedSprite::addLayer(string_t spriteSheet, Layer_Type type)
{
    if (s_layerMap.at(type) == nullptr)
    {
        //doesnt exist yet, add to map
        sf::Sprite* layer = new sf::Sprite(AssetManager::Instance()->getTexture(spriteSheet), charRect);
        layer->setPosition(entity->getComponent<Position>().getPosition());
        layer->setScale(3,3);
        s_layerMap.at(type) = layer;
    }
    else
    {
        //replace
        sf::Sprite* layer = s_layerMap.at(type);
        layer->setTexture(AssetManager::Instance()->getTexture(spriteSheet));
        layer->setTextureRect(charRect);
        layer->setScale(3, 3);
    }
    refreshState();
}

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

void AnimatedSprite::setPosition(sf::Vector2f pos)
{
    for(int i = 0; i < PROTAGONIST_LAYERS; i++)
    {
        auto* s = s_layerMap[static_cast<Layer_Type>(i)];
        if (s != nullptr)
            s_layerMap[static_cast<Layer_Type>(i)]->setPosition(pos);
    }
}

void AnimatedSprite::render(sf::RenderWindow *window)
{
    for(int i = 0; i < PROTAGONIST_LAYERS; i++)
    {
        auto* s = s_layerMap[static_cast<Layer_Type>(i)];
        if (s != nullptr)
            window->draw(*s_layerMap[static_cast<Layer_Type>(i)]);
    }
}

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