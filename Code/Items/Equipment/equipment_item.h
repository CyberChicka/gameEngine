//
// Created by Doni on 09.06.2023.
//

#ifndef GAMEENGINE_BROUGHT_EQUIPMENT_ITEM_H
#define GAMEENGINE_BROUGHT_EQUIPMENT_ITEM_H


#include "../Item.h"

class equipment_item: public Item{
public:
    equipment_item(Sprite *sprite, GameLvL *LvL, float X, float Y, int W, int H, string Name);
    ~equipment_item();
    bool isTake(Player &player);
    void initAnim() override;
    void animation(float time)override;
};


#endif //GAMEENGINE_BROUGHT_EQUIPMENT_ITEM_H
