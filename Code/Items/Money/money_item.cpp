//
// Created by Doni on 09.06.2023.
//

#include "money_item.h"

money_item::money_item(sf::Sprite *sprite, GameLvL *LvL, float X, float Y, int W, int H, std::string Name): Item(sprite, LvL, X, Y, W, H, Name){
    if(this->name == "Money"){ this->s->setScale(0.7f, 0.7f); }
    if(this->name == "Diamond"){ this->s->setScale(0.7f, 0.7f);  }
    initAnim();
}
money_item::~money_item() {
    cout << "============== removed from item money ============" << endl;
    delete this->s;
    delete this->gameLvL;
}

void money_item::initAnim() {
    if(this->name == "Money")
        this->animations[int(AnimationIndex::Walking)] = Animation(6, 0.008, 36, 0, 36, 46, 0);
    if(this->name == "Diamond")
        this->animations[int(AnimationIndex::Walking)] = Animation(6, 0.008, 59, 0, 40, 60, 0);
}

void money_item::animation(float time) {
    this->curAnimation = AnimationIndex::Walking;
    this->animations[int(this->curAnimation)].Update(*s, time);
}

bool money_item::isTake(Player &player) {
    if(player.e_Radius->getGlobalBounds().intersects(this->getRect())){
        if(this->name == "Money"){ player.money += 1; return true; }
        if(this->name == "Diamond"){ player.money += 5; return true; }
    }
    else return false;
}