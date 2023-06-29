//
// Created by Doni on 28.06.2023.
//

#ifndef GAMEENGINE_BROUGHT_SOOTHSAYER_H
#define GAMEENGINE_BROUGHT_SOOTHSAYER_H


#include "../Nps.h"

class Soothsayer: public Nps{
public:
    Soothsayer(Sprite *sprite, GameLvL *LvL, CreateText T_NPS,  float X, float Y, int W, int H, string Name);
    ~Soothsayer();
    void animation(float time)override;
    void Dialogue(Event event, Player player)override;
    void initAnim()override;
    void update(float time);
};


#endif //GAMEENGINE_BROUGHT_SOOTHSAYER_H
