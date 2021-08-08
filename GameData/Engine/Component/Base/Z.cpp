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

bool Z::compare(const Entity* left, const Entity* right)
{
    //TODO: this assertion is failing... why???
    //TODO: how many times is sortZInternal being called?
    //TODO: possible it is being overloaded with several calls per update?
    //TODO: debug and pay attention and see if you notice ocmmonalities
    //TODO: like left always being the NULL one
    assert(left != nullptr);
    assert(right != nullptr);

    if (!left->hasComponent<Z>())
        if (right->hasComponent<Z>())
            return false;
    if (!right->hasComponent<Z>())
        return true; // prevent reaching below code if none have it

    return right->getComponent<Z>().z() != 0;
}