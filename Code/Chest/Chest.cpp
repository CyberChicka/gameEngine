//
// Created by Doni on 11.07.2023.
//

#include "Chest.h"

Chest::Chest(Sprite *sprite, GameLvL *LvL, float X, float Y, int W, int H, string Name): Entity(sprite, LvL, X, Y, W, H, Name){
    this->is_open = false;
    if(this->name == "SmallChest"){ s->setScale(1.0f, 1.0f); }
    if(this->name == "MiddleChest"){ s->setScale(1.0f, 1.0f); }
    if(this->name == "BigChest"){ s->setScale(1.0f, 1.0f); }
    initAnim();
}
Chest::~Chest() {
    cout << "============== removed from chest ============"<< endl;
    delete s;
    delete gameLvL;
}

void Chest::initAnim() {
    if(this->name == "SmallChest"){
        this->animations[int(AnimationIndex::WalkingOpen)] = Animation(8, 0.008, 194, 0, 160, 150, 1);
        this->animations[int(AnimationIndex::WalkingClose)] = Animation(1, 0, 194, 0, 160, 150, 1);
    }
    if(this->name == "MiddleChest"){
        this->animations[int(AnimationIndex::WalkingOpen)] = Animation(8, 0.008, 194, 0, 160, 150, 1);
        this->animations[int(AnimationIndex::WalkingClose)] = Animation(1, 0, 194, 0, 160, 150, 1);
    }
    if(this->name == "BigChest"){
        this->animations[int(AnimationIndex::WalkingOpen)] = Animation(8, 0.008, 194, 0, 160, 150, 1);
        this->animations[int(AnimationIndex::WalkingClose)] = Animation(1, 0, 194, 0, 160, 150, 1);
    }
}

void Chest::animation(float time) {
    if(is_open){
        this->curAnimation = AnimationIndex::WalkingOpen;
    }
    else {
        this->curAnimation = AnimationIndex::WalkingClose;
    }
    this->animations[int(this->curAnimation)].Update(*this->s, time);
}

FloatRect Chest::getRect() {
    return FloatRect(this->position.x, this->position.y, this->w, this->h);
}

void Chest::update(float time, GameLvL *gLvL) {
    this->gameLvL = gLvL;
    this->animation(time);
    this->position.x += time*this->dx;
    this->checkCollisionMap(this->dx, 0.f); // Касание с картой по x
    this->position.y += time*this->dy;
    this->checkCollisionMap(0.f, this->dy); // Касание с картой по y
    this->dy+=0.0015*time; // Притяжение к земле
    this->s->setPosition(this->position);
}

float Chest::GetX() {
    return this->position.x;
}

float Chest::GetY() {
    return this->position.y;
}

void Chest::checkCollisionMap(float dX, float dY) {
    for(int i = this->position.y / 32; i<(this->position.y + h) / 32; i++) // Проходимся по высоте
        for(int j = this->position.x / 32; j<(this->position.x + w) / 32; j++) // Проходимся по ширине
        {
            this->cell = this->gameLvL->MapLvL[i][j];
            if(cell == '=' || cell == '.' || cell == '-' || cell == '<' || cell == '>' || cell == '{' || cell == '}')
            {
                if (dY>0){
                    this->position.y = i * 32 - h;
                    this->dy = 0;
                    this->onGround = true;
                }
                if (dY<0){
                    this->position.y = i * 32 + 32;
                    this->dy = 0;
                }
                if (dX>0){
                    this->position.x = j * 32 - w;
                }
                if (dX<0){
                    this->position.x = j * 32 + 32;
                }
            }
            if(this->gameLvL->gameLvL == 1){
                if(this->position.x < 1){ this->position.x = this->position.x + 1; }
                if(this->position.y < 1){ this->position.y = this->position.y + 1; }
            }
        }
}

void Chest::draw(sf::RenderWindow &window, sf::View view) {
    this->dist = sqrt((s->getPosition().x - view.getCenter().x)*(s->getPosition().x - view.getCenter().x) +
                      (s->getPosition().y - view.getCenter().y)*(s->getPosition().y - view.getCenter().y));
    if(this->dist < window.getSize().x){
        window.draw(*this->s);
    }
}

int Chest::OpenChest() {
    int random_num;
    srand(time(NULL));
    random_num = rand() % 3 + 1;
    this->is_open = true;
    return random_num;
}