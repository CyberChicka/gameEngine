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
    void RenderDraw(RenderWindow &window, View view);
    void initMap();
    static const int h_Block = 32;
    static const int w_Block = 32;
    constexpr static const int WitchMap[] = {0, 343, 320, 500, 320, 320, 320};
    constexpr static const int HeightMap[] = {0, 80, 80, 100, 200, 80, 80};
    //static const int WitchMap2 = 320;
    //static const int HeightMap2 = 80;
//    static const int WitchMap3 = 500;
//    static const int HeightMap3 = 100;
//    static const int WitchMap4 = 320;
//    static const int HeightMap4 = 80;
//    static const int WitchMap5 = 320;
//    static const int HeightMap5 = 80;
//    static const int WitchMap6 = 320;
//    static const int HeightMap6 = 80;
    String *MapLvL;
};

#endif //GAMEENGINE_BROUGHT_GAMELVL_H
