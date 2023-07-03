//
// Created by Doni on 28.06.2023.
//

#ifndef GAMEENGINE_BROUGHT_SUPREME_WIZARD_H
#define GAMEENGINE_BROUGHT_SUPREME_WIZARD_H


#include "../Nps.h"

class Supreme_Wizard: public Nps{
public:
    Supreme_Wizard(Sprite *sprite, GameLvL *LvL, CreateText *T_NPS,  float X, float Y, int W, int H, string Name);
    ~Supreme_Wizard();
    void animation(float time)override;
    void Dialogue(Event event, Player player)override;
    void initAnim()override;
};


#endif //GAMEENGINE_BROUGHT_SUPREME_WIZARD_H
