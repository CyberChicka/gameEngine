//
// Created by Doni on 19.05.2023.
//

#include "Animation.h"

Animation::Animation(float Frame, float Speed,int RectLeft, int RectTop, int Width, int Height, int L_R) {
    this->frame = Frame; l_r = L_R;
    this->rect_l = RectLeft; this->rect_t = RectTop;
    this->w = Width; this->h = Height; this->speed = Speed;
}
void Animation::Update(Sprite &s, float time) {
    this->cur_Frame += this->speed * time;
    if (this->cur_Frame > this->frame)this->cur_Frame -= this->frame;
    if(l_r == 0){
        s.setTextureRect(IntRect(this->rect_l * int(this->cur_Frame), this->rect_t, this->w, this->h));
    }
    else if(l_r == 1){
        s.setTextureRect(IntRect(this->rect_l * int(this->cur_Frame)+this->w, this->rect_t, -this->w, this->h));
    }
    else if(l_r == 2){
        s.setTextureRect(IntRect(this->rect_l, this->rect_t * int(this->cur_Frame), this->w, this->h));
    }
    else if(l_r == 3){
        s.setTextureRect(IntRect(this->rect_l, this->rect_t * int(this->cur_Frame) + this->h, this->w, -this->h));
    }
}