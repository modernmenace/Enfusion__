#include "Z.h"
#include "../../Lvl/LevelManager.h"

Z::Z(uint8_t z)
{
    z_z = z;
}

void Z::setZ(uint8_t val)
{
    z_z = val;
    LevelManager::Instance()->getCurrentLevel().sortZOrder();
}

bool Z::compare(Entity* left, Entity* right)
{
    return left->getComponent<Z>().z() < right->getComponent<Z>().z();
}