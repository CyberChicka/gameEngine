//
// Created by Doni on 01.06.2023.
//

#include "Object.h"

Object::Object(Sprite *sprite, GameLvL *LvL, float X, float Y, int W, int H, string Name):Entity(sprite, LvL, X, Y, W, H, Name){
    if(this->name == "Home"){ this->s->setScale(1.2f, 1.2f); }
    if(this->name == "DarkTreeBig"){ this->s->setScale(2.0f, 2.0f); }
    if(this->name == "DarkTreeSmall"){ this->s->setScale(2.0f, 2.0f); }
    this->initAnim();
}
Object::~Object() {
    cout << "============== removed from object ============"<< endl;
    delete s;
    delete gameLvL;
}

FloatRect Object::getRect() {
    return FloatRect(this->position.x, this->position.y, this->w, this->h);
}
void Object::animation(float time) {
    this->curAnimation = AnimationIndex::Walking;
    this->animations[int(this->curAnimation)].Update(*this->s, time);
}
void Object::initAnim() {
    if(this->name == "Home"){
        this->animations[int(AnimationIndex::Walking)] = Animation(1, 0, 0, 0, 450, 280, 0);
    }
    if(this->name == "FlyingObelisk"){
        this->animations[int(AnimationIndex::Walking)] = Animation(13, 0.008, 200, 0, 145, 390, 0);
    }
    if(this->name == "DarkTreeBig"){
        this->animations[int(AnimationIndex::Walking)] = Animation(1, 0, 0, 0, 125, 135, 0);
    }
    if(this->name == "DarkTreeSmall"){
        this->animations[int(AnimationIndex::Walking)] = Animation(1, 0, 0, 0, 125, 135, 0);
    }
}

void Object::draw(RenderWindow &window, View view) {
    this->dist = sqrt((s->getPosition().x - view.getCenter().x)*(s->getPosition().x - view.getCenter().x) +
            (s->getPosition().y - view.getCenter().y)*(s->getPosition().y - view.getCenter().y));
    if(this->dist < window.getSize().x){
        window.draw(*this->s);
    }
}

float Object::GetY() {
    return this->position.y;
}
float Object::GetX(){
    return this->position.x;
}

void Object::update(float time, GameLvL *gLvL){
    this->gameLvL = gLvL;
    this->animation(time);
    this->position.x += time*this->dx;
    this->checkCollisionMap(this->dx, 0.f); // Касание с картой по x
    this->position.y += time*this->dy;
    this->checkCollisionMap(0.f, this->dy); // Касание с картой по y
    this->dy+=0.0015*time; // Притяжение к земле
    this->s->setPosition(this->position);
}

void Object::checkCollisionMap(float dX, float dY) // Работа с картой
{
    for(int i = this->position.y / 32; i<(this->position.y + h) / 32; i++) // Проходимся по высоте
        for(int j = this->position.x / 32; j<(this->position.x + w) / 32; j++) // Проходимся по ширине
        {
            this->cell = this->gameLvL->MapLvL[i][j];
            if(cell == '=' || cell == '.' || cell == '-' || cell == '<' || cell == '>' || cell == '{' || cell == '}')
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
                }
                if (dX<0){
                    this->position.x = j * 32 + 32;
                }
            }
            if(this->gameLvL->gameLvL == 1){
                if(this->position.x < 1){ this->position.x = this->position.x + 1; }
                if(this->position.y < 1){ this->position.y = this->position.y + 1; }
            }
        }
}

void Object::setPosition(float x, float y) {
    this->position.x = x;
    this->position.y = y;
}
//Object::Object(Sprite *sprite, GameLvL *LvL, float X, float Y, int W, int H, string Name):Entity(sprite, LvL, X, Y, W, H, Name){
//
//}
//Object::~Object() {
//
//}
//
//FloatRect Object::getRect() {
//
//}
//void Object::animation(float time) {
//
//}
//void Object::initAnim() {
//
//}
//
//void Object::draw(RenderWindow &window, View view) {
//
//}
//
//float Object::GetY() {
//
//}
//float Object::GetX(){
//
//}
//
//void Object::update(float time, GameLvL *gLvL){
//
//}
//
//void Object::checkCollisionMap(float dX, float dY) // Работа с картой
//{
//
//}
//
//void Object::setPosition(float x, float y) {
//
//}
