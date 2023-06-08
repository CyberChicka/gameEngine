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
    CreateImage *s_player;
    CreateImage *s_EnemyGhost, *s_EnemySkeleton;
    CreateImage *s_LvL1, *s_LvL2, *s_LvL3;
    // Music & sound
    m_Music *m_lvl1;
    m_Music *m_lvl2;
    m_Music *m_lvl3;
    //player
    s_Sound *so_player_attack;
    //enemy
    s_Sound *so_enemy_attack;
    Config();
    static Config *instance;
private:
    void LoadImage();
    void LoadText();
    void LoadSound();
    void LoadMusic();
};


#endif //GAMEENGINE_CONFIG_H
