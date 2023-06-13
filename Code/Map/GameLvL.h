#ifndef GAMEENGINE_BROUGHT_GAMELVL_H
#define GAMEENGINE_BROUGHT_GAMELVL_H
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class GameLvL {
private:
public:
    Sprite *s;
    int gameLvL, dist;
    GameLvL(Sprite *sprite, int GameLvL);
    ~GameLvL();
    void setSprite(Sprite *sprite);
    void RenderDraw(RenderWindow &window, View view);
    void initMap();
    static const int h_Block = 32;
    static const int w_Block = 32;
    static const int WitchMap = 343;
    static const int HeightMap = 30;
    static const int WitchMap2 = 320;
    static const int HeightMap2 = 50;
    static const int WitchMap3 = 320;
    static const int HeightMap3 = 30;
    String *MapLvL = new String;
};

#endif //GAMEENGINE_BROUGHT_GAMELVL_H
