
#ifndef GAMEENGINE_BROUGHT_CHEST_H
#define GAMEENGINE_BROUGHT_CHEST_H


#include "../Entity.h"
#include "../ Animation/Animation.h"

class Chest: public Entity{
public:
    enum class AnimationIndex{ WalkingClose, WalkingOpen, WalkingOpening, Count };
    Chest(Sprite *sprite, GameLvL *LvL, float X, float Y, int W, int H, string Name);
    ~Chest();
    FloatRect getRect()override;
    void animation(float time)override;
    void draw(RenderWindow &window, View view)override;
    void update(float time, GameLvL *gLvL);
    int OpenChest();
    void checkCollisionMap(float dX, float dY)override;
    float GetX()override;
    float GetY()override;
    void initAnim()override;
    Animation animations[int(AnimationIndex::Count)];
    AnimationIndex curAnimation = AnimationIndex::Count;
};

#endif //GAMEENGINE_BROUGHT_CHEST_H
