#pragma once
#include <iostream>
#include <string>
using namespace std;


class Password
{
	string pass;

public:

	Password();
	Password(string pass0);

	int security_level();

	bool operator==(Password& pass0);
	bool operator!=(Password& pass0);

	friend ostream& operator<<(ostream& os, const Password& pass0);
	friend istream& operator>>(istream& is, Password& pass0);
};

Password::Password() {

	pass = "";
}

Password::Password(string pass0) {

	pass = pass0;
}

int Password::security_level() {

	int lvl = 0;
	int length = pass.size();
	bool numbers = false, lower = false, upper = false, special = false;
	const string specials{ "!@#$%^&*()-_=+<>?/""'[]{}\\|" };

	for (int i = 0; i < length; i++) {

		if (pass[i] >= '0' and pass[i] <= '9')
			numbers = true;

		if (pass[i] >= 'a' and pass[i] <= 'z')
			lower = true;

		if (pass[i] >= 'A' and pass[i] <= 'Z')
			upper = true;

		if (specials.find(pass[i]) != string::npos)
			special = true;
	}

	if (numbers)
		lvl++;
	if (lower)
		lvl++;
	if (upper)
		lvl++;
	if (special)
		lvl++;
	if (length >= 8)
		lvl++;
	
	return lvl;
}

bool Password::operator==(Password& pass0) {

	if (pass == pass0.pass)
		return true;
	return false;
}

bool Password::operator!=(Password& pass0) {

	if (pass != pass0.pass)
		return true;
	return false;
}

ostream& operator<<(ostream& os, const Password& pass0) {

	os << "Your password is: " << pass0.pass << endl;
	return os;
}

istream& operator>>(istream& is, Password& pass0) {

	is >> pass0.pass;
	return is;
};