//
// Created by Doni on 15.05.2023.

#include "GameEngine.h"

GameEngine::GameEngine() {
    //this->m_Menu.show();
    this->initClass();
    this->initWindow();
}
GameEngine::~GameEngine() {
    cout << "========== removed from memory ========" << endl;
    if(this->window != nullptr){ delete this->window; }
    delete Config::getInstance(); // очищаем память
    delete this->player; // очищаем память
    delete this->GUI;
    delete this->gameLvL; // очищаем память
    delete this->enemyMagDamage;
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
    // Fon update
    for(itFon = fonLvL[gameLvL->gameLvL].begin(); itFon != fonLvL[gameLvL->gameLvL].end(); itFon++){
        (*itFon)->update(this->game_time, this->gameLvL);
    }
    // player update
    this->player->update(this->game_time, this->gameLvL);
    this->GUI->GUI_update(this->player);
    this->player->particles->update(this->elapsed);
    // Object update
    for(itObject = objLvL[gameLvL->gameLvL].begin(); itObject != objLvL[gameLvL->gameLvL].end(); itObject++){
        (*itObject)->update(this->game_time, this->gameLvL);
    }
    // Enemy update
    for(itEnemy = enemyLvL[gameLvL->gameLvL].begin(); itEnemy != enemyLvL[gameLvL->gameLvL].end(); itEnemy++){
        if(!(*itEnemy)->life)this->enemyLvL[gameLvL->gameLvL].erase(itEnemy);
        (*itEnemy)->update(this->game_time, this->gameLvL,  this->player);
        //cout << size(enemyLvL[gameLvL->gameLvL]) << endl;
    }
    for(itChest = chestLvL[gameLvL->gameLvL].begin(); itChest != chestLvL[gameLvL->gameLvL].end(); itChest++){
        (*itChest)->update(this->game_time, this->gameLvL);
    }
    // Nps update
    for(itNps = npsLvL[gameLvL->gameLvL].begin(); itNps != npsLvL[gameLvL->gameLvL].end(); itNps++){
        (*itNps)->update(this->game_time, this->gameLvL);
    }
    // Item update
    for(itItem = itemLvL[gameLvL->gameLvL].begin(); itItem != itemLvL[gameLvL->gameLvL].end(); itItem++){
        (*itItem)->update(this->game_time, this->gameLvL);
    }
    // Bullet update
    for(itBullet = bulletLvL.begin(); itBullet != bulletLvL.end(); itBullet++){
        (*itBullet)->upadte(this->game_time);
    }
    // Evnet
    this->pollEvents();
}

void GameEngine::render(){ // Рендер изображения
    this->renderClear();
    // render fon
    for(itFon = fonLvL[gameLvL->gameLvL].begin(); itFon != fonLvL[gameLvL->gameLvL].end(); itFon++){
        (*itFon)->draw(*this->window, this->config->view);
    }
    gameLvL->RenderDraw(*this->window, this->config->view); // Рисуем карту
    // Object render
    for(itObject = objLvL[gameLvL->gameLvL].begin(); itObject != objLvL[gameLvL->gameLvL].end(); itObject++){
        (*itObject)->draw(*this->window, this->config->view);
    }
    // Nps render
    for(itNps = npsLvL[gameLvL->gameLvL].begin(); itNps != npsLvL[gameLvL->gameLvL].end(); itNps++){
        (*itNps)->draw(*this->window, this->config->view);
    }
    // Chest render
    for(itChest = chestLvL[gameLvL->gameLvL].begin(); itChest != chestLvL[gameLvL->gameLvL].end(); itChest++){
        (*itChest)->draw(*this->window, this->config->view);
    }
    // Item render
    for(itItem = itemLvL[gameLvL->gameLvL].begin(); itItem != itemLvL[gameLvL->gameLvL].end(); itItem++){
        (*itItem)->draw(*this->window, this->config->view);
    }
    // render player
    this->player->draw(*this->window, this->config->view);
    // Enemy render
    for(itEnemy = enemyLvL[gameLvL->gameLvL].begin(); itEnemy != enemyLvL[gameLvL->gameLvL].end(); itEnemy++){
        (*itEnemy)->draw(*this->window, this->config->view);
    }
    // Bullet Render
    for(itBullet = bulletLvL.begin(); itBullet != bulletLvL.end(); itBullet++){
        (*itBullet)->draw(*this->window, this->config->view);
    }
    this->GUI->GUI_draw(*this->window, this->player, this->config->view);
    this->window->display(); // создаём дисплей
    // Работа с камерой
    this->config->getPlayerCoordinateForView(this->player->GetX(), this->player->GetY()); // привязываем камеру к игроку
    this->window->setView(this->config->view); //  привязываем окно к камере
}

