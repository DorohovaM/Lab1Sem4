#include <iostream>
using namespace std;

int main() {

	int selectedtest = 0;
	cout << "Select a task:" << endl
		<< "1 - Matrix" << endl
		<< "2 - Time" << endl
		<< "3 - Point" << endl
		<< "4 - RGB" << endl
		<< "5 - Password" << endl
		<< "6 - Contribution" << endl
		<< "7 - Watch" << endl;
	cin >> selectedtest;

	switch (selectedtest)
	{
		case 1: {
			int matrix_test();
			matrix_test();
			break;
		}

		case 2: {
			int time_test();
			time_test();
			break;
		}
		case 3: {
			int point_test();
			point_test();
			break;
		}
		case 4: {
			int RGB_test();
			RGB_test();
			break;
		}

		case 5: {
			int Password_test();
			Password_test();
			break;
		}

		case 6: {
			int Contribution_test();
			Contribution_test();
			break;
		}

		case 7: {
			int Stopwatch_test();
			Stopwatch_test();
			break;
		}

		default:
			exit;
	}

	return 0;

}