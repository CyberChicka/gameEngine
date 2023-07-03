//
// Created by Doni on 28.06.2023.
//

#include "Knight.h"

Knight::Knight(sf::Sprite *sprite, GameLvL *LvL, CreateText *T_NPS, float X, float Y, int W, int H, std::string Name): Nps(sprite, LvL, T_NPS, X, Y, W, H, Name) {
    this->initAnim();
    s->setScale(0.6f, 0.6f);
}
Knight::~Knight() {
    cout << "============== removed from nps historian ============"<< endl;
    delete t_Nps;
    delete this->gameLvL;
    delete this->s;
}

void Knight::animation(float time) {
    this->curAnimation = AnimationIndex::Walking;
    this->animations[int(this->curAnimation)].Update(*s, time);
}

void Knight::initAnim() {
    this->animations[int(AnimationIndex::Walking)] = Animation(20, 0.008, 287, 0, 262, 235, 0);
}

//void Knight::update(float time, GameLvL *gLvL){
//    this->gameLvL = gLvL;
//    this->animation(time);
//    this->position.x += this->dx *time;
//    this->checkCollisionMap(this->dx, 0);
//    this->position.y += this->dy * time;
//    checkCollisionMap(0, this->dy);
//    this->dy += 0.0015 * time;
//    this->s->setPosition(position);
//}

void Knight::Dialogue(sf::Event event, Player player) {
    this->t_Nps->text->setPosition(this->position.x + 25, this->position.y - 60);
    ostringstream  d_Nps;
    if(event.type == Event::KeyPressed){
        if(event.key.code == Keyboard::F){
            if(player.e_Radius->getGlobalBounds().intersects(this->getRect())){
                switch (this->isNpsDialogue){
                    case true:
                        this->ClickNps++;
                        this->isNpsDialogue = false;
                        d_Nps << getNpsMessage(this->ClickNps, this->gameLvL->gameLvL, this->name);
                        this->t_Nps->text->setString(d_Nps.str());
                        if(this->gameLvL->gameLvL == 1){
                            if(this->ClickNps >= 2)this->ClickNps = 0;
                        }
                        else if(this->gameLvL->gameLvL == 2){
                            if(this->ClickNps >= 2){this->ClickNps = 0;}
                        }
                        break;
                    case false:
                        this->isNpsDialogue = true;
                        break;
                }

            }
        }
    }
}
//void Knight::draw(sf::RenderWindow &window, sf::View view) {
//    this->dist = sqrt((s->getPosition().x - view.getCenter().x)*(s->getPosition().x - view.getCenter().x) +
//                      (s->getPosition().y - view.getCenter().y)*(s->getPosition().y - view.getCenter().y));
//    if(this->dist < window.getSize().x){
//        window.draw(*this->s);
//        if(this->isNpsDialogue){
//            window.draw(*this->t_Nps->text);
//        }
//    }
//}