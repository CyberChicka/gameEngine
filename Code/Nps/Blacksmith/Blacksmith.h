//
// Created by Doni on 28.06.2023.
//

#ifndef GAMEENGINE_BROUGHT_BLACKSMITH_H
#define GAMEENGINE_BROUGHT_BLACKSMITH_H


#include "../Nps.h"

class Blacksmith: public Nps{
public:
    Blacksmith(Sprite *sprite, GameLvL *LvL, CreateText T_NPS,  float X, float Y, int W, int H, string Name);
    ~Blacksmith();
    void animation(float time)override;
    void Dialogue(Event event, Player player)override;
    void initAnim()override;
    void update(float time, GameLvL *gLvL)override;
    void Interaction(Event event, Player &player);
};


#endif //GAMEENGINE_BROUGHT_BLACKSMITH_H
