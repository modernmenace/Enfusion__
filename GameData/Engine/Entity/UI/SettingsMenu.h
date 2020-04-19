#ifndef ENFUSION___SETTINGSMENU_H
#define ENFUSION___SETTINGSMENU_H

#include "../Entity.h"
#include "../../Component/Base/Position.h"
#include "../../Component/Base/Sprite.h"
#include "../../../Engine/Core/Settings.h"

class SettingsMenu : Entity {

public:
    SettingsMenu();
    void initialize() override;
    void handleInput(sf::Mouse::Button) override;
    void handleInput(sf::Keyboard::Key) override;
    void render(sf::RenderWindow*)      override;

    void show();
    void hide();

private:
    bool s_active = false;

};


#endif //ENFUSION___SETTINGSMENU_H
