//
// Created by Doni on 14.07.2023.
//

#include "CreateShader.h"

CreateShader::CreateShader(string File) {
    this->file = File;
    LoadShader();
}
CreateShader::~CreateShader() {
    cout << "\"============== removed from Shader ============\"" << endl;
    delete m_shader;
}

void CreateShader::LoadShader() {
    this->m_shader = new Shader;
    if(this->m_shader->loadFromFile("File/Shader/" + file, Shader::Fragment)){
        cout <<"Is Load Shader :)" << endl;
    }
    if (!this->m_shader->isAvailable()) {
        std::cout << "The shader is not available\n";
    }
}

void CreateShader::update(Clock clk) {
    this->m_shader->setParameter("time", clk.getElapsedTime().asSeconds());
}