//
// Created by Doni on 15.05.2023.
//
#include <valarray>
#include "Enemy_Ghost.h"
#include "../../Map/GameLvL.h"
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
    delete this->e_Radius;
}

FloatRect Enemy_Ghost::getRect(){ return FloatRect (this->position.x, this->position.y, this->w, this->h); }

void Enemy_Ghost::ControlEnemy(float time, float pX, float pY) {
    distance = ((position.x - pX) * (position.x - pX) + (position.y - pY) * (position.y - pY));
    if(this->name == "Ghost"){
        if(distance > 10){
            dx =0.03 * time * (pX - position.x) / distance;
        }
    }
}

void Enemy_Ghost::update(float time, Player *p) {
    this->State();
    ControlEnemy(time, p->position.x, p->position.y);
    this->animation(time);
    this->position.x += this->dx * time; this->checkCollisionMap(this->dx, 0.f);
    this->position.y += this->dy * time;this->checkCollisionMap(0.f, this->dy);
    if(!this->onGround)this->dy+=0.0015*time;
    this->s->setPosition(this->position);
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
float Enemy_Ghost::GetX() { return this->position.x; }
float Enemy_Ghost::GetY() { return this->position.y; }

void Enemy_Ghost::checkCollisionMap(float dX, float dY){
    for(int i = this->position.y / 32; i<(this->position.y + h) / 32; i++)
        for(int j = this->position.x / 32; j<(this->position.x + w) / 32; j++){
            if(this->gameLvL->gameLvL == 1){ }
            if(this->gameLvL->MapLvL[i][j] == '=' || this->gameLvL->MapLvL[i][j] == '.' || this->gameLvL->MapLvL[i][j] == '-' || this->gameLvL->MapLvL[i][j] == '<' ||
            this->gameLvL->MapLvL[i][j] == '>' || this->gameLvL->MapLvL[i][j] == '{' || this->gameLvL->MapLvL[i][j] == '}')
            {
                if (dY>0){
                    this->position.y = i * 32 - h;
                    this->dy = 0;
                    this->onGround = true;
                }
                if (dY<0){
                    this->position.y = i * 32 + 32;
                    this->dy = 0;
                }
                if (dX>0){
                    this->position.x = j * 32 - w;
                    dx = -0.1;
                }
                if (dX<0){
                    this->position.x = j * 32 + 32; dx = 0.1;
                }
            }
            if(this->position.x < 1){ this->position.x = this->position.x + 1; }
            if(this->position.y < 1){ this->position.y = this->position.y + 1; }
//                if(this->position.y > 900){ this->position.y = this->position.y - 0.5;}
//                if(this->position.x > 10167){ this->position.x = this->position.x - 0.5;}

        }
}

void Enemy_Ghost::draw(sf::RenderWindow &window, View view){
    this->dist = sqrt((s->getPosition().x - view.getCenter().x)*(s->getPosition().x - view.getCenter().x) + (s->getPosition().y - view.getCenter().y)*(s->getPosition().y - view.getCenter().y));
    if(dist < window.getSize().x){
        window.draw(*this->s);
    }
}

void Enemy_Ghost::Attack(Player &p) {

}
void Enemy_Ghost::TakingDamage(Player &p) {

}