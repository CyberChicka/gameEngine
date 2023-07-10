//
// Created by Doni on 28.06.2023.
//

#ifndef GAMEENGINE_BROUGHT_SWORDSMAN_H
#define GAMEENGINE_BROUGHT_SWORDSMAN_H


#include "../Nps.h"

class Swordsman: public Nps{
public:
    Swordsman(Sprite *sprite, GameLvL *LvL, CreateText *T_NPS,  float X, float Y, int W, int H, string Name);
    ~Swordsman();
    void animation(float time)override;
    void Dialogue(Event event, Player *player)override;
    void initAnim()override;
    void Interaction(Event event, Player &player)override;
};


#endif //GAMEENGINE_BROUGHT_SWORDSMAN_H
