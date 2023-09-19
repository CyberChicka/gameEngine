#include "Player.h"

Player::Player(Sprite *sprite, GameLvL *LvL, float X, float Y, int W, int H, string Name):Entity(sprite, LvL, X, Y, W, H, Name){
    this->initAnim();
    this->s_player[1] = new CreateImage("SpriteEntity/Player/Player-Blue.png");
    this->s_player[2] = new CreateImage("SpriteEntity/Player/Player-Red.png");
    this->s_player[3] = new CreateImage("SpriteEntity/Player/Player-Green.png");
    this->s_player[4] = new CreateImage("SpriteEntity/Player/Player-Brow.png");
    this->s->setScale(0.5f, 0.5f);
    this->s->setOrigin(this->w,this->h/2);
    this->e_Radius = new CircleShape(120.f);
    this->e_Radius->setScale(1.0f, 0.5f);
    this->particles = new ParticleSystem(10);
    this->gameLvL = new GameLvL(*LvL);
    this->life = true;
    this->isInventory = true;
    if(this->name == "player"){
        this->is_health = 120; this->f_health = 120;
        this->k_silver = 0;
        this->k_gold = 0;
        this->money = 0;
        this->w_sprint = 210;
        this->lvl_player = 1;
        this->particle_of_strength_shoot = false;
        this->particle_of_strength_sprint = false;
        this->particle_of_strength_repulsion = false;
        this->particle_of_strength_speed = false;
        this->particle_of_strength_jump = false;
    }
    if(this->name == "god"){
        for(int i = 0; i < size(sword); i++){
            sword[i] = true;
            shield[i] = true;
        }
        this->is_health = 9999999; this->f_health = 9999999;
        this->k_silver = 100;
        this->k_gold = 100;
        this->money = 100;
        this->w_sprint = 250;
        this->lvl_player = 1;
        this->particle_of_strength_shoot = true;
        this->particle_of_strength_sprint = true;
        this->particle_of_strength_repulsion = true;
        this->particle_of_strength_speed = true;
        this->particle_of_strength_jump = true;
    }
}
Player::~Player() {
    cout << "============== removed from player ============"<< endl;
    delete this->gameLvL;
    delete this->s;
    delete this->particles;
    delete this->e_Radius;
    delete []*this->s_player;
}
FloatRect Player::getRect() {
    return FloatRect(this->pos.x, this->pos.y, this->w, this->h);
}
void Player::animation(float time) {
    if(this->life){
        for(int i = 0; i < size(equipment); i++){
            if(equipment[i])s->setTexture(*s_player[i]->t);
        }
        if(this->isBlock){
            if(this->state == right) this->curAnimation = AnimationIndex::BlockR;
            else if(this->state == left) this->curAnimation = AnimationIndex::BlockL;
            else this->curAnimation = AnimationIndex::BlockR;
        }
        else if(this->isAttack){
                this->stop = false;
                if(this->state == right){
                    this->curAnimation = AnimationIndex::AttackR;
                    if(this->animations[int(AnimationIndex::AttackR)].cur_Frame > 6){
                        this->isAttack = false;
                    }
                }
                else if(this->state == left){
                    this->curAnimation = AnimationIndex::AttackL;
                    if(this->animations[int(AnimationIndex::AttackL)].cur_Frame > 6){
                        this->isAttack = false;
                    }
                }
                else{
                    this->curAnimation = AnimationIndex::AttackR;
                    if(this->animations[int(AnimationIndex::AttackR)].cur_Frame > 6){
                        this->isAttack = false;
                    }
                }
        }
        else{
            if(this->isRun){
                if(this->state == right){this->curAnimation = AnimationIndex::RunR;}
                else if(this->state == left){this->curAnimation = AnimationIndex::RunL;}
                else{ this->curAnimation = AnimationIndex::RunR;}
            }
            if(this->stop){
                if(this->state == right){this->curAnimation = AnimationIndex::WalkingR;}
                else if(this->state == left) {this->curAnimation = AnimationIndex::WalkingL;}
                else{ this->curAnimation = AnimationIndex::WalkingR; }
            }
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
    this->animations[int(AnimationIndex::WalkingR)] = Animation(8, 0.009, 300, 0, 292, 282, 0);
    this->animations[int(AnimationIndex::WalkingL)] = Animation(8, 0.009, 300, 290, 292, 282, 0);
    // Run
    this->animations[int(AnimationIndex::RunR)] = Animation(8, 0.009, 300, 580, 292, 282, 0);
    this->animations[int(AnimationIndex::RunL)] = Animation(8, 0.009, 300, 870, 292, 282, 0);
    // Attack
    this->animations[int(AnimationIndex::AttackR)] = Animation(7, 0.011, 302, 1740, 292,282, 0);
    this->animations[int(AnimationIndex::AttackL)] = Animation(7, 0.011, 302, 2030, 292,282, 0);
    //Block
    this->animations[int(AnimationIndex::BlockR)] = Animation(8, 0.009, 300, 1160, 292,282, 0);
    this->animations[int(AnimationIndex::BlockL)] = Animation(8, 0.009, 300, 1450, 292,282, 0);
    //Dead
    this->animations[int(AnimationIndex::DeadR)] = Animation(1, 0.009, 300, 2320, 292, 282, 0);
    this->animations[int(AnimationIndex::DeadL)] = Animation(1, 0.009, 300, 2320, 292, 282, 1);

}
void Player::ControlMove() {
    if(this->life){
        this->stop = true;
        this->isBlock = false;
        this->isRun = false;
        if(this->name == "god"){ onGround = true; }
        if(mouse.isButtonPressed(mouse.Right)){
            this->isBlock = true;
            this->stop = false;
        }
        else if(mouse.isButtonPressed(mouse.Left)){
            this->isAttack = true;
            this->stop = false;
        }
        else{
            if((key.isKeyPressed(key.LShift) && key.isKeyPressed(key.D)) && this->isSprint){
                this->state = SRight;
                this->stop = false;
                this->sprint_time = 0;
            }
            else if((key.isKeyPressed(key.LShift) && key.isKeyPressed(key.A)) && this->isSprint){
                this->state = SLeft;
                this->stop = false;
                this->sprint_time = 0;
            }
            else{
                if(key.isKeyPressed(key.A) || key.isKeyPressed(key.Left)){
                    this->state = left;
                    if(this->particle_of_strength_speed)this->speed = 0.25;
                    else this->speed = 0.20; // speed 0.20
                    this->isRun = true;
                    this->stop = false;
                }
                if(key.isKeyPressed(key.D) || key.isKeyPressed(key.Right)){
                    this->state = right;
                    if(this->particle_of_strength_speed)this->speed = 0.25;
                    else this->speed = 0.20; // speed 0.20
                    this->isRun = true;
                    this->stop = false;
                }
                if((key.isKeyPressed(key.Space) || key.isKeyPressed(key.Up)) && this->onGround){
                    if(this->name == "player") {
                        this->onGround = false;
                        if(this->particle_of_strength_jump)this->dy -= 0.72;
                        else this->dy -= 0.66; // jump 0.65
                    }
                    if(this->name == "god"){
                        this->dy -= 0.02;
                    }
                    this->stop = false;
                }
                if(key.isKeyPressed(key.S)){
                    if(this->name == "god"){
                        this->dy += 0.02;
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
            case left:
                this->dx = -this->speed;
                break;
            case right:
                this->dx = this->speed;
                break;
            // /////////// sprint ////////////
            case SLeft:
                if(this->particle_of_strength_sprint)
                    this->pos.x -= this->w_sprint;
                break;
            case SRight:
                if(particle_of_strength_sprint)
                    this->pos.x += this->w_sprint;
                break;
            // //////////////////////////////
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
void Player::s_position() {
    if(!this->isRun && this->state == right){
        this->s->setPosition(this->pos.x, this->pos.y - 62);
    }
    else if(this->isAttack && this->state == left){
            this->s->setPosition(this->pos.x - 30, this->pos.y - 62);
    }
    else{
        this->s->setPosition(this->pos.x + 30, this->pos.y - 62);
    }
    // ///////////////////////// radius /////////////////////////
    this->e_Radius->setPosition(this->pos.x - 95, this->pos.y - 50);
    // ///////////////////////// Particle /////////////////////////
    this->particles->setEmitter(this->pos.x + 28, this->pos.y + 30);
}
void Player::update(float time, GameLvL *gLvL){
    this->gameLvL = gLvL; // Game LvL
    this->move(); // Move
    this->animation(time); // Anim
    // ////////////// strength ///////////////
    this->attack_time += time;
    this->sprint_time += time;
    this->bullet_time += time;
    // ////////////////// sprint & bullet ////////////////
    if(this->sprint_time > 3500)this->isSprint = true;
    else this->isSprint = false;
    if(this->bullet_time > 5000)this->isShoot = true;
    else this->isShoot = false;
    // //////////////// position ////////////////////
    this->pos.x += this->dx * time;
    this->checkCollisionMap(this->dx, 0.f);
    this->pos.y += this->dy * time;
    this->checkCollisionMap(0.f, this->dy);
    if(this->name == "player")this->dy = this->dy + 0.0015*time; // Притяжение к земле
    this->s_position();
    // //////////////////// life /////////////////////////
    if(this->is_health <= 0)this->life = false;
}

void Player::draw(RenderWindow &window, View view){
    window.draw(*this->particles);
    //window.draw(*e_Radius);
    window.draw(*this->s);
}
void Player::checkCollisionMap(float dX, float dY) {
    for(int i = this->pos.y / h_block; i < (this->pos.y + h) / h_block; i++)
        for(int j = this->pos.x / w_block; j < (this->pos.x + w) / w_block; j++){
            this->cell = this->gameLvL->MapLvL[i][j];
            if(cell == '=' || cell == '.' || cell == '-' || cell == '<' || cell == '>' || cell == '{' || cell == '}')
            {
                if (dY>0){
                    this->pos.y = i * h_block - h;
                    this->dy = 0;
                    this->onGround = true;
                }
                if (dY<0){
                    this->pos.y = i * h_block + h_block;
                    this->dy = 0;
                }
                if (dX>0) this->pos.x = j * w_block - w;
                if (dX<0) this->pos.x = j * w_block + w_block;
            }
            if(this->gameLvL->gameLvL == 1){
                if(this->pos.x < 1){ this->pos.x = this->pos.x + 1; }
                if(this->pos.y < 1){ this->pos.y = this->pos.y + 1; }
            }
        }
}