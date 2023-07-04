//
// Created by Doni on 09.06.2023.
//

#ifndef GAMEENGINE_BROUGHT_MONEY_ITEM_H
#define GAMEENGINE_BROUGHT_MONEY_ITEM_H


#include "../Item.h"

class money_item: public Item{
public:
    money_item(Sprite *sprite, GameLvL *LvL, float X, float Y, int W, int H, string Name);
    ~money_item();
    bool isTake(Player &player)override;
    void initAnim() override;
    void animation(float time)override;
};


#endif //GAMEENGINE_BROUGHT_MONEY_ITEM_H
