//
// Created by Doni on 28.06.2023.
//

#include "FonGame.h"

#include <utility>

FonGame::FonGame(sf::Sprite *sprite, GameLvL *LvL, float X, float Y, int W, int H, string Name): Entity(sprite, LvL, X, Y, W, H, Name){
    this->initAnim();
}
FonGame::~FonGame() {
    cout << "============== removed from fon ============"<< endl;
    delete this->gameLvL;
    delete this->s;
}
void FonGame::animation(float time) {
    this->curAnimation = AnimationIndex::Walking;
    this->animations[int(this->curAnimation)].Update(*this->s, time);
}
void FonGame::initAnim() {
    this->animations[int(AnimationIndex::Walking)] = Animation(1, 0.f, 0, 0, 5000, 500, 0);
}

float FonGame::GetY() { return this->position.y; }
float FonGame::GetX() { return this->position.x; }
void FonGame::update(float time, GameLvL *gLvL){
    this->gameLvL = gLvL;
    this->animation(time);
    this->position.y += time*this->dy;
    this->position.x += time*this->dx;
    this->s->setPosition(this->position);
}
void FonGame::draw(sf::RenderWindow &window, sf::View view) {
    window.draw(*this->s);
}

void FonGame::checkCollisionMap(float dX, float dY) {

}

void FonGame::setPosition(float x, float y) {
    this->position.x = x;
    this->position.y = y;
}

FloatRect FonGame::getRect() {
    return FloatRect(this->position.x, this->position.y, this->w, this->h);
}

