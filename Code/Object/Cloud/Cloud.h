#ifndef GAMEENGINE_BROUGHT_CLOUD_H
#define GAMEENGINE_BROUGHT_CLOUD_H


#include "../Object.h"

class Cloud: public Object {
public:
    enum class AnimationIndex{ Walking, Count };
    Cloud(Sprite *sprite, GameLvL *LvL, float X, float Y, int W, int H, string Name);
    ~Cloud();
    FloatRect getRect()override;
    void update(float time, GameLvL *gLvL)override;
    void draw(RenderWindow &window, View view)override;
    void animation(float time)override;
    void initAnim()override;
    void setPosition(float x, float y)override;
private:
    Animation animations[int(AnimationIndex::Count)];
    AnimationIndex curAnimation = AnimationIndex::Count;
};


#endif //GAMEENGINE_BROUGHT_CLOUD_H
