//
// Created by Doni on 14.07.2023.
//

#ifndef GAMEENGINE_BROUGHT_CREATESHADER_H
#define GAMEENGINE_BROUGHT_CREATESHADER_H

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

class CreateShader {
public:
    Shader *m_shader;
    string  file;
    CreateShader(string File);
    ~CreateShader();
    void LoadShader();
    void update(Clock clk);
};


#endif //GAMEENGINE_BROUGHT_CREATESHADER_H
