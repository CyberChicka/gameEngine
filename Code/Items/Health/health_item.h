//
// Created by Doni on 09.06.2023.
//

#ifndef GAMEENGINE_BROUGHT_HEALTH_ITEM_H
#define GAMEENGINE_BROUGHT_HEALTH_ITEM_H


#include "../Item.h"

class health_item: public Item{
public:
    health_item(Sprite *sprite, GameLvL *LvL, float X, float Y, int W, int H, string Name);
    ~health_item();
    bool isTake(Player &player)override;
    void initAnim()override;
    void animation(float time)override;
};


#endif //GAMEENGINE_BROUGHT_HEALTH_ITEM_H
