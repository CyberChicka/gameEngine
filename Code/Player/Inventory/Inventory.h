//
// Created by Doni on 16.07.2023.
//

#ifndef GAMEENGINE_BROUGHT_INVENTORY_H
#define GAMEENGINE_BROUGHT_INVENTORY_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Player.h"
#include "../../Image/CreateImage.h"
#include "../../Text/CreateText.h"
#include <sstream>

class Inventory {
public:
    CreateImage *s_silverKey, *s_goldKey, *s_money, *s_backpack_inventory;
    CreateText *t_health, *t_lvl, *t_money, *t_gold_key, *t_silver_key;
    CreateImage *s_sword[5], *s_shield[5];
    Vector2f p_mouse;
    Vector2i l_position;
    bool isInvent;
    Sprite *s;
    Inventory(Sprite *sprite);
    ~Inventory();
    void update(Player *player);
    void position(View view);
    void draw(RenderWindow &window, Player *player, View view);
};


#endif //GAMEENGINE_BROUGHT_INVENTORY_H
