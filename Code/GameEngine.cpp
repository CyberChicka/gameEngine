//
// Created by Doni on 15.05.2023.

#include "GameEngine.h"

GameEngine::GameEngine() {
    initClass();
    initWindow();
    initSounds();
    initText();
}
GameEngine::~GameEngine() {
    cout << "========== removed from memory ========" << endl;
    if(window != nullptr){ delete window; }
    delete Config::getInstance(); // очищаем память
    delete player; // очищаем память
    delete gameLvL; // очищаем память
}
bool GameEngine::isRunning(){
    if (window == nullptr){cout << "\n Error Windows \n"; return false;}
    else return window->isOpen();
}

void GameEngine::update() {
    // Time
    game_time = clock.getElapsedTime().asMicroseconds();
    clock.restart();
    game_time = game_time / 800;
    // View
    config->getPlayerCoordinateForView(player->GetX(), player->GetY());

    // update class
    player->update(game_time);
    if(gameLvL->gameLvL == 1){
        for(itEnemy = enemyLvL1.begin(); itEnemy != enemyLvL1.end(); itEnemy++){
            (*itEnemy)->update(game_time, player);
        }
    }
    // Evnet
    pollEvents();
}

void GameEngine::render(){ // Рендер изображения
    window->clear(Color::Cyan); // очищаем окно
    gameLvL->RenderDraw(*window, config->view); // Рисуем карту
    window->setView(config->view); // привязываем окно к камере

    player->draw(*window, config->view); // Выводим картинку игрока
    if(gameLvL->gameLvL == 1){
        for(itEnemy = enemyLvL1.begin(); itEnemy != enemyLvL1.end(); itEnemy++){
            (*itEnemy)->draw(*window, config->view);
        }
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
    const Uint32 style = sf::Style::Close | sf::Style::Titlebar;

    // Создание окна и камеру, вертикальное синхронизация
    window = new sf::RenderWindow(videoMode, config->window_title, style);
    config->view.reset(FloatRect(0, 0, config->view_size.x, config->view_size.y));
    window->setFramerateLimit(config->window_frame);
    window->setVerticalSyncEnabled(true);
}

void GameEngine::initClass() {
    gameLvL = new GameLvL(config->s_LvL1->s, 1);

    player = new Player(config->s_player->s, gameLvL ,857, 1800, 56, 60, "player");
    //LvL1
    //Enemy
    enemyLvL1.push_back(new Enemy_Ghost(config->s_EnemyGhost->s, gameLvL, 700, 1800, 40, 88, "Ghost"));

    //enemyLvL1.push_back(new Enemy_Skeleton(config->s_EnemySkeleton->s, gameLvL,0, 0, 0, 0, "EnemySkeleton1"));
}

void GameEngine::pollEvents() {
    while (window->pollEvent(game_event)){
        EventFunc();
        if(game_event.type == Event::Closed || game_event.key.code == Keyboard::Escape){
            window->close();
        }
        if(game_event.type == Event::KeyPressed){
            if(game_event.key.code == sf::Keyboard::Tab){
                cout << "X - " << player->position.x <<"\n"<< "Y - " <<  player->position.y << "\n"
                << "Health - " <<  player->is_health << endl;
            }
            if(game_event.key.code == Keyboard::Num1){
                gameLvL = new GameLvL(config->s_LvL1->s, 1);
                player->setPosition(1000, 1600);
                player->gameLvL = gameLvL;
                cout << "LvL: 1" << endl;
            }
            if(game_event.key.code == Keyboard::Num2){
                gameLvL = new GameLvL(config->s_LvL1->s, 2);
                player->setPosition(1000, 700);
                player->gameLvL = gameLvL;
                cout << "LvL: 2" << endl;
            }
            if(game_event.key.code == Keyboard::Num3){
                gameLvL = new GameLvL(config->s_LvL1->s, 3);
                player->setPosition(1000, 1500);
                player->gameLvL = gameLvL;
                cout << "LvL: 3" << endl;
            }
            if(game_event.key.code == Keyboard::Num4){
                gameLvL = new GameLvL(config->s_LvL1->s, 4);
                player->setPosition(1000, 1500);
                player->gameLvL = gameLvL;
                cout << "LvL: 4" << endl;
            }
            if(game_event.key.code == Keyboard::Num5){
                gameLvL = new GameLvL(config->s_LvL1->s, 5);
                player->setPosition(1000, 1500);
                player->gameLvL = gameLvL;
                cout << "LvL: 5" << endl;
            }
            if(game_event.key.code == Keyboard::Num6){
                gameLvL = new GameLvL(config->s_LvL1->s, 3);
                player->setPosition(1000, 1500);
                player->gameLvL = gameLvL;
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

}

void GameEngine::TakeEquipment() {

}

void GameEngine::TakeChest() {

}

void GameEngine::TakeNps() {

}

void GameEngine::TakeDoor() {

}
void GameEngine::TakeEnemy() {

}
// Sound
void GameEngine::initSounds() {

}
// Text
void GameEngine::initText() {

}

void GameEngine::run() {
    while (isRunning()){
        update();
        render();
    }
}
