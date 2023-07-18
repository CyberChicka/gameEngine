#ifndef GAMEENGINE_ENEMY_SCELET_H
#define GAMEENGINE_ENEMY_SCELET_H

#include "../Enemy.h"

class Enemy_Skeleton: public Enemy{
public:
public:
    Enemy_Skeleton(Sprite *sprite, GameLvL *LvL, float X, float Y, int W, int H, string Name);
    ~Enemy_Skeleton();
    FloatRect getRect();
    void ControlMove();
    void move();
    void update(float time, GameLvL *gLvL, Player *p)override;
    void animation(float time)override;
    void Attack(Player &p)override;
    //void TakingDamage(Player &p)override;
    void initAnim()override;
    void draw(RenderWindow &window, View view)override;
    void checkCollisionMap(float dX, float dY)override;
    float GetX()override;
    float GetY()override;
};


#endif
