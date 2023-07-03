//
// Created by Doni on 28.06.2023.
//

#ifndef GAMEENGINE_BROUGHT_AIDEN_H
#define GAMEENGINE_BROUGHT_AIDEN_H


#include "../Nps.h"

class Aiden: public Nps{
public:
    Aiden(Sprite *sprite, GameLvL *LvL, CreateText *T_NPS,  float X, float Y, int W, int H, string Name);
    ~Aiden();
//    FloatRect getRect()override;
    void animation(float time)override;
    void initAnim()override;
    void Dialogue(Event event, Player player)override;
    Animation animations[int(AnimationIndex::Count)];
    AnimationIndex curAnimation = AnimationIndex::Count;
};


#endif //GAMEENGINE_BROUGHT_AIDEN_H
