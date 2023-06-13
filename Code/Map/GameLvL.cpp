//
// Created by Doni on 18.05.2023.
//

#include <valarray>
#include "GameLvL.h"

GameLvL::GameLvL(sf::Sprite *sprite, int GameLvL) {
    this->s = sprite;
    this->gameLvL = GameLvL;
    this->initMap();
}
GameLvL::~GameLvL() {
    cout << "============== removed from map lvl ============"<< endl;
    delete this->s;
    delete this->MapLvL;
}

void GameLvL::initMap() {
    if(this->gameLvL == 1){
        this->MapLvL = new String[HeightMap]{
                "                                                                                                                                                                                                                                                                                                                                                        ",
                "                                                                                                                                                                                                                                                                                                                                                        ",
                "                                                                                                                                                                                                                                                                                                                                                        ",
                "                                                                                                                                                                                                                                                                                                                                                        ",
                "                                                                                                                                                                                                                                                                                                                                                        ",
                "                {===}                                                                                                                                                                                                                                                                                                                                   ",
                "                                                                                                                                                                                                                                                                                                                                                        ",
                "                                                                                                        ------                                                                                                                                                                                                                                          ",
                "    -------                                                                                                                                                                                                                                                                                                                                             ",
                "                                                                                                                                                                                                                                                                                                                                                        ",
                "                                                                                                                  -------                                                                                                                                                                                                                              ",
                "                                                                                                                                                                                                                                                                                                                                                       ",
                "                ----                                                                                                                                                                                 ---------                                                                                                                                         ",
                "                                                                                                                           ------                                                    {========}                                                                                                                                                        ",
                "                                                                                                                                                                                                                                                                                                                                                       ",
                "         ----                                                                                                                                                                                                    {============}                                                                                                                        ",
                "                                                                                                               ----------                                                                                       {..............========}                                                                                                               ",
                "                                                                                                                                                                                                               {........................=====}                                                                                                         ",
                "                                                                                                                                                                                                              {...............................======}                                                                                                  ",
                "  {=====}                                                                                             --------                                                                                               {.......................................=======}                                                                                          ",
                "  <......===}                                                    {======}                                                                                                                                  {=................................................======}                                                                                   ",
                "  <..........==}                                        {========........}                                                                                                                              {==........................................................>                                                                                   ",
                "{=..............========================================..................=====}              {=========================================================================================================............................................................=======  =========================================================================}",
                "<...............................................................................======}    {==......................................................................................................................     ..................................................  .........................................................................>",
                "<......................................................................................====.........................................................................................................................                                     .............       .........................................................................>",
                "<......................................................................................................................................................................................................................                                                      .........................................................................>",
                "<........................................................................................................................................................................................................................                                                  ...........................................................................>",
                "<........................................................................................................................................................................................................................................................             ................................................................................>",
                "<.....................................................................................................................................................................................................................................................................................................................................................>",
                "<.....................................................................................................................................................................................................................................................................................................................................................>",
        };
    }
    if(this->gameLvL == 2) {
        this->MapLvL = new String[HeightMap2]{
                "                                                                                                                                                                                                                                                                                                                                 ",
                "                                                                                                                                                                                                                                                                                                                                 ",
                "                                                                                                                                                                                                                                                                     ------                                                      ",
                "                                                                                                                                                                                                                                        -------------------                    ---------                       ------            ",
                "                                                                                                                                                                                                                                                                                                       -                         ",
                "                                                                                                                                                                                                                                                             ---                                                                 ",
                "                                                                                                                                                                                                                                                                                             ---                                 ",
                "                                                                                                                                                                                                                              ----                                                                                               ",
                "                                                                                                                                                                                                                                                                                                                                 ",
                "                                                                <==============>                                                                                                                                                                                                                                       --        ",
                "                                                                                                                                                                                                                                                                                                                                ",
                "                                                                                                                                                                                                                                      ----                                                                                      ",
                "                                                       -                                                                                                                                                                                                                                                                        ",
                "                                                                                                                                                                                                                                                                                                                                ",
                "                                                                                                                                                                                                                                                                                                                                ",
                "                                         --------                                                                                                                                                                                        ---------                                                                              ",
                "                                                                                                                                                                                                                                                                                                                                ",
                "                                                                                                                                                                                                                                                                                                                                ",
                "                                                                                                                                                                                                                                                                                                                                ",
                "                                  --                                                                                                                                                                                                                                                                                            ",
                "                                                                                                                                                                                                                               ------                                                                                           ",
                "                                                                                                                                                                                                                                                                                                                                ",
                "                                         ---                                                                                                                                                                                                                                                                                    ",
                "                                                                                                                                                                                                                                                                                                                                ",
                "                                                                                                                                                                                                                       ----                                                                                                     ",
                "                                                   --                                                                                                                                                                                                                                                                           ",
                "                                                                                                                                                                                                                                                                                                                                ",
                "                                                                                                                                                                                                                                                                                                                                ",
                "                                                          -                                                                                                                                                    ----                                                                                                             ",
                "                                                                                                                                                                                                                                                                                                                                ",
                "                                                                                                                                                                                                                                                                                                                                ",
                "                                                                                                                                                                                                                                                                                                                                ",
                "                                                        <================>                                                                                                                        <=====>                                                                                                                       ",
                "<=======================================================..................========================================================================================================================.......======================================================================================================================>",
                "<..............................................................................................................................................................................................................................................................................................................................>",
                "<..............................................................................................................................................................................................................................................................................................................................>",
                "<..............................................................................................................................................................................................................................................................................................................................>",
                "<..............................................................................................................................................................................................................................................................................................................................>",
                "<..............................................................................................................................................................................................................................................................................................................................>",
                "<..............................................................................................................................................................................................................................................................................................................................>",
                "<..............................................................................................................................................................................................................................................................................................................................>",
        };
    }
    if(this->gameLvL == 3){
        this->MapLvL = new String[HeightMap3]{
                "                                                                                                                                                                                                                                                             ==",
                "                                                                                                                                                                                                                                                              ",
                "                                                                                                                                                                                                                                                              ",
                "                                                                                                                                                                                                                                                              ",
                "                                                                                                                                                                                                                                                              ",
                "                                                                                                                                                                                                                                                              ",
                "                                                                                                                                                                                                                                                              ",
                "                                                                                                                                                                                                                                                              ",
                "                                                                                                                                                                                                                                                              ",
                "                                                                                                                                                                                                                                                              ",
                "                                                                                                                                                                                                                                                              ",
                "                                                                                                                                                                                                                                                              ",
                "                                                                                                                                                                                                                                                              ",
                "                                                                                                                                                                                                                                                              ",
                "                                                                                                                                                                                                                                                              ",
                "                                                                                                                                                                                                                                                              ",
                "                                                                                                                                                                                                                                                              ",
                "                                                                                                                                                                                                                                                              ",
                "                                                                                                                                                                                                                                                              ",
                "                                                                                                                                                                                                                                                              ",
                "                                                                                                                                                                                                                                                              ",
                "                                                                                                                                                                                                                                                              ",
                "{============================================================================================================================================================================================================================================================}",
                "<............................................................................................................................................................................................................................................................>",
                "<............................................................................................................................................................................................................................................................>",
                "<............................................................................................................................................................................................................................................................>",
                "<............................................................................................................................................................................................................................................................>",
                "<............................................................................................................................................................................................................................................................>",
                "<............................................................................................................................................................................................................................................................>",
                "<............................................................................................................................................................................................................................................................>",
        };
    }
}
void GameLvL::setSprite(Sprite *sprite){
    this->s = sprite;
}


