#pragma once
#include <iostream>
using namespace std;

class Contribution
{
	double percent, balance;
	int period;
	bool repl_wit;

public:
	Contribution();
	Contribution(double perc, double bal, int per, bool rw);

	friend Contribution& operator+(Contribution& cont, int& summ);
	friend Contribution& operator-(Contribution& cont, int& summ);

	float calc_income();

	friend ostream& operator<<(ostream& os, Contribution& cont);
	friend istream& operator>>(istream& is, Contribution& cont);
};

Contribution::Contribution()
{
	percent = balance = 0;
	period= 0;
	repl_wit = false;
}

Contribution::Contribution(double perc, double bal, int per, bool rw) {

	percent = perc;
	balance = bal;
	period = per;
	repl_wit = rw;

}

Contribution& operator+(Contribution& cont, int& summ) {

	if (cont.repl_wit)
		cont.balance += summ;
	return cont;
}

Contribution& operator-(Contribution& cont, int& summ) {

	if (cont.repl_wit)
		cont.balance -= summ;
	
	if (cont.balance <= 0)
		cont.balance = 0;

	return cont;
}

float Contribution::calc_income() {

	if (balance <= 0)
		return 0;

	float income;
	
	income = balance * (percent * period);
	return income;

}

ostream& operator<<(ostream& os, Contribution& cont) {

	os << "Balance: " << cont.balance << endl;
	os << "The percent: " << cont.percent * 100 << "%" << endl;
	os << "Period of contribution:" << cont.period << " years" << endl;

	if (cont.repl_wit)
		os << "You can deposit and withdraw money" << endl;

	os << "Expected income: " << cont.calc_income() << endl;

	return os;
}
istream& operator>>(istream& is, Contribution& cont) {

	is >> cont.balance >> cont.percent >> cont.period >> cont.repl_wit;
	cont.percent = cont.percent / 100;

	return is;

}