//
// Created by Doni on 15.05.2023.

#include "GameEngine.h"

GameEngine::GameEngine() {
    initWindow();
    initClass();
}
GameEngine::~GameEngine() {
    cout << "========== removed from memory ========" << endl;
    if(window != nullptr){ delete window; }
    delete Config::getInstance(); // очищаем память
    delete player; // очищаем память
    delete gameLvL; // очищаем память
}
bool GameEngine::isRunning(){
    if (window == nullptr){ cout << "\n Error Windows \n"; return false; }
    else return window->isOpen();
}

void GameEngine::update() {
    // Time
    game_time = clock.getElapsedTime().asMicroseconds();
    elapsed = clock.restart();
    game_time = game_time / 800;
    // View
    config->getPlayerCoordinateForView(player->GetX(), player->GetY());
    // Fon update
    for(itFon = fonLvL[gameLvL->gameLvL].begin(); itFon != fonLvL[gameLvL->gameLvL].end(); itFon++){
        (*itFon)->update(game_time, gameLvL);
    }
    player->update(game_time, gameLvL); // player update
    player->particles->update(elapsed);
    // Object update
    for(itObject = objLvL[gameLvL->gameLvL].begin(); itObject != objLvL[gameLvL->gameLvL].end(); itObject++){
        (*itObject)->update(game_time, gameLvL);
    }
    // Enemy update
    for(itEnemy = enemyLvL[gameLvL->gameLvL].begin(); itEnemy != enemyLvL[gameLvL->gameLvL].end(); itEnemy++){
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
    pollEvents();
}

void GameEngine::render(){ // Рендер изображения
    renderClear();
    // render fon
    for(itFon = fonLvL[gameLvL->gameLvL].begin(); itFon != fonLvL[gameLvL->gameLvL].end(); itFon++){ (*itFon)->draw(*window, config->view); }
    gameLvL->RenderDraw(*window, config->view); // Рисуем карту
    window->setView(config->view); // привязываем окно к камере
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
    player->draw(*window, config->view);
    // Enemy render
    for(itEnemy = enemyLvL[gameLvL->gameLvL].begin(); itEnemy != enemyLvL[gameLvL->gameLvL].end(); itEnemy++){
        (*itEnemy)->draw(*window, config->view);
    }
    // Bullet Render
    for(itBullet = bulletLvL.begin(); itBullet != bulletLvL.end(); itBullet++){
        (*itBullet)->draw(*window, config->view);
    }
    window->display(); // создаём дисплей
}

void GameEngine::initWindow() {
    // для начало используем это способ, потом через настройки будем изменять размер
    config->window_size.x = VideoMode::getDesktopMode().width / 2; // ширину монитора делим на 2
    config->window_size.y = VideoMode::getDesktopMode().height / 2;// высоту монитора делим на 2
    config->view_size.x = config->window_size.x;
    config->view_size.y = config->window_size.y;
    const VideoMode videoMode = VideoMode(1280, 720);
    const Uint32 style = sf::Style::Close| sf::Style::Titlebar;
    // Создание окна и камеру, вертикальное синхронизация
    window = new sf::RenderWindow(videoMode, config->window_title, style);
    config->view.reset(FloatRect(0, 0, config->view_size.x, config->view_size.y));
    window->setFramerateLimit(config->window_frame);
    window->setVerticalSyncEnabled(true);
}

void GameEngine::initClass() {
    gameLvL = new GameLvL(config->s_LvL1->s, 1);
    //LvL1
    player = new Player(config->s_player->s, gameLvL ,1000, 1800, 56, 60, "player");
    //Enemy
    enemyLvL[1] = {

    };
    //enemyLvL[1].push_back(new Enemy_Ghost(config->s_EnemyGhost->s, gameLvL, 1400, 1390, 40, 88, "Ghost"));
    //enemy lvl 2
    enemyLvL[2] = {
            new Enemy_Ghost(config->s_EnemyGhost->s, gameLvL, 800, 1636, 40, 88, "Ghost")
    };
    //enemyLvL[2].push_back(new Enemy_Ghost(config->s_EnemyGhost->s, gameLvL, 800, 1636, 40, 88, "Ghost"));
    // enemy lvl 3
    enemyLvL[3] = {

    };
    // Object LvL 1
    objLvL[1] = {
            new Object(config->s_Object_HomeDrov->s, gameLvL, 1200, 1600, 100, 298,"Home")
    };
    //objLvL[1].push_back(new Object(config->s_Object_HomeDrov->s, gameLvL, 1200, 1600, 100, 298,"Home"));
    // Object LvL 2
    objLvL[2] = {

    };
    // Object LvL 3
    objLvL[3] = {
            new Object(config->s_Object_FlyingObelisk->s, gameLvL, 1400, 1600, 145, 390,"FlyingObelisk"),
            new Object(config->s_Object_DarkTreeBig->s, gameLvL, 1450, 1600, 125, 265,"DarkTreeBig"),
            new Object(config->s_Object_DarkTreeSmall->s, gameLvL, 1450, 1600, 125, 265,"DarkTreeSmall")
    };
//    objLvL[3].push_back(new Object(config->s_Object_FlyingObelisk->s, gameLvL, 1400, 1600, 145, 390,"FlyingObelisk"));
//    objLvL[3].push_back(new Object(config->s_Object_DarkTreeBig->s, gameLvL, 1450, 1600, 125, 265,"DarkTreeBig"));
//    objLvL[3].push_back(new Object(config->s_Object_DarkTreeSmall->s, gameLvL, 1450, 1600, 125, 265,"DarkTreeSmall"));
    //Chest
    chestLvL[1] = {
            new Chest(config->s_Chest_Small->s, gameLvL, 9790, 1600, 65, 70, "SmallChest"),
            new Chest(config->s_Chest_Small->s, gameLvL, 5903, 1600, 65, 70, "SmallChest"),
            new Chest(config->s_Chest_Middle->s, gameLvL, 582, 1600, 65, 82, "MiddleChest"),
            new Chest(config->s_Chest_Big->s, gameLvL, 3410, 1600, 65, 90, "BigChest")
    };
//    chestLvL[1].push_back(new Chest(config->s_Chest_Small->s, gameLvL, 9790, 1600, 65, 70, "SmallChest"));
//    chestLvL[1].push_back(new Chest(config->s_Chest_Small->s, gameLvL, 5903, 1600, 65, 70, "SmallChest"));
//    chestLvL[1].push_back(new Chest(config->s_Chest_Middle->s, gameLvL, 582, 1600, 65, 82, "MiddleChest"));
//    chestLvL[1].push_back(new Chest(config->s_Chest_Big->s, gameLvL, 3410, 1600, 65, 90, "BigChest"));
    //Nps
    //Nps nps_1(config->s_Nps_Historian->s, gameLvL, config->text_nps, 1600, 1520, 56, 60, "Historian");
    npsLvL[1] = {
            new Knight(config->s_Nps_Knight->s, gameLvL, config->text_nps_knight, 9500, 586, 56, 138, "Knight"),
            new Historian(config->s_Nps_Historian->s, gameLvL, config->text_nps_historian, 1100, 1520, 156, 150, "Historian"),
            new Blacksmith(config->s_Nps_Blacksmith->s, gameLvL, config->text_nps_blacksmith, 5750, 1620, 122, 152, "Blacksmith")
    };
//    npsLvL[1].push_back(new Knight(config->s_Nps_Knight->s, gameLvL, config->text_nps_knight, 9500, 586, 56, 138, "Knight"));
//    npsLvL[1].push_back(new Historian(config->s_Nps_Historian->s, gameLvL, config->text_nps_historian, 1100, 1520, 156, 150, "Historian"));
//    npsLvL[1].push_back(new Blacksmith(config->s_Nps_Blacksmith->s, gameLvL, config->text_nps_blacksmith, 5750, 1620, 122, 152, "Blacksmith"));
    // nps lvl 2
    npsLvL[2] = {
            new Aiden(config->s_Nps_Aiden->s, gameLvL, config->text_nps_aiden,4300, 1620, 50, 50, "Aiden"),
            new Blacksmith(config->s_Nps_Blacksmith->s, gameLvL, config->text_nps_blacksmith, 1000, 1620, 50, 152, "Blacksmith"),
            new Witcher(config->s_Nps_Witcher->s, gameLvL, config->text_nps_witcher, 800, 1620, 50, 190, "Witcher")
    };
//    npsLvL[2].push_back(new Aiden(config->s_Nps_Aiden->s, gameLvL, config->text_nps_aiden,4300, 1620, 50, 50, "Aiden"));
//    npsLvL[2].push_back(new Witcher(config->s_Nps_Witcher->s, gameLvL, config->text_nps_witcher, 800, 1620, 50, 190, "Witcher"));
//    npsLvL[2].push_back(new Witcher(config->s_Nps_Witcher->s, gameLvL, config->text_nps_witcher, 800, 1620, 50, 190, "Witcher"));
    // nps lvl 3
    npsLvL[3] = {
            new Supreme_Wizard(config->s_Nps_SupremeWizard->s, gameLvL, config->text_nps_supreme_wizard, 1250, 1620, 122, 152, "Supreme_Wizard"),
            new Blacksmith(config->s_Nps_Blacksmith->s, gameLvL, config->text_nps_blacksmith, 1100, 1620, 122, 152, "Blacksmith"),
            new Soothsayer(config->s_Nps_Soothsayer->s, gameLvL, config->text_nps_soothsayer, 2000, 1620, 122, 152, "Soothsayer"),
            new Swordsman(config->s_Nps_Swordsman->s, gameLvL, config->text_nps_swordsman, 5280, 1620, 122, 152, "Swordsman")
    };
//    npsLvL[3].push_back(new Blacksmith(config->s_Nps_Blacksmith->s, gameLvL, config->text_nps_blacksmith, 1100, 1620, 122, 152, "Blacksmith"));
//    npsLvL[3].push_back(new Supreme_Wizard(config->s_Nps_SupremeWizard->s, gameLvL, config->text_nps_supreme_wizard, 1250, 1620, 122, 152, "Supreme_Wizard"));
//    npsLvL[3].push_back(new Soothsayer(config->s_Nps_Soothsayer->s, gameLvL, config->text_nps_soothsayer, 2000, 1620, 122, 152, "Soothsayer"));
//    npsLvL[3].push_back(new Swordsman(config->s_Nps_Swordsman->s, gameLvL, config->text_nps_swordsman, 5280, 1620, 122, 152, "Swordsman"));
    // Item
    itemLvL[1] = {
            new health_item(config->s_Item_Health->s, gameLvL, 4800, 1600, 40, 45, "Health"),
            new money_item(config->s_Item_Money->s, gameLvL, 300, 1600, 30, 40, "Money"),
            new money_item(config->s_Item_Diamond->s, gameLvL, 9400, 1600, 40, 60, "Diamond"),
            new key_item(config->s_Item_KeySilver->s, gameLvL, 8, 1600, 40, 45, "KeySilver"),
            new key_item(config->s_Item_KeyGold->s, gameLvL, 9300, 1600, 40, 45, "KeyGold")
    };
//    itemLvL[1].push_back(new health_item(config->s_Item_Health->s, gameLvL, 4800, 1600, 40, 45, "Health"));
//    itemLvL[1].push_back(new money_item(config->s_Item_Money->s, gameLvL, 300, 1600, 30, 40, "Money"));
//    itemLvL[1].push_back(new money_item(config->s_Item_Diamond->s, gameLvL, 9400, 1600, 40, 60, "Diamond"));
//    itemLvL[1].push_back(new key_item(config->s_Item_KeySilver->s, gameLvL, 8, 1600, 40, 45, "KeySilver"));
//    itemLvL[1].push_back(new key_item(config->s_Item_KeyGold->s, gameLvL, 9300, 1600, 40, 45, "KeyGold"));
    // item lvl 2
    itemLvL[2] = {

    };

    // item lvl 3
    itemLvL[3] = {

    };

    //Fon
    fonLvL[1] = {
            new FonGame(config->s_LvL1_Fon->s, gameLvL, 0, 1360, 10, 10,"Fon"),
            new FonGame(config->s_LvL1_Fon->s, gameLvL, 4900, 1360, 10, 10,"Fon"),
            new FonGame(config->s_LvL_1_FonBack->s, gameLvL, 0, 1860, 0, 0, "Back"),
            new FonGame(config->s_LvL_1_FonBack->s, gameLvL, 4900, 1860, 0, 0, "Back")
    };
//    fonLvL[1].push_back(new FonGame(config->s_LvL1_Fon->s, gameLvL, 0, 1360, 10, 10," "));
//    fonLvL[1].push_back(new FonGame(config->s_LvL1_Fon->s, gameLvL, 4900, 1360, 10, 10," "));
//    fonLvL[1].push_back(new FonGame(config->s_LvL_1_FonBack->s, gameLvL, 0, 1860, 0, 0, " "));
//    fonLvL[1].push_back(new FonGame(config->s_LvL_1_FonBack->s, gameLvL, 4900, 1860, 0, 0, " "));
    //
    fonLvL[2] = {
//            new FonGame(config->s_LvL2_Fon->s, gameLvL, 0, 1360, 10, 10," "),
//            new FonGame(config->s_LvL2_Fon->s, gameLvL, 4900, 1360, 10, 10," ")
    };
//    fonLvL[2].push_back(new FonGame(config->s_LvL2_Fon->s, gameLvL, 0, 1360, 10, 10," "));
//    fonLvL[2].push_back(new FonGame(config->s_LvL2_Fon->s, gameLvL, 4900, 1360, 10, 10," "));
    //
    fonLvL[3] = {

    };

}
void GameEngine::pollEvents() {
    while (window->pollEvent(game_event)){
        EventFunc();
        if(game_event.type == Event::Closed || game_event.key.code == Keyboard::Escape){
            window->close();
        }
        // масштабирования камеры
        if (game_event.type == sf::Event::MouseWheelScrolled)
        {
            if (game_event.mouseWheelScroll.delta < 0)
                config->view.zoom(1.1f);
            else if (game_event.mouseWheelScroll.delta > 0)
                config->view.zoom(0.9f);
        }
        if(game_event.type == Event::KeyPressed){
            if(game_event.key.code == Keyboard::P){
                if(player->is_health > 0)
                    player->is_health -= 20;
            }
            if(game_event.key.code == sf::Keyboard::Tab){
                cout << "X - " << player->position.x <<"\n"<< "Y - " <<  player->position.y << "\n"
                     << "Health: " <<  player->is_health << " / " << player->f_health << "\n"
                     << "level: " << player->lvl_player<<"\n"
                     << "k_silver: " << player->k_Silver << "\n"
                     << "k_gold: " << player->k_Gold << "\n"
                     << "money: " << player->money <<endl;
            }
            if(game_event.key.code == Keyboard::F1){
                gameLvL = new GameLvL(config->s_LvL1->s, 1);
                player->setPosition(1000, 1600);
                cout << "LvL: 1" << endl;
            }
            if(game_event.key.code == Keyboard::F2){
                gameLvL = new GameLvL(config->s_LvL2->s, 2);
                player->setPosition(1000, 600);
                cout << "LvL: 2" << endl;
            }
            if(game_event.key.code == Keyboard::F3){
                gameLvL = new GameLvL(config->s_LvL3->s, 3);
                player->setPosition(1000, 1500);
                cout << "LvL: 3" << endl;
            }
            if(game_event.key.code == Keyboard::F4){
                gameLvL = new GameLvL(config->s_LvL4->s, 4);
                player->setPosition(1000, 1500);
                cout << "LvL: 4" << endl;
            }
            if(game_event.key.code == Keyboard::F5){
                gameLvL = new GameLvL(config->s_LvL5->s, 5);
                player->setPosition(1000, 1500);
                cout << "LvL: 5" << endl;
            }
            if(game_event.key.code == Keyboard::F6){
                gameLvL = new GameLvL(config->s_LvL6->s, 6);
                player->setPosition(1000, 1500);
                cout << "LvL: 6" << endl;
            }
        }
    }
}

void GameEngine::EventFunc() {
    ShootBullet();
    TakeItems();
    TakeEquipment();
    TakeChest();
    TakeDoor();
    TakeNps();
}

void GameEngine::TakeItems() {
    for(itItem = itemLvL[gameLvL->gameLvL].begin(); itItem != itemLvL[gameLvL->gameLvL].end(); itItem++){
        if ((*itItem)->isTake(*player)) {
            itemLvL[gameLvL->gameLvL].erase(itItem);
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
                            if ((*itChest)->OpenChest() == 1){ itemLvL[gameLvL->gameLvL].push_back(new key_item(config->s_Item_KeySilver->s, gameLvL, (*itChest)->position.x + 20,(*itChest)->position.y, 40, 45, "KeySilver")); }
                            if ((*itChest)->OpenChest() == 2){ itemLvL[gameLvL->gameLvL].push_back(new health_item(config->s_Item_Health->s, gameLvL, (*itChest)->position.x + 20,(*itChest)->position.y, 40, 45, "Health")); }
                            if ((*itChest)->OpenChest() == 3){ }
                        }
                    }
                    if ((*itChest)->name == "MiddleChest" && player->k_Silver > 0) {
                        if ((!(*itChest)->is_open)) {
                            if ((*itChest)->OpenChest() == 1){itemLvL[gameLvL->gameLvL].push_back(new key_item(config->s_Item_KeyGold->s, gameLvL, (*itChest)->position.x + 20,(*itChest)->position.y, 40, 45, "KeyGold"));}
                            if ((*itChest)->OpenChest() == 2){itemLvL[gameLvL->gameLvL].push_back(new money_item(config->s_Item_Money->s, gameLvL, (*itChest)->position.x + 20,(*itChest)->position.y, 40, 45, "Money"));}
                            if ((*itChest)->OpenChest() == 3){itemLvL[gameLvL->gameLvL].push_back(new health_item(config->s_Item_Health->s, gameLvL, (*itChest)->position.x + 20,(*itChest)->position.y, 40, 45, "Health"));}
                            player->k_Silver--;
                        }
                    }
                    if ((*itChest)->name == "BigChest" && player->k_Gold > 0) {
                        if ((!(*itChest)->is_open)) {
                            if ((*itChest)->OpenChest() == 1){itemLvL[gameLvL->gameLvL].push_back(new money_item(config->s_Item_Diamond->s, gameLvL, (*itChest)->position.x + 20,(*itChest)->position.y, 40, 45, "Diamond"));}
                            if ((*itChest)->OpenChest() == 2){itemLvL[gameLvL->gameLvL].push_back(new key_item(config->s_Item_KeyGold->s, gameLvL, (*itChest)->position.x + 20,(*itChest)->position.y, 40, 45, "KeyGold"));}
                            if ((*itChest)->OpenChest() == 3){itemLvL[gameLvL->gameLvL].push_back(new key_item(config->s_Item_KeySilver->s, gameLvL, (*itChest)->position.x + 20,(*itChest)->position.y, 40, 45, "KeySilver"));}
                            player->k_Gold--;
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

}

void GameEngine::ShootBullet() {
    if(game_event.type == Event::KeyPressed){
        if(game_event.key.code == Keyboard::LControl){
            if(player->life && player->isShoot){
                bulletLvL.push_back(new Bullet(config->s_Bullet->s,gameLvL, player->position.x, player->position.y, 500, 370, "Bullet", player->state));
                player->BulletTime = 0;
            }
        }
    }
}
// clear color
void GameEngine::renderClear(){
    if(gameLvL->gameLvL == 1){
        window->clear(Color(173, 208, 207));
    }
    else if(gameLvL->gameLvL == 2){
        window->clear(Color(173, 208, 207));
    }
    else if(gameLvL->gameLvL == 3){
        window->clear(Color(40, 40, 40));
    }
    else if(gameLvL->gameLvL == 4){
        window->clear(Color(173, 208, 207));
    }
    else if(gameLvL->gameLvL == 5){
        window->clear(Color(173, 208, 207));
    }
    else if(gameLvL->gameLvL == 6){
        window->clear(Color(173, 208, 207));
    }
    else{

    }
}

void GameEngine::run() {
    while (isRunning()){
        update();
        render();
    }
}