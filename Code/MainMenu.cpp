
#include "MainMenu.h"


MainMenu::MainMenu() {
    selection_index = 0;
    initWindow();
    initText();
    initSounds();
}
MainMenu::~MainMenu() {
    if (window != nullptr) delete window;
}

bool MainMenu::isRunning() {
    if (window == nullptr) return false;
    else return window->isOpen();
}

void MainMenu::pollEvents() {

    sf::Event event;
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        }
//        if (event.type == sf::Event::KeyPressed) {
//            if (event.key.code == sf::Keyboard::Up) {
//                if (selection_index > 0) selection_index--;
//            } else if (event.key.code == sf::Keyboard::Down) {
//                if (selection_index < 2) selection_index++;
//            } else if (event.key.code == sf::Keyboard::Enter || event.key.code == sf::Keyboard::Space) {
//                okey->play();
//
//                while (okey->getStatus() == sf::Sound::Status::Playing) {
//                    sf::sleep(sf::milliseconds(10));
//                }
//
//                switch (selection_index) {
//                    case 0:
//                        Config::getInstance()->selected_map = Config::getInstance()->maps["single-player"];
//                        window->close();
//                        break;
//                    case 1:
//                        Config::getInstance()->selected_map = Config::getInstance()->maps["dual-player"];
//                        window->close();
//                        break;
//                    case 2: exit(1);
//                }
//            }
//        }
    }
}

void MainMenu::update() {
    pollEvents();

}

void MainMenu::render(){
    window->clear();


    window->display();
}

void MainMenu::initWindow() {
    // для начало используем это способ, потом через настройки будем изменять размер
    const sf::VideoMode videoMode = sf::VideoMode(800, 600);
    const string GameTitle = "MainMenu";
    const sf::Uint32 style = sf::Style::Close | sf::Style::Titlebar;

    // Создание окна, верт. синх., 120 фпс
    window = new sf::RenderWindow(videoMode, GameTitle, style);
    window->setFramerateLimit(120);
    window->setVerticalSyncEnabled(true);


}

void MainMenu::initText() {

}

void MainMenu::initSounds() {

}

void MainMenu::show() {
    while (isRunning()) {
        update();
        render();
    }
}
