#ifndef ENFUSION___Z_H
#define ENFUSION___Z_H

#include "../Component.h"

class Z : public Component {

public:
    explicit Z(uint8_t z = Z_BOTTOM);

    void setZ(uint8_t val);

    inline uint8_t z() const { return z_z; }

    static bool compare(Entity* left, Entity* right);

private:
    uint8_t z_z;

};


#endif //ENFUSION___Z_H
