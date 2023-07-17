//
// Created by Doni on 16.07.2023.
//

#include "Inventory.h"

Inventory::Inventory(Sprite *sprite) {
    this->s = sprite;
    this->s_inGoldKey = new CreateImage("SpriteObject/inGoldKey.png");
    this->s_inSilverKey = new CreateImage("SpriteObject/inSilverKey.png");
    this->s_inMoney = new CreateImage("SpriteObject/inMoney.png");
    this->s_inBackpackInventory = new CreateImage("SpriteObject/inInventory.png");
    this->t_health = new CreateText("MaredivRegular.ttf", 20, " ", Color(10, 10, 10));
    this->t_lvl = new CreateText("MaredivRegular.ttf", 20, " ", Color(10, 10, 10));
    this->t_silver_key = new CreateText("MaredivRegular.ttf", 15, " ", Color(10, 10, 10));
    this->t_gold_key = new CreateText("MaredivRegular.ttf", 15, " ", Color(10, 10, 10));
    this->t_money = new CreateText("MaredivRegular.ttf", 15, " ", Color(10, 10, 10));
}
Inventory::~Inventory() {
    delete this->s_inGoldKey;
    delete this->s_inSilverKey;
    delete this->s_inMoney;
    delete this->t_gold_key;
    delete this->t_money;
    delete this->t_lvl;
    delete this->t_silver_key;
    delete this->t_health;
    delete this->s;
}

void Inventory::update(Player *player){
    this->isInvent = player->isInventory;
    ostringstream os_isHealth, os_fHealth, os_LvL,os_money, os_silver_key, os_gold_key;
    os_isHealth << player->is_health;
    os_fHealth << player->f_health;
    os_LvL << player->lvl_player;
    os_gold_key << player->k_Gold;
    os_silver_key << player->k_Silver;
    os_money << player->money;

    this->t_health->setString(os_isHealth.str() + " / " + os_fHealth.str());
    this->t_lvl->setString("Is LvL : " + os_LvL.str());
    this->t_silver_key->setString(os_silver_key.str());
    this->t_gold_key->setString(os_gold_key.str());
    this->t_money->setString(os_money.str());
}

void Inventory::position(View view){
    this->s->setPosition(view.getCenter().x - 600, view.getCenter().y - 200);
    //sprite
    this->s_inBackpackInventory->s->setPosition(view.getCenter().x - 480, view.getCenter().y + 240);
    this->s_inMoney->s->setPosition(view.getCenter().x - 175, view.getCenter().y - 65);
    this->s_inSilverKey->s->setPosition(view.getCenter().x - 175, view.getCenter().y - 15);
    this->s_inGoldKey->s->setPosition(view.getCenter().x - 175, view.getCenter().y + 38);
    //text
    this->t_money->text->setPosition(view.getCenter().x - 140, view.getCenter().y - 38);
    this->t_silver_key->text->setPosition(view.getCenter().x - 140, view.getCenter().y + 16);
    this->t_gold_key->text->setPosition(view.getCenter().x - 140, view.getCenter().y + 68);
    this->t_lvl->text->setPosition(view.getCenter().x - 426, view.getCenter().y - 92);
    this->t_health->text->setPosition(view.getCenter().x - 375, view.getCenter().y - 122);
}
void Inventory::draw(sf::RenderWindow &window, View view){
    this->position(view);
    if(this->isInvent){
        this->s_inBackpackInventory->s->setTextureRect(IntRect(68, 0, 64, 64));
        window.draw(*this->s);
        window.draw(*this->s_inGoldKey->s);
        window.draw(*this->s_inSilverKey->s);
        window.draw(*this->s_inMoney->s);
        window.draw(*this->t_health->text);
        window.draw(*this->t_lvl->text);
        window.draw(*this->t_money->text);
        window.draw(*this->t_gold_key->text);
        window.draw(*this->t_silver_key->text);
    }
    else{ this->s_inBackpackInventory->s->setTextureRect(IntRect(0, 0, 64, 64)); }
    window.draw(*this->s_inBackpackInventory->s);
}