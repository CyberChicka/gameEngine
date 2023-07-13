//
// Created by Doni on 15.05.2023.

#include "GameEngine.h"

GameEngine::GameEngine() {
    this->initWindow();
    this->initClass();
}
GameEngine::~GameEngine() {
    cout << "========== removed from memory ========" << endl;
    if(this->window != nullptr){ delete this->window; }
    delete Config::getInstance(); // очищаем память
    delete this->player; // очищаем память
    delete this->gameLvL; // очищаем память
}
bool GameEngine::isRunning(){
    if (this->window == nullptr){ cout << "\n Error Windows \n"; return false; }
    else return this->window->isOpen();
}

void GameEngine::update() {
    // Time
    this->game_time = this->clock.getElapsedTime().asMicroseconds();
    this->elapsed = this->clock.restart();
    this->game_time = this->game_time / 800;
    // View
    this->config->getPlayerCoordinateForView(this->player->GetX(), this->player->GetY());
    // Fon update
    for(itFon = fonLvL[gameLvL->gameLvL].begin(); itFon != fonLvL[gameLvL->gameLvL].end(); itFon++){
        (*itFon)->update(game_time, gameLvL);
    }
    // player update
    this->player->update(game_time, gameLvL);
    this->player->particles->update(elapsed);
    // Object update
    for(itObject = objLvL[gameLvL->gameLvL].begin(); itObject != objLvL[gameLvL->gameLvL].end(); itObject++){
        (*itObject)->update(game_time, gameLvL);
    }
    // Enemy update
    for(itEnemy = enemyLvL[gameLvL->gameLvL].begin(); itEnemy != enemyLvL[gameLvL->gameLvL].end(); itEnemy++){
        (*itEnemy)->Attack(*player);
        if(!(*itEnemy)->life)this->enemyLvL[gameLvL->gameLvL].erase(itEnemy);
        (*itEnemy)->update(game_time, gameLvL,  player);
    }
    for(itChest = chestLvL[gameLvL->gameLvL].begin(); itChest != chestLvL[gameLvL->gameLvL].end(); itChest++){
        (*itChest)->update(game_time, gameLvL);
    }
    // Nps update
    for(itNps = npsLvL[gameLvL->gameLvL].begin(); itNps != npsLvL[gameLvL->gameLvL].end(); itNps++){
        (*itNps)->update(game_time, gameLvL);
    }
    // Item update
    for(itItem = itemLvL[gameLvL->gameLvL].begin(); itItem != itemLvL[gameLvL->gameLvL].end(); itItem++){
        (*itItem)->update(game_time, gameLvL);
    }
    // Bullet update
    for(itBullet = bulletLvL.begin(); itBullet != bulletLvL.end(); itBullet++){
        (*itBullet)->upadte(game_time);
    }
    // Evnet
    this->pollEvents();
}

void GameEngine::render(){ // Рендер изображения
    renderClear();
    // render fon
    for(itFon = fonLvL[gameLvL->gameLvL].begin(); itFon != fonLvL[gameLvL->gameLvL].end(); itFon++){
        (*itFon)->draw(*window, config->view);
    }
    gameLvL->RenderDraw(*window, config->view); // Рисуем карту\

    // Object render
    for(itObject = objLvL[gameLvL->gameLvL].begin(); itObject != objLvL[gameLvL->gameLvL].end(); itObject++){
        (*itObject)->draw(*window, config->view);
    }
    // Nps render
    for(itNps = npsLvL[gameLvL->gameLvL].begin(); itNps != npsLvL[gameLvL->gameLvL].end(); itNps++){
        (*itNps)->draw(*window, config->view);
    }
    // Chest render
    for(itChest = chestLvL[gameLvL->gameLvL].begin(); itChest != chestLvL[gameLvL->gameLvL].end(); itChest++){
        (*itChest)->draw(*window, config->view);
    }
    // Item render
    for(itItem = itemLvL[gameLvL->gameLvL].begin(); itItem != itemLvL[gameLvL->gameLvL].end(); itItem++){
        (*itItem)->draw(*window, config->view);
    }
    // render player
    this->player->draw(*window, config->view);
    // Enemy render
    for(itEnemy = enemyLvL[gameLvL->gameLvL].begin(); itEnemy != enemyLvL[gameLvL->gameLvL].end(); itEnemy++){
        (*itEnemy)->draw(*window, config->view);
    }
    // Bullet Render
    for(itBullet = bulletLvL.begin(); itBullet != bulletLvL.end(); itBullet++){
        (*itBullet)->draw(*window, config->view);
    }
    this->window->setView(config->view); // привязываем окно к камере
    this->window->display(); // создаём дисплей
}

