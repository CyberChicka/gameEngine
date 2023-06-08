#ifndef GAMEENGINE_ENTITY_H
#define GAMEENGINE_ENTITY_H
#include <SFML/Graphics.hpp>
#include "Map/GameLvL.h"

using namespace std;
using namespace sf;

class Entity {
public:
    GameLvL *gameLvL;
    Vector2f position;
    float dx, dy, CurrentFrame, speed;
    int w, h, is_health, f_health, isLvLMap, money, k_Silver, k_Gold;
    bool life, onGround, isMove, stop;
    string name;
    RectangleShape *e_Radius = new RectangleShape;//e_Radius -> entity radius
    Sprite *s = new Sprite;
    enum {left, right, up, down, jump, stay, SLeft, SRight} state;
    Entity(Sprite *sprite, GameLvL *LvL, float X, float Y, int W, int H, string Name);
    ~Entity();
    virtual FloatRect getRect() = 0;
    void move();
    void ControlMove();
    void update(float time);
    virtual void animation(float time) = 0;
    virtual void initAnim() = 0;
    virtual void draw(RenderWindow &window) = 0;
    virtual void checkCollisionMap(float dX, float dY) = 0;
    virtual float GetX() = 0;
    virtual float GetY() = 0;
};


#endif
