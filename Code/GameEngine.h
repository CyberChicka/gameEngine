#ifndef GAMEENGINE_GAMEENGINE_H
#define GAMEENGINE_GAMEENGINE_H
#include "Config.h"

#include "MainMenu.h"
#include "Player/Player.h"
#include "Enemy/Enemy.h"
#include "Enemy/Enemy Ghost/Enemy_Ghost.h"
#include "Enemy/Enemy Scelet/Enemy_Scelet.h"
#include "Map/GameLvL.h"

using namespace sf;
using namespace std;

class GameEngine {
public:
    GameEngine();
    ~GameEngine();

    void run();
private:
    RenderWindow *window;
    //Game
    float game_time = 0;
    Clock clock;
    Config *config = Config::getInstance();
    Event game_event; // создаём переменную типа Event
    // Class player
    Player *player;
    // Class Enemy
    list<Enemy*>::iterator itEnemy;
    list<Enemy*> enemyLvL1;
    // Map
    GameLvL *gameLvL;
    void update();
    //
    void render();
    //
    void pollEvents();
    void EventFunc();
    void TakeItems();
    void TakeChest();
    void TakeDoor();
    void TakeEnemy();
    void TakeEquipment();
    void TakeNps();
    //
    bool isRunning();
    // intialize the RenderWindow.
    void initClass();
    void initWindow();
    void initText();
    void initSounds();
    //

};
#endif //GAMEENGINE_GAMEENGINE_H
