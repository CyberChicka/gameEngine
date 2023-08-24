//
// Created by Doni on 24.08.2023.
//

#include "Particle_of_Strength_item.h"

Particle_of_Strength_item::Particle_of_Strength_item(Sprite *sprite, GameLvL *LvL, float X, float Y, int W, int H, string Name): Item(sprite, LvL, X, Y, W, H, Name) {
    if(name == "Sprint")this->s->setScale(2.5f, 2.5f);
    if(name == "Shoot")this->s->setScale(2.5f, 2.5f);
    if(this->name == "Repulsion")this->s->setScale(2.5f, 2.5f);
    if(this->name == "Speed")this->s->setScale(2.5f, 2.5f);
    this->initAnim();
}
Particle_of_Strength_item::~Particle_of_Strength_item() {
    cout << "============== removed from item money ============" << endl;
    delete this->s;
    delete this->gameLvL;
}

void Particle_of_Strength_item::initAnim() {
    if(this->name == "Sprint")
        this->animations[int(AnimationIndex::Walking)] = Animation(16, 0.008, 16, 0, 14, 16, 0);
    if(this->name == "Shoot")
        this->animations[int(AnimationIndex::Walking)] = Animation(16, 0.008, 16, 0, 14, 16, 0);
    if(this->name == "Repulsion")
        this->animations[int(AnimationIndex::Walking)] = Animation(16, 0.008, 16, 0, 14, 16, 0);
    if(this->name == "Speed")
        this->animations[int(AnimationIndex::Walking)] = Animation(16, 0.008, 16, 0, 14, 16, 0);
}
void Particle_of_Strength_item::animation(float time){
    this->curAnimation = AnimationIndex::Walking;
    this->animations[int(this->curAnimation)].Update(*s, time);
}

bool Particle_of_Strength_item::isTake(Player &player){
    if(player.e_Radius->getGlobalBounds().intersects(this->getRect())){
        if(this->name == "Sprint"){ player.particle_of_strength_sprint = true; return true; }
        if(this->name == "Shoot"){ player.particle_of_strength_shoot = true; return true; }
        if(this->name == "Repulsion"){ player.particle_of_strength_repulsion = true; return true;}
        if(this->name == "Speed"){player.particle_of_strength_speed = true; return true; }
    }
    return false;
}