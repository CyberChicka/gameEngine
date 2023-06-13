//
// Created by Doni on 17.05.2023.
//

#include "Item.h"

Item::Item(sf::Sprite *sprite, GameLvL *LvL,  float X, float Y, int W, int H, std::string Name) : Entity(sprite, LvL, X, Y, W, H, Name){
    if(this->name == "Health"){ }
    if(this->name == "Money"){ }
    if(this->name == " "){ }
    if(this->name == " "){ }
}
Item::~Item() {
    cout << "============== removed from item ============" << endl;
    delete s;
}

void Item::animation(float time) {
    if(this->name == "Health"){

    }
    if(this->name == "Money"){

    }
}

bool Item::isTake(Player &player){
    if(player.e_Radius->getGlobalBounds().intersects(this->getRect())){
        if(this->name == "Health"){
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
        if(this->name == "Money"){ player.money += 1; return true; }
        if(this->name == "Diamond"){ player.money += 5; return true; }
        if(this->name == "SilverKey"){ player.k_Silver++; return true; }
        if(this->name == "GoldKey"){ player.k_Gold++; return true; }
    }
    return false;
}

void Item::update(float time) {
    animation(time);
    this->position.x += this->dx*time;
    checkCollisionMap(this->dx, 0);
    this->position.y += this->dy*time;
    checkCollisionMap(0, this->dy);
    if(!this->onGround) this->dy = this->dy + 0.0015*time;
    this->s->setPosition(this->position);
}

float Item::GetX() { return this->position.x; }
float Item::GetY() { return this->position.y; }

void Item::checkCollisionMap(float dX, float dY) {

}

void Item::draw(sf::RenderWindow &window){ window.draw(*this->s); }