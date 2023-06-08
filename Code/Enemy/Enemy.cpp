
#include "Enemy.h"

Enemy::Enemy(Sprite *sprite, GameLvL *LvL,  float X, float Y, int W, int H, string Name): Entity(sprite, LvL, X, Y, W, H, Name){
    this->s->setOrigin(this->w/2,this->h/2);
    this->life = true;
    this->dx = 0; this->dy = 0;
    this->gameLvL = new GameLvL(*LvL);
    this->is_health = 100;
    initAnim();
}
Enemy::~Enemy() {
    delete this->gameLvL;
    delete this->s;
    delete this->e_Radius;
}

FloatRect Enemy::getRect() { return FloatRect(this->position.x, this->position.y, this->w, this->h); }

void Enemy::ControlMove() { }

void Enemy::ControlEnemy(float pX, float pY, float time) {

}
void Enemy::move() {

}

void Enemy::update(float time, Player *p) {}

void Enemy::animation(float time) { }

void Enemy::initAnim() { }

float Enemy::GetX() { return this->position.x; }
float Enemy::GetY() { return this->position.y; }

void Enemy::checkCollisionMap(float dX, float dY) {
    for(int i = this->position.y / 32; i<(this->position.y + h) / 32; i++)
        for(int j = this->position.x / 32; j<(this->position.x + w) / 32; j++){
            if(this->isLvLMap == 1){
                if(this->gameLvL->MapLvL[i][j] == '=' || this->gameLvL->MapLvL[i][j] == '.' || this->gameLvL->MapLvL[i][j] == '-' || this->gameLvL->MapLvL[i][j] == '<' ||
                   this->gameLvL->MapLvL[i][j] == '>' || this->gameLvL->MapLvL[i][j] == '{' || this->gameLvL->MapLvL[i][j] == '}')
                {
                    if (dY>0){ this->position.y = i * 32 - h;  this->dy = 0; this->onGround = true; }
                    if (dY<0){this->position.y = i * 32 + 32;  this->dy = 0;}
                    if (dX>0){this->position.x = j * 32 - w; }
                    if (dX<0){this->position.x = j * 32 + 32;}
                }
                if(this->position.y < 1){  this->position.y = this->position.y + 0.5;}
                if(this->position.x < 1){  this->position.x = this->position.x + 0.5;}
//                if(this->position.y > 900){ this->position.y = this->position.y - 0.5;}
//                if(this->position.x > 10167){ this->position.x = this->position.x - 0.5;}
            }
        }
}

void Enemy::draw(RenderWindow &window) { }

void Enemy::Attack(Player &p) { }

void Enemy::TakingDamage(Player &p) {}

void Enemy::State() {
    if(this->dx > 0){
        this->state = this->right;
        this->isStop = false;
    }
    else if(this->dx < 0){
        this->state = this->left;
        this->isStop = false;
    }
    else{
        this->state = this->stay;
        this->isStop = true;
    }
}