void GameEngine::initWindow() {
    // для начало используем это способ, потом через настройки будем изменять размер
    this->config->window_size.x = VideoMode::getDesktopMode().width / 2; // ширину монитора делим на 2
    this->config->window_size.y = VideoMode::getDesktopMode().height / 2;// высоту монитора делим на 2
    this->config->view_size.x = this->config->window_size.x;
    this->config->view_size.y = this->config->window_size.y;
    const VideoMode videoMode = VideoMode(1280, 720);
    const Uint32 style = sf::Style::Close| sf::Style::Titlebar;
    // Создание окна и камеру, вертикальное синхронизация
    this->window = new sf::RenderWindow(videoMode, config->window_title, style);
    this->config->view.reset(FloatRect(0, 0, config->view_size.x, config->view_size.y));
    this->window->setFramerateLimit(config->window_frame);
    this->window->setVerticalSyncEnabled(true);
}

void GameEngine::initClass() {
    // gameLvL
    this->gameLvL = new GameLvL(config->s_LvL1->s, 1);
    //Player
    this->player = new Player(config->s_player->s, gameLvL ,1000, 1800, 56, 60, "player");
    // Attack Enemy
    this->enemyMagDamage = new FonGame(config->s_Enemy_MagDamage->s, gameLvL, 0, 0, 0, 0,"MagDamage");
    //Enemy
    this->enemyLvL[1] = {
//            new Enemy_Ghost(config->s_EnemyGhost->s, gameLvL, 800, 1236, 40, 88, "Ghost"),
//            new Enemy_Bat(config->s_Enemy_Bat->s, gameLvL, 800, 1236, 65, 55, "Bat"),
//            new Enemy_Boom(config->s_Enemy_Boom->s, gameLvL, 800, 1236, 50, 50, "Boom"),
//            new Enemy_BigGhost(config->s_Enemy_BigGhost->s, gameLvL, 800, 1236, 65, 125, "BigGhost"),
            new Enemy_Mag(config->s_Enemy_Mag->s,enemyMagDamage, gameLvL, 800, 1236, 40, 110, "Mag"),
    };
    //enemy lvl 2
    this->enemyLvL[2] = {
            new Enemy_Ghost(config->s_EnemyGhost->s, gameLvL, 800, 1636, 40, 88, "Ghost"),
    };
    // enemy lvl 3
    this->enemyLvL[3] = {

    };
    // Object LvL 1
    this->objLvL[1] = {
            new Object(config->s_Object_HomeDrov->s, gameLvL, 1200, 1600, 100, 298,"Home"),
            new Object(config->s_Object_TableHouse->s, gameLvL, 9520, 1600, 400, 300, "TableHouse")
    };
    // Object LvL 2
    this->objLvL[2] = {
            new Object(config->s_Object_BushHouse->s, gameLvL, 3400, 1600, 500, 300, "BushHouse"),
            new Object(config->s_Object_BonfireHouse->s, gameLvL, 4100, 1600, 1230, 574, "BonfireHouse"),
    };
    // Object LvL 3
    this->objLvL[3] = {
            new Object(config->s_Object_FlyingObelisk->s, gameLvL, 1400, 1600, 145, 390,"FlyingObelisk"),
            new Object(config->s_Object_DarkTreeBig->s, gameLvL, 1450, 1600, 125, 265,"DarkTreeBig"),
            new Object(config->s_Object_DarkTreeSmall->s, gameLvL, 1450, 1600, 125, 265,"DarkTreeSmall"),
            //RemainsSkeleton
            new Object(config->s_Object_RemainsSkeleton->s, gameLvL, 500, 1600, 95, 72, "RemainsSkeleton"),
            new Object(config->s_Object_RemainsSkeleton->s, gameLvL, 1500, 1600, 95, 72, "RemainsSkeleton"),
            new Object(config->s_Object_RemainsSkeleton->s, gameLvL, 2400, 1600, 95, 72, "RemainsSkeleton"),
            new Object(config->s_Object_RemainsSkeleton->s, gameLvL, 3300, 1600, 95, 72, "RemainsSkeleton"),
            new Object(config->s_Object_RemainsSkeleton->s, gameLvL, 3500, 1600, 95, 72, "RemainsSkeleton"),
            new Object(config->s_Object_RemainsSkeleton->s, gameLvL, 3700, 1600, 95, 72, "RemainsSkeleton"),
    };
    //Chest
    this->chestLvL[1] = {
            new Chest(config->s_Chest_Small->s, gameLvL, 1000, 1600, 65, 70, "SmallChest"),
            new Chest(config->s_Chest_Middle->s, gameLvL, 1200, 1600, 65, 82, "MiddleChest"),
            new Chest(config->s_Chest_Big->s, gameLvL, 1400, 1600, 65, 90, "BigChest"),
            //
            new Chest(config->s_Chest_Small->s, gameLvL, 9790, 1600, 65, 70, "SmallChest"),
            new Chest(config->s_Chest_Small->s, gameLvL, 5903, 1600, 65, 70, "SmallChest"),
            new Chest(config->s_Chest_Middle->s, gameLvL, 570, 1248, 65, 82, "MiddleChest"),
            new Chest(config->s_Chest_Big->s, gameLvL, 3390, 1310, 65, 90, "BigChest")
    };
    this->chestLvL[2] = {
            new Chest(config->s_Chest_Small->s, gameLvL, 3410, 1600, 65, 70, "SmallChest"),
            new Chest(config->s_Chest_Big->s, gameLvL, 2250, 1600, 65, 90, "BigChest"),
    };
    this->chestLvL[3] = {

    };
    //Nps
    this->npsLvL[1] = {
            new Knight(config->s_Nps_Knight->s, gameLvL, config->text_nps_knight, 9500, 586, 56, 138, "Knight"),
            new Historian(config->s_Nps_Historian->s, gameLvL, config->text_nps_historian, 1100, 1520, 156, 150, "Historian"),
            new Blacksmith(config->s_Nps_Blacksmith->s, gameLvL, config->text_nps_blacksmith, 5750, 1620, 122, 152, "Blacksmith")
    };
    // nps lvl 2
    this->npsLvL[2] = {
            new Aiden(config->s_Nps_Aiden->s, gameLvL, config->text_nps_aiden,4550, 1620, 50, 105, "Aiden"),
            new Blacksmith(config->s_Nps_Blacksmith->s, gameLvL, config->text_nps_blacksmith, 1000, 1620, 50, 152, "Blacksmith"),
            new Witcher(config->s_Nps_Witcher->s, gameLvL, config->text_nps_witcher, 800, 1620, 50, 190, "Witcher")
    };
    // nps lvl 3
    this->npsLvL[3] = {
            new Supreme_Wizard(config->s_Nps_SupremeWizard->s, gameLvL, config->text_nps_supreme_wizard, 1250, 1620, 122, 152, "Supreme_Wizard"),
            new Blacksmith(config->s_Nps_Blacksmith->s, gameLvL, config->text_nps_blacksmith, 1100, 1620, 122, 152, "Blacksmith"),
            new Soothsayer(config->s_Nps_Soothsayer->s, gameLvL, config->text_nps_soothsayer, 2000, 1620, 122, 152, "Soothsayer"),
            new Swordsman(config->s_Nps_Swordsman->s, gameLvL, config->text_nps_swordsman, 5280, 1620, 122, 152, "Swordsman")
    };
    // Item
    this->itemLvL[1] = {
            new health_item(config->s_Item_Health->s, gameLvL, 4800, 1600, 40, 45, "Health"),
            new money_item(config->s_Item_Money->s, gameLvL, 300, 1600, 30, 40, "Money"),
            new money_item(config->s_Item_Diamond->s, gameLvL, 9400, 1600, 40, 60, "Diamond"),
            new key_item(config->s_Item_KeySilver->s, gameLvL, 8, 1600, 40, 45, "KeySilver"),
            new key_item(config->s_Item_KeyGold->s, gameLvL, 9300, 1600, 40, 45, "KeyGold")
    };
    // item lvl 2
    this->itemLvL[2] = {

    };
    // item lvl 3
    this->itemLvL[3] = {

    };
    //Fon
    this->fonLvL[1] = {
            new FonGame(config->s_LvL1_Fon->s, gameLvL, 0, 1360, 10, 10,"Fon"),
            new FonGame(config->s_LvL1_Fon->s, gameLvL, 4900, 1360, 10, 10,"Fon"),
            new FonGame(config->s_LvL_1_FonBack->s, gameLvL, 0, 1860, 0, 0, "Back"),
            new FonGame(config->s_LvL_1_FonBack->s, gameLvL, 4900, 1860, 0, 0, "Back")
    };
    // Fon lvl 2
    this->fonLvL[2] = {
//            new FonGame(config->s_LvL2_Fon->s, gameLvL, 0, 1360, 10, 10," "),
//            new FonGame(config->s_LvL2_Fon->s, gameLvL, 4900, 1360, 10, 10," ")
    };
    // Fon lvl 3
    this->fonLvL[3] = {

    };

}
void GameEngine::pollEvents() {
    while (this->window->pollEvent(this->game_event)){
        EventFunc();
        if(game_event.type == Event::Closed || game_event.key.code == Keyboard::Escape){
            this->window->close();
        }
        // масштабирования камеры
        if (game_event.type == sf::Event::MouseWheelScrolled)
        {
            if (game_event.mouseWheelScroll.delta < 0)
                this->config->view.zoom(1.1f);
            else if (game_event.mouseWheelScroll.delta > 0)
                this->config->view.zoom(0.9f);
        }
        if(game_event.type == Event::KeyPressed){
            if(game_event.key.code == Keyboard::P){
                if(player->is_health > 0)
                    this->player->is_health -= 20;
            }
            if(game_event.key.code == sf::Keyboard::Tab){
                cout << "X - " << player->position.x <<"\n"<< "Y - " <<  player->position.y << "\n"
                     << "Health: " <<  player->is_health << " / " << player->f_health << "\n"
                     << "level: " << player->lvl_player<<"\n"
                     << "k_silver: " << player->k_Silver << "\n"
                     << "k_gold: " << player->k_Gold << "\n"
                     << "money: " << player->money << "\n"
                     << "speed: " << player->speed<<endl;
            }
            if(game_event.key.code == Keyboard::F1){
                this->gameLvL = new GameLvL(config->s_LvL1->s, 1);
                this->player->setPosition(1000, 1600);
                cout << "LvL: 1" << endl;
            }
            if(game_event.key.code == Keyboard::F2){
                this->gameLvL = new GameLvL(config->s_LvL2->s, 2);
                this->player->setPosition(1000, 600);
                cout << "LvL: 2" << endl;
            }
            if(game_event.key.code == Keyboard::F3){
                this->gameLvL = new GameLvL(config->s_LvL3->s, 3);
                this->player->setPosition(1000, 1500);
                cout << "LvL: 3" << endl;
            }
            if(game_event.key.code == Keyboard::F4){
                this-> gameLvL = new GameLvL(config->s_LvL4->s, 4);
                this->player->setPosition(1000, 1500);
                cout << "LvL: 4" << endl;
            }
            if(game_event.key.code == Keyboard::F5){
                this->gameLvL = new GameLvL(config->s_LvL5->s, 5);
                this->player->setPosition(1000, 1500);
                cout << "LvL: 5" << endl;
            }
            if(game_event.key.code == Keyboard::F6){
                this->gameLvL = new GameLvL(config->s_LvL6->s, 6);
                this->player->setPosition(1000, 1500);
                cout << "LvL: 6" << endl;
            }
        }
    }
}

