#ifndef ENFUSION___Z_H
#define ENFUSION___Z_H

#include "../../Lvl/LevelManager.h"
#include "../Component.h"

class Z : public Component {

public:
    Z(uint8_t z = Z_BOTTOM)
    {
        z_z = z;
    }

    void setZ(uint8_t val)
    {
        z_z = val;
        LevelManager::Instance()->getCurrentLevel().sortZOrder();
    }

    inline uint8_t z() const { return z_z; }

private:
    uint8_t z_z;

};


#endif //ENFUSION___Z_H
