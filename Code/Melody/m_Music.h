//
// Created by Doni on 07.06.2023.
//

#ifndef GAMEENGINE_BROUGHT_M_MUSIC_H
#define GAMEENGINE_BROUGHT_M_MUSIC_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>

using namespace sf;
using namespace std;


class m_Music {
public:
    Music *music;
    ifstream *fin;
    string file, f_volume;
    int volume;
    m_Music(string f);
    ~m_Music();
    void play();
    void stop();
    void pause();
    void setVolume();
    void setPosition(float , float , float);
    void setPosition(Vector3f);
};


#endif //GAMEENGINE_BROUGHT_M_MUSIC_H
