#ifndef GAMEENGINE_MAINMENU_H
#define GAMEENGINE_MAINMENU_H

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class MainMenu {
public:
    MainMenu();
    ~MainMenu();

    void show();
private:
    RenderWindow *window;
    int selection_index;
    float game_time;
    Clock clock;
    //
    void update();
    //
    void render();
    //
    void pollEvents();
    //
    bool isRunning();
    // intialize the RenderWindow.
    void initWindow();
    void initText();
    void initSounds();
    //
};


#endif //GAMEENGINE_MAINMENU_H
