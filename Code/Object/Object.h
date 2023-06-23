
#ifndef GAMEENGINE_BROUGHT_OBJECT_H
#define GAMEENGINE_BROUGHT_OBJECT_H


#include <valarray>
#include "../Entity.h"

class Object: public Entity{
public:
    Object(Sprite *sprite, GameLvL *LvL, float  X, float Y, int W, int H, string Name);
    ~Object();
    FloatRect getRect()override;
    void animation(float time)override;
    void initAnim()override;
    void draw(RenderWindow &window, View view)override;
    void checkCollisionMap(float dX, float dY)override;
    float GetX()override;
    float GetY()override;
};

#endif //GAMEENGINE_BROUGHT_OBJECT_H
