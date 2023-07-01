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

    for(itFon = fonLvL.begin(); itFon != fonLvL.end(); itFon++){ (*itFon)->update(game_time, gameLvL->gameLvL); } // update fon
    // update class
    player->update(game_time);
    if(gameLvL->gameLvL == 1){
        for(itEnemy = enemyLvL1.begin(); itEnemy != enemyLvL1.end(); itEnemy++){
            (*itEnemy)->update(game_time, player);
        }
        for(itObject = objLvL1.begin(); itObject != objLvL1.end(); itObject++){
            (*itObject)->update(game_time);
        }
    }
    // Evnet
    pollEvents();
}

void GameEngine::render(){ // Рендер изображения
    window->clear(Color(173, 208, 207)); // очищаем окно
    // render fon
    for(itFon = fonLvL.begin(); itFon != fonLvL.end(); itFon++){
        (*itFon)->draw(*window, config->view);
    }
    gameLvL->RenderDraw(*window, config->view); // Рисуем карту
    window->setView(config->view); // привязываем окно к камере

    player->draw(*window, config->view); // Выводим картинку игрока

    if(gameLvL->gameLvL == 1){
        for(itEnemy = enemyLvL1.begin(); itEnemy != enemyLvL1.end(); itEnemy++){
            (*itEnemy)->draw(*window, config->view);
        }
        for(itObject = objLvL1.begin(); itObject != objLvL1.end(); itObject++){
            (*itObject)->draw(*window, config->view);
        }
    }
    else if(gameLvL->gameLvL == 2){
        for(itEnemy = enemyLvL2.begin(); itEnemy != enemyLvL2.end(); itEnemy++){
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
    // Object

    //Fon
    fonLvL.push_back(new FonGame(config->s_LvL1_Fon->s, gameLvL, 0, 1360, 5000, 50, "Fon_LvL_1"));
    fonLvL.push_back(new FonGame(config->s_LvL1_Fon->s, gameLvL, 4900, 1360, 5000, 50, "Fon_LvL_1"));
    fonLvL.push_back(new FonGame(config->s_LvL2_Fon->s, gameLvL, 0, 1360, 5000, 50, "Fon_LvL_2"));
    fonLvL.push_back(new FonGame(config->s_LvL2_Fon->s, gameLvL, 4900, 1360, 5000, 50, "Fon_LvL_2"));
    fonLvL.push_back(new FonGame(config->s_LvL3_Fon->s, gameLvL, 0, 1360, 5000, 50, "Fon_LvL_3"));
    fonLvL.push_back(new FonGame(config->s_LvL3_Fon->s, gameLvL, 4900, 1360, 5000, 50, "Fon_LvL_3"));
    fonLvL.push_back(new FonGame(config->s_LvL4_Fon->s, gameLvL, 0, 1360, 5000, 50, "Fon_LvL_4"));
    fonLvL.push_back(new FonGame(config->s_LvL4_Fon->s, gameLvL, 4900, 1360, 5000, 50, "Fon_LvL_4"));
    fonLvL.push_back(new FonGame(config->s_LvL5_Fon->s, gameLvL, 0, 1360, 5000, 50, "Fon_LvL_5"));
    fonLvL.push_back(new FonGame(config->s_LvL5_Fon->s, gameLvL, 4900, 1360, 5000, 50, "Fon_LvL_5"));
    fonLvL.push_back(new FonGame(config->s_LvL6_Fon->s, gameLvL, 0, 1360, 5000, 50, "Fon_LvL_6"));
    fonLvL.push_back(new FonGame(config->s_LvL6_Fon->s, gameLvL, 4900, 1360, 5000, 50, "Fon_LvL_6"));
}
void GameEngine::pollEvents() {
    while (window->pollEvent(game_event)){
        EventFunc();
        if(game_event.type == Event::Closed || game_event.key.code == Keyboard::Escape){
            window->close();
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
                player->gameLvL = gameLvL;
                cout << "LvL: 1" << endl;
            }
            if(game_event.key.code == Keyboard::Num2){
                gameLvL = new GameLvL(config->s_LvL2->s, 2);
                player->setPosition(1000, 600);
                player->gameLvL = gameLvL;
                cout << "LvL: 2" << endl;
            }
            if(game_event.key.code == Keyboard::Num3){
                gameLvL = new GameLvL(config->s_LvL3->s, 3);
                player->setPosition(1000, 1500);
                player->gameLvL = gameLvL;
                cout << "LvL: 3" << endl;
            }
            if(game_event.key.code == Keyboard::Num4){
                gameLvL = new GameLvL(config->s_LvL4->s, 4);
                player->setPosition(1000, 1500);
                player->gameLvL = gameLvL;
                cout << "LvL: 4" << endl;
            }
            if(game_event.key.code == Keyboard::Num5){
                gameLvL = new GameLvL(config->s_LvL5->s, 5);
                player->setPosition(1000, 1500);
                player->gameLvL = gameLvL;
                cout << "LvL: 5" << endl;
            }
            if(game_event.key.code == Keyboard::Num6){
                gameLvL = new GameLvL(config->s_LvL6->s, 6);
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
