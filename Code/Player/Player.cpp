#include "Player.h"

Player::Player(Sprite *sprite, GameLvL *LvL, float X, float Y, int W, int H, string Name):Entity(sprite, LvL, X, Y, W, H, Name){
    this->s->setScale(0.5f, 0.5f);
    this->s->setOrigin(this->w/2,this->h/2);
    this->is_health = 120; this->f_health = 120;
    this->life = true;
    this->e_Radius = new CircleShape(120.f);
    this->e_Radius->setScale(1.0f, 0.5f);
    this->particles = new ParticleSystem(10);
    this->gameLvL = new GameLvL(*LvL);
    this->k_Silver = 10;
    this->k_Gold = 10;
    this->money = 10;
    this->lvl_player = 10;
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
    return FloatRect(this->pos.x, this->pos.y, this->w, this->h);
}

void Player::animation(float time) {
    if(this->life){
        if(this->isBlock){
            this->s->setPosition(pos);
            if(this->state == right) this->curAnimation = AnimationIndex::BlockR;
            else if(this->state == left) this->curAnimation = AnimationIndex::BlockL;
            else this->curAnimation = AnimationIndex::BlockR;
        }
        if(this->isAttack && !this->isBlock){
            this->stop = false;
            this->s->setPosition(pos.x, pos.y - 40);
            if(this->state == right){
                this->curAnimation = AnimationIndex::AttackR;
                if(this->animations[int(AnimationIndex::AttackR)].cur_Frame > 6){ this->isAttack = false; }
            }
            else if(this->state == left){
                this->curAnimation = AnimationIndex::AttackL;
                if(this->animations[int(AnimationIndex::AttackL)].cur_Frame > 6){ this->isAttack = false; }
            }
            else{
                this->curAnimation = AnimationIndex::AttackR;
                if(this->animations[int(AnimationIndex::AttackR)].cur_Frame > 6){ this->isAttack = false; }
            }
        }
        if(this->isRun && !this->isAttack){
            this->s->setPosition(this->pos);
            if(this->state == right) this->curAnimation = AnimationIndex::RunR;
            else if(this->state == left) this->curAnimation = AnimationIndex::RunL;
            else this->curAnimation = AnimationIndex::RunR;
        }
        if(this->stop && !this->isAttack){
            this->s->setPosition(this->pos);
            if(this->state == right) this->curAnimation = AnimationIndex::WalkingR;
            else if(this->state == left) this->curAnimation = AnimationIndex::WalkingL;
            else this->curAnimation = AnimationIndex::WalkingR;
        }
    }
    else{
        if(this->state == right) this->curAnimation = AnimationIndex::DeadR;
        else if(this->state == left) this->curAnimation = AnimationIndex::DeadL;
        else this->curAnimation = AnimationIndex::DeadR;
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
    this->animations[int(AnimationIndex::AttackL)] = Animation(7, 0.011, 288, 630, 280,300, 1);
    this->animations[int(AnimationIndex::AttackR)] = Animation(7, 0.011, 288, 630, 280,300, 0);
    //Block
    this->animations[int(AnimationIndex::BlockL)] = Animation(8, 0.009, 202, 384, 190,150, 1);
    this->animations[int(AnimationIndex::BlockR)] = Animation(8, 0.009, 202, 384, 190,150, 0);
    //Dead
    this->animations[int(AnimationIndex::DeadL)] = Animation(8, 0.009, 155, 0, 155, 150, 1);
    this->animations[int(AnimationIndex::DeadR)] = Animation(8, 0.009, 155, 0, 155, 150, 0);

}

void Player::ControlMove() {
    if(this->life){
        this->stop = true; this->isBlock = false; this->isRun = false;
        this->isJump = false;
        if(Mouse::isButtonPressed(Mouse::Right)){ this->isBlock = true;
            this->stop = false;
            this->speed = 0;
        }
        else{
            if(Mouse::isButtonPressed(Mouse::Left)){
                this->isAttack = true;
                this->stop = false;
                this->speed = 0;
            }
            else{
                if((Keyboard::isKeyPressed(Keyboard::LShift) && Keyboard::isKeyPressed(Keyboard::D)) && this->isSprint){
                    this->state = SRight;
                    this->SprintTime = 0;
                    this->stop = false;
                }
                else if((Keyboard::isKeyPressed(Keyboard::LShift) && Keyboard::isKeyPressed(Keyboard::A)) && this->isSprint){
                    this->state = SLeft;
                    this->SprintTime = 0;
                    this->stop = false;
                }
                else{
                    if(Keyboard::isKeyPressed(sf::Keyboard::A) || Keyboard::isKeyPressed(sf::Keyboard::Left)){
                        this->state = left;
                        this->speed += 0.5; // speed 0.20
                        this->isRun = true;
                        this->stop = false;
                    }
                    if(Keyboard::isKeyPressed(sf::Keyboard::D) || Keyboard::isKeyPressed(sf::Keyboard::Right)){
                        this->state = right;
                        this->speed += 0.5; // speed 20
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
void Player::move(float time) {
    this->ControlMove();
    if(this->life){
        switch (this->state) {
            case left: this->dx = -this->speed; break;
            case right: this->dx = this->speed; break;
            case SLeft: this->pos.x -= 14 * time; break;
            case SRight: this->pos.x += 14 * time; break;
        }
        this->speed = 0;
    }
}

float Player::GetX() { return this->pos.x; }
float Player::GetY() { return this->pos.y; }

void Player::setPosition(float x, float y) {
    this->pos.x = x;
    this->pos.y = y;
}

void Player::update(float time, GameLvL *gLvL){
    this->particles->setEmitter(this->pos.x + 28, this->pos.y + 30);
    this->gameLvL = gLvL;
    // Move
    this->move(time);
    //Anim
    this->animation(time);
    // sprint
    this->SprintTime += time;
    this->BulletTime += time;
    if(this->SprintTime > 3500)this->isSprint = true;
    else this->isSprint = false;
    if(this->BulletTime > 5000)this->isShoot = true;
    else this->isShoot = false;
    //position
    this->pos.x += this->dx * time;
    this->checkCollisionMap(this->dx, 0.f);
    this->pos.y += this->dy * time;
    this->checkCollisionMap(0.f, this->dy);
    this->dy = this->dy + 0.0015*time; // Притяжение к земле
    if(!this->isAttack)this->s->setPosition(this->pos);
    this->e_Radius->setPosition(this->pos.x - 95, this->pos.y - 50);
    // life
    if(this->is_health <= 0)this->life = false;
}

View Player::setPlayerCoordinateForView(sf::View &view) {
    view.setCenter(this->pos.x, this->pos.y - 100);
    return view;
}
void Player::draw(RenderWindow &window, View view){
    window.draw(*this->particles);
    //window.draw(*e_Radius);
    window.draw(*this->s);
}
void Player::checkCollisionMap(float dX, float dY) {
    for(int i = this->pos.y / 32; i < (this->pos.y + h) / 32; i++)
        for(int j = this->pos.x / 32; j < (this->pos.x + w) / 32; j++){
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

//            if(this->position.y > 900){ this->position.y = this->position.y - 0.5;}
//            if(this->position.x > 10167){ this->position.x = this->position.x - 0.5;}
        }
}