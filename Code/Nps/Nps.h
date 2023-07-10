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
    int ClickNps;
    CreateText *t_Nps;
    enum class AnimationIndex{ Walking, Count };
    Nps(Sprite *sprite, GameLvL *LvL, CreateText *T_NPS, float X, float Y, int W, int H, string Name);
    ~Nps();
    FloatRect getRect()override;
    void animation(float time)override;
    void initAnim()override;
    void update(float time, GameLvL *gLvL);
    void draw(RenderWindow &window, View view)override;
    void checkCollisionMap(float dX, float dY)override;
    float GetX()override;
    float GetY()override;
    virtual void Dialogue(Event event, Player *player) = 0;
    virtual void Interaction(Event event, Player &player) = 0;
    Animation animations[int(AnimationIndex::Count)];
    AnimationIndex curAnimation = AnimationIndex::Count;
};


#endif //GAMEENGINE_BROUGHT_NPS_H
