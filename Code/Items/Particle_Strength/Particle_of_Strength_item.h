//
// Created by Doni on 24.08.2023.
//

#ifndef GAMEENGINE_BROUGHT_PARTICLE_OF_STRENGTH_ITEM_H
#define GAMEENGINE_BROUGHT_PARTICLE_OF_STRENGTH_ITEM_H

#include "../Item.h"

class Particle_of_Strength_item: public Item{
public:
    Particle_of_Strength_item(Sprite *sprite, GameLvL *LvL, float X, float Y, int W, int H, string Name);
    ~Particle_of_Strength_item();
    bool isTake(Player &player)override;
    void initAnim() override;
    void animation(float time)override;
};


#endif //GAMEENGINE_BROUGHT_PARTICLE_OF_STRENGTH_ITEM_H
