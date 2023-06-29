//
// Created by Doni on 29.06.2023.
//

#include "getNpsMessage.h"

string getNpsMessage(int Click, int numLvL, string Name){
    string TextNps;
    if(Name == "Aiden"){
        if(numLvL == 1){
            switch (Click) {
                case 1: TextNps = "Hello wanderer,\nwhat brings you to this place"; break;
                case 2: TextNps = "My name is Aiden,\nand I am a local herbalist";break;
                case 3: TextNps = "If you don't want \nanything, you're free"; break;
            }
        }
        else if(numLvL == 2){
            switch (Click) {
                case 1: TextNps = "Hello wanderer,\nwhat brings you to this place"; break;
                case 2: TextNps = "My name is Aiden,\nand I am a local herbalist";break;
                case 3: TextNps = "If you don't want \nanything, you're free"; break;
            }
        } else if(numLvL == 3){
            switch (Click) {
                case 1: TextNps = "Hello wanderer,\nwhat brings you to this place"; break;
                case 2: TextNps = "My name is Aiden,\nand I am a local herbalist";break;
                case 3: TextNps = "If you don't want \nanything, you're free"; break;
            }
        }
    }
    if(Name == " "){
        if(numLvL == 1){
            switch (Click) {
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    break;
            }
        }
    }
    return TextNps;
}