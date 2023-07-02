//
// Created by Doni on 01.06.2023.
//

#include "Object.h"

Object::Object(sf::Sprite *sprite, GameLvL *LvL, float X, float Y, int W, int H, std::string Name):Entity(sprite, LvL, X, Y, W, H, Name){
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
    this->animations[int(this->curAnimation)].Update(*this->s, time);
}
void Object::initAnim() {
    // Idle
    if(this->name == " "){
        this->animations[int(AnimationIndex::Walking)] = Animation(1, 0.008, 0, 0, 5000, 500, 0);
    }
    else if(this->name == "House"){
        this->animations[int(AnimationIndex::Walking)] = Animation(0, 0.008, 0, 0, 0, 0, 0);
    }
    else if(this->name == " "){
        this->animations[int(AnimationIndex::Walking)] = Animation(0, 0.008, 0, 0, 0, 0, 0);
    }
    else{
        this->animations[int(AnimationIndex::Walking)] = Animation(0, 0.008, 0, 0, 0, 0, 0);
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
    this->position.x = time*this->dx;
    this->checkCollisionMap(this->dx, 0); // Касание с картой по x
    this->position.y = time*this->dy;
    this->checkCollisionMap(0, this->dy); // Касание с картой по y
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
                if(this->position.x < 1){
                    this->position.x = this->position.x + 1;
                }
                if(this->position.y < 1){
                    this->position.y = this->position.y + 1;
                }
            }
            else if(this->gameLvL->gameLvL == 2){
                if(this->position.x < 1){
                    this->position.x = this->position.x + 1;
                }
                if(this->position.y < 1){
                    this->position.y = this->position.y + 1;
                }
            }
        }
}