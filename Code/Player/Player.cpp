#include "Player.h"
#include "../Map/GameLvL.h"

Player::Player(Sprite *sprite, GameLvL *LvL, float X, float Y, int W, int H, string Name):Entity(sprite, LvL, X, Y, W, H, Name){
    this->s->setScale(0.5f, 0.5f);
    this->s->setOrigin(this->w/2,this->h/2);
    this->is_health = 120; this->f_health = 120;
    this->life = true;
    this->e_Radius = new CircleShape(120.f);
    this->particles = new ParticleSystem(10);
    this->gameLvL = new GameLvL(*LvL);
    this->money = 0;
    this->lvl_player = 1;
    this->dx = 0; this->dy = 0;
    this->initAnim();
}
Player::~Player() {
    cout << "============== removed from player ============"<< endl;
    delete this->gameLvL;
    delete this->s;
    delete this->particles;
    delete this->e_Radius;
}
FloatRect Player::getRect() {
    return FloatRect(this->position.x, this->position.y, this->w, this->h);
}

void Player::animation(float time) {
    if(this->life){
        if(this->isBlock){
            if(this->state == right) this->curAnimation = AnimationIndex::BlockR;
            else if(this->state == left) this->curAnimation = AnimationIndex::BlockL;
            else this->curAnimation = AnimationIndex::BlockR;
        }
        if(this->isAttack){
            s->setPosition(position.x, position.y - 40);
            if(this->state == right) this->curAnimation = AnimationIndex::AttackR;
            else if(this->state == left) this->curAnimation = AnimationIndex::AttackL;
            else this->curAnimation = AnimationIndex::AttackR;
        }
        if(this->isRun){
            if(this->state == right) this->curAnimation = AnimationIndex::RunR;
            else if(this->state == left) this->curAnimation = AnimationIndex::RunL;
            else this->curAnimation = AnimationIndex::RunR;
        }
        if(this->stop){
            if(this->state == right) this->curAnimation = AnimationIndex::WalkingR;
            else if(this->state == left) this->curAnimation = AnimationIndex::WalkingL;
            else this->curAnimation = AnimationIndex::WalkingR;
        }
//        if(this->isJump){
//            if(this->state == right) this->curAnimation = AnimationIndex::JumpR;
//            else if(this->state == left) this->curAnimation = AnimationIndex::JumpL;
//            else this->curAnimation = AnimationIndex::JumpR;
//        }
        if(!this->onGround && !this->isAttack){
            if(this->state == right) this->curAnimation = AnimationIndex::JumpR;
            else if(this->state == left) this->curAnimation = AnimationIndex::JumpL;
            else this->curAnimation = AnimationIndex::JumpR;
        }
    }
    this->animations[int(this->curAnimation)].Update(*s, time);
}
void Player::initAnim() {
    // Idle
    this->animations[int(AnimationIndex::WalkingL)] = Animation(8, 0.009, 194, 0, 160, 150, 1);
    this->animations[int(AnimationIndex::WalkingR)] = Animation(8, 0.009, 194, 0, 160, 150, 0);
    // Run
    this->animations[int(AnimationIndex::RunL)] = Animation(8, 0.009, 155, 200, 155, 150, 1);
    this->animations[int(AnimationIndex::RunR)] = Animation(8, 0.009, 155, 200, 155, 150, 0);
    // Attack
    this->animations[int(AnimationIndex::AttackL)] = Animation(7, 0.015, 288, 630, 280,300, 1);
    this->animations[int(AnimationIndex::AttackR)] = Animation(7, 0.015, 288, 630, 280,300, 0);
    //Block
    this->animations[int(AnimationIndex::BlockL)] = Animation(8, 0.009, 202, 384, 190,150, 1);
    this->animations[int(AnimationIndex::BlockR)] = Animation(8, 0.009, 202, 384, 190,150, 0);
    // Jump
    this->animations[int(AnimationIndex::JumpL)] = Animation(8, 0.009, 155, 200, 155, 150, 1);
    this->animations[int(AnimationIndex::JumpR)] = Animation(8, 0.009, 155, 200, 155, 150, 0);

}

