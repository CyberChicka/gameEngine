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
        Code/Melody/s_Sound.h Code/Items/Key/key_item.cpp Code/Items/Key/key_item.h Code/Items/Health/health_item.cpp Code/Items/Health/health_item.h Code/Items/Equipment/equipment_item.cpp Code/Items/Equipment/equipment_item.h Code/Items/Money/money_item.cpp Code/Items/Money/money_item.h Code/Utils.cpp Code/Utils.h Code/Text/CreateText.cpp Code/Text/CreateText.h)

set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc ")

set(SFML_STATIC_LIBRARIES TRUE)

set(SFML_DIR "E:\\programm\\SFML-2.5.1\\lib\\cmake\\SFML")

target_link_libraries(GameEngine_Brought sfml-graphics sfml-audio sfml-network)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_nodules")

find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)


