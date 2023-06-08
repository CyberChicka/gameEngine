
#include "Enemy_Scelet.h"

Enemy_Skeleton::Enemy_Skeleton(Sprite *sprite, GameLvL *LvL, float X, float Y, int W, int H, std::string Name): Enemy(sprite, LvL,  X, Y, W, H, Name) {
    this->life = true;
    this->gameLvL = new GameLvL(*LvL);
    this->is_health = 120;
    this->dx = 0; this->dy = 0;
    initAnim();
}
Enemy_Skeleton::~Enemy_Skeleton() {
    delete this->gameLvL;
    delete s;
}

FloatRect Enemy_Skeleton::getRect() {
    return FloatRect (this->position.x, this->position.y, this->w, this->h);
}

void Enemy_Skeleton::ControlMove() {

}
void Enemy_Skeleton::move() {
    if(this->life){

    }
}

void Enemy_Skeleton::update(float time) {
    this->s->setPosition(position);
    if(this->life){

    }
}

void Enemy_Skeleton::animation(float time) {

}

void Enemy_Skeleton::initAnim() {

}

float Enemy_Skeleton::GetX() {
    return this->position.x;
}

float Enemy_Skeleton::GetY() {
    return this->position.y;
}

void Enemy_Skeleton::checkCollisionMap(float dX, float dY){

}

void Enemy_Skeleton::draw(sf::RenderWindow &window) {
    window.draw(*this->s);
}

void Enemy_Skeleton::Attack(Player &p) {

}

void Enemy_Skeleton::TakingDamage(Player &p) {

}

