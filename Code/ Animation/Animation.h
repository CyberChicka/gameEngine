#ifndef GAMEENGINE_BROUGHT_ANIMATION_H
#define GAMEENGINE_BROUGHT_ANIMATION_H
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

class Animation{
public:
    int l_rect, t_rect, w, h, l_r;
    float cur_Frame, speed, frame;
    Vector2f pos;
    Animation() = default;
    Animation(float Frame, float Speed, int RectLeft, int RectTop, int Width, int Height, int L_R);
    void Update(Sprite &s, float time);
};


#endif //GAMEENGINE_BROUGHT_ANIMATION_H
