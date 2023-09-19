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
    // particle of strength
    delete this->s_particle_of_strength_shoot;
    delete this->s_particle_of_strength_sprint;
    //delete bullet sprite
    delete this->s_bullet;
    //music & sound
    delete []*this->m_lvl;
    //
    delete this->so_player_attack;
    delete this->so_enemy_Ghost_attack;
    delete this->so_enemy_Scelet_attack;
    this->DeleteChest();
    this->DeleteText();
    this->DeleteObject();
    this->DeleteNps();
    this->DeleteLvL();
    this->DeleteItem();
    this->DeleteEnemy();
    // delete sprite lvl
    delete []*this->s_LvL;
    cout << "============== removed from config ============"<< endl;
}

void Config::DeleteEnemy()const{
    // Delete enemy sprite
    delete this->s_enemy_ghost_heavenly;
    delete this->s_enemy_BigGhost_heavenly;
    delete this->s_enemy_bat_heavenly;
    delete this->s_enemy_ghost;
    delete this->s_enemy_skeleton;
    delete this->s_enemy_bat;
    delete this->s_enemy_boom;
    delete this->s_enemy_mag;
    delete this->s_enemy_BigGhost;
    delete this->s_enemy_MagDamage;
}
void Config::DeleteItem()const {
    // delete item sprite
    delete this->s_item_money;
    delete this->s_item_KeySilver;
    delete this->s_item_KeyGold;
    delete this->s_item_diamond;
    delete this->s_item_health;
    delete[]*this->s_item_sword;
    delete[]*this->s_item_shield;
}
void Config::DeleteLvL()const{
    // delete fon lvl
    delete []*this->s_LvL_Fon;
    delete []*this->s_LvL_FonBack;
    // delete fon cloud lvl
    delete this->s_Cloud_ainm;
    delete this->s_Cloud_big;
    delete this->s_Cloud_middle;
    delete this->s_Cloud_small;
}
void Config::DeleteNps()const{
    // delete Nps sprite
    delete this->s_nps_witcher;
    delete this->s_nps_swordsman;
    delete this->s_nps_SupremeWizard;
    delete this->s_nps_soothsayer;
    delete this->s_nps_knight;
    delete this->s_nps_historian;
    delete this->s_nps_blacksmith;
    delete this->s_nps_aiden;
}
void Config::DeleteObject()const{
    // delete object
    delete this->s_obj_stove;
    delete this->s_obj_HomeDrov;
    delete this->s_obj_FlyingObelisk;
    delete this->s_obj_DarkBush;
    delete this->s_obj_DarkBush2;
    delete this->s_obj_DarkStone;
    delete this->s_obj_DarkTreeBig;
    delete this->s_obj_DarkTreeSmall;
    delete this->s_obj_BushHouse;
    delete this->s_obj_RemainsSkeleton;
    delete this->s_obj_BonfireHouse;
    delete this->s_obj_TableHouse;
}
void Config::DeleteText()const{
    // Text
    delete this->text_nps_knight;
    delete this->text_nps_swordsman;
    delete this->text_nps_supreme_wizard;
    delete this->text_nps_soothsayer;
    delete this->text_nps_historian;
    delete this->text_nps_aiden;
    delete this->text_nps_witcher;
}
void Config::DeleteChest() const {
    // delete chest sprite
    delete this->s_chest_small;
    delete this->s_chest_middle;
    delete this->s_chest_big;
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
    this->ImagePlayer();
    this->ImageEnemy();
    this->ImageLvL();
    this->ImageNps();
    this->ImageItem();
    this->ImageObject();
    this->ImageChest();
}

