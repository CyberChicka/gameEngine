#include "Config.h"

Config *Config::instance = nullptr;

Config::Config() {
    LoadMusic();
    LoadSound();
    LoadText();
    LoadImage();
}
Config::~Config() {
    delete s_player;
    // Delete enemy sprite
    delete s_EnemyGhost;
    delete s_EnemySkeleton;
    delete s_Enemy_Bat;
    delete s_Enemy_Boom;
    delete s_Enemy_Mag;
    delete s_Enemy_BigGhost;
    delete s_Enemy_MagDamage;
    // delete sprite lvl
    delete s_LvL1;
    delete s_LvL2;
    delete s_LvL3;
    delete s_LvL4;
    delete s_LvL5;
    delete s_LvL6;
    // delete fon lvl
    delete s_LvL1_Fon;
    delete s_LvL2_Fon;
    delete s_LvL3_Fon;
    delete s_LvL4_Fon;
    delete s_LvL5_Fon;
    delete s_LvL6_Fon;
    delete s_LvL_1_FonBack;
    delete s_LvL_2_FonBack;
    delete s_LvL_3_FonBack;
    delete s_LvL_4_FonBack;
    delete s_LvL_5_FonBack;
    delete s_LvL_6_FonBack;
    // delete Nps sprite
    delete s_Nps_Witcher;
    delete s_Nps_Swordsman;
    delete s_Nps_SupremeWizard;
    delete s_Nps_Soothsayer;
    delete s_Nps_Knight;
    delete s_Nps_Historian;
    delete s_Nps_Blacksmith;
    delete s_Nps_Aiden;
    // delete item sprite
    delete s_Item_Money;
    delete s_Item_KeySilver;
    delete s_Item_KeyGold;
    delete s_Item_Diamond;
    delete s_Item_Health;
    // delete object
    delete s_Object_HomeDrov;
    delete s_Object_FlyingObelisk;
    delete s_Object_DarkBush;
    delete s_Object_DarkBush2;
    delete s_Object_DarkStone;
    delete s_Object_DarkTreeBig;
    delete s_Object_DarkTreeSmall;
    delete s_Object_BushHouse;
    delete s_Object_RemainsSkeleton;
    delete s_Object_BonfireHouse;
    delete s_Object_TableHouse;
    // delete chest sprite
    delete s_Chest_Small;
    delete s_Chest_Middle;
    delete s_Chest_Big;
    //delete bullet sprite
    delete s_Bullet;
    //music & sound
    delete m_lvl1;
    delete m_lvl2;
    delete m_lvl3;
    // Text
    delete text_nps_knight;
    delete text_nps_swordsman;
    delete text_nps_supreme_wizard;
    delete text_nps_soothsayer;
    delete text_nps_historian;
    delete text_nps_aiden;
    delete text_nps_historian;
    delete text_nps_witcher;
    //
    delete so_player_attack;
    delete so_enemy_Ghost_attack;
    delete so_enemy_Scelet_attack;
    cout << "============== removed from config ============"<< endl;
}

Config *Config::getInstance() {
    if (instance == nullptr) instance = new Config();
    return instance;
}

View Config::getPlayerCoordinateForView(float x, float y) {
    float tempX = x; float tempY = y;
    this->view.setCenter(tempX, tempY - 100); // Следим за игроком передавая его координаты
    return this->view;
}

