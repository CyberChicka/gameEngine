//
// Created by Doni on 07.06.2023.
//

#include "m_Music.h"


m_Music::m_Music(string f) {
    file = f;
    music = new Music;
    fin = new ifstream;
    if(music->openFromFile(file)){
        cout << "Is Load Music :)" << endl;
    }
    else{ cout << "Error!: -- Load Music -- :(" << endl;}
    setVolume();
}
m_Music::~m_Music() {
    cout << "============== removed from music ============"<< endl;
    delete music;
    delete fin;
}

void m_Music::play() {
    music->play();
}

void m_Music::stop() {
    music->stop();
}

void m_Music::pause() {
    music->pause();
}

void m_Music::setVolume() {
    f_volume = "File/Save/Sound/SoundAndMusic.txt";
    fin->open(f_volume);
    if(fin->is_open()){
        while (!fin->eof()){ *fin >> volume;}
    } else { cout <<"Error"<< endl;}
    fin->close();

    switch (volume) {
        case 0: music->setVolume(0); break;
        case 1: music->setVolume(10);break;
        case 2: music->setVolume(20);break;
        case 3: music->setVolume(30);break;
        case 4: music->setVolume(40);break;
        case 5: music->setVolume(50);break;
        case 6: music->setVolume(60);break;
        case 7: music->setVolume(70);break;
        case 8: music->setVolume(80);break;
        case 9: music->setVolume(90);break;
        case 10: music->setVolume(100);break;
    }
}

void m_Music::setPosition(float x, float y, float z) {
    music->setPosition(x, y, z);
}
void m_Music::setPosition(Vector3f position) {
    music->setPosition(position);
}