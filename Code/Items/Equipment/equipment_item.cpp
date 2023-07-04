//
// Created by Doni on 09.06.2023.
//

#include "equipment_item.h"

equipment_item::equipment_item(sf::Sprite *sprite, GameLvL *LvL, float X, float Y, int W, int H, std::string Name): Item(sprite, LvL, X, Y, W, H, Name) {
    if(this->name == "SwordBlue"){ this->s->setScale(1.0f, 1.0f);  }
    if(this->name == "SwordRed"){ this->s->setScale(1.0f, 1.0f);   }
    if(this->name == "SwordGreen"){ this->s->setScale(1.0f, 1.0f); }
    if(this->name == "SwordBrow"){ this->s->setScale(1.0f, 1.0f);  }
    if(this->name == "ShieldBlue"){ this->s->setScale(1.0f, 1.0f); }
    if(this->name == "ShieldRed"){ this->s->setScale(1.0f, 1.0f);  }
    if(this->name == "ShieldGreen"){ this->s->setScale(1.0f, 1.0f);}
    if(this->name == "ShieldBrow"){ this->s->setScale(1.0f, 1.0f); }

}
equipment_item::~equipment_item() {
    cout << "============== removed from item equipment ============" << endl;
    delete this->s;
    delete this->gameLvL;
}

bool equipment_item::isTake(Player &player) {
    if(player.e_Radius->getGlobalBounds().intersects(this->getRect())){
        if(this->name == "SwordBlue"){ }
        if(this->name == "SwordRed"){ }
        if(this->name == "SwordGreen"){ }
        if(this->name == "SwordBrow"){ }
        if(this->name == "ShieldBlue"){ }
        if(this->name == "ShieldRed"){ }
        if(this->name == "ShieldGreen"){ }
        if(this->name == "ShieldBrow"){ }

    }
}

void equipment_item::initAnim() {
    if(this->name == "SwordBlue"){ this->animations[int(AnimationIndex::Walking)] = Animation(1, 0, 0, 0, 0, 0, 0);}
    if(this->name == "SwordRed"){ this->animations[int(AnimationIndex::Walking)] = Animation(1, 0, 0, 0, 0, 0, 0);}
    if(this->name == "SwordGreen"){ this->animations[int(AnimationIndex::Walking)] = Animation(1, 0, 0, 0, 0, 0, 0);}
    if(this->name == "SwordBrow"){ this->animations[int(AnimationIndex::Walking)] = Animation(1, 0, 0, 0, 0, 0, 0);}
    if(this->name == "ShieldBlue"){ this->animations[int(AnimationIndex::Walking)] = Animation(1, 0, 0, 0, 0, 0, 0);}
    if(this->name == "ShieldRed"){ this->animations[int(AnimationIndex::Walking)] = Animation(1, 0, 0, 0, 0, 0, 0);}
    if(this->name == "ShieldGreen"){ this->animations[int(AnimationIndex::Walking)] = Animation(1, 0, 0, 0, 0, 0, 0);}
    if(this->name == "ShieldBrow"){ this->animations[int(AnimationIndex::Walking)] = Animation(1, 0, 0, 0, 0, 0, 0);}
}

void equipment_item::animation(float time) {
    this->curAnimation = AnimationIndex::Walking;
    this->animations[int(this->curAnimation)].Update(*s, time);
}