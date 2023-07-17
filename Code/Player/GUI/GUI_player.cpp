//
// Created by Doni on 16.07.2023.
//

#include "GUI_player.h"

GUI_player::GUI_player(sf::Sprite *S_Health, sf::Sprite *S_Inventory, sf::Sprite *S_Features) {
    this->s_health = S_Health;
    this->s_inventory = S_Inventory;
    this->s_features = S_Features;
    this->GUI_life = new LifeBar(s_health);
    this->GUI_invent = new Inventory(s_inventory);
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
}

void GUI_player::GUI_draw(sf::RenderWindow &window){
    if(this->GUI_visible){
        this->GUI_invent->draw(window);
        this->GUI_life->draw(window);
    }
}