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
    // Nps update
    for(itNps = npsLvL[gameLvL->gameLvL].begin(); itNps != npsLvL[gameLvL->gameLvL].end(); itNps++){
        (*itNps)->update(game_time, gameLvL);
    }
    // Item update
    for(itItem = itemLvL[gameLvL->gameLvL].begin(); itItem != itemLvL[gameLvL->gameLvL].end(); itItem++){
        (*itItem)->update(game_time, gameLvL);
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
    // Nps render
    for(itNps = npsLvL[gameLvL->gameLvL].begin(); itNps != npsLvL[gameLvL->gameLvL].end(); itNps++){
        (*itNps)->draw(*window, config->view);
    }
    // Item render
    for(itItem = itemLvL[gameLvL->gameLvL].begin(); itItem != itemLvL[gameLvL->gameLvL].end(); itItem++){
        (*itItem)->draw(*window, config->view);
    }
    // Object render
    for(itObject = objLvL[gameLvL->gameLvL].begin(); itObject != objLvL[gameLvL->gameLvL].end(); itObject++){
        (*itObject)->draw(*window, config->view);
    }
    // render player
    player->draw(*window, config->view);
    // Enemy render
    for(itEnemy = enemyLvL[gameLvL->gameLvL].begin(); itEnemy != enemyLvL[gameLvL->gameLvL].end(); itEnemy++){
        (*itEnemy)->draw(*window, config->view);
    }
    window->display(); // создаём дисплей
}

void GameEngine::initWindow() {
    // для начало используем это способ, потом через настройки будем изменять размер
    config->window_size.x = VideoMode::getDesktopMode().width / 2; // ширину монитора делим на 2
    config->window_size.y = VideoMode::getDesktopMode().height / 2;// высоту монитора делим на 2
    config->view_size.x = config->window_size.x;
    config->view_size.y = config->window_size.y;
    const VideoMode videoMode = VideoMode(config->window_size.x, config->window_size.y);
    const Uint32 style = sf::Style::Close| sf::Style::Titlebar;

    // Создание окна и камеру, вертикальное синхронизация
    window = new sf::RenderWindow(videoMode, config->window_title, style);
    config->view.reset(FloatRect(0, 0, config->view_size.x, config->view_size.y));
    //window->setFramerateLimit(config->window_frame);
    //window->setVerticalSyncEnabled(true);
}

