
#ifndef GAMEENGINE_BROUGHT_OBJECT_H
#define GAMEENGINE_BROUGHT_OBJECT_H


#include <valarray>
#include "../Entity.h"
#include "../ Animation/Animation.h"

class Object: public Entity{
public:
    enum class AnimationIndex{Walking, Count};
    Object(Sprite *sprite, GameLvL *LvL, float X, float Y, int W, int H, string Name);
    ~Object();
    FloatRect getRect()override;
    void update(float time, GameLvL *gLvL);
    void draw(RenderWindow &window, View view)override;
    void animation(float time)override;
    void initAnim()override;
    void checkCollisionMap(float dX, float dY)override;
    void setPosition(float x, float y);
    float GetX()override;
    float GetY()override;
private:
    Animation animations[int(AnimationIndex::Count)];
    AnimationIndex curAnimation = AnimationIndex::Count;
};

#endif //GAMEENGINE_BROUGHT_OBJECT_H