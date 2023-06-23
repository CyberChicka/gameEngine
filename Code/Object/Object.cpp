//
// Created by Doni on 01.06.2023.
//

#include "Object.h"

Object::Object(sf::Sprite *sprite, GameLvL *LvL, float X, float Y, int W, int H, std::string Name): Entity(sprite, LvL, X, Y, W, H, Name) {
    this->initAnim();
}
Object::~Object() {
    delete s;
    delete gameLvL;
    delete e_Radius;
}

FloatRect Object::getRect() {
    return FloatRect(this->position.x, this->position.y, this->w, this->h);
}

void Object::animation(float time) {

}

void Object::initAnim() {

}

void Object::draw(sf::RenderWindow &window, sf::View view) {
    this->dist = sqrt((s->getPosition().x - view.getCenter().x)*(s->getPosition().x - view.getCenter().x) + (s->getPosition().y - view.getCenter().y)*(s->getPosition().y - view.getCenter().y));
    if(dist < window.getSize().x){
        window.draw(*this->s);
    }
}

float Object::GetY() {

}
float Object::GetX(){

}

void Object::checkCollisionMap(float dX, float dY){

}