//
// Created by Doni on 16.07.2023.
//

#include "Inventory.h"

Inventory::Inventory(Sprite *sprite) {
    this->s = sprite;
    this->s_goldKey = new CreateImage("SpriteObject/inGoldKey.png");
    this->s_silverKey = new CreateImage("SpriteObject/inSilverKey.png");
    this->s_money = new CreateImage("SpriteObject/inMoney.png");
    this->s_backpack_inventory = new CreateImage("SpriteObject/inInventory.png");
    this->t_health = new CreateText("MaredivRegular.ttf", 20, " ", Color(10, 10, 10));
    this->t_lvl = new CreateText("MaredivRegular.ttf", 20, " ", Color(10, 10, 10));
    this->t_silver_key = new CreateText("MaredivRegular.ttf", 15, " ", Color(10, 10, 10));
    this->t_gold_key = new CreateText("MaredivRegular.ttf", 15, " ", Color(10, 10, 10));
    this->t_money = new CreateText("MaredivRegular.ttf", 15, " ", Color(10, 10, 10));
    this->s_sword[0] = new CreateImage(" ");
    this->s_sword[1] = new CreateImage("SpriteItems/sword_shield/SwordBlue.png");
    this->s_sword[2] = new CreateImage("SpriteItems/sword_shield/SwordRed.png");
    this->s_sword[3] = new CreateImage("SpriteItems/sword_shield/SwordGreen.png");
    this->s_sword[4] = new CreateImage("SpriteItems/sword_shield/SwordBrow.png");
    this->s_shield[0] = new CreateImage(" ");
    this->s_shield[1] = new CreateImage("SpriteItems/sword_shield/ShieldBlue.png");
    this->s_shield[2] = new CreateImage("SpriteItems/sword_shield/ShieldRed.png");
    this->s_shield[3] = new CreateImage("SpriteItems/sword_shield/ShieldGreen.png");
    this->s_shield[4] = new CreateImage("SpriteItems/sword_shield/ShieldBrow.png");
    for(int i = 0; i < size(s_sword); i++){
        this->s_sword[i]->s->setScale(0.5f, 0.5f);
        this->s_shield[i]->s->setScale(0.5f, 0.5f);
    }
}
Inventory::~Inventory() {
    delete this->s_goldKey;
    delete this->s_silverKey;
    delete this->s_money;
    delete this->t_gold_key;
    delete this->t_money;
    delete this->t_lvl;
    delete this->t_silver_key;
    delete this->t_health;
    delete this->s;
    for(int i = 0; i < size(s_sword); i++){
        delete this->s_sword[i];
        delete this->s_shield[i];
    }
}

void Inventory::update(Player *player){
    if(Mouse::isButtonPressed(sf::Mouse::Right)){
        for(int i = 0; i < size(s_sword); i++){
            if(player->sword[i] && player->shield[i]){
                if(s_sword[i]->isToch(p_mouse)){
                    player->equipment[i] = true;
                }
            }
        }
    }
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
    this->s_sword[1]->s->setPosition(view.getCenter().x - 420, view.getCenter().y - 50);
    this->s_sword[2]->s->setPosition(view.getCenter().x - 370, view.getCenter().y - 50);
    this->s_sword[3]->s->setPosition(view.getCenter().x - 318, view.getCenter().y - 50);
    this->s_sword[4]->s->setPosition(view.getCenter().x - 265, view.getCenter().y - 50);
    this->s_shield[1]->s->setPosition(view.getCenter().x - 420, view.getCenter().y - 16);
    this->s_shield[2]->s->setPosition(view.getCenter().x - 370, view.getCenter().y - 16);
    this->s_shield[3]->s->setPosition(view.getCenter().x - 318, view.getCenter().y - 16);
    this->s_shield[4]->s->setPosition(view.getCenter().x - 265, view.getCenter().y - 16);
    this->s->setPosition(view.getCenter().x - 600, view.getCenter().y - 200);
    //sprite
    this->s_backpack_inventory->s->setPosition(view.getCenter().x - 480, view.getCenter().y + 240);
    this->s_money->s->setPosition(view.getCenter().x - 175, view.getCenter().y - 65);
    this->s_silverKey->s->setPosition(view.getCenter().x - 175, view.getCenter().y - 15);
    this->s_goldKey->s->setPosition(view.getCenter().x - 175, view.getCenter().y + 38);
    //text
    this->t_money->text->setPosition(view.getCenter().x - 140, view.getCenter().y - 38);
    this->t_silver_key->text->setPosition(view.getCenter().x - 140, view.getCenter().y + 16);
    this->t_gold_key->text->setPosition(view.getCenter().x - 140, view.getCenter().y + 68);
    this->t_lvl->text->setPosition(view.getCenter().x - 426, view.getCenter().y - 92);
    this->t_health->text->setPosition(view.getCenter().x - 375, view.getCenter().y - 122);
}
void Inventory::draw(sf::RenderWindow &window, Player *player, View view){
    this->l_position = Mouse::getPosition(window);
    this->p_mouse = window.mapPixelToCoords(l_position);
    this->position(view);
    if(this->isInvent){
        this->s_backpack_inventory->s->setTextureRect(IntRect(68, 0, 64, 64));
        window.draw(*this->s);
        window.draw(*this->s_goldKey->s);
        window.draw(*this->s_silverKey->s);
        window.draw(*this->s_money->s);
        window.draw(*this->t_health->text);
        window.draw(*this->t_lvl->text);
        window.draw(*this->t_money->text);
        window.draw(*this->t_gold_key->text);
        window.draw(*this->t_silver_key->text);
        for(int i = 0; i < size(player->sword); i++){
            if(player->sword[i])window.draw(*this->s_sword[i]->s);
            if(player->shield[i])window.draw(*this->s_shield[i]->s);
        }
    }
    else{ this->s_backpack_inventory->s->setTextureRect(IntRect(0, 0, 64, 64));}
    window.draw(*this->s_backpack_inventory->s);
}