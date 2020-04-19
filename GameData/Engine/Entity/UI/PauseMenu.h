#ifndef ENFUSION___PAUSEMENU_H
#define ENFUSION___PAUSEMENU_H

#include "../Entity.h"
#include "../../Component/Base/Position.h"
#include "../../Component/Base/Sprite.h"
#include "Button.h"

class PauseMenu : public Entity {

public:
    PauseMenu();
    void initialize() override;
    void handleInput(sf::Mouse::Button)     override;
    void render(sf::RenderWindow* window)   override;

    void toggleMenu();

    inline bool active() { return p_active; }

private:
    bool   p_active = false;
    Button p_b_resume;
};


#endif //ENFUSION___PAUSEMENU_H
