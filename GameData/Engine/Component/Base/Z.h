#ifndef ENFUSION___Z_H
#define ENFUSION___Z_H

#include "../Component.h"

class Z : public Component {

public:
    Z(uint8_t z = Z_BOTTOM)
    {
        z_z = z;
    }

    inline void    setZ(uint8_t val) { z_z = val; }
    inline uint8_t z() const         { return z_z; }

private:
    uint8_t z_z;

};


#endif //ENFUSION___Z_H