void GameEngine::EventFunc() {
    this->ShootBullet();
    this->TakeItems();
    this->TakeEquipment();
    this->TakeChest();
    this->TakeDoor();
    this->TakeNps();
}

void GameEngine::TakeItems() {
    if (game_event.type == Event::KeyPressed){
        if (game_event.key.code == Keyboard::F){
            for(itItem = itemLvL[gameLvL->gameLvL].begin(); itItem != itemLvL[gameLvL->gameLvL].end(); itItem++){
                if ((*itItem)->isTake(*player)) {
                    this->itemLvL[gameLvL->gameLvL].erase(itItem);
                }
            }
        }
    }
}

void GameEngine::TakeEquipment() {

}

void GameEngine::TakeChest() {
    if (game_event.type == Event::KeyPressed) {
        if (game_event.key.code == Keyboard::F) {
            for (itChest = chestLvL[gameLvL->gameLvL].begin(); itChest != chestLvL[gameLvL->gameLvL].end(); itChest++) {
                if (player->e_Radius->getGlobalBounds().intersects((*itChest)->getRect())) {
                    if ((*itChest)->name == "SmallChest") {
                        if (!(*itChest)->is_open) {
                            if ((*itChest)->OpenChest() == 1){ itemLvL[gameLvL->gameLvL].push_back(new key_item(config->s_Item_KeySilver->s, gameLvL, (*itChest)->position.x + 18,(*itChest)->position.y, 40, 45, "KeySilver")); }
                            if ((*itChest)->OpenChest() == 2){ itemLvL[gameLvL->gameLvL].push_back(new health_item(config->s_Item_Health->s, gameLvL, (*itChest)->position.x + 18,(*itChest)->position.y, 40, 45, "Health")); }
                            if ((*itChest)->OpenChest() == 3){ }
                        }
                    }
                    if ((*itChest)->name == "MiddleChest" && player->k_Silver > 0) {
                        if ((!(*itChest)->is_open)) {
                            if ((*itChest)->OpenChest() == 1){this->itemLvL[gameLvL->gameLvL].push_back(new key_item(config->s_Item_KeyGold->s, gameLvL, (*itChest)->position.x + 22,(*itChest)->position.y, 40, 45, "KeyGold"));}
                            if ((*itChest)->OpenChest() == 2){this->itemLvL[gameLvL->gameLvL].push_back(new money_item(config->s_Item_Money->s, gameLvL, (*itChest)->position.x + 22,(*itChest)->position.y, 40, 45, "Money"));}
                            if ((*itChest)->OpenChest() == 3){this->itemLvL[gameLvL->gameLvL].push_back(new health_item(config->s_Item_Health->s, gameLvL, (*itChest)->position.x + 22,(*itChest)->position.y, 40, 45, "Health"));}
                            this->player->k_Silver--;
                        }
                    }
                    if ((*itChest)->name == "BigChest" && player->k_Gold > 0) {
                        if ((!(*itChest)->is_open)) {
                            if ((*itChest)->OpenChest() == 1){this->itemLvL[gameLvL->gameLvL].push_back(new money_item(config->s_Item_Diamond->s, gameLvL, (*itChest)->position.x + 25,(*itChest)->position.y, 40, 45, "Diamond"));}
                            if ((*itChest)->OpenChest() == 2){this->itemLvL[gameLvL->gameLvL].push_back(new key_item(config->s_Item_KeyGold->s, gameLvL, (*itChest)->position.x + 25,(*itChest)->position.y, 40, 45, "KeyGold"));}
                            if ((*itChest)->OpenChest() == 3){this->itemLvL[gameLvL->gameLvL].push_back(new key_item(config->s_Item_KeySilver->s, gameLvL, (*itChest)->position.x + 25,(*itChest)->position.y, 40, 45, "KeySilver"));}
                            this->player->k_Gold--;
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
        if(!(*itEnemy)->life){
            this->enemyLvL[gameLvL->gameLvL].erase(itEnemy);
        }
    }
}

void GameEngine::ShootBullet() {
    if(game_event.type == Event::KeyPressed){
        if(game_event.key.code == Keyboard::LControl){
            if(player->life && player->isShoot){
                this->bulletLvL.push_back(new Bullet(config->s_Bullet->s,gameLvL, player->position.x, player->position.y, 500, 370, "Bullet", player->state));
                this->player->BulletTime = 0;
            }
        }
    }
}
// clear color
void GameEngine::renderClear(){
    if(gameLvL->gameLvL == 1){
        this->window->clear(Color(173, 208, 207));
    }
    else if(gameLvL->gameLvL == 2){
        this->window->clear(Color(173, 208, 207));
    }
    else if(gameLvL->gameLvL == 3){
        this->window->clear(Color(40, 40, 40));
    }
    else if(gameLvL->gameLvL == 4){
        this->window->clear(Color(173, 208, 207));
    }
    else if(gameLvL->gameLvL == 5){
        this->window->clear(Color(173, 208, 207));
    }
    else if(gameLvL->gameLvL == 6){
        this->window->clear(Color(173, 208, 207));
    }
    else{

    }
}

void GameEngine::run() {
    while (this->isRunning()){
        this->update();
        this->render();
    }
}