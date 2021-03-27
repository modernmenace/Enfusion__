#ifndef ENFUSION___DEADTREE_H
#define ENFUSION___DEADTREE_H

#include "../StaticMapObject.h"

class DeadTree : public StaticMapObject
{

public:
    DeadTree() : StaticMapObject("Levels/desert.png", sf::IntRect(0, 304, 32, 48))
    {

    };

    void setPosition(Tile& tile) override
    {
        StaticMapObject::setPosition(tile);

        //1,1 and 1,2 blocked
        for(int i = 0; i < o_tiles.width; i++)
        {
            for(int j = 0; j < o_tiles.height; j++)
            {
                dbg_log(i << ", " << j)
                if ((i == 1 && j == 1) || (i == 1 && j == 2))
                {
                    dbg_log("HIT")
                    //todo: magic numbers
                    //todo: same as lvl_struct
                    //todo: this override is not getting called
                    //todo: possible issue, cast to StaticMapObject in MapGenerator
                    uint32_t tile = o_tiles.left + i + (j * 250);
                    MapGenerator::Instance()->map()->m_tiles[tile].blocked = true;
                }
            }
        }
    }
};

#endif //ENFUSION___DEADTREE_H
