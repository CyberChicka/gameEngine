//
// Created by Doni on 28.06.2023.
//
#include "Aiden.h"

Aiden::Aiden(Sprite *sprite, GameLvL *LvL, CreateText *T_NPS, float X, float Y, int W, int H, string Name): Nps(sprite, LvL, T_NPS, X, Y, W, H, Name){
    this->s->setScale(0.5f, 0.5f);
    this->initAnim();
}
Aiden::~Aiden() {
    cout << "============== removed from nps ============"<< endl;
    delete t_Nps;
    delete this->gameLvL;
    delete this->s;
}
void Aiden::animation(float time) {
    this->curAnimation = AnimationIndex::Walking;
    this->animations[int(this->curAnimation)].Update(*s, time);
}

void Aiden::initAnim() {
    this->animations[int(AnimationIndex::Walking)] = Animation(10, 0.008, 161, 0, 145, 220, 0);
}
// Диалоги с нпс
void Aiden::Dialogue(sf::Event event, Player *player) {
    this->t_Nps->text->setPosition(this->pos.x + 25, this->pos.y - 60);
    ostringstream  d_Nps;
    if(event.type == Event::KeyPressed){
        if(event.key.code == Keyboard::F){
            if(player->e_Radius->getGlobalBounds().intersects(this->getRect())){
                switch (this->is_nps_dialogue){
                    case true:
                        this->ClickNps++;
                        this->is_nps_dialogue = false;
                        d_Nps << getNpsMessage(this->ClickNps, this->gameLvL->gameLvL, this->name);
                        this->t_Nps->text->setString(d_Nps.str());
                        if(this->gameLvL->gameLvL == 2)
                            if(this->ClickNps >= 3){this->ClickNps = 0;}
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

void Aiden::Interaction(sf::Event event, Player &player) {

}