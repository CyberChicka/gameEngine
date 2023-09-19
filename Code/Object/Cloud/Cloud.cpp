#include "Cloud.h"

Cloud::Cloud(Sprite *sprite, GameLvL *LvL, float X, float Y, int W, int H, string Name): Object(sprite, LvL, X, Y, W, H, Name){
    this->initAnim();
}
Cloud::~Cloud() {
    cout << "============== removed from fon ============"<< endl;
    delete this->gameLvL;
    delete this->s;
}
void Cloud::animation(float time) {
    this->curAnimation = AnimationIndex::Walking;
    this->animations[int(this->curAnimation)].Update(*this->s, time);
}
void Cloud::initAnim() {
    if(this->name == "Cloud_anim"){
        this->animations[int(AnimationIndex::Walking)] = Animation(6, 0.0008, 534, 0, 524, 460, 0);
    }
    if(this->name == "Cloud_Big"){
        this->animations[int(AnimationIndex::Walking)] = Animation(1, 0, 0, 0, 524, 460, 0);
    }
    if(this->name == "Cloud_Middle"){
        this->animations[int(AnimationIndex::Walking)] = Animation(1, 0, 0, 0, 5000, 500, 0);
    }
    if(this->name == "Cloud_Small"){
        this->animations[int(AnimationIndex::Walking)] = Animation(1, 0, 0, 0, 5000, 500, 0);

    }
}
void Cloud::update(float time, GameLvL *gLvL){
    if(this->name == "Cloud_Big"){
        this->dx += 0.00002;
    }
    else if(this->name == "Cloud_Middle"){
        this->dx += 0.00003;
    }
    else if(this->name == "Cloud_Small"){
        this->dx += 0.00004;
    }
    else{
        this->dx += 0.00001;
    }
    if(this->pos.x > 15000){
        this->pos.x = 0;
    }
    this->gameLvL = gLvL;
    this->animation(time);
    this->pos.x += time * this->dx;
    this->s->setPosition(this->pos);
}
void Cloud::draw(sf::RenderWindow &window, sf::View view) {
    this->dist = sqrt((s->getPosition().x - view.getCenter().x)*(s->getPosition().x - view.getCenter().x) +
                      (s->getPosition().y - view.getCenter().y)*(s->getPosition().y - view.getCenter().y));
    if(this->dist < window.getSize().x){
        window.draw(*this->s);
    }
}
void Cloud::setPosition(float x, float y) {
    this->pos.x = x;
}

FloatRect Cloud::getRect() {
    return FloatRect(this->pos.x, this->pos.y, this->w, this->h);
}

