//
// Created by Doni on 29.06.2023.
//

#include "getNpsMessage.h"

string getNpsMessage(int Click, int numLvL, string Name){
    string TextNps = " ";
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
        else{
            switch (Click) {
                case 1: TextNps = "Hello wanderer,\nwhat brings you to this place"; break;
                case 2: TextNps = "My name is Aiden,\nand I am a local herbalist";break;
                case 3: TextNps = "If you don't want \nanything, you're free"; break;
            }
        }
    }
    if(Name == "Historian"){
        if(numLvL == 1){
            switch (Click) {
                case 1: TextNps = "Hello Geralt"; break;
                case 2: TextNps = "My name is Historian"; break;
                case 3: TextNps = "Ask me how you got here\nand how I know you"; break;
                case 4: TextNps = "I'd tell you everything, but if I did,\nI don't think your head could take it."; break;
                case 5: TextNps = "You have to gradually become aware\nof everything that is going on"; break;
                case 6: TextNps = "I'll tell you one thing, Witch!\nShe has swallowed your memory."; break;
            }
        }
        else if(numLvL == 2){
            switch (Click) {
                case 1: TextNps = "Hello wanderer,\nwhat brings you to this place"; break;
                case 2: TextNps = "Hello wanderer,\nwhat brings you to this place"; break;
                case 3: TextNps = "Hello wanderer,\nwhat brings you to this place"; break;
            }
        }
        else if(numLvL == 3){
            switch (Click) {
                case 1: TextNps = "Hello wanderer,\nwhat brings you to this place"; break;
                case 2: TextNps = "Hello wanderer,\nwhat brings you to this place"; break;
                case 3: TextNps = "Hello wanderer,\nwhat brings you to this place"; break;
            }
        }
    }
    if(Name == "Witcher"){
        if(numLvL == 1){
            switch (Click) {
                case 1: TextNps = "Hello Stranger!"; break;
                case 2: TextNps = "I see that you are here"; break;
                case 3: TextNps = "What is your name?"; break;
                case 4: TextNps = "Geralt is an unusual name"; break;
                case 5: TextNps = "If you need anything Geralt, \nplease contact me"; break;
                case 6: TextNps = "For a certain amount, \nI can improve equipment :)"; break;
                case 7: TextNps = "1 - Upgrade for 10 coins\n"
                                  "2 - Leave"; break;
            }
        }
    }
    if(Name == "Blacksmith"){
        if(numLvL == 1){
            switch (Click) {
                case 1: TextNps = "Hello Stranger!"; break;
                case 2: TextNps = "I see that you are here"; break;
                case 3: TextNps = "What is your name?"; break;
                case 4: TextNps = "Geralt is an unusual name"; break;
                case 5: TextNps = "If you need anything Geralt, \nplease contact me"; break;
                case 6: TextNps = "For a certain amount, \nI can improve equipment :)"; break;
                case 7: TextNps = "1 - Upgrade for 10 coins\n"
                                  "2 - Leave"; break;
            }
        }
        else if(numLvL == 2){
            switch (Click) {
                case 1: TextNps = "O! Lumberjack, you're here, too"; break;
                case 2: TextNps = "If you need anything, please contact me"; break;
                case 3: TextNps =  "1 - Upgrade for 10 coins\n"
                                   "2 - Leave"; break;
            }
        }
    }
    return TextNps;
}