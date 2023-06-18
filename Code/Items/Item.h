#ifndef GAMEENGINE_BROUGHT_ITEM_H
#define GAMEENGINE_BROUGHT_ITEM_H


#include "../Entity.h"
#include "../Player/Player.h"

class Item : public Entity{
    Item(Sprite *sprite, GameLvL *LvL, float X, float Y, int W, int H, string Name);
    ~Item();
    void animation(float time)override;
    bool isTake(Player &player);
    void update(float time);
    void draw(RenderWindow &window, View view)override;
    void checkCollisionMap(float dX, float dY)override;
    float GetX()override;
    float GetY()override;
};


#endif //GAMEENGINE_BROUGHT_ITEM_H
