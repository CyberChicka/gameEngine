//
// Created by Doni on 28.06.2023.
//

#include "Knight.h"

Knight::Knight(sf::Sprite *sprite, GameLvL *LvL, CreateText *T_NPS, float X, float Y, int W, int H, std::string Name): Nps(sprite, LvL, T_NPS, X, Y, W, H, Name) {
    this->s->setScale(0.6f, 0.6f);
    this->initAnim();
}
Knight::~Knight() {
    cout << "============== removed from nps historian ============"<< endl;
    delete t_Nps;
    delete this->gameLvL;
    delete this->s;
}

void Knight::animation(float time) {
    this->curAnimation = AnimationIndex::Walking;
    this->animations[int(this->curAnimation)].Update(*s, time);
}

void Knight::initAnim() {
    this->animations[int(AnimationIndex::Walking)] = Animation(20, 0.008, 287, 0, 262, 235, 0);
}
void Knight::Dialogue(sf::Event event, Player *player) {
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
                            if(this->ClickNps >= 2)this->ClickNps = 0;
                        }
                        else if(this->gameLvL->gameLvL == 2){
                            if(this->ClickNps >= 2){this->ClickNps = 0;}
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

void Knight::Interaction(sf::Event event, Player &player) {

}