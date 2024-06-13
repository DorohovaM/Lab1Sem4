#include "Contribution.h"
#pragma once
#include <iostream>
using namespace std;

int Contribution_test() {

    Contribution test1;
	int debt = 0;
    cout << "Enter starting balance, percent, period in years and avalibility to deposit and withdraw" << endl;
    cin >> test1;
    cout << endl;

    cout << "You have entered: " << endl << test1 << endl;
    cout << endl;
    
	cout << "Enter the amount to add to the deposit: " << endl;
	cin >> debt;
	test1 = test1 + debt;

	cout << "Your contribution now:" << endl << test1 << endl;
	cout << endl;

	cout << "Enter the amount to withdraw from the deposit: " << endl;
	cin >> debt;
	test1 = test1 - debt;

	cout << "Your contribution now:" << endl << test1 << endl;
	cout << endl;

	return 0;
}