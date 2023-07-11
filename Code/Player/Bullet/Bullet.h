

#ifndef GAMEENGINE_BROUGHT_BULLET_H
#define GAMEENGINE_BROUGHT_BULLET_H


#include "../../Entity.h"
#include "../../ Animation/Animation.h"

class Bullet: public Entity{
public:
    enum class AnimationIndex{ShootR, ShootL, Count};
    int direction;
    Bullet(Sprite *sprite, GameLvL *LvL, float X, float Y, int W, int H, string Name, int Dir);
    ~Bullet();
    void upadte(float time);
    FloatRect getRect()override;
    void animation(float time)override;
    void initAnim()override;
    void draw(RenderWindow &window, View view)override;
    void checkCollisionMap(float dX, float dY)override;
    float GetX()override;
    float GetY()override;
    Animation animations[int(AnimationIndex::Count)];
    AnimationIndex curAnimation = AnimationIndex::Count;
};


#endif //GAMEENGINE_BROUGHT_BULLET_H