void GameEngine::initWindow() {
    // для начало используем это способ, потом через настройки будем изменять размер
//    this->config->window_size.x = VideoMode::getDesktopMode().width/2; // ширину монитора делим на 2
//    this->config->window_size.y = VideoMode::getDesktopMode().height/2;// высоту монитора делим на 2
    this->config->window_size.x = 1280; // ширину монитора делим на 2
    this->config->window_size.y = 720;// высоту монитора делим на 2
    this->config->view_size.x = this->config->window_size.x;
    this->config->view_size.y = this->config->window_size.y;
    const VideoMode videoMode = VideoMode(this->config->window_size.x, this->config->window_size.y);
    const Uint32 style = sf::Style::Close| sf::Style::Titlebar;
    // Создание окна и камеру, вертикальное синхронизация
    this->window = new sf::RenderWindow(videoMode, this->config->window_title, style);
    this->config->view.reset(FloatRect(0, 0, this->config->view_size.x, this->config->view_size.y));
    //this->window->setFramerateLimit(config->window_frame);
    //this->window->setVerticalSyncEnabled(true);
}

void GameEngine::initClass() {
    // gameLvL
    this->gameLvL = new GameLvL(config->s_LvL[1]->s, 1);
    //Player
    this->player = new Player(config->s_player->s, gameLvL,1000, 1800, 56, 60, "player");
    this->GUI = new GUI_player;
    // Attack Enemy
    this->enemyMagDamage = new FonGame(config->s_enemy_MagDamage->s, gameLvL, 0, 0, 0, 0, "MagDamage");
    //Enemy
    this->enemyLvL[1] = {
            new Enemy_Bat(config->s_enemy_bat->s, gameLvL, 2200, 1236, 65, 55, "Bat"),
            new Enemy_Bat(config->s_enemy_bat->s, gameLvL, 2250, 1236, 65, 55, "Bat"),
//            new Enemy_Ghost(config->s_EnemyGhost->s, gameLvL, 800, 1236, 40, 88, "Ghost"),
            new Enemy_Bat(config->s_enemy_bat->s, gameLvL, 9800, 1236, 65, 55, "Bat"),
            new Enemy_Boom(config->s_enemy_boom->s, gameLvL, 9000, 1800, 50, 50, "Boom"),
//            new Enemy_BigGhost(config->s_Enemy_BigGhost->s, gameLvL, 800, 1236, 65, 125, "BigGhost"),
//            new Enemy_Mag(config->s_Enemy_Mag->s,enemyMagDamage, gameLvL, 800, 1236, 40, 110, "Mag"),
    };
    //enemy lvl 2
    this->enemyLvL[2] = {
            new Enemy_Bat(config->s_enemy_bat->s, gameLvL, 7500, 1236, 65, 55, "Bat"),
            new Enemy_Ghost(config->s_enemy_ghost->s, gameLvL, 7800, 1236, 40, 88, "Ghost"),
            new Enemy_Mag(config->s_enemy_mag->s, enemyMagDamage, gameLvL, 8000, 1236, 40, 110, "Mag"),
            new Enemy_Boom(config->s_enemy_boom->s, gameLvL, 7800, 1236, 50, 50, "Boom"),
    };
    // enemy lvl 3
    this->enemyLvL[3] = {
            new Enemy_Bat(config->s_enemy_bat->s, gameLvL, 11250, 1236, 65, 55, "Bat"),
            new Enemy_Ghost(config->s_enemy_ghost->s, gameLvL, 7761, 1890, 40, 88, "Ghost"),
            new Enemy_Ghost(config->s_enemy_ghost->s, gameLvL, 8805, 1890, 40, 88, "Ghost"),
            new Enemy_BigGhost(config->s_enemy_BigGhost->s, gameLvL, 5010, 2418, 65, 125, "BigGhost"),
            new Enemy_Boom(config->s_enemy_boom->s, gameLvL, 5010, 2418, 2626, 50, "Boom"),
            new Enemy_Boom(config->s_enemy_boom->s, gameLvL, 865, 2404, 2626, 50, "Boom"),
    };
    // enemy lvl 4
    this->enemyLvL[4] = {

    };
    // enemy lvl 5
    this->enemyLvL[5] = {

    };
    // enemy lvl 6
    this->enemyLvL[6] = {

    };
    // Object LvL 1
    this->objLvL[1] = {
            new Object(config->s_object_stove->s, gameLvL, 5650, 1600, 92, 108, "Stove"),
            new Object(config->s_object_HomeDrov->s, gameLvL, 1200, 1600, 100, 298, "Home"),
            new Object(config->s_object_TableHouse->s, gameLvL, 9520, 1600, 400, 300, "TableHouse"),
    };
    // Object LvL 2
    this->objLvL[2] = {
            new Object(config->s_object_BushHouse->s, gameLvL, 3400, 1600, 500, 300, "BushHouse"),
            new Object(config->s_object_BonfireHouse->s, gameLvL, 4100, 1600, 1230, 574, "BonfireHouse"),
    };
    // Object LvL 3
    this->objLvL[3] = {
            new Object(config->s_object_FlyingObelisk->s, gameLvL, 1400, 1600, 145, 390, "FlyingObelisk"),
            new Object(config->s_object_DarkTreeBig->s, gameLvL, 1450, 1600, 125, 265, "DarkTreeBig"),
            new Object(config->s_object_DarkTreeSmall->s, gameLvL, 1450, 1600, 125, 265, "DarkTreeSmall"),
            //RemainsSkeleton
            new Object(config->s_object_RemainsSkeleton->s, gameLvL, 500, 1600, 95, 72, "RemainsSkeleton"),
            new Object(config->s_object_RemainsSkeleton->s, gameLvL, 1500, 1600, 95, 72, "RemainsSkeleton"),
            new Object(config->s_object_RemainsSkeleton->s, gameLvL, 2400, 1600, 95, 72, "RemainsSkeleton"),
            new Object(config->s_object_RemainsSkeleton->s, gameLvL, 3300, 1600, 95, 72, "RemainsSkeleton"),
            new Object(config->s_object_RemainsSkeleton->s, gameLvL, 3500, 1600, 95, 72, "RemainsSkeleton"),
            new Object(config->s_object_RemainsSkeleton->s, gameLvL, 3700, 1600, 95, 72, "RemainsSkeleton"),
            new Object(config->s_object_RemainsSkeleton->s, gameLvL, 4700, 1600, 95, 72, "RemainsSkeleton"),
            new Object(config->s_object_RemainsSkeleton->s, gameLvL, 5100, 1600, 95, 72, "RemainsSkeleton"),
            new Object(config->s_object_RemainsSkeleton->s, gameLvL, 5400, 1600, 95, 72, "RemainsSkeleton"),
            new Object(config->s_object_RemainsSkeleton->s, gameLvL, 5700, 1600, 95, 72, "RemainsSkeleton"),
            new Object(config->s_object_RemainsSkeleton->s, gameLvL, 6200, 1600, 95, 72, "RemainsSkeleton"),
    };
    // Object LvL 4
    this->objLvL[4] = {

    };
    // Object LvL 5
    this->objLvL[5] = {

    };
    // Object LvL 6
    this->objLvL[6] = {

    };
    //Chest
    this->chestLvL[1] = {
            new Chest(config->s_chest_small->s, gameLvL, 1000, 1600, 65, 70, "SmallChest"),
            new Chest(config->s_chest_middle->s, gameLvL, 1200, 1600, 65, 82, "MiddleChest"),
            new Chest(config->s_chest_big->s, gameLvL, 1400, 1600, 65, 90, "BigChest"),
            //
            new Chest(config->s_chest_small->s, gameLvL, 9790, 1600, 65, 70, "SmallChest"),
            new Chest(config->s_chest_small->s, gameLvL, 5903, 1600, 65, 70, "SmallChest"),
            new Chest(config->s_chest_middle->s, gameLvL, 570, 1248, 65, 82, "MiddleChest"),
            new Chest(config->s_chest_big->s, gameLvL, 3026, 1100, 65, 90, "BigChest")
    };
    //Chest lvl 2
    this->chestLvL[2] = {
            new Chest(config->s_chest_small->s, gameLvL, 3410, 1500, 65, 70, "SmallChest"),
            new Chest(config->s_chest_big->s, gameLvL, 2250, 1500, 65, 90, "BigChest"),
    };
    //Chest lvl 3
    this->chestLvL[3] = {
            new Chest(config->s_chest_big->s, gameLvL, 8142, 2562, 65, 90, "BigChest"),
    };
    //Chest lvl 4
    this->chestLvL[4] = {

    };
    //Chest lvl 5
    this->chestLvL[5] = {

    };
    //Chest lvl 6
    this->chestLvL[6] = {

    };
    //Nps
    this->npsLvL[1] = {
            new Knight(config->s_nps_knight->s, gameLvL, config->text_nps_knight, 9500, 586, 56, 138, "Knight"),
            new Historian(config->s_nps_historian->s, gameLvL, config->text_nps_historian, 1100, 1520, 156, 150, "Historian"),
            new Blacksmith(config->s_nps_blacksmith->s, gameLvL, config->text_nps_blacksmith, 5750, 1620, 122, 152, "Blacksmith"),
    };
    // nps lvl 2
    this->npsLvL[2] = {
            new Aiden(config->s_nps_aiden->s, gameLvL, config->text_nps_aiden, 4550, 1620, 50, 105, "Aiden"),
            new Blacksmith(config->s_nps_blacksmith->s, gameLvL, config->text_nps_blacksmith, 1000, 1620, 50, 152, "Blacksmith"),
            new Witcher(config->s_nps_witcher->s, gameLvL, config->text_nps_witcher, 800, 1620, 50, 190, "Witcher")
    };
    // nps lvl 3
    this->npsLvL[3] = {
            new Supreme_Wizard(config->s_nps_SupremeWizard->s, gameLvL, config->text_nps_supreme_wizard, 1250, 1620, 122, 152, "Supreme_Wizard"),
            new Blacksmith(config->s_nps_blacksmith->s, gameLvL, config->text_nps_blacksmith, 1100, 1250, 122, 152, "Blacksmith"),
            new Soothsayer(config->s_nps_soothsayer->s, gameLvL, config->text_nps_soothsayer, 2000, 1250, 122, 152, "Soothsayer"),
            new Swordsman(config->s_nps_swordsman->s, gameLvL, config->text_nps_swordsman, 1727, 2460, 122, 152, "Swordsman")
    };
    // nps lvl 4
    this->npsLvL[4] = {

    };
    // nps lvl 5
    this->npsLvL[5] = {

    };
    // nps lvl 6
    this->npsLvL[6] = {

    };
    // Item
    this->itemLvL[1] = {
            new equipment_item(config->s_item_sword[1]->s, gameLvL, 1000, 1600, 30, 25, "SwordBlue"),
            new equipment_item(config->s_item_sword[2]->s, gameLvL, 1050, 1600, 30, 25, "SwordRed"),
            new equipment_item(config->s_item_sword[3]->s, gameLvL, 1100, 1600, 30, 25, "SwordGreen"),
            new equipment_item(config->s_item_sword[4]->s, gameLvL, 1150, 1600, 30, 25, "SwordBrow"),

            new equipment_item(config->s_item_shield[1]->s, gameLvL, 1200, 1600, 30, 65, "ShieldBlue"),
            new equipment_item(config->s_item_shield[2]->s, gameLvL, 1250, 1600, 30, 65, "ShieldRed"),
            new equipment_item(config->s_item_shield[3]->s, gameLvL, 1300, 1600, 30, 65, "ShieldGreen"),
            new equipment_item(config->s_item_shield[4]->s, gameLvL, 1350, 1600, 30, 65, "ShieldBrow"),

            new health_item(config->s_item_health->s, gameLvL, 4800, 1600, 40, 45, "Health"),
            new money_item(config->s_item_money->s, gameLvL, 300, 1600, 30, 40, "Money"),
            new money_item(config->s_item_diamond->s, gameLvL, 9400, 1600, 40, 60, "Diamond"),
            new key_item(config->s_item_KeySilver->s, gameLvL, 8, 1600, 40, 45, "KeySilver"),
            new key_item(config->s_item_KeyGold->s, gameLvL, 9300, 1600, 40, 45, "KeyGold"),

            new Particle_of_Strength_item(config->s_particle_of_strength_sprint->s, gameLvL, 2000, 1600, 40, 40, "Sprint"),
            new Particle_of_Strength_item(config->s_particle_of_strength_shoot->s, gameLvL, 2100, 1600, 40, 40, "Shoot"),
            new Particle_of_Strength_item(config->s_particle_of_strength_shoot->s, gameLvL, 2200, 1600, 40, 40, "Repulsion"),
            new Particle_of_Strength_item(config->s_particle_of_strength_shoot->s, gameLvL, 2300, 1600, 40, 40, "Speed"),
    };
    // item lvl 2
    this->itemLvL[2] = {
            new money_item(config->s_item_money->s, gameLvL, 4000, 1200, 30, 40, "Money"),
            new health_item(config->s_item_health->s, gameLvL, 2000, 1200, 40, 45, "Health"),
            new key_item(config->s_item_KeySilver->s, gameLvL, 550, 1200, 40, 45, "KeySilver"),
            new key_item(config->s_item_KeyGold->s, gameLvL, 4550, 1200, 40, 45, "KeyGold"),
    };
    // item lvl 3
    this->itemLvL[3] = {
            new key_item(config->s_item_KeySilver->s, gameLvL, 8142, 2562,40, 45, "KeySilver"),
    };
    // item lvl 4
    this->itemLvL[4] = {

    };
    // item lvl 5
    this->itemLvL[5] = {

    };
    // item lvl 6
    this->itemLvL[6] = {

    };
    //Fon
    this->fonLvL[1] = {
            new FonGame(config->s_LvL_Fon[1]->s, gameLvL, 0, 1360, 10, 10,"Fon"),
            new FonGame(config->s_LvL_Fon[1]->s, gameLvL, 4900, 1360, 10, 10,"Fon"),
            new FonGame(config->s_LvL_FonBack[1]->s, gameLvL, 0, 1860, 0, 0, "Back"),
            new FonGame(config->s_LvL_FonBack[1]->s, gameLvL, 4900, 1860, 0, 0, "Back")
    };
    // Fon lvl 2
    this->fonLvL[2] = {
//            new FonGame(config->s_LvL2_Fon->s, gameLvL, 0, 1360, 10, 10," "),
//            new FonGame(config->s_LvL2_Fon->s, gameLvL, 4900, 1360, 10, 10," ")
    };
    // Fon lvl 3
    this->fonLvL[3] = {

    };
    // Fon lvl 4
    this->fonLvL[4] = {

    };
    // Fon lvl 5
    this->fonLvL[5] = {

    };
    // Fon lvl 6
    this->fonLvL[6] = {

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
            if(game_event.key.code == sf::Keyboard::I){
                switch (this->GUI->GUI_visible) {
                    case true: this->GUI->GUI_visible = false; break;
                    case false: this->GUI->GUI_visible = true; break;
                }
            }
            if(game_event.key.code == Keyboard::P){
                if(player->is_health > 0)
                    this->player->is_health -= 20;
            }
            if(game_event.key.code == sf::Keyboard::Tab){
                cout << "X - " << player->pos.x << "\n" << "Y - " << player->pos.y << "\n"
                     << "Health: " <<  player->is_health << " / " << player->f_health << "\n"
                     << "level: " << player->lvl_player<<"\n"
                     << "k_silver: " << player->k_Silver << "\n"
                     << "k_gold: " << player->k_Gold << "\n"
                     << "money: " << player->money << "\n" << endl;
            }
            if(game_event.key.code == Keyboard::F1){
                this->gameLvL = new GameLvL(config->s_LvL[1]->s, 1);
                this->player->setPosition(1000, 1600);
                cout << "LvL: 1" << endl;
            }
            if(game_event.key.code == Keyboard::F2){
                this->gameLvL = new GameLvL(config->s_LvL[2]->s, 2);
                this->player->setPosition(1000, 600);
                cout << "LvL: 2" << endl;
            }
            if(game_event.key.code == Keyboard::F3){
                this->gameLvL = new GameLvL(config->s_LvL[3]->s, 3);
                this->player->setPosition(1000, 1500);
                cout << "LvL: 3" << endl;
            }
            if(game_event.key.code == Keyboard::F4){
                this-> gameLvL = new GameLvL(config->s_LvL[4]->s, 4);
                this->player->setPosition(1000, 1500);
                cout << "LvL: 4" << endl;
            }
            if(game_event.key.code == Keyboard::F5){
                this->gameLvL = new GameLvL(config->s_LvL[5]->s, 5);
                this->player->setPosition(1000, 1500);
                cout << "LvL: 5" << endl;
            }
            if(game_event.key.code == Keyboard::F6){
                this->gameLvL = new GameLvL(config->s_LvL[6]->s, 6);
                this->player->setPosition(1000, 1500);
                cout << "LvL: 6" << endl;
            }
        }
    }
}
void GameEngine::EventFunc() {
    this->TakeInventory();
    this->ShootBullet();
    this->TakeItems();
    this->TakeChest();
    this->TakeDoor();
    this->TakeEnemy();
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
                    if ((*itChest)->name == "MiddleChest" && player->k_Silver > 0) {
                        if (((*itChest)->is_open)) {
                            if ((*itChest)->OpenChest() == 1){this->itemLvL[gameLvL->gameLvL].push_back(new key_item(config->s_item_KeyGold->s, gameLvL, (*itChest)->pos.x + 22, (*itChest)->pos.y, 40, 45, "KeyGold"));}
                            if ((*itChest)->OpenChest() == 2){this->itemLvL[gameLvL->gameLvL].push_back(new money_item(config->s_item_money->s, gameLvL, (*itChest)->pos.x + 22, (*itChest)->pos.y, 40, 45, "Money"));}
                            if ((*itChest)->OpenChest() == 3){this->itemLvL[gameLvL->gameLvL].push_back(new health_item(config->s_item_health->s, gameLvL, (*itChest)->pos.x + 22, (*itChest)->pos.y, 40, 45, "Health"));}
                            this->player->k_Silver--;
                        }
                    }
                    if ((*itChest)->name == "BigChest" && player->k_Gold > 0) {
                        if (((*itChest)->is_open)) {
                            if ((*itChest)->OpenChest() == 1){this->itemLvL[gameLvL->gameLvL].push_back(new money_item(config->s_item_diamond->s, gameLvL, (*itChest)->pos.x + 25, (*itChest)->pos.y, 40, 45, "Diamond"));}
                            if ((*itChest)->OpenChest() == 2){this->itemLvL[gameLvL->gameLvL].push_back(new key_item(config->s_item_KeyGold->s, gameLvL, (*itChest)->pos.x + 25, (*itChest)->pos.y, 40, 45, "KeyGold"));}
                            if ((*itChest)->OpenChest() == 3){this->itemLvL[gameLvL->gameLvL].push_back(new key_item(config->s_item_KeySilver->s, gameLvL, (*itChest)->pos.x + 25, (*itChest)->pos.y, 40, 45, "KeySilver"));}
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
        (*itEnemy)->TakingDamage(*this->player, bulletLvL, game_event);
    }
}

void GameEngine::ShootBullet() {
    if(game_event.type == Event::KeyPressed){
        if(game_event.key.code == Keyboard::LControl){
            if(player->life && player->isShoot && player->particle_of_strength_shoot){
                this->bulletLvL.push_back(new Bullet(config->s_bullet->s, gameLvL, player->GetX(), player->GetY() - 40, 200, 50, "Bullet", player->state));
                this->player->bullet_time = 0;
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

void GameEngine::run(){
    while (this->isRunning()){
        this->update();
        this->render();
    }
}