//
// Created by Doni on 07.06.2023.
//

#ifndef GAMEENGINE_BROUGHT_S_SOUND_H
#define GAMEENGINE_BROUGHT_S_SOUND_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>
#include <iostream>

using namespace sf;
using namespace std;

class s_Sound {
public:
    Sound *sound;
    SoundBuffer *s_buffer;
    ifstream *fin;
    int volume;
    string file, f_volume;
    s_Sound(string);
    ~s_Sound();
    void play();
    void stop();
    void pause();
    void setVolume();
    void setPosition(float , float , float );
    void setPosition(Vector3f);
};


#endif //GAMEENGINE_BROUGHT_S_SOUND_H
