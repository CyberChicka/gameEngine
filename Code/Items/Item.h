#ifndef GAMEENGINE_BROUGHT_ITEM_H
#define GAMEENGINE_BROUGHT_ITEM_H


#include "../Entity.h"
#include "../Player/Player.h"

class Item: public Entity{
public:
    enum class AnimationIndex{ Walking, Count};
    Item(Sprite *sprite, GameLvL *LvL, float X, float Y, int W, int H, string Name);
    ~Item();
    FloatRect getRect()override;
    void animation(float time)override;
    void initAnim()override;
    virtual bool isTake(Player &player) = 0;
    void update(float time, GameLvL *gLvL);
    void draw(RenderWindow &window, View view)override;
    void checkCollisionMap(float dX, float dY)override;
    float GetX()override;
    float GetY()override;
    Animation animations[int(AnimationIndex::Count)];
    AnimationIndex curAnimation = AnimationIndex::Count;
};


#endif //GAMEENGINE_BROUGHT_ITEM_H