void GameLvL::RenderDraw(sf::RenderWindow &window, View view) {
    if(this->gameLvL == 1){
        for (int i = 0; i < this->HeightMap; i++)
            for (int j = 0; j < this->WitchMap; j++) {
                this->dist = sqrt((s->getPosition().x - view.getCenter().x)*(s->getPosition().x - view.getCenter().x) + (s->getPosition().y - view.getCenter().y)*(s->getPosition().y - view.getCenter().y));
                this->s->setPosition(j * 32, i * 32);
                if(this->dist < window.getSize().x){
                    switch (this->MapLvL[i][j]) {
                        case ' ':this->s->setTextureRect(IntRect(270, 0, w_Block, h_Block)); break;
                        case '=':this->s->setTextureRect(IntRect(68, 0, w_Block, h_Block));break;
                        case '}':this->s->setTextureRect(IntRect(101, 0, w_Block, h_Block)); break;
                        case '{':this->s->setTextureRect(IntRect(34, 0, w_Block, h_Block)); break;
                        case '<':this->s->setTextureRect(IntRect(133, 0, w_Block, h_Block)); break;
                        case '.':this->s->setTextureRect(IntRect(164, 0, w_Block, h_Block)); break;
                        case '>':this->s->setTextureRect(IntRect(196, 0, w_Block, h_Block));break;
                        case '-':this->s->setTextureRect(IntRect(230, 0, w_Block, h_Block));break;
                    }
                    window.draw(*this->s);
                }
            }
    }
    else if(this->gameLvL == 2){
        for (int i = 0; i < this->HeightMap2; i++)
            for (int j = 0; j < this->WitchMap2; j++) {
                switch (this->MapLvL[i][j]) {
                    case ' ':this->s->setTextureRect(IntRect(270, 0, w_Block, h_Block)); break;
                    case '=':this->s->setTextureRect(IntRect(68, 0, w_Block, h_Block));break;
                    case '}':this->s->setTextureRect(IntRect(101, 0, w_Block, h_Block)); break;
                    case '{':this->s->setTextureRect(IntRect(34, 0, w_Block, h_Block)); break;
                    case '<':this->s->setTextureRect(IntRect(133, 0, w_Block, h_Block)); break;
                    case '.':this->s->setTextureRect(IntRect(164, 0, w_Block, h_Block)); break;
                    case '>':this->s->setTextureRect(IntRect(196, 0, w_Block, h_Block));break;
                    case '-':this->s->setTextureRect(IntRect(230, 0, w_Block, h_Block));break;
                }
                this->s->setPosition(j * 32, i * 32);
                window.draw(*this->s);
            }
    }
    else if(this->gameLvL == 3){
        for (int i = 0; i < this->HeightMap3; i++)
            for (int j = 0; j < this->WitchMap3; j++) {
                switch (this->MapLvL[i][j]) {
                    case ' ':this->s->setTextureRect(IntRect(270, 0, w_Block, h_Block));break;
                    case '=':this->s->setTextureRect(IntRect(68, 0, w_Block, h_Block));break;
                    case '}':this->s->setTextureRect(IntRect(101, 0, w_Block, h_Block));break;
                    case '{':this->s->setTextureRect(IntRect(34, 0, w_Block, h_Block));break;
                    case '<':this->s->setTextureRect(IntRect(133, 0, w_Block, h_Block));break;
                    case '.':this->s->setTextureRect(IntRect(164, 0, w_Block, h_Block));break;
                    case '>':this->s->setTextureRect(IntRect(196, 0, w_Block, h_Block));break;
                    case '-':this->s->setTextureRect(IntRect(230, 0, w_Block, h_Block));break;
                }
                this->s->setPosition(j * 32, i * 32);
                window.draw(*this->s);
            }
    }
    else{

    }
}