#include "Door.h"
Door::Door(Sprite *sprite, GameLvL *LvL, float X, float Y, int W, int H, string Name): Object(sprite, LvL, X, Y, W, H, Name){
    this->isOpen = false;
    this->initAnim();
}
Door::~Door() {
    cout << "============== removed from fon ============"<< endl;
    delete this->gameLvL;
    delete this->s;
}
void Door::animation(float time) {
    if(this->isOpen){
        if(this->animations[int(AnimationIndex::Opening)].cur_Frame < 8)
            this->curAnimation = AnimationIndex::Opening;
        else
            this->curAnimation = AnimationIndex::Open;
    }
    else {
        this->curAnimation = AnimationIndex::Close;
    }
    this->animations[int(this->curAnimation)].Update(*this->s, time);
}
void Door::initAnim() {
    if(this->name == "BigDoor"){
        this->animations[int(AnimationIndex::Close)] = Animation(1, 0, 0, 0, 0, 0, 0);
        this->animations[int(AnimationIndex::Open)] = Animation(1, 0, 0, 0, 0, 0, 0);
        this->animations[int(AnimationIndex::Opening)] = Animation(10, 0.008, 0, 0, 0, 0, 0);
    }
    if(this->name == "MiddleDoor"){
        this->animations[int(AnimationIndex::Close)] = Animation(1, 0, 0, 0, 0, 0, 0);
        this->animations[int(AnimationIndex::Open)] = Animation(1, 0, 0, 0, 0, 0, 0);
        this->animations[int(AnimationIndex::Opening)] = Animation(10, 0.008, 0, 0, 0, 0, 0);
    }
    if(this->name == "SmallDoor"){
        this->animations[int(AnimationIndex::Close)] = Animation(1, 0, 0, 0, 0, 0, 0);
        this->animations[int(AnimationIndex::Open)] = Animation(1, 0, 0, 0, 0, 0, 0);
        this->animations[int(AnimationIndex::Opening)] = Animation(10, 0.008, 0, 0, 0, 0, 0);
    }
}
void Door::update(float time, GameLvL *gLvL){
    this->gameLvL = gLvL;
    this->animation(time);
    this->pos.y += time * this->dy;
    this->pos.x += time * this->dx;
    this->s->setPosition(this->pos);
}
void Door::draw(sf::RenderWindow &window, sf::View view) {
    window.draw(*this->s);
}
void Door::setPosition(float x, float y) {
    this->pos.x = x;
    this->pos.y = y;
}

FloatRect Door::getRect() {
    return FloatRect(this->pos.x, this->pos.y, this->w, this->h);
}

bool Door::isTouch(Player &player) {
    if(this->name == "BigDoor"){
        if(player.e_Radius->getGlobalBounds().intersects(this->getRect())){
            if(player.k_gold > 0){
                this->isOpen = true;
                player.k_gold -= 1;
            }
        }
    }
    if(this->name == "MiddleDoor"){
        if(player.e_Radius->getGlobalBounds().intersects(this->getRect())){
            if(player.k_silver > 0){
                this->isOpen = true;
                player.k_silver -= 1;
            }
        }
    }
    if(this->name == "MiddleDoor"){
        if(player.e_Radius->getGlobalBounds().intersects(this->getRect())){
                this->isOpen = true;
        }
    }
    return false;
}
