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
    return FloatRect(this->pos.x, this->pos.y, this->w, this->h);
}
void Item::animation(float time) { }
void Item::initAnim() { }
bool Item::isTake(Player &player){ return false; }
void Item::update(float time, GameLvL *gLvL) {
    this->gameLvL = gLvL;
    animation(time);
    this->pos.x += this->dx * time;
    checkCollisionMap(this->dx, 0);
    this->pos.y += this->dy * time;
    checkCollisionMap(0, this->dy);
    if(!this->onGround)this->dy = dy + 0.0015*time; // Притяжение к земле
    this->s->setPosition(this->pos);
}

float Item::GetX() { return this->pos.x; }
float Item::GetY() { return this->pos.y; }

void Item::checkCollisionMap(float dX, float dY) {
    for(int i = this->pos.y / 32; i < (this->pos.y + h) / 32; i++)
        for(int j = this->pos.x / 32; j < (this->pos.x + w) / 32; j++){
            if(this->gameLvL->MapLvL[i][j] == '=' || this->gameLvL->MapLvL[i][j] == '.' || this->gameLvL->MapLvL[i][j] == '-' || this->gameLvL->MapLvL[i][j] == '<' ||
            this->gameLvL->MapLvL[i][j] == '>' || this->gameLvL->MapLvL[i][j] == '{' || this->gameLvL->MapLvL[i][j] == '}')
            {
                if (dY>0){ this->pos.y = i * 32 - h; this->dy = 0; this->onGround = true; }
                if (dY<0){this->pos.y = i * 32 + 32; this->dy = 0;}
                if (dX>0){this->pos.x = j * 32 - w; }
                if (dX<0){this->pos.x = j * 32 + 32;}
            }
            if(this->pos.y < 1){ this->pos.y = this->pos.y + 0.5;}
            if(this->pos.x < 1){ this->pos.x = this->pos.x + 0.5;}
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