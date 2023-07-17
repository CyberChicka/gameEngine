//
// Created by Doni on 17.07.2023.
//

#include "Features.h"

Features::Features() {
    this->s_features_shoot = new CreateImage("SpriteEntity/Player/iconMenuGame/features-1.png");
    this->s_features_sprint = new CreateImage("SpriteEntity/Player/iconMenuGame/features-2.png");
    this->s_features_shoot->s->setScale(0.3f, 0.3f);
    this->s_features_sprint->s->setScale(0.3f, 0.3f);
}
Features::~Features() {
    delete this->s_features_shoot;
    delete this->s_features_sprint;
}

void Features::update(Player *player) {
    if(player->isShoot){
        this->s_features_shoot->s->setTextureRect(IntRect(0, 0, 200, 200));
    }
    else{
        this->s_features_shoot->s->setTextureRect(IntRect(200, 0, 200, 200));
    }
    if(player->isSprint){
        this->s_features_sprint->s->setTextureRect(IntRect(0, 0, 200, 200));
    }
    else{
        this->s_features_sprint->s->setTextureRect(IntRect(200, 0, 200, 200));
    }
}

void Features::position(sf::View view) {
    this->s_features_sprint->s->setPosition(view.getCenter().x + 450, view.getCenter().y + 245);
    this->s_features_shoot->s->setPosition(view.getCenter().x + 380, view.getCenter().y + 245);
}
void Features::draw(sf::RenderWindow &window, View view) {
    position(view);
    window.draw(*this->s_features_sprint->s);
    window.draw(*this->s_features_shoot->s);
}