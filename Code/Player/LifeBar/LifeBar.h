//
// Created by Doni on 29.06.2023.
//

#ifndef GAMEENGINE_BROUGHT_LIFEBAR_H
#define GAMEENGINE_BROUGHT_LIFEBAR_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Player.h"

using namespace sf;
using namespace std;
class LifeBar {
public:
    RectangleShape bar;
    Sprite *s;
    LifeBar(Sprite *sprite);
    ~LifeBar();
    void update(Player *player);
    void draw(RenderWindow &window);
};


#endif //GAMEENGINE_BROUGHT_LIFEBAR_H
