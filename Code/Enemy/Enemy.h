#ifndef GAMEENGINE_ENEMY_H
#define GAMEENGINE_ENEMY_H

#include "../Entity.h"
#include "../Map/GameLvL.h"
#include "../ Animation/Animation.h"
#include "../Player/Player.h"
#include "windows.h"

class Enemy: public Entity{
public:
    bool isAttack, isStop;
    float distance;
    int Time, timeAttack;
    GameLvL *gameLvL;
    enum class AnimationIndex{RunL, RunR,
            Walking, WalkingL, WalkingR,
            AttackL, AttackR,
            Boom, Count};
    Enemy(Sprite *sprite,GameLvL *LvL,  float X, float Y, int W, int H, string Name);
    ~Enemy();
    FloatRect getRect() override;
    virtual void ControlEnemy(float, float, float) = 0;
    void ControlMove();
    void move();
    virtual void update(float time, GameLvL *gLvL, Player *p) = 0;
    void animation(float time)override;
    void initAnim()override;
    virtual void Attack(Player &p) = 0;
    void TakingDamage(Player &p);
    void draw(RenderWindow &window, View view)override;
    void checkCollisionMap(float dX, float dY)override;
    void State();
    float GetX()override;
    float GetY()override;
    Animation animations[int(AnimationIndex::Count)];
    AnimationIndex curAnimation = AnimationIndex::Count;
};


#endif //GAMEENGINE_ENEMY_H
