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
    this->s->setPosition(player->pos.x - 600, player->pos.y - 450);
    this->bar.setPosition(player->pos.x - 548, player->pos.y - 418);
    if(player->is_health >= 0){
        if(player->is_health <= player->f_health){
            this->bar.setSize(Vector2f((player->f_health - player->is_health) * 10 / player->f_health, 10));
        }
    }
}

void LifeBar::draw(sf::RenderWindow &window) {
    window.draw(*this->s);
    window.draw(this->bar);
}