//
// Created by Doni on 16.07.2023.
//

#include "Inventory.h"

Inventory::Inventory(Sprite *sprite) {
    this->s = sprite;
    this->inGoldKey = new CreateImage("SpriteObject/inGoldKey.png");
    this->inSilverKey = new CreateImage("SpriteObject/inSilverKey.png");
    this->inMoney = new CreateImage("SpriteObject/inMoney.png");
    this->inBackpackInventory = new CreateImage("SpriteObject/inInventory.png");
    this->t_health = new CreateText("MaredivRegular.ttf", 20, " ", Color(10, 10, 10));
    this->t_lvl = new CreateText("MaredivRegular.ttf", 20, " ", Color(10, 10, 10));
    this->t_silver_key = new CreateText("MaredivRegular.ttf", 15, " ", Color(10, 10, 10));
    this->t_gold_key = new CreateText("MaredivRegular.ttf", 15, " ", Color(10, 10, 10));
    this->t_money = new CreateText("MaredivRegular.ttf", 15, " ", Color(10, 10, 10));
}
Inventory::~Inventory() {
    delete this->inGoldKey;
    delete this->inSilverKey;
    delete this->inMoney;
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
    this->position(player);
}

void Inventory::position(Player *p){
    this->s->setPosition(p->pos);
    //sprite
    this->inBackpackInventory->s->setPosition(p->pos.x - 100, p->pos.y - 100);
    this->inMoney->s->setPosition(p->pos.x - 172, p->pos.y - 65);
    this->inSilverKey->s->setPosition(p->pos.x - 172, p->pos.y - 15);
    this->inGoldKey->s->setPosition(p->pos.x - 172, p->pos.y + 38);
    //text
    this->t_silver_key->text->setPosition(p->pos.x - 134, p->pos.y + 12);
    this->t_gold_key->text->setPosition(p->pos.x - 134, p->pos.y + 65);
    this->t_money->text->setPosition(p->pos.x - 134, p->pos.y - 42);
    this->t_lvl->text->setPosition(p->pos.x - 426, p->pos.y - 92);
    this->t_health->text->setPosition(p->pos.x - 375, p->pos.y - 122);
}
void Inventory::draw(sf::RenderWindow &window){
    if(this->isInvent){
        this->inBackpackInventory->s->setTextureRect(IntRect(64, 0, 64, 64));
        window.draw(*this->s);
        window.draw(*this->inGoldKey->s);
        window.draw(*this->inSilverKey->s);
        window.draw(*this->inMoney->s);
        window.draw(*this->t_health->text);
        window.draw(*this->t_lvl->text);
        window.draw(*this->t_money->text);
        window.draw(*this->t_gold_key->text);
        window.draw(*this->t_silver_key->text);
    }
    else{
        this->inBackpackInventory->s->setTextureRect(IntRect(0, 0, 64, 64));
    }
    window.draw(*this->inBackpackInventory->s);
}