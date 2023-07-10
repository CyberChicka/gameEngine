//
// Created by Doni on 16.06.2023.
//

#include "CreateText.h"

CreateText::CreateText(string File, int Size_Text, string Name_Text, Color Color) {
    this->color = Color;
    this->file = File;
    this->size_text = Size_Text;
    this->name_text = Name_Text;
    this->text = new Text;
    this->font = new Font;
    if(this->font->loadFromFile("File/Text/" + this->file)){
        this->text->setFont(*this->font);
        this->text->setCharacterSize(this->size_text);
        this->text->setString(this->name_text);
        this->text->setFillColor(this->color);
        cout << "Is load text" << endl;
    }
    else cout << "Error!: -- load text --" << endl;
}
CreateText CreateText::operator+(const CreateText &other) { // Перегрузка оператора сложения
//    CreateText *result;
//    result->name_text = name_text + other.name_text;
//    delete result;
//    return *result;
}
CreateText::~CreateText(){
    cout << "============== removed from text ============"<< endl;
    delete this->text;
    delete this->font;
}
void CreateText::setString(string Name_Text) {
    this->name_text = Name_Text;
    this->text->setString(this->name_text);
}

void CreateText::setColor(sf::Color color) const {
    this->text->setFillColor(color);
}