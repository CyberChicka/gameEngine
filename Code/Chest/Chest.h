
#ifndef GAMEENGINE_BROUGHT_CHEST_H
#define GAMEENGINE_BROUGHT_CHEST_H


#include "../Entity.h"
#include "../ Animation/Animation.h"

class Chest: public Entity{
public:
    bool is_open;
    enum class AnimationIndex{ WalkingClose, WalkingOpen };
    Chest(Sprite *sprite, GameLvL *LvL, float X, float Y, int W, int H, string Name);
    ~Chest();
    FloatRect getRect()override;
    void animation(float time)override;
    void initAnim()override;
    void draw(RenderWindow &window, View view)override;
    void update(float time, GameLvL *gLvL);
    int OpenChest();
    void checkCollisionMap(float dX, float dY)override;
    float GetX()override;
    float GetY()override;
    Animation animations[int(AnimationIndex::WalkingClose)];
    AnimationIndex curAnimation = AnimationIndex::WalkingClose;
};

#endif //GAMEENGINE_BROUGHT_CHEST_H