void GameEngine::initClass() {
    gameLvL = new GameLvL(config->s_LvL1->s, 1);
    //LvL1
    player = new Player(config->s_player->s, gameLvL ,1000, 1800, 56, 60, "player");
    //Enemy
    enemyLvL[1].push_back(new Enemy_Ghost(config->s_EnemyGhost->s, gameLvL, 1400, 1390, 40, 88, "Ghost"));
    enemyLvL[2].push_back(new Enemy_Ghost(config->s_EnemyGhost->s, gameLvL, 800, 1636, 40, 88, "Ghost"));
    // Object LvL 1
    objLvL[1].push_back(new Object(config->s_Object_HomeDrov->s, gameLvL, 1200, 1600, 100, 298,"Home"));
    // Object LvL 2

    // Object LvL 3
    objLvL[3].push_back(new Object(config->s_Object_FlyingObelisk->s, gameLvL, 1400, 1600, 145, 390,"FlyingObelisk"));

    objLvL[3].push_back(new Object(config->s_Object_DarkTreeBig->s, gameLvL, 1450, 1600, 125, 265,"DarkTreeBig"));
    objLvL[3].push_back(new Object(config->s_Object_DarkTreeSmall->s, gameLvL, 1450, 1600, 125, 265,"DarkTreeSmall"));
    //Nps
    //Nps nps_1(config->s_Nps_Historian->s, gameLvL, config->text_nps, 1600, 1520, 56, 60, "Historian");
    npsLvL[1].push_back(new Knight(config->s_Nps_Knight->s, gameLvL, config->text_nps, 9500, 586, 56, 138, "Knight"));
    npsLvL[1].push_back(new Historian(config->s_Nps_Historian->s, gameLvL, config->text_nps, 1100, 1520, 56, 150, "Historian"));
    npsLvL[1].push_back(new Blacksmith(config->s_Nps_Blacksmith->s, gameLvL, config->text_nps, 5750, 1620, 122, 152, "Blacksmith"));
    //
    npsLvL[2].push_back(new Aiden(config->s_Nps_Aiden->s, gameLvL, config->text_nps, 4300, 1620, 50, 50, "Aiden"));
    npsLvL[2].push_back(new Witcher(config->s_Nps_Witcher->s, gameLvL, config->text_nps, 800, 1620, 50, 190, "Witcher"));
    npsLvL[2].push_back(new Blacksmith(config->s_Nps_Blacksmith->s, gameLvL, config->text_nps, 1200, 1620, 122, 152, "Blacksmith"));
    //
    npsLvL[3].push_back(new Blacksmith(config->s_Nps_Blacksmith->s, gameLvL, config->text_nps, 1100, 1620, 122, 152, "Blacksmith"));
    npsLvL[3].push_back(new Supreme_Wizard(config->s_Nps_SupremeWizard->s, gameLvL, config->text_nps, 1250, 1620, 122, 152, "Supreme_Wizard"));
    npsLvL[3].push_back(new Soothsayer(config->s_Nps_Soothsayer->s, gameLvL, config->text_nps, 2000, 1620, 122, 152, "Soothsayer"));
    npsLvL[3].push_back(new Swordsman(config->s_Nps_Swordsman->s, gameLvL, config->text_nps, 5280, 1620, 122, 152, "Swordsman"));
    // Item
    itemLvL[1].push_back(new health_item(config->s_Item_Health->s, gameLvL, 4800, 1600, 40, 45, "Health"));
    itemLvL[1].push_back(new money_item(config->s_Item_Money->s, gameLvL, 300, 1600, 30, 40, "Money"));
    itemLvL[1].push_back(new money_item(config->s_Item_Diamond->s, gameLvL, 9400, 1600, 40, 60, "Diamond"));
    itemLvL[1].push_back(new key_item(config->s_Item_KeySilver->s, gameLvL, 8, 1600, 40, 45, "KeySilver"));
    itemLvL[1].push_back(new key_item(config->s_Item_KeyGold->s, gameLvL, 9300, 1600, 40, 45, "KeyGold"));
    //Fon
//    fonLvL[1].push_back(new FonGame(config->s_LvL1_Fon->s, gameLvL, 0, 1360, 10, 10," "));
//    fonLvL[1].push_back(new FonGame(config->s_LvL1_Fon->s, gameLvL, 4900, 1360, 10, 10," "));
//    fonLvL[2].push_back(new FonGame(config->s_LvL2_Fon->s, gameLvL, 0, 1360, 10, 10," "));
//    fonLvL[2].push_back(new FonGame(config->s_LvL2_Fon->s, gameLvL, 4900, 1360, 10, 10," "));
}
void GameEngine::pollEvents() {
    while (window->pollEvent(game_event)){
        EventFunc();
        if(game_event.type == Event::Closed || game_event.key.code == Keyboard::Escape){
            window->close();
        }
        // масштабирования камеры
        if(game_event.type == Event::MouseWheelScrolled){
            if (game_event.type == sf::Event::MouseWheelScrolled)
            {
                if (game_event.mouseWheelScroll.delta < 0)
                    config->view.zoom(1.1f);
                else if (game_event.mouseWheelScroll.delta > 0)
                    config->view.zoom(0.9f);
            }
        }
        if(game_event.type == Event::KeyPressed){
            if(game_event.key.code == Keyboard::P){
                if(player->is_health > 0)
                    player->is_health -= 20;
            }
            if(game_event.key.code == sf::Keyboard::Tab){
                cout << "X - " << player->position.x <<"\n"<< "Y - " <<  player->position.y << "\n"
                     << "Health: " <<  player->is_health << " / " << player->f_health << endl;
            }
            if(game_event.key.code == Keyboard::Num1){
                gameLvL = new GameLvL(config->s_LvL1->s, 1);
                player->setPosition(1000, 1600);
                cout << "LvL: 1" << endl;
            }
            if(game_event.key.code == Keyboard::Num2){
                gameLvL = new GameLvL(config->s_LvL2->s, 2);
                player->setPosition(1000, 600);
                cout << "LvL: 2" << endl;
            }
            if(game_event.key.code == Keyboard::Num3){
                gameLvL = new GameLvL(config->s_LvL3->s, 3);
                player->setPosition(1000, 1500);
                cout << "LvL: 3" << endl;
            }
            if(game_event.key.code == Keyboard::Num4){
                gameLvL = new GameLvL(config->s_LvL4->s, 4);
                player->setPosition(1000, 1500);
                cout << "LvL: 4" << endl;
            }
            if(game_event.key.code == Keyboard::Num5){
                gameLvL = new GameLvL(config->s_LvL5->s, 5);
                player->setPosition(1000, 1500);
                cout << "LvL: 5" << endl;
            }
            if(game_event.key.code == Keyboard::Num6){
                gameLvL = new GameLvL(config->s_LvL6->s, 6);
                player->setPosition(1000, 1500);
                cout << "LvL: 6" << endl;
            }
        }
    }
}

void GameEngine::EventFunc() {
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
        } else {

        }
    }
}

void GameEngine::TakeEquipment() {

}

void GameEngine::TakeChest() {

}

void GameEngine::TakeNps() {
    for(itNps = npsLvL[gameLvL->gameLvL].begin(); itNps != npsLvL[gameLvL->gameLvL].end(); itNps++){
//        if((*itNps)->name == " "){
//            (*itNps)->Dialogue(game_event, *player);
//            (*itNps)->Interaction(game_event, *player);
//        } // Пока не работает
    }
}

void GameEngine::TakeDoor() {

}
void GameEngine::TakeEnemy() {

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
        window->clear(Color(10, 10, 10));
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