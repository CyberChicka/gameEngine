//
// Created by Doni on 19.05.2023.
//

#include "Animation.h"

Animation::Animation(float Frame, float Speed,int RectLeft, int RectTop, int Width, int Height, int L_R) {
    this->frame = Frame; this->l_r = L_R;
    this->l_rect = RectLeft; this->t_rect = RectTop;
    this->w = Width; this->h = Height; this->speed = Speed;
}
void Animation::Update(Sprite &s, float time) {
    this->cur_Frame += this->speed * time;
    if (this->cur_Frame > this->frame)this->cur_Frame -= this->frame;
    if(l_r == 0)
        s.setTextureRect(IntRect(this->l_rect * int(this->cur_Frame), this->t_rect, this->w, this->h));
    else if(l_r == 1)
        s.setTextureRect(IntRect(this->l_rect * int(this->cur_Frame) + this->w, this->t_rect, -this->w, this->h));
    else if(l_r == 2)
        s.setTextureRect(IntRect(this->l_rect, this->t_rect * int(this->cur_Frame), this->w, this->h));
    else if(l_r == 3)
        s.setTextureRect(IntRect(this->l_rect + this->w, this->t_rect * int(this->cur_Frame), -this->w, this->h));
    else
        s.setTextureRect(IntRect(this->l_rect, this->t_rect, this->w, this->h));
}