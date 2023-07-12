//
// Created by Doni on 12.07.2023.
//

#include "Enemy_Mag.h"

Enemy_Mag::Enemy_Mag(sf::Sprite *sprite, FonGame *Damage, GameLvL *LvL, float X, float Y, int W, int H, std::string Name): Enemy(sprite, LvL, X, Y, W, H, Name) {
    this->sDamage = new FonGame(*Damage);
    if(this->name == "Mag"){ this->is_health = 50; this->isAttack = false;}
    this->initAnim();
}
Enemy_Mag::~Enemy_Mag() {
    cout << "============== removed from enemy_mag ============"<< endl;
    delete sDamage;
    delete this->gameLvL;
    delete this->s;
}

void Enemy_Mag::ControlEnemy(float time, float pX, float pY) {
    this->distance = ((this->position.x - pX) * (this->position.x - pX) + (this->position.y - pY) * (this->position.y - pY));
    if(this->name == "Mag"){
        if(this->distance > 10){
            this->dx += 0.01 * time * (pX - this->position.x) / this->distance;
        }
    }
}

void Enemy_Mag::initAnim() {
    this->animations[int(AnimationIndex::AttackL)] = Animation(20, 0.008, 150, 0, 140, 172, 0);
    this->animations[int(AnimationIndex::AttackR)] = Animation(20, 0.008, 150, 0, 140, 172, 1);
    this->animations[int(AnimationIndex::WalkingL)] = Animation(20, 0.008, 150, 184, 140, 172, 0);
    this->animations[int(AnimationIndex::WalkingR)] = Animation(20, 0.008, 150, 184, 140, 172, 1);
}

void Enemy_Mag::animation(float time) {
    if(this->isStop){
        if(this->isAttack){
            if(this->state == right)this->curAnimation = AnimationIndex::AttackR;
            else if(this->state == left)this->curAnimation = AnimationIndex::AttackL;
            else this->curAnimation = AnimationIndex::AttackR;
        }
        if(!this->isAttack){
            if(this->state == right)this->curAnimation = AnimationIndex::WalkingR;
            else if(this->state == left)this->curAnimation = AnimationIndex::WalkingL;
            else this->curAnimation = AnimationIndex::WalkingR;
        }
    }
    else{
        if(this->state == right)this->curAnimation = AnimationIndex::WalkingR;
        else if(this->state == left)this->curAnimation = AnimationIndex::WalkingL;
        else this->curAnimation = AnimationIndex::WalkingR;
    }
    this->animations[int(this->curAnimation)].Update(*s, time);
}

void Enemy_Mag::update(float time, GameLvL *gLvL, Player *p) {
    sDamage->update(time, gLvL);
    this->gameLvL = gLvL;
    this->State();
    ControlEnemy(time, p->position.x, p->position.y);
    this->animation(time);
    this->position.x += this->dx * time;
    this->checkCollisionMap(this->dx, 0.f);
    this->position.y += this->dy * time;
    this->checkCollisionMap(0.f, this->dy);
    if(!this->onGround)this->dy+=0.0015*time;
    this->s->setPosition(this->position);
    if(this->is_health <= 0)this->life = false;
}

void Enemy_Mag::Attack(Player &p) {
    if(this->name == "Mag"){
        p.e_Radius->setRadius(360.f);
        if(p.e_Radius->getGlobalBounds().intersects(this->getRect())){
            this->isAttack = true;
            this->isStop = true;
            this->dx = 0;
        }
        else{
            this->isAttack = false;
            this->isStop = false;
        }
        if(this->isAttack){
            this->randomNumber = rand();
            if(timeAttack > 1000){
                sDamage->setPosition(p.GetX(), position.y - 30);
                if(sDamage->s->getGlobalBounds().intersects(p.getRect()) && !p.isBlock){ p.is_health -= 20; }
                this->timeAttack = 0;
            }
        }
    }
}
void Enemy_Mag::draw(RenderWindow &window, View view) {
    this->dist = sqrt((s->getPosition().x - view.getCenter().x)*(s->getPosition().x - view.getCenter().x) + (s->getPosition().y - view.getCenter().y)*(s->getPosition().y - view.getCenter().y));
    if(dist < window.getSize().x){
        window.draw(*this->s);
        sDamage->draw(window, view);
    }
}

void Enemy_Mag::TakingDamage(Player &p) {

}