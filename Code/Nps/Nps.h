//
// Created by Doni on 28.06.2023.
//

#ifndef GAMEENGINE_BROUGHT_NPS_H
#define GAMEENGINE_BROUGHT_NPS_H


#include "../Entity.h"
#include "../ Animation/Animation.h"

class Nps: public Entity{
public:
    enum class AnimationIndex{ Walking };
    Nps(Sprite *sprite, GameLvL *LvL, float X, float Y, int W, int H, string Name);
    ~Nps();
    FloatRect getRect()override;
    void animation(float time)override;
    void initAnim()override;
    void update(float time);
    void draw(RenderWindow &window, View view)override;
    void checkCollisionMap(float dX, float dY)override;
    float GetX()override;
    float GetY()override;
    Animation animations[int(AnimationIndex::Walking)];
    AnimationIndex curAnimation = AnimationIndex::Walking;
};


#endif //GAMEENGINE_BROUGHT_NPS_H
