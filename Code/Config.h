#ifndef GAMEENGINE_CONFIG_H
#define GAMEENGINE_CONFIG_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace sf;
using namespace std;

#include "Image/CreateImage.h"
#include "Text/CreateText.h"
#include "Enemy/Enemy.h"

#include "Melody/m_Music.h"
#include "Melody/s_Sound.h"

class Config {
public:
    ~Config();
    static Config *getInstance();
    Config(const Config&) = delete;
    Config &operator=(const Config&) = delete;

    Vector2i window_size = {0, 0}; // размер окна
    Vector2i view_size = { 0, 0};
    const int window_frame = 120; // Кадров в секунду
    const string window_title = "GameEngine";
    // Камера
    View view;
    View getPlayerCoordinateForView(float x, float y);
    // Sprite
    //SmartPointer<CreateImage>*s_player;
    CreateImage *s_player;
    // Enemy
    CreateImage *s_EnemyGhost, *s_EnemySkeleton, *s_Enemy_Bat, *s_Enemy_BigGhost, *s_Enemy_Boom, *s_Enemy_Mag, *s_Enemy_MagDamage;
    // Nps
    CreateImage *s_Nps_Aiden, *s_Nps_Blacksmith, *s_Nps_Historian, *s_Nps_Knight,
    *s_Nps_Soothsayer, *s_Nps_SupremeWizard, *s_Nps_Swordsman, *s_Nps_Witcher;
    // Item
    CreateImage *s_Item_Health, *s_Item_KeySilver, *s_Item_KeyGold, *s_Item_Money, *s_Item_Diamond;
    // LvL
    CreateImage *s_LvL[7];
    // LvL Fon
    CreateImage *s_LvL_Fon[7], *s_LvL_FonBack[7];
    // Object
    CreateImage *s_Object_HomeDrov, *s_Object_BushHouse, *s_Object_BonfireHouse, *s_Object_TableHouse, *s_Object_FlyingObelisk,
    *s_Object_DarkBush, *s_Object_DarkBush2, *s_Object_DarkStone, *s_Object_DarkTreeBig, *s_Object_DarkTreeSmall,
    *s_Object_RemainsSkeleton;
    // Chest
    CreateImage *s_Chest_Small, *s_Chest_Middle, *s_Chest_Big;
    // Bullet
    CreateImage *s_Bullet;
    // Text
    CreateText *text_nps_blacksmith;
    CreateText *text_nps_historian;
    CreateText *text_nps_knight;
    CreateText *text_nps_aiden;
    CreateText *text_nps_witcher;
    CreateText *text_nps_supreme_wizard;
    CreateText *text_nps_soothsayer;
    CreateText *text_nps_swordsman;
    // Music & sound
    m_Music *m_lvl[7];
    //player
    s_Sound *so_player_attack;
    //enemy
    s_Sound *so_enemy_Ghost_attack;
    s_Sound *so_enemy_Scelet_attack;
    //
    Config();
    static Config *instance;
private:
    void LoadImage();
    void LoadText();
    void LoadSound();
    void LoadMusic();
};


#endif //GAMEENGINE_CONFIG_H
