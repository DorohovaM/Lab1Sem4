#include "Point.h"
#include <iostream>
using namespace std;

int point_test()
{
    Point test1, test2;
    cout << "Enter the x and y for the point" << endl;
    cin >> test1;
    cout << "Enter another x and y for the point" << endl;
    cin >> test2;
    cout << endl;

    cout << "You have entered: " << endl << test1 << endl << test2 << endl;
    
    cout << "Is point1 == point2?" << endl << (test1 == test2) << endl;
    cout << "Is point1 != point2?" << endl << (test1 != test2) << endl;

    cout << "In what quater is the first point?" << endl << test1.coord_quarter() << endl;

    double k, b;
    cout << "Enter k and b for line y = kx + b" << endl;
    cin >> k >> b;
    cout << endl;

    if (test1.on_straight_line(k, b))
        cout << "The first point lies on a straight line" << endl;
    if (test1.above_straight_line(k, b))
        cout << "The first point lies above the straight line" << endl;
    if (test1.under_straight_line(k, b))
        cout << "The first point lies under a straight line" << endl;

    return 0;
}