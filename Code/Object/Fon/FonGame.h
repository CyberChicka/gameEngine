

#ifndef GAMEENGINE_BROUGHT_FONGAME_H
#define GAMEENGINE_BROUGHT_FONGAME_H


#include "../Object.h"

class FonGame: public Object{
public:
    enum class AnimationIndex{ Walking };
    FonGame(Sprite *sprite, GameLvL *LvL, float X, float Y, int W, int H, string Name);
    ~FonGame();
    FloatRect getRect()override;
    void update(float time, GameLvL *gLvL)override;
    void draw(RenderWindow &window, View view)override;
    void animation(float time)override;
    void initAnim()override;
    void setPosition(float x, float y)override;
private:
    Animation animations[int(AnimationIndex::Walking)];
    AnimationIndex curAnimation = AnimationIndex::Walking;
};


#endif //GAMEENGINE_BROUGHT_FONGAME_H