void Player::ControlMove() {
    if(this->life){
        this->stop = true; this->isBlock = false; this->isAttack = false; this->isRun = false; //this->isJump = false;
        this->isJump = false;
        if(Mouse::isButtonPressed(Mouse::Right)){ this->isBlock = true; this->stop = false; this->speed = 0; }
        else{
            if(Mouse::isButtonPressed(Mouse::Left)){ isAttack = true; stop = false; speed = 0;}
            else{
                if((Keyboard::isKeyPressed(Keyboard::LShift) && Keyboard::isKeyPressed(Keyboard::D)) && this->isSprint){
                    this->state = SRight; this->stop = false; this->SprintTime = 0;
                }
                else if((Keyboard::isKeyPressed(Keyboard::LShift) && Keyboard::isKeyPressed(Keyboard::A)) && this->isSprint){
                    this->state = SLeft;  this->stop = false; this->SprintTime = 0;
                }
                else{
                    if(Keyboard::isKeyPressed(sf::Keyboard::A) || Keyboard::isKeyPressed(sf::Keyboard::Left)){
                        this->state = left;
                        this->speed = 0.5; // speed 0.20
                        this->isRun = true;
                        this->stop = false;
                    }
                    if(Keyboard::isKeyPressed(sf::Keyboard::D) || Keyboard::isKeyPressed(sf::Keyboard::Right)){
                        this->state = right;
                        this->speed = 0.5; // speed 20
                        this->isRun = true;
                        this->stop = false;
                    }
                    if((Keyboard::isKeyPressed(sf::Keyboard::Space) || Keyboard::isKeyPressed(sf::Keyboard::Up)) && this->onGround){
                        this->isJump = true;
                        this->dy -= 0.8; // jump 0.65
                        this->onGround = false;
                        this->stop = false;
                    }
                }
            }
        }

    }
}
void Player::move() {
    this->ControlMove();
    if(this->life){
        switch (this->state) {
            case left: this->dx = -this->speed; break;
            case right: this->dx = this->speed; break;
            case SLeft: this->position.x -= 150; break;
            case SRight: this->position.x += 150; break;
            case stay: this->dx = 0; this->dy = 0; this->speed = 0;break;
        }
        this->speed = 0;
    }
}

float Player::GetX() { return this->position.x; }
float Player::GetY() { return this->position.y; }

void Player::setPosition(float x, float y) {
    this->position.x = x;
    this->position.y = y;
}

void Player::update(float time, GameLvL *gLvL){
    this->particles->setEmitter(this->position.x + 28, this->position.y + 30);
    this->gameLvL = gLvL;
    // Move
    this->move();
    //Anim
    this->animation(time);
    // sprint
    this->SprintTime += time;
    if(this->SprintTime > 3500)this->isSprint = true;
    else this->isSprint = false;
    //position
    this->position.x += this->dx * time;
    this->checkCollisionMap(this->dx, 0.f);

    this->position.y += this->dy * time;
    this->checkCollisionMap(0.f, this->dy);

    this->dy+=0.0015*time;
    if(!this->isAttack)this->s->setPosition(this->position);
    this->e_Radius->setPosition(position);
    // life
    if(this->is_health <= 0)this->life = false;
}
void Player::draw(RenderWindow &window, View view){
    window.draw(*this->particles);
    window.draw(*this->s);
}
void Player::checkCollisionMap(float dX, float dY) {
    for(int i = this->position.y / 32; i<(this->position.y + h) / 32; i++)
        for(int j = this->position.x / 32; j<(this->position.x + w) / 32; j++){
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

//            if(this->position.y > 900){ this->position.y = this->position.y - 0.5;}
//            if(this->position.x > 10167){ this->position.x = this->position.x - 0.5;}
        }
}