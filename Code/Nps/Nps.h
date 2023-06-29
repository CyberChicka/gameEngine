//
// Created by Doni on 28.06.2023.
//

#ifndef GAMEENGINE_BROUGHT_NPS_H
#define GAMEENGINE_BROUGHT_NPS_H


#include "../Entity.h"
#include "../ Animation/Animation.h"
#include "../Player/Player.h"
#include <sstream>
#include "NpsMessage/getNpsMessage.h"
#include "../Text/CreateText.h"

class Nps: public Entity{
public:
    int ClickNps = 0;
    CreateText *t_Nps;
    enum class AnimationIndex{ Walking };
    Nps(Sprite *sprite, GameLvL *LvL, CreateText T_NPS, float X, float Y, int W, int H, string Name);
    ~Nps();
    FloatRect getRect()override;
    void animation(float time)override;
    void initAnim()override;
    void update(float time);
    void draw(RenderWindow &window, View view)override;
    void checkCollisionMap(float dX, float dY)override;
    virtual void Dialogue(Event event, Player player) = 0;
    float GetX()override;
    float GetY()override;
    Animation animations[int(AnimationIndex::Walking)];
    AnimationIndex curAnimation = AnimationIndex::Walking;
};


#endif //GAMEENGINE_BROUGHT_NPS_H
