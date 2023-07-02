//
// Created by Doni on 28.06.2023.
//

#include "Blacksmith.h"

Blacksmith::Blacksmith(sf::Sprite *sprite, GameLvL *LvL, CreateText T_NPS, float X, float Y, int W, int H, std::string Name): Nps(sprite, LvL, T_NPS, X, Y, W, H, Name){
    this->initAnim();
}
Blacksmith::~Blacksmith() {
    delete t_Nps;
    delete this->gameLvL;
    delete this->s;
}

void Blacksmith::animation(float time) {
    this->animations[int(this->curAnimation)].Update(*s, time);
}

void Blacksmith::initAnim() {
    this->animations[int(AnimationIndex::Walking)] = Animation(0, 0.008, 0, 0, 0, 0, 0);
}

void Blacksmith::update(float time, GameLvL *gLvL){
    this->gameLvL = gLvL;
    this->animation(time);
    this->position.x = this->dx *time;
    this->checkCollisionMap(this->dx, 0);
    this->position.y = this->dy * time;
    checkCollisionMap(0, this->dy);
    this->dy += 0.0015 * time;
    this->s->setPosition(position);
}

void Blacksmith::Dialogue(sf::Event event, Player player) {
    this->t_Nps->text->setPosition(this->position.x + 25, this->position.y - 60);
    ostringstream  d_Nps;
    if(event.type == Event::KeyPressed){
        if(event.key.code == Keyboard::F){
            if(player.e_Radius->getGlobalBounds().intersects(this->getRect())){
                switch (this->isNpsDialogue){
                    case true:
                        this->isNpsDialogue = false;
                        d_Nps << getNpsMessage(this->ClickNps, this->gameLvL->gameLvL, this->name);
                        this->t_Nps->text->setString(d_Nps.str());
                        if(this->gameLvL->gameLvL == 1){
                            if(this->ClickNps<=7) this->ClickNps++;
                            if(this->ClickNps==8)this->ClickNps--;
                        }
                        else if(this->gameLvL->gameLvL == 2){
                            if(this->ClickNps<=7) this->ClickNps++;
                            if(this->ClickNps==8)this->ClickNps--;
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

void Blacksmith::Interaction(sf::Event event, Player &player) {
    if(player.e_Radius->getGlobalBounds().intersects(this->getRect())){
        if(this->ClickNps == 7){
            if(event.type == Event::KeyPressed){
                if(event.key.code == Keyboard::Num1){
                    if(player.money > 9 && player.lvl_player < 10 && !this->isNpsDialogue){
                        player.lvl_player += 1;
                        player.is_health += 30;
                        player.f_health += 30;
                        player.money -= 10;
                    }
                }
                if(event.key.code == Keyboard::Num2){
                    this->isNpsDialogue = true;
                }
            }
        }
    }
}