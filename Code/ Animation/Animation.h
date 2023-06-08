#ifndef GAMEENGINE_BROUGHT_ANIMATION_H
#define GAMEENGINE_BROUGHT_ANIMATION_H
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

class Animation {
public:
    int rect_l, rect_t, w, h, l_r;
    Vector2f pos;
    float cur_Frame = 0, speed = 0, frame = 0;
    Animation() = default;
    Animation(float Frame, float Speed, int RectLeft, int RectTop, int Width, int Height, int L_R);
    void Update(Sprite &s, float time);
};


#endif //GAMEENGINE_BROUGHT_ANIMATION_H
