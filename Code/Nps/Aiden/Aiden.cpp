//
// Created by Doni on 28.06.2023.
//
#include "Aiden.h"

Aiden::Aiden(Sprite *sprite, GameLvL *LvL, CreateText *T_NPS, float X, float Y, int W, int H, string Name): Nps(sprite, LvL, T_NPS, X, Y, W, H, Name){
    s->setScale(0.5f, 0.5f);
    this->life = true;
    this->onGround = false;
    if(this->name == "Aiden"){ is_health = 60; }
    this->initAnim();
}
Aiden::~Aiden() {
    cout << "============== removed from nps ============"<< endl;
    delete t_Nps;
    delete this->gameLvL;
    delete this->s;
}
//
//FloatRect Aiden::getRect() {
//    return FloatRect(this->position.x, this->position.y, this->w, this->h);
//}
void Aiden::animation(float time) {
    this->curAnimation = AnimationIndex::Walking;
    this->animations[int(this->curAnimation)].Update(*s, time);
}

void Aiden::initAnim() {
    this->animations[int(AnimationIndex::Walking)] = Animation(10, 0.008, 161, 0, 145, 220, 0);
}

//void Aiden::update(float time, GameLvL *gLvL){
//    this->gameLvL = gLvL;
//    this->animation(time);
//    this->position.x += this->dx *time;
//    this->checkCollisionMap(this->dx, 0);
//    this->position.y += this->dy * time;
//    checkCollisionMap(0, this->dy);
//    this->dy += 0.0015 * time;
//    this->s->setPosition(position);
//}
// Диалоги с нпс
void Aiden::Dialogue(sf::Event event, Player player) {
    this->t_Nps->text->setPosition(this->position.x + 25, this->position.y - 60);
    ostringstream  d_Nps;
    if(event.type == Event::KeyPressed){
        if(event.key.code == Keyboard::F){
            if(player.e_Radius->getGlobalBounds().intersects(this->getRect())){
                switch (this->isNpsDialogue){
                    case true:
                        this->ClickNps++;
                        this->isNpsDialogue = false;
                        d_Nps << getNpsMessage(this->ClickNps, this->gameLvL->gameLvL, this->name);
                        this->t_Nps->text->setString(d_Nps.str());
                        if(this->gameLvL->gameLvL == 1){
                            if(this->ClickNps >= 3){this->ClickNps = 0;}
                        }
                        else if(this->gameLvL->gameLvL == 2){
                            if(this->ClickNps >= 3){this->ClickNps = 0;}
                        }
                        break;
                        case false:
                            this->isNpsDialogue = true;
                            break;
                    }

            }
        }
    }
}