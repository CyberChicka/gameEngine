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
    delete s_EnemyGhost;
    delete s_EnemySkeleton;
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
    //music & sound
    delete m_lvl1;
    delete m_lvl2;
    delete m_lvl3;

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
    view.setCenter(tempX, tempY - 100); // Следим за игроком передавая его координаты
    return view;
}

void Config::LoadImage() {
    //Sprite Player
    s_player = new CreateImage("SpriteEntity/PlayerBlue.png");
    //Sprite Enemy
    s_EnemyGhost = new CreateImage("SpriteEntity/Enemy/EnemyGhost.png");
    s_EnemySkeleton = new CreateImage("SpriteEntity/Enemy/");
    //Sprite LvL Map
    s_LvL1 = new CreateImage("MapTexture/LvL1.png");
    s_LvL2 = new CreateImage("MapTexture/LvL2.png");
    s_LvL3 = new CreateImage("MapTexture/LvL3.png");
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
}

void Config::LoadText() {
    text_nps_history = new CreateText(" ", 50, "I, player");
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