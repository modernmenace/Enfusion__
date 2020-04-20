#ifndef ENFUSION___SETTINGSMENU_H
#define ENFUSION___SETTINGSMENU_H

#include "../../Entity.h"
#include "../../../Component/Base/Position.h"
#include "../../../Component/Base/Sprite.h"
#include "../../../Core/Settings.h"
#include "../Elements/Button.h"
#include "../Elements/TickBox.h"
#include "../Elements/DropBox.h"

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

    Button applyButton;
    Button cancelButton;
    Button controlsButton;

    TextDisplay s_resolutionText;
    TextDisplay s_fullscreenText;
    TickBox     s_fsrnTickBox;
    DropBox     s_resDropBox;
    TextDisplay s_resText;

};


#endif //ENFUSION___SETTINGSMENU_H
