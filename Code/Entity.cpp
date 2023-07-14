//
// Created by Doni on 15.05.2023.
//

#include "Entity.h"
Entity::Entity(Sprite *sprite, GameLvL *LvL, float X, float Y, int W, int H, std::string Name) {
    pos.x = X;
    pos.y = Y;
    dy = 0; dx = 0;
    w = W; h = H;
    s = new Sprite(*sprite);
    gameLvL = new GameLvL(*LvL);
    s->setTextureRect(IntRect(0, 0, w, h));
    life = true;
    onGround = false;
    is_health = 100;
    name = Name;
}
Entity::~Entity() {
    cout << "============== removed from entity ============"<< endl;
    delete gameLvL;
    delete s;
}
