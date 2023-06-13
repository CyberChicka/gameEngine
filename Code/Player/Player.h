#ifndef GAMEENGINE_PLAYER_H
#define GAMEENGINE_PLAYER_H
#include "../Entity.h"
#include "../Map/GameLvL.h"
#include "../ Animation/Animation.h"
#include "../Utils.h"


class Player: public Entity{
public:
    bool isAttack, isBlock, isSprint, isRun, isJump;
    int lvl_player;
    int SprintTime;
    char cell;
    enum class AnimationIndex{RunL, RunR,
            WalkingL, WalkingR,
            AttackL, AttackR,
            BlockL, BlockR,
            JumpL, JumpR,
            Count};
    Player(Sprite *sprite, GameLvL *LvL, float X, float Y, int W, int H, string Name);
    ~Player();
    FloatRect getRect()override;
    void move();
    void ControlMove();
    void update(float time);
    void draw(RenderWindow &window)override;
    void animation(float time)override;
    void initAnim()override;
    void checkCollisionMap(float dX, float dY)override;
    void setPosition(float x, float y);
    float GetX()override;
    float GetY()override;
private:
    Animation animations[int(AnimationIndex::Count)];
    AnimationIndex curAnimation = AnimationIndex::Count;
};


#endif
