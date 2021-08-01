#ifndef ENFUSION___CONTROLSMENU_H
#define ENFUSION___CONTROLSMENU_H

#include "../../../Engine/Entity/Entity.h"
#include "../../../Engine/Component/Base/Position.h"
#include "../../../Engine/Component/Base/Sprite.h"
#include "../Elements/Button.h"
#include "../Elements/ScrollArea.h"

class ControlsMenu : Entity {

public:
    ControlsMenu(sf::Vector2f position);
    void initialize() override;
    void handleInput(sf::Keyboard::Key) override;
    void handleInput(sf::Mouse::Button) override;
    void render(sf::RenderWindow*, uint8_t z = 0) override;

    void show();
    inline void hide()   { c_active = false; };
    inline bool active() { return c_active; }


private:
    bool c_active = false;

    Button applyButton;
    Button cancelButton;

    ScrollArea c_Area;

};


#endif //ENFUSION___CONTROLSMENU_H
