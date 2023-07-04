//
// Created by Doni on 09.06.2023.
//

#include "health_item.h"

health_item::health_item(sf::Sprite *sprite, GameLvL *LvL, float X, float Y, int W, int H, std::string Name): Item(sprite, LvL, X, Y, W, H, Name){
    this->s->setScale(0.9f, 0.9f);
    this->initAnim();
}
health_item::~health_item() {
    cout << "============== removed from item health ============" << endl;
    delete this->s;
    delete this->gameLvL;
}

bool health_item::isTake(Player &player) {
    if(player.e_Radius->getGlobalBounds().intersects(this->getRect())){
        if(player.is_health < player.f_health){
            if(player.f_health - player.is_health <= 10){
                player.is_health+=player.f_health - player.is_health;
                return true;
            }
            else {
                player.is_health += 10;
                return true;
            }
        } else return false;
    }
    return false;
}

void health_item::initAnim() {
    this->animations[int(AnimationIndex::Walking)] = Animation(6, 0.008, 52, 0, 40, 45, 0);
}

void health_item::animation(float time) {
    this->curAnimation = AnimationIndex::Walking;
    this->animations[int(this->curAnimation)].Update(*s, time);
}