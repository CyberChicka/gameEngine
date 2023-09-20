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
#include "Shader/CreateShader.h"
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
    // /////////////////////// Камера ///////////////////////
    View view;
    View getPlayerCoordinateForView(float x, float y);
    // /////////////////////// Sprite ///////////////////////
    //SmartPointer<CreateImage>*s_player;
    CreateImage *s_player;
    // /////////////////////// Particle_of_Strength ///////////////////////
    CreateImage *s_particle_of_strength_shoot, *s_particle_of_strength_sprint;
    // /////////////////////// Enemy ///////////////////////
    CreateImage *s_enemy_ghost, *s_enemy_ghost_heavenly, *s_enemy_skeleton, *s_enemy_bat, *s_enemy_bat_heavenly,
    *s_enemy_BigGhost, *s_enemy_BigGhost_heavenly, *s_enemy_boom, *s_enemy_mag, *s_enemy_MagDamage;
    // /////////////////////// Nps ///////////////////////
    CreateImage *s_nps_aiden, *s_nps_blacksmith, *s_nps_historian, *s_nps_knight,
    *s_nps_soothsayer, *s_nps_SupremeWizard, *s_nps_swordsman, *s_nps_witcher;
    // /////////////////////// Item ///////////////////////
    CreateImage *s_item_health, *s_item_KeySilver, *s_item_KeyGold, *s_item_money, *s_item_diamond;
    CreateImage *s_item_sword[5], *s_item_shield[5];
    // /////////////////////// LvL ///////////////////////
    CreateImage *s_LvL[7];
    CreateImage *s_Fire_LvL[5];
    // /////////////////////// LvL Fon ///////////////////////
    CreateImage *s_LvL_Fon[7], *s_LvL_FonBack[7];
    CreateImage *s_Cloud_ainm, *s_Cloud_big, *s_Cloud_middle, *s_Cloud_small;
    // /////////////////////// Object ///////////////////////
    CreateImage *s_obj_HomeDrov, *s_obj_BushHouse, *s_obj_BonfireHouse, *s_obj_TableHouse, *s_obj_FlyingObelisk,
    *s_obj_DarkBush, *s_obj_DarkBush2, *s_obj_DarkStone, *s_obj_DarkTreeBig, *s_obj_DarkTreeSmall,
    *s_obj_RemainsSkeleton, *s_obj_stove;
    // /////////////////////// Chest ///////////////////////
    CreateImage *s_chest_small, *s_chest_middle, *s_chest_big;
    // /////////////////////// Bullet ///////////////////////
    CreateImage *s_bullet;
    CreateImage *s_shuriken[5];
    // /////////////////////// Text ///////////////////////
    CreateText *text_nps_blacksmith;
    CreateText *text_nps_historian;
    CreateText *text_nps_knight;
    CreateText *text_nps_aiden;
    CreateText *text_nps_witcher;
    CreateText *text_nps_supreme_wizard;
    CreateText *text_nps_soothsayer;
    CreateText *text_nps_swordsman;
    // /////////////////////// Music & sound ///////////////////////
    m_Music *m_lvl[7];
    // /////////////////////// player ///////////////////////
    s_Sound *so_player_attack;
    // /////////////////////// enemy ///////////////////////
    s_Sound *so_enemy_Ghost_attack;
    s_Sound *so_enemy_Scelet_attack;
    // Shader
    //CreateShader *shader;
    Config();
    static Config *instance;
private:
    // /////////////////////// Delete ///////////////////////
    void DeleteEnemy()const;
    void DeleteNps()const;
    void DeleteItem()const;
    void DeleteObject()const;
    void DeleteText()const;
    void DeleteLvL()const;
    void DeleteChest()const;
    // /////////////////////// LoadImage ///////////////////////
    void ImagePlayer();
    void ImageEnemy();
    void ImageNps();
    void ImageItem();
    void ImageObject();
    void ImageLvL();
    void ImageChest();
    // /////////////////////// Load ///////////////////////
    void LoadShader();
    void LoadImage();
    void LoadText();
    void LoadSound();
    void LoadMusic();
};


#endif //GAMEENGINE_CONFIG_H
