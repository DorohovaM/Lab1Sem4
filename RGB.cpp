#include "RGB.h"
#pragma once
#include <iostream>
using namespace std;

int RGB_test() {

    RGB test1, test2;
    cout << "Enter color in RGB (r, g, b)" << endl;
    cin >> test1;
    cout << "Enter another color in RGB (r, g, b)" << endl;
    cin >> test2;
    cout << endl;

    cout << "You have entered: " << endl << test1 << endl << test2 << endl;

    cout << "Is color1 correct?" << endl << test1.is_correct() << endl;
    cout << "Is color2 correct?" << endl << test2.is_correct() << endl;

    if (!test1.is_correct())
        test1.RGB_Clamp();
    if (!test2.is_correct())
        test2.RGB_Clamp();

    cout << "Is color1 == color2?" << endl << (test1 == test2) << endl;
    cout << "Is color1 != color2?" << endl << (test1 != test2) << endl;

    return 0;
}