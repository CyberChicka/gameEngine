//
// Created by Doni on 29.06.2023.
//

#include "LifeBar.h"

LifeBar::LifeBar(Sprite *sprite) {
    this->s = sprite;
    this->bar.setFillColor(Color::Black);
}
LifeBar::~LifeBar() {
    delete this->s;
}

void LifeBar::update(Player *player) {
    if(player->is_health >= 0){
        if(player->is_health <= player->f_health){

            this->bar.setSize(Vector2f((player->f_health - player->is_health) * 317 / player->f_health, 26));
        }
    }
}

void LifeBar::position(sf::View view) {
    this->s->setPosition(view.getCenter().x - 600, view.getCenter().y - 320);
    this->bar.setPosition(view.getCenter().x - 548, view.getCenter().y - 288);
}

void LifeBar::draw(sf::RenderWindow &window, View view) {
    position(view);
    window.draw(*this->s);
    window.draw(this->bar);
}