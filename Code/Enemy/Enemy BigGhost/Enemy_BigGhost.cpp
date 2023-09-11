//
// Created by Doni on 12.07.2023.
//

#include "Enemy_BigGhost.h"

Enemy_BigGhost::Enemy_BigGhost(Sprite *sprite, GameLvL *LvL, float X, float Y, int W, int H, string Name): Enemy(sprite, LvL, X, Y, W, H, Name) {
    if(this->name == "BigGhost"){
        this->is_health = 80;
        this->dx = 0.1;
        this->s->setScale(0.5f, 0.5f);
    }
    this->initAnim();
}
Enemy_BigGhost::~Enemy_BigGhost() {
    cout << "============== removed from enemy_big_ghost ============"<< endl;
    delete this->gameLvL;
    delete this->s;
}

void Enemy_BigGhost::ControlEnemy(float time, float pX, float pY) {
    distance = ((pos.x - pX) * (pos.x - pX) + (pos.y - pY) * (pos.y - pY));
    if(this->name == "BigGhost"){
        if(distance > 50){
            this->dx += 0.04 * time * (pX - this->pos.x) / this->distance;
            this->dx += 0.04 * time * (pX - this->pos.x) / this->distance;
        }
    }
}

void Enemy_BigGhost::update(float time, GameLvL *gLvL, Player *p) {
    this->gameLvL = gLvL;
    this->timeAttack += time;
    this->Attack(*p);
    this->State();
    ControlEnemy(time, p->pos.x, p->pos.y);
    this->animation(time);
    this->pos.x += this->dx * time; this->checkCollisionMap(this->dx, 0.f);
    this->pos.y += this->dy * time;this->checkCollisionMap(0.f, this->dy);
    this->dy+=0.0015*time;
    this->s->setPosition(this->pos);
    if(this->is_health <= 0)this->life = false;
}
void Enemy_BigGhost::animation(float time) {
    if(this->life){
        if(this->name == "BigGhost"){
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

void Enemy_BigGhost::initAnim(){
    this->animations[int(AnimationIndex::RunL)] = Animation(11, 0.008, 167, 0, 130, 320, 1);
    this->animations[int(AnimationIndex::RunR)] = Animation(11, 0.008, 167, 0, 130, 320, 0);
    this->animations[int(AnimationIndex::WalkingL)] = Animation(1, 0, 0, 0, 130, 320, 1);
    this->animations[int(AnimationIndex::WalkingR)] = Animation(1, 0, 0, 0, 130, 320, 0);
}

void Enemy_BigGhost::Attack(Player &p) {
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
                p.is_health -= 30;
                this->timeAttack = 0;
            }
        }
    }
}
//void Enemy_BigGhost::TakingDamage(Player &p) { }