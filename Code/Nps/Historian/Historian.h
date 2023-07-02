//
// Created by Doni on 28.06.2023.
//

#ifndef GAMEENGINE_BROUGHT_HISTORIAN_H
#define GAMEENGINE_BROUGHT_HISTORIAN_H


#include "../Nps.h"

class Historian: public Nps{
public:
    Historian(Sprite *sprite, GameLvL *LvL, CreateText T_NPS,  float X, float Y, int W, int H, string Name);
    ~Historian();
    void animation(float time)override;
    void Dialogue(Event event, Player player)override;
    void initAnim()override;
    void update(float time, GameLvL *gLvL)override;
};


#endif //GAMEENGINE_BROUGHT_HISTORIAN_H
