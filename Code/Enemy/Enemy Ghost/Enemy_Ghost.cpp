//
// Created by Doni on 15.05.2023.
//
#include <valarray>
#include "Enemy_Ghost.h"
Enemy_Ghost::Enemy_Ghost(Sprite *sprite, GameLvL *LvL, float X, float Y, int W, int H, string Name): Enemy(sprite, LvL, X, Y, W, H, Name) {
    this->s->setTextureRect(IntRect(0, 0, w, h));
    this->life = true;
    this->onGround = false;
    this->gameLvL = new GameLvL(*LvL);
    if(this->name == "Ghost"){ is_health = 60; dx = 0.1; state = stay; }
    this->initAnim();
}
Enemy_Ghost::~Enemy_Ghost() {
    cout << "============== removed from enemy_ghost ============"<< endl;
    delete this->gameLvL;
    delete this->s;
}

void Enemy_Ghost::ControlEnemy(float time, float pX, float pY) {
    distance = ((pos.x - pX) * (pos.x - pX) + (pos.y - pY) * (pos.y - pY));
    if(this->name == "Ghost"){
        if(distance > 50){
            dx = 0.80 * time * (pX - pos.x) / distance;
        }
    }
}

void Enemy_Ghost::update(float time, GameLvL *gLvL, Player *p) {
    this->gameLvL = gLvL;
    this->State();
    this->timeAttack += time;
    this->Attack(*p);
    ControlEnemy(time, p->pos.x, p->pos.y);
    this->animation(time);
    this->pos.x += this->dx * time; this->checkCollisionMap(this->dx, 0.f);
    this->pos.y += this->dy * time;this->checkCollisionMap(0.f, this->dy);
    this->dy+=0.0015*time;
    this->s->setPosition(this->pos);
    if(this->is_health <= 0)this->life = false;
}
void Enemy_Ghost::animation(float time) {
    if(this->life){
        if(this->name == "Ghost"){
            if(this->isStop){
                if(this->state == right)this->curAnimation = AnimationIndex::WalkingR;
                else if(this->state == left)this->curAnimation = AnimationIndex::WalkingL;
                else this->curAnimation = AnimationIndex::WalkingR;
            }
            else{
                if(this->state == right)this->curAnimation = AnimationIndex::RunR;
                else if(this->state == left)this->curAnimation = AnimationIndex::RunL;
                else this->curAnimation = AnimationIndex::RunR;
            }
        }
    }
    this->animations[int(this->curAnimation)].Update(*s, time);
}

void Enemy_Ghost::initAnim(){
    this->animations[int(AnimationIndex::RunL)] = Animation(12, 0.008, 110, 180, 85, 140, 1);
    this->animations[int(AnimationIndex::RunR)] = Animation(12, 0.008, 110, 180, 85, 140, 0);
    this->animations[int(AnimationIndex::WalkingL)] = Animation(1, 0, 0, 0, 65, 140, 1);
    this->animations[int(AnimationIndex::WalkingR)] = Animation(1, 0, 0, 0, 65, 140, 0);
}

void Enemy_Ghost::Attack(Player &p) {
    if(p.e_Radius->getGlobalBounds().intersects(this->getRect())){
        if(p.isBlock){
            if(p.particle_of_strength_repulsion){
                if(p.state == Player::left){ this->dx = -0.3; }
                else if(p.state == Player::right){ this->dx = 0.3; }
                else this->dx = -0.3;
            }
        }
        else{
            if(this->timeAttack > 2000){
                p.is_health -= 10;
                this->timeAttack = 0;
            }
        }
    }
}
//void Enemy_Ghost::TakingDamage(Player &p) {}