//
// Created by Doni on 11.07.2023.
//

#include "Chest.h"

Chest::Chest(Sprite *sprite, GameLvL *LvL, float X, float Y, int W, int H, string Name): Entity(sprite, LvL, X, Y, W, H, Name){
    this->is_open = true;
    this->initAnim();
}
Chest::~Chest() {
    cout << "============== removed from chest ============"<< endl;
    delete s;
    delete gameLvL;
}

void Chest::initAnim() {
    if(this->name == "SmallChest"){
        this->animations[int(AnimationIndex::WalkingOpening)] = Animation(10, 0.008, 80, 0, 50, 75, 1);
        this->animations[int(AnimationIndex::WalkingOpen)] = Animation(1, 0.0, 728, 0, 65, 75, 4);
        this->animations[int(AnimationIndex::WalkingClose)] = Animation(1, 0.0, 0, 0, 65, 75, 4);
    }
    if(this->name == "MiddleChest"){
        this->animations[int(AnimationIndex::WalkingOpening)] = Animation(10, 0.008, 90, 0, 70, 88, 1);
        this->animations[int(AnimationIndex::WalkingOpen)] = Animation(1, 0.0, 810, 0, 70, 88, 4);
        this->animations[int(AnimationIndex::WalkingClose)] = Animation(1, 0.0, 0, 0, 70, 88, 4);
    }
    if(this->name == "BigChest"){
        this->animations[int(AnimationIndex::WalkingOpening)] = Animation(10, 0.008, 109, 0, 88, 95, 1);
        this->animations[int(AnimationIndex::WalkingOpen)] = Animation(1, 0.0, 968, 0, 85, 95, 4);
        this->animations[int(AnimationIndex::WalkingClose)] = Animation(1, 0.0, 0, 0, 85, 95, 4);
    }
}

void Chest::animation(float time) {
    if(!is_open){
        if(this->animations[int(AnimationIndex::WalkingOpening)].cur_Frame < 8)
            this->curAnimation = AnimationIndex::WalkingOpening;
        else
            this->curAnimation = AnimationIndex::WalkingOpen;
    }
    else{
        this->curAnimation = AnimationIndex::WalkingClose;
    }
    this->animations[int(this->curAnimation)].Update(*this->s, time);
}

FloatRect Chest::getRect() {
    return FloatRect(this->pos.x, this->pos.y, this->w, this->h);
}

void Chest::update(float time, GameLvL *gLvL) {
    this->gameLvL = gLvL;
    this->animation(time);
    this->pos.x += time * this->dx;
    this->checkCollisionMap(this->dx, 0.f); // Касание с картой по x
    this->pos.y += time * this->dy;
    this->checkCollisionMap(0.f, this->dy); // Касание с картой по y
    this->dy = dy + 0.0015*time; // Притяжение к земле
    this->s->setPosition(this->pos);
}

float Chest::GetX() {
    return this->pos.x;
}

float Chest::GetY() {
    return this->pos.y;
}

void Chest::checkCollisionMap(float dX, float dY) {
    for(int i = this->pos.y / 32; i < (this->pos.y + h) / 32; i++) // Проходимся по высоте
        for(int j = this->pos.x / 32; j < (this->pos.x + w) / 32; j++) // Проходимся по ширине
        {
            this->cell = this->gameLvL->MapLvL[i][j];
            if(cell == '=' || cell == '.' || cell == '-' || cell == '<' || cell == '>' || cell == '{' || cell == '}')
            {
                if (dY>0){
                    this->pos.y = i * 32 - h;
                    this->dy = 0;
                    this->onGround = true;
                }
                if (dY<0){
                    this->pos.y = i * 32 + 32;
                    this->dy = 0;
                }
                if (dX>0){
                    this->pos.x = j * 32 - w;
                }
                if (dX<0){
                    this->pos.x = j * 32 + 32;
                }
            }
            if(this->gameLvL->gameLvL == 1){
                if(this->pos.x < 1){ this->pos.x = this->pos.x + 1; }
                if(this->pos.y < 1){ this->pos.y = this->pos.y + 1; }
            }
        }
}

void Chest::draw(RenderWindow &window, View view) {
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
    this->is_open = false;
    return random_num;
}
