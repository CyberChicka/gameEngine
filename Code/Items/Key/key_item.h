//
// Created by Doni on 09.06.2023.
//

#ifndef GAMEENGINE_BROUGHT_KEY_ITEM_H
#define GAMEENGINE_BROUGHT_KEY_ITEM_H


#include "../Item.h"

class key_item: public Item {
public:
    key_item(Sprite *sprite, GameLvL *LvL, float X, float Y, int W, int H, string Name);
    ~key_item();
    bool isTake(Player &player)override;
    void initAnim() override;
    void animation(float time)override;
};


#endif //GAMEENGINE_BROUGHT_KEY_ITEM_H
