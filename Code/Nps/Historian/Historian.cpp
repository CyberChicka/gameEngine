//
// Created by Doni on 28.06.2023.
//

#include "Historian.h"

Historian::Historian(sf::Sprite *sprite, GameLvL *LvL, CreateText *T_NPS, float X, float Y, int W, int H, std::string Name): Nps(sprite, LvL, T_NPS, X, Y, W, H, Name) {
    this->s->setScale(0.6f, 0.6f);
    this->initAnim();
}
Historian::~Historian() {
    cout << "============== removed from nps historian ============"<< endl;
    delete t_Nps;
    delete this->gameLvL;
    delete this->s;
}

void Historian::animation(float time) {
    this->curAnimation = AnimationIndex::Walking;
    this->animations[int(this->curAnimation)].Update(*s, time);
}

void Historian::initAnim() {
    this->animations[int(AnimationIndex::Walking)] = Animation(26, 0.008, 0, 367, 400, 340, 2);
}
void Historian::Dialogue(sf::Event event, Player *player){

    this->t_Nps->text->setPosition(this->pos.x + 25, this->pos.y - 60);
    ostringstream  d_Nps;
    if(event.type == Event::KeyPressed){
        if(event.key.code == Keyboard::F){
            if(player->e_Radius->getGlobalBounds().intersects(this->getRect())){
                switch (this->is_nps_dialogue){
                    case true:
                        this->ClickNps++;
                        if(this->gameLvL->gameLvL == 1){
                            if(this->ClickNps == 6)this->ClickNps = 0;
                        }
                        else if(this->gameLvL->gameLvL == 2){
                            if(this->ClickNps >= 8){this->ClickNps = 0;}
                        }
                        this->is_nps_dialogue = false;
                        d_Nps << getNpsMessage(this->ClickNps, this->gameLvL->gameLvL, this->name);
                        this->t_Nps->text->setString(d_Nps.str());
                        break;
                    case false:
                        this->t_Nps->text->setString(" ");
                        this->is_nps_dialogue = true;
                        break;
                }

            }
        }
    }
}

void Historian::Interaction(sf::Event event, Player &player) {

}