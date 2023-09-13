#ifndef GAMEENGINE_BROUGHT_DOOR_H
#define GAMEENGINE_BROUGHT_DOOR_H
#include "../Object.h"
#include "../../Player/Player.h"

class Door: public Object{
    enum class AnimationIndex{ Open, Opening, Close, Count };
    bool isOpen;
    Door(Sprite *sprite, GameLvL *LvL, float X, float Y, int W, int H, string Name);
    ~Door();
    FloatRect getRect()override;
    void update(float time, GameLvL *gLvL)override;
    void draw(RenderWindow &window, View view)override;
    void animation(float time)override;
    void initAnim()override;
    void setPosition(float x, float y)override;
    bool isTouch(Player &player);
private:
    Animation animations[int(AnimationIndex::Count)];
    AnimationIndex curAnimation = AnimationIndex::Count;
};


#endif //GAMEENGINE_BROUGHT_DOOR_H
