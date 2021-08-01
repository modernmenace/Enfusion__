#ifndef ENFUSION___SETTINGSMENU_H
#define ENFUSION___SETTINGSMENU_H

#include "../../../Engine/Entity/Entity.h"
#include "../../../Engine/Component/Base/Position.h"
#include "../../../Engine/Component/Base/Sprite.h"
#include "../../../Engine/Core/Settings.h"
#include "../Elements/Button.h"
#include "../Elements/TickBox.h"
#include "../Elements/DropBox.h"
#include "ControlsMenu.h"

class SettingsMenu : Entity {

public:
    SettingsMenu();
    void initialize() override;
    void handleInput(sf::Mouse::Button) override;
    void handleInput(sf::Keyboard::Key) override;
    void render(sf::RenderWindow*, uint8_t z) override;

    void show();
    void hide();
    inline bool active() { return s_active; }

private:
    bool s_active = false;

    Button applyButton;
    Button cancelButton;
    Button controlsButton;

    TextDisplay s_resolutionText;
    TextDisplay s_fullscreenText;
    TickBox     s_fsrnTickBox;
    DropBox     s_resDropBox;

    ControlsMenu c_menu;

};


#endif //ENFUSION___SETTINGSMENU_H
