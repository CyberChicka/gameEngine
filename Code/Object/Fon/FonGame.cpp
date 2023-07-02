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
}
void FonGame::animation(float time) {
    this->animations[int(this->curAnimation)].Update(*this->s, time);
}
void FonGame::initAnim() {
    this->animations[int(AnimationIndex::Walking)] = Animation(1, 0, 0, 0, 5000, 500, 0);
}

float FonGame::GetY() {
    return this->position.y;
}

float FonGame::GetX() {
    return this->position.x;
}

void FonGame::update(float time, GameLvL *gLvL){
    this->gameLvL = gLvL;
    this->animation(time);
    this->s->setPosition(this->position);
}
void FonGame::draw(sf::RenderWindow &window, sf::View view) {
    this->dist = sqrt((s->getPosition().x - view.getCenter().x)*(s->getPosition().x - view.getCenter().x) +
                      (s->getPosition().y - view.getCenter().y)*(s->getPosition().y - view.getCenter().y));
    if(this->dist < 5800){
        window.draw(*this->s);
    }
}