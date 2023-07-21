#ifndef GAMEENGINE_CREATEIMAGE_H
#define GAMEENGINE_CREATEIMAGE_H

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class CreateImage {
public:
    string file;
    bool Touch;
    Texture *t;
    Sprite *s;
    CreateImage(string f);
    ~CreateImage();
    void Load();
    bool isToch(float X, float  Y) const;
    bool isToch(Vector2f) const;
};


#endif //GAMEENGINE_CREATEIMAGE_H