void Config::LoadImage() {
    //Sprite Player
    s_player = new CreateImage("SpriteEntity/PlayerBlue.png");
    //Sprite Enemy
    s_EnemyGhost = new CreateImage("SpriteEntity/Enemy/EnemyGhost.png");
    s_EnemySkeleton = new CreateImage("SpriteEntity/Enemy/");
    s_Enemy_BigGhost = new CreateImage("SpriteEntity/Enemy/EnemyBigGhost.png");
    s_Enemy_Boom = new CreateImage("SpriteEntity/Enemy/EnemyBoom.png");
    s_Enemy_Bat = new CreateImage("SpriteEntity/Enemy/EnemyBat.png");
    s_Enemy_Mag = new CreateImage("SpriteEntity/Enemy/EnemyMag.png");
    s_Enemy_MagDamage = new CreateImage("SpriteObject/DamageEnemy/DamageMag.png");
    //Sprite LvL Map
    s_LvL1 = new CreateImage("MapTexture/LvL1.png");
    s_LvL2 = new CreateImage("MapTexture/LvL2-up.png");
    s_LvL3 = new CreateImage("MapTexture/LvL3-up.png");
    s_LvL4 = new CreateImage("MapTexture/LvL4.png");
    s_LvL5 = new CreateImage("MapTexture/LvL5.png");
    s_LvL6 = new CreateImage("MapTexture/LvL6.png");
    // Sprite LvL Fon
    s_LvL1_Fon = new CreateImage("SpriteMapObject/FonLvL1_.png");
    s_LvL2_Fon = new CreateImage("SpriteMapObject/FonLvL2_.png");
    s_LvL3_Fon = new CreateImage("SpriteMapObject/FonLvL3_.png");
    s_LvL4_Fon = new CreateImage("SpriteMapObject/FonLvL4_.png");
    s_LvL5_Fon = new CreateImage("SpriteMapObject/FonLvL5_.png");
    s_LvL6_Fon = new CreateImage("SpriteMapObject/FonLvL6_.png");
    s_LvL_1_FonBack = new CreateImage("SpriteMapObject/FonLvL1_Back.png");
    s_LvL_2_FonBack = new CreateImage("SpriteMapObject/FonLvL2_Back.png");
    s_LvL_3_FonBack = new CreateImage("SpriteMapObject/FonLvL3_Back.png");
    s_LvL_4_FonBack = new CreateImage("SpriteMapObject/FonLvL4_Back.png");
    s_LvL_5_FonBack = new CreateImage("SpriteMapObject/FonLvL5_Back.png");
    s_LvL_6_FonBack = new CreateImage("SpriteMapObject/FonLvL6_Back.png");
    // Sprite Nps
    s_Nps_Aiden = new CreateImage("SpriteEntity/Nps/Nps_Aiden.png");
    s_Nps_Blacksmith = new CreateImage("SpriteEntity/Nps/Blacksmith.png");
    s_Nps_Historian = new CreateImage("SpriteEntity/Nps/Nps_Historian.png");
    s_Nps_Knight = new CreateImage("SpriteEntity/Nps/Nps_Knight.png");
    s_Nps_Soothsayer = new CreateImage("SpriteEntity/Nps/Nps_Soothsayer.png");
    s_Nps_SupremeWizard = new CreateImage("SpriteEntity/Nps/Supreme_Wizard.png");
    s_Nps_Swordsman = new CreateImage("SpriteEntity/Nps/Nps_Swordsman.png");
    s_Nps_Witcher = new CreateImage("SpriteEntity/Nps/Witcher.png");
    // Sprite Item
    s_Item_Health = new CreateImage("SpriteItems/HealthLife.png");
    s_Item_KeySilver = new CreateImage("SpriteItems/KeySilver.png");
    s_Item_KeyGold = new CreateImage("SpriteItems/KeyGold.png");
    s_Item_Money = new CreateImage("SpriteItems/Money.png");
    s_Item_Diamond = new CreateImage("SpriteItems/Diamond.png");
    // Sprite Object
    s_Object_HomeDrov = new CreateImage("SpriteMapObject/House/HouseDrov.png");
    s_Object_BushHouse = new CreateImage("SpriteMapObject/House/Bush_House.png");
    s_Object_BonfireHouse = new CreateImage("SpriteMapObject/House/Bonfire_House.png");
    s_Object_FlyingObelisk = new CreateImage("SpriteMapObject/Object/FlyingObelisk.png");
    s_Object_DarkBush = new CreateImage("SpriteMapObject/Object/Dark-bush.png");
    s_Object_DarkBush2 = new CreateImage("SpriteMapObject/Object/Dark-bush-2.png");
    s_Object_DarkStone = new CreateImage("SpriteMapObject/Object/Dark-stone.png");
    s_Object_DarkTreeBig = new CreateImage("SpriteMapObject/Object/Dark-tree-Big.png");
    s_Object_DarkTreeSmall = new CreateImage("SpriteMapObject/Object/Dark-tree-Small.png");
    s_Object_RemainsSkeleton = new CreateImage("SpriteMapObject/miniObject/RemainsSkeleton.png");
    s_Object_TableHouse = new CreateImage("SpriteMapObject/House/Table_House.png");
    // class chest
    s_Chest_Small = new CreateImage("SpriteObject/Chest/SmallChest.png");
    s_Chest_Middle = new CreateImage("SpriteObject/Chest/MiddleChest.png");
    s_Chest_Big = new CreateImage("SpriteObject/Chest/BigChest.png");
    // class bullet
    s_Bullet = new CreateImage("SpriteEntity/Player/AttacPlaz1.png");
}

void Config::LoadText() {
    text_nps_blacksmith = new CreateText("MaredivRegular.ttf", 25, " ", Color::Black);
    text_nps_historian = new CreateText("MaredivRegular.ttf", 25, " ", Color::Black);
    text_nps_aiden = new CreateText("MaredivRegular.ttf", 25, " ", Color::Black);
    text_nps_soothsayer = new CreateText("MaredivRegular.ttf", 25, " ", Color::Black);
    text_nps_supreme_wizard = new CreateText("MaredivRegular.ttf", 25, " ", Color::Black);
    text_nps_swordsman = new CreateText("MaredivRegular.ttf", 25, " ", Color::Black);
    text_nps_knight = new CreateText("MaredivRegular.ttf", 25, " ", Color::Black);
    text_nps_witcher = new CreateText("MaredivRegular.ttf", 25, " ", Color::Black);
}

void Config::LoadMusic() {
    m_lvl1 = new m_Music(" ");
    m_lvl2 = new m_Music(" ");
    m_lvl3 = new m_Music(" ");
}

void Config::LoadSound() {
    so_player_attack = new s_Sound(" ");
    so_enemy_Ghost_attack = new s_Sound(" ");
    so_enemy_Scelet_attack = new s_Sound(" ");
}