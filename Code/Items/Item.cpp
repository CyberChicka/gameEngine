//
// Created by Doni on 17.05.2023.
//

#include "Item.h"

Item::Item(sf::Sprite *sprite, GameLvL *LvL,  float X, float Y, int W, int H, std::string Name) : Entity(sprite, LvL, X, Y, W, H, Name){
    this->initAnim();
}
Item::~Item() {
    cout << "============== removed from item ============" << endl;
    delete this->s;
    delete this->gameLvL;
}

FloatRect Item::getRect() {
    return FloatRect(this->position.x, this->position.y, this->w, this->h);
}
void Item::animation(float time) { }
void Item::initAnim() { }
bool Item::isTake(Player &player){ return false; }
void Item::update(float time, GameLvL *gLvL) {
    this->gameLvL = gLvL;
    animation(time);
    this->position.x += this->dx*time;
    checkCollisionMap(this->dx, 0);
    this->position.y += this->dy*time;
    checkCollisionMap(0, this->dy);
    if(!this->onGround) this->dy = this->dy + 0.0015*time;
    this->s->setPosition(this->position);
}

float Item::GetX() { return this->position.x; }
float Item::GetY() { return this->position.y; }

void Item::checkCollisionMap(float dX, float dY) {
    for(int i = this->position.y / 32; i<(this->position.y + h) / 32; i++)
        for(int j = this->position.x / 32; j<(this->position.x + w) / 32; j++){
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

void Item::draw(RenderWindow &window, View view){
    this->dist = sqrt((s->getPosition().x - view.getCenter().x)*(s->getPosition().x - view.getCenter().x) +
                      (s->getPosition().y - view.getCenter().y)*(s->getPosition().y - view.getCenter().y));
    if(this->dist < window.getSize().x){
        window.draw(*this->s);
    }
}