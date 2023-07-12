//
// Created by Doni on 12.07.2023.
//

#ifndef GAMEENGINE_BROUGHT_ENEMY_MAG_H
#define GAMEENGINE_BROUGHT_ENEMY_MAG_H


#include "../Enemy.h"
#include "../../Object/Fon/FonGame.h"

class Enemy_Mag: public Enemy{
public:
    FonGame *sDamage;
    Enemy_Mag(Sprite *sprite, FonGame *Damage, GameLvL *LvL, float X, float Y, int W, int H, string Name);
    ~Enemy_Mag();
    void ControlEnemy(float , float , float )override;
    void update(float time, GameLvL *gLvL, Player *p)override;
    void animation(float time)override;
    void initAnim()override;
    void Attack(Player &p)override;
    void TakingDamage(Player &p)override;
    void draw(RenderWindow &window, View view)override;
};


#endif //GAMEENGINE_BROUGHT_ENEMY_MAG_H
