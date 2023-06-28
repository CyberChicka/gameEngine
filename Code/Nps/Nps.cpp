//
// Created by Doni on 28.06.2023.
//
#include "Nps.h"

Nps::Nps(Sprite *sprite, GameLvL *LvL, float X, float Y, int W, int H, string Name): Entity(sprite, LvL, X, Y, W, H, Name){
    this->initAnim();
}
Nps::~Nps() {
    cout << "============== removed from nps ============"<< endl;
    delete this->gameLvL;
    delete this->s;
    delete this->e_Radius;
}

FloatRect Nps::getRect() {
    return FloatRect(this->position.x, this->position.y, this->w, this->h);
}

void Nps::animation(float time) {

}

void Nps::initAnim() {

}

void Nps::Dialogue(sf::Event event, Player player) {

}
void Nps::update(float time) {
    this->animation(time);
    this->position.x = this->dx *time;
    this->checkCollisionMap(this->dx, 0);
    this->position.y = this->dy * time;
    checkCollisionMap(0, this->dy);
    this->dy += 0.0015 * time;
    this->s->setPosition(position);
}

void Nps::draw(sf::RenderWindow &window, sf::View view) {
    this->dist = sqrt((s->getPosition().x - view.getCenter().x)*(s->getPosition().x - view.getCenter().x) +
                      (s->getPosition().y - view.getCenter().y)*(s->getPosition().y - view.getCenter().y));
    if(this->dist < window.getSize().x){
        window.draw(*this->s);
    }
}

void Nps::checkCollisionMap(float dX, float dY) {
    for(int i = this->position.y / 32; i<(this->position.y + h) / 32; i++)
        for(int j = this->position.x / 32; j<(this->position.x + w) / 32; j++){
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
                if (dX>0){ this->position.x = j * 32 - w; }
                if (dX<0){ this->position.x = j * 32 + 32; }
            }
            if(this->gameLvL->gameLvL == 1){
                if(this->position.x < 1){ this->position.x = this->position.x + 1; }
                if(this->position.y < 1){ this->position.y = this->position.y + 1; }
            }
        }
}

float Nps::GetX() {
    return position.x;
}

float Nps::GetY() {
    return position.y;
}