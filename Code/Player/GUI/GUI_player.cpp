//
// Created by Doni on 16.07.2023.
//

#include "GUI_player.h"

GUI_player::GUI_player() {
    this->s_health = new CreateImage("SpriteEntity/Player/iconMenuGame/HealthBar.png");
    this->s_inventory = new CreateImage("SpriteEntity/Player/iconMenuGame/OpenInventory.png");
    this->s_features = new CreateImage("SpriteEntity/Player/iconMenuGame/features.png");
    this->GUI_features = new Features;
    this->GUI_life = new LifeBar(s_health->s);
    this->GUI_invent = new Inventory(s_inventory->s);
    this->GUI_visible = true;
}
GUI_player::~GUI_player() {
    cout << "============== removed from gui player ============"<< endl;
    delete this->GUI_life;
    delete this->GUI_invent;
    delete this->s_health;
    delete this->s_features;
    delete this->s_inventory;
}

void GUI_player::GUI_update(Player *player){
    this->GUI_invent->update(player);
    this->GUI_life->update(player);
    this->GUI_features->update(player);
}

void GUI_player::GUI_draw(sf::RenderWindow &window, View view){
    if(this->GUI_visible){
        this->GUI_invent->draw(window, view);
        this->GUI_life->draw(window, view);
        this->GUI_features->draw(window, view);
    }
}