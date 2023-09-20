//
// Created by Doni on 15.05.2023.

#include "GameEngine.h"

GameEngine::GameEngine() {
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
    cout << "Game Exit!" << endl;
    sleep(10);
}
////////////////////////////////////// update //////////////////////////////////
void GameEngine::update() {
    // Time
    this->game_time = this->clock.getElapsedTime().asMicroseconds();
    this->elapsed = this->clock.restart();
    this->game_time = this->game_time / 800;
    // //////////////////// Fon update ////////////////////
    for(itFon = fonLvL[gameLvL->gameLvL].begin(); itFon != fonLvL[gameLvL->gameLvL].end(); itFon++){
        (*itFon)->update(this->game_time,this->gameLvL);
    }
    // /////////////// Cloud update //////////////////////
    for(itCloud = cloudLvL[gameLvL->gameLvL].begin(); itCloud != cloudLvL[gameLvL->gameLvL].end(); itCloud++){
        (*itCloud)->update(this->game_time, this->gameLvL);
    }
    // //////////////////// player update ////////////////////
    this->player->update(this->game_time, this->gameLvL);
    this->GUI->GUI_update(this->player);
    this->player->particles->update(this->elapsed);
    // //////////////////// Object update ////////////////////
    for(itObject = objLvL[gameLvL->gameLvL].begin(); itObject != objLvL[gameLvL->gameLvL].end(); itObject++){
        (*itObject)->update(this->game_time, this->gameLvL);
    }
    // //////////////////// Enemy update ////////////////////
    for(itEnemy = enemyLvL[gameLvL->gameLvL].begin(); itEnemy != enemyLvL[gameLvL->gameLvL].end(); itEnemy++){
        if(!(*itEnemy)->life)this->enemyLvL[gameLvL->gameLvL].erase(itEnemy);
        (*itEnemy)->update(this->game_time, this->gameLvL,  this->player);
    }
    // //////////////////// Chest update ////////////////////
    for(itChest = chestLvL[gameLvL->gameLvL].begin(); itChest != chestLvL[gameLvL->gameLvL].end(); itChest++){
        (*itChest)->update(this->game_time, this->gameLvL);
    }
    // //////////////////// Nps update ////////////////////
    for(itNps = npsLvL[gameLvL->gameLvL].begin(); itNps != npsLvL[gameLvL->gameLvL].end(); itNps++){
        (*itNps)->update(this->game_time, this->gameLvL);
    }
    // //////////////////// Item update ////////////////////
    for(itItem = itemLvL[gameLvL->gameLvL].begin(); itItem != itemLvL[gameLvL->gameLvL].end(); itItem++){
        (*itItem)->update(this->game_time, this->gameLvL);
    }
    // //////////////////// Bullet update ////////////////////
    for(itBullet = bulletLvL.begin(); itBullet != bulletLvL.end(); itBullet++){
        (*itBullet)->upadte(this->game_time);
    }
    this->pollEvents(); // Event
}
////////////////////////////////////// render //////////////////////////////////
void GameEngine::render(){ // Рендер изображения
    this->renderClear();
    // //////////////////// render fon ////////////////////
    for(itFon = fonLvL[gameLvL->gameLvL].begin(); itFon != fonLvL[gameLvL->gameLvL].end(); itFon++){
         (*itFon)->draw(*this->window, this->config->view);
    }
    // //////////////////// render Cloud ////////////////////
    for(itCloud = cloudLvL[gameLvL->gameLvL].begin(); itCloud != cloudLvL[gameLvL->gameLvL].end(); itCloud++){
        (*itCloud)->draw(*this->window, this->config->view);
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
//////////////////////////////////// init Window ///////////////////////
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
    this->window->setFramerateLimit(config->window_frame);
    this->window->setVerticalSyncEnabled(true);
}
//////////////////////////////////// init Class ///////////////////////
void GameEngine::initClass() {
    // gameLvL
    this->gameLvL = new GameLvL(config->s_LvL[1]->s, 1);
    //Player
    this->player = new Player(config->s_player->s, gameLvL,8000, 1500, 56, 60, "god");
    this->enemyMagDamage = new FonGame(config->s_enemy_MagDamage->s, gameLvL, 0, 0, 0, 0, "MagDamage");
    this->GUI = new GUI_player;
    //Enemy
    this->initClassEnemy();
//    // Object
    this->initClassObject();
    //Chest
    this->initClassChest();
    //Nps
    this->initClassNps();
    // Item
    this->initClassItem();
//    //Fon
    this->initClassFon();
    // Cloud
    this->initClassCloud();
}
//////////////////////////////////// Event /////////////////////////////
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
                     << "Health: " << player->is_health << " / " << player->f_health << "\n"
                     << "level: " << player->lvl_player << "\n"
                     << "k_silver: " << player->k_silver << "\n"
                     << "k_gold: " << player->k_gold << "\n"
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
//////////////////////////////// clear color ///////////////////////////
void GameEngine::renderClear(){
    switch (gameLvL->gameLvL) {
        case 1:this->window->clear(Color(173, 208, 207));break;
        case 2:this->window->clear(Color(173, 208, 207)); break;
        case 3:this->window->clear(Color(30, 30, 30)); break;
        case 4:this->window->clear(Color(173, 208, 207)); break;
        case 5:this->window->clear(Color(173, 208, 207)); break;
        case 6:this->window->clear(Color(173, 208, 207)); break;
    }

}
///////////////////////////////////// Game Run //////////////////////////////////////
bool GameEngine::isRunning(){
    if (this->window == nullptr){ cout << "\n Error Windows \n"; return false; }
    else return this->window->isOpen();
}
void GameEngine::run(){
    while (this->isRunning()){
        this->update();
        this->render();
    }
}