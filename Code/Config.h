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
    CreateImage *s_EnemyGhost, *s_EnemySkeleton;
    CreateImage *s_Nps_Aiden, *s_Nps_Blacksmith, *s_Nps_Historian, *s_Nps_Knight,
    *s_Nps_Soothsayer, *s_Nps_SupremeWizard, *s_Nps_Swordsman, *s_Nps_Witcher;
    CreateImage *s_Item_Health, *s_Item_KeySilver, *s_Item_KeyGold, *s_Item_Money, *s_Item_Diamond;
    CreateImage *s_LvL1, *s_LvL2, *s_LvL3, *s_LvL4, *s_LvL5, *s_LvL6;
    CreateImage *s_LvL1_Fon, *s_LvL2_Fon, *s_LvL3_Fon, *s_LvL4_Fon, *s_LvL5_Fon, *s_LvL6_Fon;
    CreateImage *s_Object_HomeDrov;
    // Text
    CreateText *text_nps;
    // Music & sound
    m_Music *m_lvl1;
    m_Music *m_lvl2;
    m_Music *m_lvl3;
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
