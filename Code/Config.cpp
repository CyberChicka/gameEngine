#include "Config.h"

Config *Config::instance = nullptr;

Config::Config() {
    LoadMusic();
    LoadSound();
    LoadText();
    LoadImage();
}
Config::~Config() {
    delete this->s_player;
    // Delete enemy sprite
    delete this->s_EnemyGhost;
    delete this->s_EnemySkeleton;
    delete this->s_Enemy_Bat;
    delete this->s_Enemy_Boom;
    delete this->s_Enemy_Mag;
    delete this->s_Enemy_BigGhost;
    delete this->s_Enemy_MagDamage;
    // delete sprite lvl
    for(int i = 0; i < size(this->s_LvL); i++){
        delete this->s_LvL[i];
    }
    // delete fon lvl
    for(int i = 0; i < size(this->s_LvL_Fon); i++){
        delete this->s_LvL_Fon[i];
    }
    for(int i = 0; i < size(this->s_LvL_FonBack); i++){
        delete this->s_LvL_FonBack[i];
    }
    // delete Nps sprite
    delete this->s_Nps_Witcher;
    delete this->s_Nps_Swordsman;
    delete this->s_Nps_SupremeWizard;
    delete this->s_Nps_Soothsayer;
    delete this->s_Nps_Knight;
    delete this->s_Nps_Historian;
    delete this->s_Nps_Blacksmith;
    delete this->s_Nps_Aiden;
    // delete item sprite
    delete this->s_Item_Money;
    delete this->s_Item_KeySilver;
    delete this->s_Item_KeyGold;
    delete this->s_Item_Diamond;
    delete this->s_Item_Health;
    // delete object
    delete this->s_Object_HomeDrov;
    delete this->s_Object_FlyingObelisk;
    delete this->s_Object_DarkBush;
    delete this->s_Object_DarkBush2;
    delete this->s_Object_DarkStone;
    delete this->s_Object_DarkTreeBig;
    delete this->s_Object_DarkTreeSmall;
    delete this->s_Object_BushHouse;
    delete this->s_Object_RemainsSkeleton;
    delete this->s_Object_BonfireHouse;
    delete this->s_Object_TableHouse;
    // delete chest sprite
    delete this->s_Chest_Small;
    delete this->s_Chest_Middle;
    delete this->s_Chest_Big;
    //delete bullet sprite
    delete this->s_Bullet;
    //music & sound
    for(int i = 0; i < size(m_lvl); i++){
        delete this->m_lvl[i];
    }
    // Text
    delete this->text_nps_knight;
    delete this->text_nps_swordsman;
    delete this->text_nps_supreme_wizard;
    delete this->text_nps_soothsayer;
    delete this->text_nps_historian;
    delete this->text_nps_aiden;
    delete this->text_nps_witcher;
    //
    delete this->so_player_attack;
    delete this->so_enemy_Ghost_attack;
    delete this->so_enemy_Scelet_attack;
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
    this->s_player = new CreateImage("SpriteEntity/PlayerBlue.png");
    //Sprite Enemy
    this->s_EnemyGhost = new CreateImage("SpriteEntity/Enemy/EnemyGhost.png");
    this->s_EnemySkeleton = new CreateImage("SpriteEntity/Enemy/");
    this->s_Enemy_BigGhost = new CreateImage("SpriteEntity/Enemy/EnemyBigGhost.png");
    this->s_Enemy_Boom = new CreateImage("SpriteEntity/Enemy/EnemyBoom.png");
    this->s_Enemy_Bat = new CreateImage("SpriteEntity/Enemy/EnemyBat.png");
    this->s_Enemy_Mag = new CreateImage("SpriteEntity/Enemy/EnemyMag.png");
    this->s_Enemy_MagDamage = new CreateImage("SpriteObject/DamageEnemy/DamageMag.png");
    //Sprite LvL Map
    this->s_LvL[1] = new CreateImage("MapTexture/LvL1.png");
    this->s_LvL[2] = new CreateImage("MapTexture/LvL2-up.png");
    this->s_LvL[3] = new CreateImage("MapTexture/LvL3-up.png");
    this->s_LvL[4] = new CreateImage("MapTexture/LvL4.png");
    this->s_LvL[5] = new CreateImage("MapTexture/LvL5.png");
    this->s_LvL[6] = new CreateImage("MapTexture/LvL6.png");
    // Sprite LvL Fon
    this->s_LvL_Fon[1] = new CreateImage("SpriteMapObject/FonLvL1_.png");
    this->s_LvL_Fon[2] = new CreateImage("SpriteMapObject/FonLvL2_.png");
    this->s_LvL_Fon[3] = new CreateImage("SpriteMapObject/FonLvL3_.png");
    this->s_LvL_Fon[4] = new CreateImage("SpriteMapObject/FonLvL4_.png");
    this->s_LvL_Fon[5] = new CreateImage("SpriteMapObject/FonLvL5_.png");
    this->s_LvL_Fon[6] = new CreateImage("SpriteMapObject/FonLvL6_.png");
    this->s_LvL_FonBack[1] = new CreateImage("SpriteMapObject/FonLvL1_Back.png");
    this->s_LvL_FonBack[2] = new CreateImage("SpriteMapObject/FonLvL2_Back.png");
    this->s_LvL_FonBack[3] = new CreateImage("SpriteMapObject/FonLvL3_Back.png");
    this->s_LvL_FonBack[4] = new CreateImage("SpriteMapObject/FonLvL4_Back.png");
    this->s_LvL_FonBack[5] = new CreateImage("SpriteMapObject/FonLvL5_Back.png");
    this->s_LvL_FonBack[6] = new CreateImage("SpriteMapObject/FonLvL6_Back.png");
    // Sprite Nps
    this->s_Nps_Aiden = new CreateImage("SpriteEntity/Nps/Nps_Aiden.png");
    this->s_Nps_Blacksmith = new CreateImage("SpriteEntity/Nps/Blacksmith.png");
    this->s_Nps_Historian = new CreateImage("SpriteEntity/Nps/Nps_Historian.png");
    this->s_Nps_Knight = new CreateImage("SpriteEntity/Nps/Nps_Knight.png");
    this->s_Nps_Soothsayer = new CreateImage("SpriteEntity/Nps/Nps_Soothsayer.png");
    this->s_Nps_SupremeWizard = new CreateImage("SpriteEntity/Nps/Supreme_Wizard.png");
    this->s_Nps_Swordsman = new CreateImage("SpriteEntity/Nps/Nps_Swordsman.png");
    this->s_Nps_Witcher = new CreateImage("SpriteEntity/Nps/Witcher.png");
    // Sprite Item
    this->s_Item_Health = new CreateImage("SpriteItems/HealthLife.png");
    this->s_Item_KeySilver = new CreateImage("SpriteItems/KeySilver.png");
    this->s_Item_KeyGold = new CreateImage("SpriteItems/KeyGold.png");
    this->s_Item_Money = new CreateImage("SpriteItems/Money.png");
    this->s_Item_Diamond = new CreateImage("SpriteItems/Diamond.png");
    // Sprite Object
    this->s_Object_HomeDrov = new CreateImage("SpriteMapObject/House/HouseDrov.png");
    this->s_Object_BushHouse = new CreateImage("SpriteMapObject/House/Bush_House.png");
    this->s_Object_BonfireHouse = new CreateImage("SpriteMapObject/House/Bonfire_House.png");
    this->s_Object_FlyingObelisk = new CreateImage("SpriteMapObject/Object/FlyingObelisk.png");
    this->s_Object_DarkBush = new CreateImage("SpriteMapObject/Object/Dark-bush.png");
    this->s_Object_DarkBush2 = new CreateImage("SpriteMapObject/Object/Dark-bush-2.png");
    this->s_Object_DarkStone = new CreateImage("SpriteMapObject/Object/Dark-stone.png");
    this->s_Object_DarkTreeBig = new CreateImage("SpriteMapObject/Object/Dark-tree-Big.png");
    this->s_Object_DarkTreeSmall = new CreateImage("SpriteMapObject/Object/Dark-tree-Small.png");
    this->s_Object_RemainsSkeleton = new CreateImage("SpriteMapObject/miniObject/RemainsSkeleton.png");
    this->s_Object_TableHouse = new CreateImage("SpriteMapObject/House/Table_House.png");
    // class chest
    this->s_Chest_Small = new CreateImage("SpriteObject/Chest/SmallChest.png");
    this->s_Chest_Middle = new CreateImage("SpriteObject/Chest/MiddleChest.png");
    this->s_Chest_Big = new CreateImage("SpriteObject/Chest/BigChest.png");
    // class bullet
    this->s_Bullet = new CreateImage("SpriteEntity/Player/AttacPlaz1.png");
    // GUI player
    this->s_player_features = new CreateImage("SpriteEntity/Player/iconMenuGame/features.png");
    this->s_player_health = new CreateImage("SpriteEntity/Player/iconMenuGame/HealthBar.png");
    this->s_player_inventory = new CreateImage("SpriteEntity/Player/iconMenuGame/OpenInventory.png");
}

