cmake_minimum_required(VERSION 3.25)
project(GameEngine_Brought)

set(CMAKE_CXX_STANDARD 17)

add_executable(GameEngine_Brought main.cpp Code/GameEngine.cpp Code/GameEngine.h Code/Player/Player.cpp
        Code/Player/Player.h Code/Entity.cpp Code/Entity.h Code/Enemy/Enemy.cpp Code/Enemy/Enemy.h Code/MainMenu.cpp
        Code/MainMenu.h "Code/Enemy/Enemy Ghost/Enemy_Ghost.cpp" "Code/Enemy/Enemy Ghost/Enemy_Ghost.h"
        "Code/Enemy/Enemy Scelet/Enemy_Scelet.cpp" "Code/Enemy/Enemy Scelet/Enemy_Scelet.h"
        Code/Config.cpp Code/Config.h Code/Image/CreateImage.cpp Code/Image/CreateImage.h Code/Items/Item.cpp
        Code/Items/Item.h Code/Map/GameLvL.cpp Code/Map/GameLvL.h "Code/ Animation/Animation.cpp" "Code/ Animation/Animation.h"
        Code/Object/Object.cpp Code/Object/Object.h Code/Melody/m_Music.cpp Code/Melody/m_Music.h Code/Melody/s_Sound.cpp
        Code/Melody/s_Sound.h Code/Items/Key/key_item.cpp Code/Items/Key/key_item.h Code/Items/Health/health_item.cpp Code/Items/Health/health_item.h Code/Items/Equipment/equipment_item.cpp Code/Items/Equipment/equipment_item.h Code/Items/Money/money_item.cpp Code/Items/Money/money_item.h Code/Text/CreateText.cpp Code/Text/CreateText.h Code/Object/Fon/FonGame.cpp Code/Object/Fon/FonGame.h Code/Nps/Nps.cpp Code/Nps/Nps.h Code/Nps/Aiden/Aiden.cpp Code/Nps/Aiden/Aiden.h Code/Nps/Blacksmith/Blacksmith.cpp Code/Nps/Blacksmith/Blacksmith.h Code/Nps/Historian/Historian.cpp Code/Nps/Historian/Historian.h Code/Nps/Knight/Knight.cpp Code/Nps/Knight/Knight.h Code/Nps/Soothsayer/Soothsayer.cpp Code/Nps/Soothsayer/Soothsayer.h Code/Nps/Supreme_Wizard/Supreme_Wizard.cpp Code/Nps/Supreme_Wizard/Supreme_Wizard.h Code/Nps/Swordsman/Swordsman.cpp Code/Nps/Swordsman/Swordsman.h Code/Nps/Witcher/Witcher.cpp Code/Nps/Witcher/Witcher.h Code/Nps/NpsMessage/getNpsMessage.cpp Code/Nps/NpsMessage/getNpsMessage.h Code/Player/LifeBar/LifeBar.cpp Code/Player/LifeBar/LifeBar.h Code/Particle/ParticleSystem.h)

set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc ")

set(SFML_STATIC_LIBRARIES TRUE)

set(SFML_DIR "E:\\programm\\SFML-2.5.1\\lib\\cmake\\SFML")

target_link_libraries(GameEngine_Brought sfml-graphics sfml-audio sfml-network)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_nodules")

find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)


