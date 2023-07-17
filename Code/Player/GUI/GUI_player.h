#ifndef GAMEENGINE_BROUGHT_GUI_PLAYER_H
#define GAMEENGINE_BROUGHT_GUI_PLAYER_H

#include "../LifeBar/LifeBar.h"
#include "../Inventory/Inventory.h"
#include "../Features/Features.h"

class GUI_player {
public:
    bool GUI_visible;
    LifeBar *GUI_life;
    Inventory *GUI_invent;
    Features *GUI_features;
    CreateImage *s_health, *s_inventory, *s_features;
    GUI_player();
    ~GUI_player();
    void GUI_update(Player *player);
    void GUI_draw(RenderWindow &window, View view);
};


#endif //GAMEENGINE_BROUGHT_GUI_PLAYER_H