void Config::LoadShader() {
    //this->shader = new CreateShader("Shader.glsl");
}
void Config::LoadText() {
    this->text_nps_blacksmith = new CreateText("MaredivRegular.ttf", 25, " ", Color::Black);
    this->text_nps_historian = new CreateText("MaredivRegular.ttf", 25, " ", Color::Black);
    this->text_nps_aiden = new CreateText("MaredivRegular.ttf", 25, " ", Color::Black);
    this->text_nps_soothsayer = new CreateText("MaredivRegular.ttf", 25, " ", Color::Black);
    this->text_nps_supreme_wizard = new CreateText("MaredivRegular.ttf", 25, " ", Color::Black);
    this->text_nps_swordsman = new CreateText("MaredivRegular.ttf", 25, " ", Color::Black);
    this->text_nps_knight = new CreateText("MaredivRegular.ttf", 25, " ", Color::Black);
    this->text_nps_witcher = new CreateText("MaredivRegular.ttf", 25, " ", Color::Black);
}

void Config::LoadMusic() {
    this->m_lvl[1] = new m_Music(" ");
    this->m_lvl[2] = new m_Music(" ");
    this->m_lvl[3] = new m_Music(" ");
    this->m_lvl[4] = new m_Music(" ");
    this->m_lvl[5] = new m_Music(" ");
    this->m_lvl[6] = new m_Music(" ");
}

void Config::LoadSound() {
    this->so_player_attack = new s_Sound(" ");
    this->so_enemy_Ghost_attack = new s_Sound(" ");
    this->so_enemy_Scelet_attack = new s_Sound(" ");
}