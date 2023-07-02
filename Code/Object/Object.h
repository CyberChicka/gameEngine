
#ifndef GAMEENGINE_BROUGHT_OBJECT_H
#define GAMEENGINE_BROUGHT_OBJECT_H


#include <valarray>
#include "../Entity.h"
#include "../ Animation/Animation.h"

class Object: public Entity{
public:
    enum class AnimationIndex{ Walking };
    bool isTouch;
    Object(Sprite *sprite, GameLvL *LvL, float  X, float Y, int W, int H, string Name);
    ~Object();
    FloatRect getRect()override;
    void animation(float time)override;
    void initAnim()override;
    virtual void update(float time, GameLvL *gLvL) = 0;
    void draw(RenderWindow &window, View view)override;
    void checkCollisionMap(float dX, float dY)override;
    float GetX()override;
    float GetY()override;
    Animation animations[int(AnimationIndex::Walking)];
    AnimationIndex curAnimation = AnimationIndex::Walking;
};

#endif //GAMEENGINE_BROUGHT_OBJECT_H
