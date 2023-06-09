//
// Created by Doni on 07.06.2023.
//

#include "s_Sound.h"

s_Sound::s_Sound(string f){
    file = f;
    sound = new Sound;
    s_buffer = new SoundBuffer;
    fin = new ifstream;
    if(s_buffer->loadFromFile(file)){
        cout << "Is Load Sound :)" << endl;
    }
    else{ cout << "Error!: -- Load Sound -- :(" << endl;}
    setVolume();
}
s_Sound::~s_Sound() {
    cout << "============== removed from sound ============"<< endl;
    delete s_buffer;
    delete sound;
    delete fin;
}

void s_Sound::setVolume() {
    f_volume = "File/Save/Sound/SoundAndMusic.txt";
    fin->open(f_volume);
    if(fin->is_open()){
        while (!fin->eof()){ *fin >> volume;}
    } else { cout <<"Error"<< endl;}
    fin->close();

    switch (volume) {
        case 0: sound->setVolume(0); break;
        case 1: sound->setVolume(10);break;
        case 2: sound->setVolume(20);break;
        case 3: sound->setVolume(30);break;
        case 4: sound->setVolume(40);break;
        case 5: sound->setVolume(50);break;
        case 6: sound->setVolume(60);break;
        case 7: sound->setVolume(70);break;
        case 8: sound->setVolume(80);break;
        case 9: sound->setVolume(90);break;
        case 10: sound->setVolume(100);break;
    }
}

void s_Sound::play() {
    sound->play();
}

void s_Sound::pause() {
    sound->pause();
}

void s_Sound::stop() {
    sound->stop();
}
void s_Sound::setPosition(float x, float y, float z) {
    sound->setPosition(x, y, z);
}
void s_Sound::setPosition(sf::Vector3f position) {
    sound->setPosition(position);
}