#ifndef GAMEENGINE_GAMEENGINE_H
#define GAMEENGINE_GAMEENGINE_H
#include "Config.h"

#include "MainMenu.h"
#include "Player/Player.h"
#include "Enemy/Enemy.h"
#include "Enemy/Enemy BigGhost/Enemy_BigGhost.h"
#include "Enemy/Enemy Boom/Enemy_Boom.h"
#include "Enemy/Enemy Mag/Enemy_Mag.h"
#include "Enemy/Enemy Bat/Enemy_Bat.h"
#include "Enemy/Enemy Ghost/Enemy_Ghost.h"
#include "Enemy/Enemy Scelet/Enemy_Scelet.h"
#include "Map/GameLvL.h"
#include "Items/Item.h"
#include "Object/Object.h"
#include "Object/Fon/FonGame.h"
#include "Nps/Nps.h"
#include "Nps/Aiden/Aiden.h"
#include "Nps/Historian/Historian.h"
#include "Nps/Blacksmith/Blacksmith.h"
#include "Nps/Knight/Knight.h"
#include "Nps/Soothsayer/Soothsayer.h"
#include "Nps/Supreme_Wizard/Supreme_Wizard.h"
#include "Nps/Swordsman/Swordsman.h"
#include "Nps/Witcher/Witcher.h"
#include "Items/Health/health_item.h"
#include "Items/Key/key_item.h"
#include "Items/Money/money_item.h"
#include "Chest/Chest.h"
#include "Player/Bullet/Bullet.h"
#include "Player/GUI/GUI_player.h"

using namespace sf;
using namespace std;

class GameEngine {
public:
    GameEngine();
    ~GameEngine();

    void run();
private:
    Config *config = Config::getInstance();
    // render
    RenderWindow *window;
    //Gam
    float game_time = 0;
    Time elapsed;
    Clock clock;
    Event game_event; // создаём переменную типа Event
    // Class player
    Player *player;
    GUI_player *GUI;
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
    list<FonGame*>fonLvL[7];
    FonGame *enemyMagDamage;
//    //Class Nps
    list<Nps*>::iterator itNps;
    list<Nps*> npsLvL[7];
    // Class Chest
    list<Chest*>::iterator itChest;
    list<Chest*> chestLvL[7];
    // class Bullet
    list<Bullet*>::iterator itBullet;
    list<Bullet*> bulletLvL;
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
    void TakeInventory();
    void ShootBullet();
    
    //
    bool isRunning();
    // intialize the RenderWindow.
    void initClass();
    void initWindow();
    void renderClear();
    //

};
#endif //GAMEENGINE_GAMEENGINE_H
