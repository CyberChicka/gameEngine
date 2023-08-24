//
// Created by Doni on 11.07.2023.
//

#include "Bullet.h"

Bullet::Bullet(sf::Sprite *sprite, GameLvL *LvL, float X, float Y, int W, int H, std::string Name, int Dir) :Entity(sprite, LvL, X, Y, W, H, Name) {
    this->direction = Dir; this->speed = 0.3;
    this->s->setScale(0.3f, 0.3f);
    initAnim();
}
Bullet::~Bullet() {
    delete this->s;
    delete this->gameLvL;
}
FloatRect Bullet::getRect() {
    return FloatRect(this->pos.x, this->pos.y, this->w, this->h);
}
void Bullet::initAnim() {
    this->animations[int(AnimationIndex::ShootL)] = Animation(33, 0.009, 574, 0, 500, 370, 1);
    this->animations[int(AnimationIndex::ShootR)] = Animation(33, 0.009, 574, 0, 500, 370, 0);
}
void Bullet::animation(float time) {
    if(this->direction == 1 || this->direction == 3){
        this->curAnimation = AnimationIndex::ShootL;
    }
    else if(this->direction == 2 || this->direction == 4){
        this->curAnimation = AnimationIndex::ShootR;
    }
    else {
        this->curAnimation = AnimationIndex::ShootR;
    }
    this->animations[int(this->curAnimation)].Update(*this->s, time);
}

void Bullet::upadte(float time) {
    this->animation(time);
    if(this->life){
        switch (this->direction)
        {
            case 0: this->dx = -this->speed; this->dy = 0; break;//интовое значение state = left
            case 1: this->dx = this->speed; this->dy = 0;  break;//интовое значение state = right
            case 2: this->dx = this->speed; this->dy = 0;  break;//интовое значение state = up
            case 4: this->dx = -this->speed; this->dy = 0;  break;//интовое значение state = up
        }
    }
    this->pos.x += time * this->dx;
    this->checkCollisionMap(this->dx, 0.f); // Касание с картой по x
    this->s->setPosition(this->pos);
}

void Bullet::draw(sf::RenderWindow &window, sf::View view) {
    this->dist = sqrt((s->getPosition().x - view.getCenter().x)*(s->getPosition().x - view.getCenter().x) +
                      (s->getPosition().y - view.getCenter().y)*(s->getPosition().y - view.getCenter().y));
    if(this->dist < window.getSize().x){
        window.draw(*this->s);
    }
}

void Bullet::checkCollisionMap(float dX, float dY) {

}

float Bullet::GetY() {
    return this->pos.y;
}

float Bullet::GetX() {
    return this->pos.x;
}