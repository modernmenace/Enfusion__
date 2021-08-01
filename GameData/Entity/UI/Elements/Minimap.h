#ifndef ENFUSION___MINIMAP_H
#define ENFUSION___MINIMAP_H

#include "../../../Engine/Entity/Entity.h"
#include "../../../Engine/Component/Base/Position.h"
#include "../../../Engine/Component/Base/Sprite.h"
#include "../../../Engine/Lvl/Level.h"
#include "../../../Engine/Lvl/Tilemap.h"

class Minimap : public Entity {

public:
    Minimap(Entity* centerEntity, Level* level);
    void initialize()              override;
    void update(sf::Time)          override;
    void render(sf::RenderWindow*) override;

    inline void setTilemap(Tilemap* t) { m_tilemap = t; }

private:
    sf::View m_view;
    Entity*  m_center  = nullptr;
    Level*   m_level   = nullptr;
    Tilemap* m_tilemap = nullptr;

    Entity m_center_marker;
};


#endif //ENFUSION___MINIMAP_H
