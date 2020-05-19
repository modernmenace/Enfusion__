#ifndef ENFUSION___QUESTDISPLAY_H
#define ENFUSION___QUESTDISPLAY_H

#include "../../../Engine/Entity/Entity.h"
#include "TextDisplay.h"

class QuestDisplay : public Entity {

public:
    QuestDisplay();
    void initialize() override;
    void render(sf::RenderWindow*) override;


private:
    TextDisplay q_title;
    Entity      q_dropBox;

};


#endif //ENFUSION___QUESTDISPLAY_H