void Config::ImagePlayer() {
    //Sprite Player
    this->s_player = new CreateImage("SpriteEntity/Player/Player-Blue.png");
    // class bullet
    this->s_bullet = new CreateImage("SpriteEntity/Player/AttacPlaz1.png");
    //particle of strength
    this->s_particle_of_strength_shoot = new CreateImage("SpriteItems/Item_LvL.png");
    this->s_particle_of_strength_sprint = new CreateImage("SpriteItems/Item_LvL.png");
}
void Config::ImageEnemy(){
    //Sprite Enemy
    this->s_enemy_ghost = new CreateImage("SpriteEntity/Enemy/EnemyGhost.png");
    this->s_enemy_ghost_heavenly = new CreateImage("SpriteEntity/Enemy/EnemyGhost_Heavenly.png");
    this->s_enemy_skeleton = new CreateImage("SpriteEntity/Enemy/EnemyGhost.png");
    this->s_enemy_BigGhost = new CreateImage("SpriteEntity/Enemy/EnemyBigGhost.png");
    this->s_enemy_BigGhost_heavenly = new CreateImage("SpriteEntity/Enemy/EnemyBigGhost_Heavenly.png");
    this->s_enemy_boom = new CreateImage("SpriteEntity/Enemy/EnemyBoom.png");
    this->s_enemy_bat = new CreateImage("SpriteEntity/Enemy/EnemyBat.png");
    this->s_enemy_bat_heavenly = new CreateImage("SpriteEntity/Enemy/EnemyBat_Heavenly.png ");
    this->s_enemy_mag = new CreateImage("SpriteEntity/Enemy/EnemyMag.png");
    this->s_enemy_MagDamage = new CreateImage("SpriteObject/DamageEnemy/DamageMag.png");
}
void Config::ImageChest(){
    // class chest
    this->s_chest_small = new CreateImage("SpriteObject/Chest/SmallChest.png");
    this->s_chest_middle = new CreateImage("SpriteObject/Chest/MiddleChest.png");
    this->s_chest_big = new CreateImage("SpriteObject/Chest/BigChest.png");
}
void Config::ImageItem(){
    // Sprite Item
    this->s_item_health = new CreateImage("SpriteItems/HealthLife.png");
    this->s_item_KeySilver = new CreateImage("SpriteItems/KeySilver.png");
    this->s_item_KeyGold = new CreateImage("SpriteItems/KeyGold.png");
    this->s_item_money = new CreateImage("SpriteItems/Money.png");
    this->s_item_diamond = new CreateImage("SpriteItems/Diamond.png");
    this->s_item_sword[1] = new CreateImage("SpriteItems/sword_shield/SwordBlue.png");
    this->s_item_sword[2] = new CreateImage("SpriteItems/sword_shield/SwordRed.png");
    this->s_item_sword[3] = new CreateImage("SpriteItems/sword_shield/SwordGreen.png");
    this->s_item_sword[4] = new CreateImage("SpriteItems/sword_shield/SwordBrow.png");
    this->s_item_shield[1] = new CreateImage("SpriteItems/sword_shield/ShieldBlue.png");
    this->s_item_shield[2] = new CreateImage("SpriteItems/sword_shield/ShieldRed.png");
    this->s_item_shield[3] = new CreateImage("SpriteItems/sword_shield/ShieldGreen.png");
    this->s_item_shield[4] = new CreateImage("SpriteItems/sword_shield/ShieldBrow.png");
}
void Config::ImageLvL(){
    //Sprite LvL Map
    this->s_LvL[1] = new CreateImage("MapTexture/LvL1-up.png");
    this->s_LvL[2] = new CreateImage("MapTexture/LvL2-up.png");
    this->s_LvL[3] = new CreateImage("MapTexture/LvL3-up.png");
    this->s_LvL[4] = new CreateImage("MapTexture/LvL4-up.png");
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
    // sprite cloud
    this->s_Cloud_ainm = new CreateImage("SpriteMapObject/FonGame/Cloud_anim.png");
    this->s_Cloud_big = new CreateImage("SpriteMapObject/FonGame/Cloud-Big.png");
    this->s_Cloud_middle = new CreateImage("SpriteMapObject/FonGame/Cloud-Middle.png");
    this->s_Cloud_small = new CreateImage("SpriteMapObject/FonGame/Cloud-Small.png");
}
void Config::ImageNps(){
    // Sprite Nps
    this->s_nps_aiden = new CreateImage("SpriteEntity/Nps/Nps_Aiden.png");
    this->s_nps_blacksmith = new CreateImage("SpriteEntity/Nps/Blacksmith.png");
    this->s_nps_historian = new CreateImage("SpriteEntity/Nps/Nps_Historian.png");
    this->s_nps_knight = new CreateImage("SpriteEntity/Nps/Nps_Knight.png");
    this->s_nps_soothsayer = new CreateImage("SpriteEntity/Nps/Nps_Soothsayer.png");
    this->s_nps_SupremeWizard = new CreateImage("SpriteEntity/Nps/Supreme_Wizard.png");
    this->s_nps_swordsman = new CreateImage("SpriteEntity/Nps/Nps_Swordsman.png");
    this->s_nps_witcher = new CreateImage("SpriteEntity/Nps/Witcher.png");
}
void Config::ImageObject(){
    // Sprite Object
    this->s_obj_HomeDrov = new CreateImage("SpriteMapObject/House/HouseDrov.png");
    this->s_obj_BushHouse = new CreateImage("SpriteMapObject/House/Bush_House.png");
    this->s_obj_BonfireHouse = new CreateImage("SpriteMapObject/House/Bonfire_House.png");
    this->s_obj_FlyingObelisk = new CreateImage("SpriteMapObject/Object/FlyingObelisk.png");
    this->s_obj_DarkBush = new CreateImage("SpriteMapObject/Object/Dark-bush.png");
    this->s_obj_DarkBush2 = new CreateImage("SpriteMapObject/Object/Dark-bush-2.png");
    this->s_obj_DarkStone = new CreateImage("SpriteMapObject/Object/Dark-stone.png");
    this->s_obj_DarkTreeBig = new CreateImage("SpriteMapObject/Object/Dark-tree-Big.png");
    this->s_obj_DarkTreeSmall = new CreateImage("SpriteMapObject/Object/Dark-tree-Small.png");
    this->s_obj_RemainsSkeleton = new CreateImage("SpriteMapObject/miniObject/RemainsSkeleton.png");
    this->s_obj_TableHouse = new CreateImage("SpriteMapObject/House/Table_House.png");
    this->s_obj_stove = new CreateImage("SpriteObject/Stove.png");
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