#ifndef GAMEENGINE_BROUGHT_GUI_PLAYER_H
#define GAMEENGINE_BROUGHT_GUI_PLAYER_H

#include "../LifeBar/LifeBar.h"
#include "../Inventory/Inventory.h"

class GUI_player {
public:
    bool GUI_visible;
    LifeBar *GUI_life;
    Inventory *GUI_invent;
    Sprite *s_health, *s_inventory, *s_features;
    GUI_player(Sprite *S_Health, Sprite *S_Inventory, Sprite *S_Features);
    ~GUI_player();
    void GUI_update(Player *player);
    void GUI_draw(RenderWindow &window);
};


#endif //GAMEENGINE_BROUGHT_GUI_PLAYER_H
