#ifndef ENFUSION___CONTROLSMENU_H
#define ENFUSION___CONTROLSMENU_H

#include "../../Entity.h"
#include "../../../Component/Base/Position.h"
#include "../../../Component/Base/Sprite.h"
#include "../Elements/Button.h"

class ControlsMenu : Entity {

public:
    ControlsMenu(sf::Vector2f position);
    void initialize() override;
    void handleInput(sf::Mouse::Button) override;
    void render(sf::RenderWindow*)      override;

    void show();
    inline void hide()   { c_active = false; };
    inline bool active() { return c_active; }


private:
    bool c_active = false;

    Button applyButton;
    Button cancelButton;

};


#endif //ENFUSION___CONTROLSMENU_H
