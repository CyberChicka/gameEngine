#ifndef GAMEENGINE_PLAYER_H
#define GAMEENGINE_PLAYER_H
#include "../Entity.h"
#include "../Map/GameLvL.h"
#include "../ Animation/Animation.h"
#include "../Particle/ParticleSystem.h"
#include "../Image/CreateImage.h"

class Player: public Entity{
public:
    CreateImage *s_player[5];
    bool isAttack, isBlock, isSprint, isShoot, isRun, isInventory;
    bool sword[5] = {false, true, false, false, false};
    bool shield[5] = {false, true, false, false, false};
    bool equipment[5] = {false, true, false, false, false};
    int lvl_player, sprint_time, bullet_time, attack_time;
    int w_sprint;
    bool particle_of_strength_sprint,
    particle_of_strength_shoot,
    particle_of_strength_repulsion,
    particle_of_strength_speed,
    particle_of_strength_jump;
    Keyboard key;
    Mouse mouse;
    ParticleSystem *particles;
    enum class AnimationIndex{RunL, RunR,
            WalkingL, WalkingR,
            AttackL, AttackR,
            BlockL, BlockR,
            DeadL, DeadR,
            Count};
    CircleShape *e_Radius;//e_Radius -> entity radius
    Player(Sprite *sprite, GameLvL *LvL, float X, float Y, int W, int H, string Name);
    ~Player();
    FloatRect getRect()override;
    void move();
    void s_position(); // sprite position
    void ControlMove();
    void update(float time, GameLvL *gLvL);
    void draw(RenderWindow &window, View view)override;
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
