#include "Code/GameEngine.h"

int main()
{
    ShowWindow(GetConsoleWindow(), SW_HIDE); // Убирает консоль
    GameEngine game;
    game.run();
    return 0;
}
