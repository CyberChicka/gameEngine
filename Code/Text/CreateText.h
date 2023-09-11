//
// Created by Doni on 16.06.2023.
//

#ifndef GAMEENGINE_BROUGHT_CREATETEXT_H
#define GAMEENGINE_BROUGHT_CREATETEXT_H
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class CreateText {
public:
    int size_text;
    string is_text;
    string file;
    Color color;
    Text *text;
    Font *font;
    CreateText(string File, int Size_Text, string Is_Text, Color Color);
    CreateText operator+(const CreateText &other);
    ~CreateText();
    void setString(string Name_Text);
    void setColor(Color color) const;
};


#endif
