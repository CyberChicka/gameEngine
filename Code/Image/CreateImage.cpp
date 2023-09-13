//
// Created by Doni on 16.05.2023.
//

#include "CreateImage.h"

CreateImage::CreateImage(string f) {
    this->file = f;
    Load();
}
CreateImage::~CreateImage() {
    cout << "============== removed from Image ============"<< endl;
    delete s;
    delete t;
}

void CreateImage::Load() {
    this->t = new Texture;
    this->s = new Sprite;
    if(this->t->loadFromFile("File/Image/"+ this->file)){
        this->s->setTexture(*this->t);
        cout << "Is Load Image :)" << endl;
    } else{
        cout << "Error!: -- Load Image -- :(" << endl;
    }
}

bool CreateImage::isToch(float X, float Y) const{
    if(this->s->getGlobalBounds().contains(X, Y))return true;
    return false;
}

bool CreateImage::isToch(Vector2f pos) const {
    if(this->s->getGlobalBounds().contains(pos))return true;
    return false;
}
