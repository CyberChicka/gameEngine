//
// Created by Doni on 09.06.2023.
//
#include "Utils.h"
#include<array>
using namespace std;

bool arr_contains_char(char elem, char arr[]) {
    int arr_len = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < arr_len; i++) {
        if (arr[i] == elem) {
            return true;
        }
    }

    return false;
}