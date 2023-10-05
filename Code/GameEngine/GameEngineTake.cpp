#include "../Code/GameEngine.h"

void GameEngine::TakeItems() {
    if (game_event.type == Event::KeyPressed){
        if (game_event.key.code == Keyboard::F){
            for(itItem = itemLvL[gameLvL->gameLvL].begin(); itItem != itemLvL[gameLvL->gameLvL].end(); itItem++){
                if ((*itItem)->isTake(*player))
                    this->itemLvL[gameLvL->gameLvL].erase(itItem);
            }
        }
    }
}
void GameEngine::TakeChest() {
    if (game_event.type == Event::KeyPressed) {
        if (game_event.key.code == Keyboard::F) {
            for (itChest = chestLvL[gameLvL->gameLvL].begin(); itChest != chestLvL[gameLvL->gameLvL].end(); itChest++) {
                if (player->e_Radius->getGlobalBounds().intersects((*itChest)->getRect())) {
                    if ((*itChest)->name == "SmallChest") {
                        if ((*itChest)->is_open) {
                            if ((*itChest)->OpenChest() == 1){ itemLvL[gameLvL->gameLvL].push_back(new key_item(config->s_item_KeySilver->s, gameLvL, (*itChest)->pos.x + 18, (*itChest)->pos.y, 40, 45, "KeySilver")); }
                            if ((*itChest)->OpenChest() == 2){ itemLvL[gameLvL->gameLvL].push_back(new health_item(config->s_item_health->s, gameLvL, (*itChest)->pos.x + 18, (*itChest)->pos.y, 40, 45, "Health")); }
                            if ((*itChest)->OpenChest() == 3){ }
                        }
                    }
                    if ((*itChest)->name == "MiddleChest" && player->k_silver > 0) {
                        if (((*itChest)->is_open)) {
                            if ((*itChest)->OpenChest() == 1){this->itemLvL[gameLvL->gameLvL].push_back(new key_item(config->s_item_KeyGold->s, gameLvL, (*itChest)->pos.x + 22, (*itChest)->pos.y, 40, 45, "KeyGold"));}
                            if ((*itChest)->OpenChest() == 2){this->itemLvL[gameLvL->gameLvL].push_back(new money_item(config->s_item_money->s, gameLvL, (*itChest)->pos.x + 22, (*itChest)->pos.y, 40, 45, "Money"));}
                            if ((*itChest)->OpenChest() == 3){this->itemLvL[gameLvL->gameLvL].push_back(new health_item(config->s_item_health->s, gameLvL, (*itChest)->pos.x + 22, (*itChest)->pos.y, 40, 45, "Health"));}
                            this->player->k_silver--;
                        }
                    }
                    if ((*itChest)->name == "BigChest" && player->k_gold > 0) {
                        if (((*itChest)->is_open)) {
                            if ((*itChest)->OpenChest() == 1){this->itemLvL[gameLvL->gameLvL].push_back(new money_item(config->s_item_diamond->s, gameLvL, (*itChest)->pos.x + 25, (*itChest)->pos.y, 40, 45, "Diamond"));}
                            if ((*itChest)->OpenChest() == 2){this->itemLvL[gameLvL->gameLvL].push_back(new key_item(config->s_item_KeyGold->s, gameLvL, (*itChest)->pos.x + 25, (*itChest)->pos.y, 40, 45, "KeyGold"));}
                            if ((*itChest)->OpenChest() == 3){this->itemLvL[gameLvL->gameLvL].push_back(new key_item(config->s_item_KeySilver->s, gameLvL, (*itChest)->pos.x + 25, (*itChest)->pos.y, 40, 45, "KeySilver"));}
                            this->player->k_gold--;
                        }
                    }
                }
            }
        }
    }
}
void GameEngine::TakeNps() {
    for(itNps = npsLvL[gameLvL->gameLvL].begin(); itNps != npsLvL[gameLvL->gameLvL].end(); itNps++){
        (*itNps)->Dialogue(game_event, player);
        (*itNps)->Interaction(game_event, *player);
    }
}
void GameEngine::TakeDoor() {

}
void GameEngine::TakeEnemy() {
    for(itEnemy = enemyLvL[gameLvL->gameLvL].begin(); itEnemy != enemyLvL[gameLvL->gameLvL].end(); itEnemy++){
        (*itEnemy)->TakingDamage(*this->player, bulletLvL, game_event);
    }
}
void GameEngine::ShootBullet() {
    if(player->life){
        if(game_event.type == Event::KeyPressed){
            if(game_event.key.code == Keyboard::LControl){
                if(player->isShoot && player->particle_of_strength_shoot){
                    for(int i = 0; i < size(player->equipment); i++)
                        if(player->equipment[i])
                            this->bulletLvL.push_back(new Bullet(config->s_shuriken[i]->s, gameLvL,
                                                                 player->GetX(), player->GetY() - 40, 130, 90,
                                                                 "Shuriken", player->state));
                    this->player->bullet_time = 0;
                }
            }
        }
    }
}
void GameEngine::TakeInventory() {
    if(game_event.type == Event::KeyPressed){
        if(game_event.key.code == Keyboard::E){
            switch (this->player->isInventory) {
                case true: this->player->isInventory = false; break;
                case false: this->player->isInventory = true; break;
            }
        }
    }
}

void GameEngine::TakeObject() {
    if (game_event.type == Event::KeyPressed){
        if (game_event.key.code == Keyboard::F){
            for(itObject = objLvL[gameLvL->gameLvL].begin(); itObject != objLvL[gameLvL->gameLvL].end(); itObject++){
                (*itObject)->isTouch(*this->player);
            }
        }
    }
}