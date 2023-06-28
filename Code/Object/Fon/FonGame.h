

#ifndef GAMEENGINE_BROUGHT_FONGAME_H
#define GAMEENGINE_BROUGHT_FONGAME_H


#include "../Object.h"

class FonGame: public Object{
public:
    FonGame(Sprite *sprite, GameLvL *LvL, float X, float Y, int W, int H, string Name);
    ~FonGame();
    FloatRect getRect()override;
    void animation(float time)override;
    void initAnim()override;
    void update(float time);
    void draw(RenderWindow &window, View view)override;
    float GetX()override;
    float GetY()override;
};


#endif //GAMEENGINE_BROUGHT_FONGAME_H
