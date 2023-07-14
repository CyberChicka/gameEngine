//
// Created by Doni on 28.06.2023.
//
#include "Nps.h"

Nps::Nps(Sprite *sprite, GameLvL *LvL, CreateText *T_NPS, float X, float Y, int W, int H, string Name): Entity(sprite, LvL, X, Y, W, H, Name){
    this->ClickNps = 0;
    this->t_Nps = new CreateText(*T_NPS);
    this->initAnim();
}
Nps::~Nps() {
    cout << "============== removed from nps ============"<< endl;
    delete this->t_Nps;
    delete this->gameLvL;
    delete this->s;
}

FloatRect Nps::getRect() { return FloatRect(this->pos.x, this->pos.y, this->w, this->h); }
void Nps::animation(float time) { }
void Nps::initAnim() { }
void Nps::update(float time, GameLvL *gLvL){
    this->gameLvL = gLvL;
    this->animation(time);
    this->pos.x += this->dx * time;
    this->checkCollisionMap(this->dx, 0);
    this->pos.y += this->dy * time;
    checkCollisionMap(0, this->dy);
    if(!this->onGround)this->dy = dy + 0.0015*time; // Притяжение к земле
    this->s->setPosition(this->pos);
}

void Nps::draw(sf::RenderWindow &window, sf::View view) {
    this->dist = sqrt((this->s->getPosition().x - view.getCenter().x)*(this->s->getPosition().x - view.getCenter().x) +
                      (this->s->getPosition().y - view.getCenter().y)*(this->s->getPosition().y - view.getCenter().y));
    if(this->dist < window.getSize().x){
        window.draw(*this->s);
        if(!this->isNpsDialogue){
            window.draw(*this->t_Nps->text);
        }
    }
}

void Nps::checkCollisionMap(float dX, float dY) {
    for(int i = this->pos.y / 32; i < (this->pos.y + h) / 32; i++)
        for(int j = this->pos.x / 32; j < (this->pos.x + w) / 32; j++){
            this->cell = this->gameLvL->MapLvL[i][j];
            if(cell == '=' || cell == '.' || cell == '-' || cell == '<' || cell == '>' || cell == '{' || cell == '}')
            {
                if (dY>0){
                    this->pos.y = i * 32 - h;
                    this->dy = 0;
                    this->onGround = true;
                }
                if (dY<0){
                    this->pos.y = i * 32 + 32;
                    this->dy = 0;
                }
                if (dX>0){ this->pos.x = j * 32 - w; }
                if (dX<0){ this->pos.x = j * 32 + 32; }
            }
            if(this->gameLvL->gameLvL == 1){
                if(this->pos.x < 1){ this->pos.x = this->pos.x + 1; }
                if(this->pos.y < 1){ this->pos.y = this->pos.y + 1; }
            }
        }
}

float Nps::GetX() { return this->pos.x; }
float Nps::GetY() { return this->pos.y; }

void Nps::Interaction(Event event, Player &player){ }
void Nps::Dialogue(Event event, Player *player){ }