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
    CreateImage *inSilverKey, *inGoldKey, *inMoney, *inBackpackInventory;
    CreateText *t_health, *t_lvl, *t_money, *t_gold_key, *t_silver_key;
    bool isInvent;
    Sprite *s;
    Inventory(Sprite *sprite);
    ~Inventory();
    void update(Player *player);
    void position(View view);
    void draw(RenderWindow &window, View view);
};


#endif //GAMEENGINE_BROUGHT_INVENTORY_H
