#ifndef GAMEENGINE_GAMEENGINE_H
#define GAMEENGINE_GAMEENGINE_H
#include "Config.h"

#include "MainMenu.h"
#include "Player/Player.h"
#include "Enemy/Enemy.h"
#include "Enemy/Enemy Ghost/Enemy_Ghost.h"
#include "Enemy/Enemy Scelet/Enemy_Scelet.h"
#include "Map/GameLvL.h"
#include "Items/Item.h"
#include "Object/Object.h"
#include "Object/Fon/FonGame.h"
#include "Nps/Nps.h"

using namespace sf;
using namespace std;

class GameEngine {
public:
    GameEngine();
    ~GameEngine();

    void run();
private:
    RenderWindow *window;
    //Gam
    float game_time = 0;
    Time elapsed;
    Clock clock;
    Config *config = Config::getInstance();
    Event game_event; // создаём переменную типа Event
    // Class player
    Player *player;
    // Class Enemy
    list<Enemy*>::iterator itEnemy;
    list<Enemy*> enemyLvL[7];
    //Class Item
    list<Item*>::iterator itItem;
    list<Item*> itemLvL[7];
    //Class Object
    list<Object*>::iterator itObject;
    list<Object*> objLvL[7];
//    //Class Fon
    list<FonGame*>::iterator itFon;
    list<FonGame*> fonLvL;
//    //Class Nps
    list<Nps*>::iterator itNps;
    list<Nps*> npsLvL;
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
    void renderClear();
    //

};
#endif //GAMEENGINE_GAMEENGINE_H
