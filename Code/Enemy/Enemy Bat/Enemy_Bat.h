//
// Created by Doni on 12.07.2023.
//

#ifndef GAMEENGINE_BROUGHT_ENEMY_BAT_H
#define GAMEENGINE_BROUGHT_ENEMY_BAT_H


#include "../Enemy.h"

class Enemy_Bat: public Enemy {
public:
    Enemy_Bat(Sprite *sprite, GameLvL *LvL, float X, float Y, int W, int H, string Name);
    ~Enemy_Bat();
    void ControlEnemy(float , float , float )override;
    void update(float time, GameLvL *gLvL, Player *p)override;
    void animation(float time)override;
    void initAnim()override;
    void Attack(Player &p)override;
    void TakingDamage(Player &p)override;
    void checkCollisionMap(float dX, float dY)override;
};


#endif //GAMEENGINE_BROUGHT_ENEMY_BAT_H