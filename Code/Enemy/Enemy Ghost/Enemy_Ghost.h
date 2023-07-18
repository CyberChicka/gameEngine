//
// Created by Doni on 15.05.2023.
//

#ifndef GAMEENGINE_ENEMY_GHOST_H
#define GAMEENGINE_ENEMY_GHOST_H

#include "../../Map/GameLvL.h"
#include "../Enemy.h"

class Enemy_Ghost: public Enemy{
public:
    Enemy_Ghost(Sprite *sprite, GameLvL *LvL, float X, float Y, int W, int H, string Name);
    ~Enemy_Ghost();
    void ControlEnemy(float , float , float )override;
    void update(float time, GameLvL *gLvL, Player *p)override;
    void animation(float time)override;
    void initAnim()override;
    void Attack(Player &p)override;
    //void TakingDamage(Player &p)override;
};


#endif //GAMEENGINE_ENEMY_GHOST_H
