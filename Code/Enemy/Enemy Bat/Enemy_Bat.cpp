//
// Created by Doni on 12.07.2023.
//

#include "Enemy_Bat.h"

Enemy_Bat::Enemy_Bat(Sprite *sprite, GameLvL *LvL, float X, float Y, int W, int H, string Name): Enemy(sprite, LvL, X, Y, W, H, Name){
    if(this->name == "Bat"){
        this->is_health = 40;
        this->s->setScale(0.4, 0.4);
        this->dx = 0.1;
    }
    this->initAnim();
}
Enemy_Bat::~Enemy_Bat() {
    cout << "============== removed from enemy_bat ============"<< endl;
    delete this->gameLvL;
    delete this->s;
}

void Enemy_Bat::ControlEnemy(float time, float pX, float pY) {
    this->distance = ((this->position.x - pX) * (this->position.x - pX) + (this->position.y - pY) * (this->position.y - pY));
    if(this->name == "Bat"){
        if(this->distance > 100){
            this->dx += 0.03 * time * (pX - this->position.x) / this->distance;
            this->dy += 0.03 * time * (pY - this->position.y) / this->distance;
        }
    }
}

void Enemy_Bat::initAnim() {
    this->animations[int(AnimationIndex::RunL)] = Animation(7, 0.008, 0, 255, 300, 255, 2);
    this->animations[int(AnimationIndex::RunR)] = Animation(7, 0.008, 0, 255, 300, 255, 3);
}

void Enemy_Bat::animation(float time){
    if(this->state == right)this->curAnimation = AnimationIndex::RunR;
    else if(this->state == left)this->curAnimation = AnimationIndex::RunL;
    else this->curAnimation = AnimationIndex::RunR;

    this->animations[int(this->curAnimation)].Update(*s, time);
}

void Enemy_Bat::Attack(Player &p) {

}

void Enemy_Bat::TakingDamage(Player &p) {

}

void Enemy_Bat::update(float time, GameLvL *gLvL, Player *p) {
    this->gameLvL = gLvL;
    this->State();
    this->ControlEnemy(time, p->position.x, p->position.y);
    this->animation(time);
    this->position.x += this->dx * time;
    this->checkCollisionMap(this->dx, 0.f);
    this->position.y += this->dy * time;
    this->checkCollisionMap(0.f, this->dy);
    this->s->setPosition(this->position);
    if(this->is_health <= 0)this->life = false;
}

void Enemy_Bat::checkCollisionMap(float dX, float dY) {
    for(int i = this->position.y / 32; i<(this->position.y + h) / 32; i++)
        for(int j = this->position.x / 32; j<(this->position.x + w) / 32; j++){
            this->cell = this->gameLvL->MapLvL[i][j];
            if(cell == '=' || cell == '.' || cell == '-' || cell == '<' || cell == '>' || cell == '{' || cell == '}')
            {
                if (dY>0){ this->position.y -= 1; this->dy = -0.15;  }//по Y вниз=>идем в пол(стоим на месте) или падаем. В этот момент надо вытолкнуть персонажа и поставить его на землю, при этом говорим что мы на земле тем самым снова можем прыгать
                if (dY<0){ this->position.y += 1; this->dy = 0.15; }//столкновение с верхними краями карты(может и не пригодиться)
                if (dX>0){ this->position.x -= 1; this->dx = -0.15;  }//с правым краем карты
                if (dX<0){ this->position.x += 1; this->dx = 0.15; }// с левым краем карты
            }
            if(this->position.x < 1){ this->position.x = this->position.x + 1; }
            if(this->position.y < 1){ this->position.y = this->position.y + 1; }
        }
}
