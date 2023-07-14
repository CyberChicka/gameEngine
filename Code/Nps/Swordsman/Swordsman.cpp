//
// Created by Doni on 28.06.2023.
//

#include "Swordsman.h"

Swordsman::Swordsman(sf::Sprite *sprite, GameLvL *LvL, CreateText *T_NPS, float X, float Y, int W, int H, std::string Name): Nps(sprite, LvL, T_NPS, X, Y, W, H, Name) {
    this->s->setScale(1.0f, 1.0f);
    this->initAnim();
}
Swordsman::~Swordsman() {
    cout << "============== removed from nps historian ============"<< endl;
    delete t_Nps;
    delete this->gameLvL;
    delete this->s;
}

void Swordsman::animation(float time) {
    this->curAnimation = AnimationIndex::Walking;
    this->animations[int(this->curAnimation)].Update(*s, time);
}

void Swordsman::initAnim() {
    this->animations[int(AnimationIndex::Walking)] = Animation(4, 0.008, 229, 0, 220, 266 , 0);
}
void Swordsman::Dialogue(sf::Event event, Player *player) {
    this->t_Nps->text->setPosition(this->pos.x + 25, this->pos.y - 60);
    ostringstream  d_Nps;
    if(event.type == Event::KeyPressed){
        if(event.key.code == Keyboard::F){
            if(player->e_Radius->getGlobalBounds().intersects(this->getRect())){
                switch (this->isNpsDialogue){
                    case true:
                        this->ClickNps++;
                        this->isNpsDialogue = false;
                        d_Nps << getNpsMessage(this->ClickNps, this->gameLvL->gameLvL, this->name);
                        this->t_Nps->text->setString(d_Nps.str());
                        if(this->gameLvL->gameLvL == 1){
                            if(this->ClickNps >= 5)this->ClickNps++;
                            if(this->ClickNps == 6)this->ClickNps--;
                        }
                        else if(this->gameLvL->gameLvL == 2){
                            if(this->ClickNps >= 5)this->ClickNps++;
                            if(this->ClickNps == 6)this->ClickNps--;
                        }
                        break;
                    case false:
                        this->t_Nps->text->setString(" ");
                        this->isNpsDialogue = true;
                        break;
                }

            }
        }
    }
}
void Swordsman::Interaction(sf::Event event, Player &player){
    if(player.e_Radius->getGlobalBounds().intersects(this->getRect())){
        if(this->ClickNps == 7){
            if(event.type == Event::KeyPressed){
                if(event.key.code == Keyboard::F){

                }
            }
        }
    }
}
