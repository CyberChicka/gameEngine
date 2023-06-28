//
// Created by Doni on 28.06.2023.
//
#include "Aiden.h"

Aiden::Aiden(Sprite *sprite, GameLvL *LvL, float X, float Y, int W, int H, string Name): Nps(sprite, LvL, X, Y, W, H, Name){
    this->initAnim();
}
Aiden::~Aiden() {
    cout << "============== removed from nps ============"<< endl;
    delete this->gameLvL;
    delete this->s;
    delete this->e_Radius;
}

void Aiden::animation(float time) {

}

void Aiden::initAnim() {

}

void Aiden::update(float time) {
    this->animation(time);
    this->position.x = this->dx *time;
    this->checkCollisionMap(this->dx, 0);
    this->position.y = this->dy * time;
    checkCollisionMap(0, this->dy);
    this->dy += 0.0015 * time;
    this->s->setPosition(position);
}
// Диалоги с нпс
void Aiden::Dialogue(sf::Event event, Player player) {
    ostringstream  d_Nps;
    if(event.type == Event::KeyPressed){
        if(event.key.code == Keyboard::F){
            if(player.getRect().intersects(this->getRect())){
                if(this->gameLvL->gameLvL == 1){
                    switch (this->isNpsDialogue) {
                        case true:

                            break;
                        case false:
                            break;
                    }
                }
                if(this->gameLvL->gameLvL == 2){
                    switch (this->isNpsDialogue) {
                        case true:

                            break;
                        case false:
                            break;
                    }
                }
                if(this->gameLvL->gameLvL == 3){
                    switch (this->isNpsDialogue) {
                        case true:

                            break;
                        case false:
                            break;
                    }
                }
            }
        }
    }
}
