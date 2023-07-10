//
// Created by Doni on 28.06.2023.
//

#ifndef GAMEENGINE_BROUGHT_KNIGHT_H
#define GAMEENGINE_BROUGHT_KNIGHT_H


#include "../Nps.h"

class Knight: public Nps{
public:
    Knight(Sprite *sprite, GameLvL *LvL, CreateText *T_NPS,  float X, float Y, int W, int H, string Name);
    ~Knight();
    void animation(float time)override;
    void Dialogue(Event event, Player *player)override;
    void Interaction(Event event, Player &player)override;
    void initAnim()override;
};


#endif //GAMEENGINE_BROUGHT_KNIGHT_H
