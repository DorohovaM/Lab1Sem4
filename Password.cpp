#include "Password.h"
#pragma once
#include <iostream>
#include <string>
using namespace std;

int Password_test() {

    Password test1, test2;
    cout << "Enter your password" << endl;
    cin >> test1;
    cout << "Enter another password" << endl;
    cin >> test2;
    cout << endl;

    cout << "You have entered: " << endl << test1 << endl << test2 << endl;
    cout << endl;

    cout << "Is password1 == password2?" << endl << (test1 == test2) << endl;
    cout << "Is password1 != password2?" << endl << (test1 != test2) << endl;
    cout << endl;

    cout << "Level of the first password: " << endl << test1.security_level() << endl;
    cout << "Level of the second password: " << endl << test2.security_level() << endl;

    return 0;
}
