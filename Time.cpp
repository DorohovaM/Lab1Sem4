#include "Time.h"

int time_test()
{
    Time test1, test2;
    cout << "Enter the time in 24-x format in hours, minutes, seconds." << endl;
    cin >> test1;
    cout << "Enter another time in 24-x format in hours, minutes, seconds." << endl;
    cin >> test2;
    cout << endl;

    cout << "You have entered: " << test1 << endl << test2 << endl;

    cout << "12 hour format:" << endl;
    test1.to_ampm();
    cout << test1 << endl;
    test2.to_ampm();
    cout << test2 << endl;

    test1.to_standart();

    cout << "time1 + time2 = " << endl;
    Time timeAdd = test1 + test2;
    cout << timeAdd << endl;

    cout << "time1 += time2 = " << endl;
    test1 += test2;
    cout << test1 << endl;

    cout << "time1 - time2 = " << endl;
    Time timeSub = test1 - test2;
    cout << timeSub << endl;

    cout << "time1 -= time2 = " << endl;
    test1 -= test2;
    cout << test1 << endl;

    cout << "Is time1 < time2?" << endl << (test1 < test2) << endl;
    cout << "Is time1 > time2?" << endl << (test1 > test2) << endl;
    cout << "Is time1 == time2?" << endl << (test1 == test2) << endl;
    cout << "Is time1 != time2?" << endl << (test1 != test2) << endl;

    return 0;
}