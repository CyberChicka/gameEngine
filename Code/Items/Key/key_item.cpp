//
// Created by Doni on 09.06.2023.
//

#include "key_item.h"

key_item::key_item(sf::Sprite *sprite, GameLvL *LvL, float X, float Y, int W, int H, std::string Name): Item(sprite, LvL, X, Y, W, H, Name){
    if(this->name == "KeySilver"){ this->s->setScale(0.7f, 0.7f); }
    if(this->name == "KeyGold"){ this->s->setScale(0.7f, 0.7f); }
    this->initAnim();
}
key_item::~key_item() {
    cout << "============== removed from item key ============" << endl;
    delete this->s;
    delete this->gameLvL;
}

void key_item::initAnim() {
    if(this->name == "KeySilver")
        this->animations[int(AnimationIndex::Walking)] = Animation(6, 0.008, 38, 0, 25, 52, 0);
    if(this->name == "KeyGold")
        this->animations[int(AnimationIndex::Walking)] = Animation(6, 0.008, 38, 0, 25, 52, 0);
}

void key_item::animation(float time) {
    this->curAnimation = AnimationIndex::Walking;
    this->animations[int(this->curAnimation)].Update(*s, time);
}

bool key_item::isTake(Player &player) {
    if(player.e_Radius->getGlobalBounds().intersects(this->getRect())){
        if(this->name == "KeySilver"){ player.k_silver += 1; return true; }
        if(this->name == "KeyGold"){ player.k_gold += 1; return true; }
    }
    return false;
}
