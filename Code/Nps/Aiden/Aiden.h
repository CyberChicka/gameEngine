//
// Created by Doni on 28.06.2023.
//

#ifndef GAMEENGINE_BROUGHT_AIDEN_H
#define GAMEENGINE_BROUGHT_AIDEN_H


#include "../Nps.h"

class Aiden: public Nps{
    Aiden(Sprite *sprite, GameLvL *LvL, float X, float Y, int W, int H, string Name);
    ~Aiden();
    void animation(float time)override;
    void Dialogue(Event event, Player player)override;
    void initAnim()override;
    void update(float time);
};


#endif //GAMEENGINE_BROUGHT_AIDEN_H
