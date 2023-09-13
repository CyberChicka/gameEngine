
#include "Enemy.h"

Enemy::Enemy(Sprite *sprite, GameLvL *LvL,  float X, float Y, int W, int H, string Name): Entity(sprite, LvL, X, Y, W, H, Name){
    this->s->setOrigin(this->w/2,this->h/2);
    this->life = true;
    this->isAttack = false;
    this->dx = 0; this->dy = 0;
    this->gameLvL = new GameLvL(*LvL);
    this->is_health = 100;
    initAnim();
}
Enemy::~Enemy() {
    cout << "============== removed from enemy ============"<< endl;
    delete this->gameLvL;
    delete this->s;
}

FloatRect Enemy::getRect() { return FloatRect(this->pos.x, this->pos.y, this->w, this->h); }

void Enemy::ControlMove() { }

void Enemy::ControlEnemy(float pX, float pY, float time) {

}
void Enemy::move() { }

void Enemy::update(float time, GameLvL *gLvL, Player *p) {}

void Enemy::animation(float time) { }

void Enemy::initAnim() { }

float Enemy::GetX() { return this->pos.x; }
float Enemy::GetY() { return this->pos.y; }

void Enemy::checkCollisionMap(float dX, float dY){
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
                if (dX>0){
                    this->pos.x = j * w_block - w;
                    this->dx = -0.1;
                }
                if (dX<0){
                    this->pos.x = j * w_block + w_block;
                    this->dx = 0.1;
                }
            }
            if(cell == '{' || cell == '<')
                if(dY > 0){ this->dx = 0.2; }
            if(cell == '}' || cell == '>')
                if(dY > 0){ this->dx = -0.2; }
            if(this->pos.x < 1) this->pos.x = this->pos.x + 1;
            if(this->pos.y < 1) this->pos.y = this->pos.y + 1;
        }
}

void Enemy::draw(RenderWindow &window, View view) {
    this->dist = sqrt((s->getPosition().x - view.getCenter().x)*(s->getPosition().x - view.getCenter().x) + (s->getPosition().y - view.getCenter().y)*(s->getPosition().y - view.getCenter().y));
    if(dist < window.getSize().x){
        window.draw(*this->s);
    }
}

void Enemy::Attack(Player &p) { }

void Enemy::TakingDamage(Player &p, list<Bullet*> &bulletLvL, Event event) {
    if (event.type == Event::MouseButtonPressed){
        if (event.key.code == Mouse::Left){
            if(p.e_Radius->getGlobalBounds().intersects(this->getRect())){
                if(p.attack_time > 1000){
                    for(int i = 0; i < p.lvl_player; i++){
                        this->is_health -= (20 + (i*2));
                    }
                    p.attack_time = 0;
                }
            }
        }
    }
    for(auto it = bulletLvL.begin(); it != bulletLvL.end(); it++){
        if((*it)->s->getGlobalBounds().intersects(this->getRect())){
            this->is_health -= 20;
            bulletLvL.erase(it);
        }
    }
}

void Enemy::State() {
    if(this->dx > 0){
        this->state = this->right;
        this->isStop = false;
    }
    else if(this->dx < 0){
        this->state = this->left;
        this->isStop = false;
    }
    else{
        this->state = this->stay;
        this->isStop = true;
    }
}