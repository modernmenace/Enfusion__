#ifndef ENFUSION___PAUSEMENU_H
#define ENFUSION___PAUSEMENU_H

#include "../../../Engine/Entity/Entity.h"
#include "../Elements/Button.h"
#include "SettingsMenu.h"

class PauseMenu : public Entity {

public:
    PauseMenu();
    void initialize() override;
    void handleInput(sf::Mouse::Button)     override;
    void handleInput(sf::Keyboard::Key)     override;
    void render(sf::RenderWindow* window)   override;

    void toggleMenu();

    inline bool active() { return p_active; }

private:
    bool   p_active = false;
    Button p_b_resume;
    Button p_b_settings;
    Button p_b_exit;

    SettingsMenu s_menu;

};


#endif //ENFUSION___PAUSEMENU_H
