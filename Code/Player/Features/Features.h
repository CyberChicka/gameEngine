#ifndef GAMEENGINE_BROUGHT_FEATURES_H
#define GAMEENGINE_BROUGHT_FEATURES_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Player.h"
#include "../../Image/CreateImage.h"
#include "../../Text/CreateText.h"

class Features {
public:
    CreateImage *s_features_sprint, *s_features_shoot;
    Features();
    ~Features();
    void position(View view);
    void update(Player *player);
    void draw(RenderWindow &window, View view);
};


#endif //GAMEENGINE_BROUGHT_FEATURES_H
