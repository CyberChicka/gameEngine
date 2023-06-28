//
// Created by Doni on 28.06.2023.
//

#include "FonGame.h"

FonGame::FonGame(sf::Sprite *sprite, GameLvL *LvL, float X, float Y, int W, int H, std::string Name): Object(sprite, LvL, X, Y, W, H, Name) {
    this->initAnim();
}
FonGame::~FonGame() {
    cout << "============== removed from fon ============"<< endl;
    delete this->gameLvL;
    delete this->s;
    delete this->e_Radius;
}

FloatRect FonGame::getRect() {
    return FloatRect(this->position.x, this->position.y, this->w, this->h);
}
void FonGame::animation(float time) {
    this->animations[int(this->curAnimation)].Update(*this->s, time);
}
void FonGame::initAnim() {
    if(this->name == "Fon_LvL_1"){
        this->animations[int(AnimationIndex::Walking)] = Animation(1, 0, 0, 0, 5000, 500, 0);
    }
}

float FonGame::GetY() {
    return this->position.y;
}

float FonGame::GetX() {
    return this->position.x;
}

void FonGame::update(float time, int numLvL) {
    this->numLvL = numLvL;
    this->animation(time);
    this->s->setPosition(this->position);
}
void FonGame::draw(sf::RenderWindow &window, sf::View view) {
    this->dist = sqrt((s->getPosition().x - view.getCenter().x)*(s->getPosition().x - view.getCenter().x) +
                      (s->getPosition().y - view.getCenter().y)*(s->getPosition().y - view.getCenter().y));
    if(this->dist < 5800){
        if(this->numLvL == 1 && this->name == "Fon_LvL_1"){ window.draw(*this->s); }
        if(this->numLvL == 2 && this->name == "Fon_LvL_2"){ window.draw(*this->s); }
        if(this->numLvL == 3 && this->name == "Fon_LvL_3"){ window.draw(*this->s); }
        if(this->numLvL == 4 && this->name == "Fon_LvL_4"){ window.draw(*this->s); }
        if(this->numLvL == 5 && this->name == "Fon_LvL_5"){ window.draw(*this->s); }
        if(this->numLvL == 6 && this->name == "Fon_LvL_6"){ window.draw(*this->s); }
    }
}