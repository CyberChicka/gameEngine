//
// Created by Doni on 12.07.2023.
//

#include "Enemy_Boom.h"


Enemy_Boom::Enemy_Boom(Sprite *sprite, GameLvL *LvL, float X, float Y, int W, int H, string Name): Enemy(sprite, LvL, X, Y, W, H, Name) {
    if(this->name == "Boom"){ is_health = 50; s->setScale(0.3f, 0.3f); }
    this->initAnim();
}
Enemy_Boom::~Enemy_Boom() {
    cout << "============== removed from enemy_boom ============"<< endl;
    delete this->gameLvL;
    delete this->s;
}

void Enemy_Boom::ControlEnemy(float time, float pX, float pY) {
    this->distance = ((pos.x - pX) * (pos.x - pX) + (pos.y - pY) * (pos.y - pY));
    if(this->name == "Boom"){
        if(this->distance > 10){
            this->dx += 0.02 * time * (pX - this->pos.x) / this->distance;
        }
    }
}
void Enemy_Boom::initAnim(){
    this->animations[int(AnimationIndex::RunL)] = Animation(20, 0.008, 244, 370, 180, 265, 1);
    this->animations[int(AnimationIndex::RunR)] = Animation(20, 0.008, 244, 370, 180, 265, 0);
    this->animations[int(AnimationIndex::Walking)] = Animation(20, 0.008, 244, 45, 180, 265, 0);
    this->animations[int(AnimationIndex::Boom)] = Animation(8, 0.008, 600, 600, 550, 600, 0);
}

void Enemy_Boom::animation(float time) {
    if(this->life){
        if(this->isAttack){
            this->curAnimation = AnimationIndex::Boom;
        }
        else{
            if(this->isStop){
                this->curAnimation = AnimationIndex::WalkingR;
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
void Enemy_Boom::update(float time, GameLvL *gLvL, Player *p) {
    this->timeAttack += time;
    this->Attack(*p);
    this->gameLvL = gLvL;
    this->State();
    ControlEnemy(time, p->pos.x, p->pos.y);
    this->animation(time);
    this->pos.x += this->dx * time;
    this->checkCollisionMap(this->dx, 0.f);
    this->pos.y += this->dy * time;
    this->checkCollisionMap(0.f, this->dy);
    if(!this->onGround)this->dy+=0.0015*time;
    this->s->setPosition(this->pos);
    if(this->isAttack)this->s->setPosition(this->pos.x, this->pos.y - 92);
    if(this->is_health <= 0)this->life = false;
}
void Enemy_Boom::Attack(Player &p) {
    if(p.e_Radius->getGlobalBounds().intersects(this->getRect())){
        this->isAttack = true;
        this->isStop = true;
        this->dx = 0;
    } else{
        this->isAttack = false;
        this->isStop = false;
    }
    if(p.isBlock){
        if(p.state == Player::left){ this->dx = -0.2; }
        else if(p.state == Player::right){ this->dx = 0.2; }
        else this->dx = -0.2;
    }
    else{
        if(this->isAttack){
            if(this->timeAttack > 2000){
                p.is_health -= 50;
                this->life = false;
                this->timeAttack = 0;
            }
        }
    }
}
void Enemy_Boom::TakingDamage(Player &p) {

}