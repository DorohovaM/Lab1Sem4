#pragma once
#include <iostream>
using namespace std;


class RGB
{
	int r, g, b;

public:

	RGB();
	RGB(int r0, int g0, int b0);

	void RGB_Clamp();
	bool is_correct();

	bool operator==(RGB& color);
	bool operator!=(RGB& color);

	friend ostream& operator<<(ostream& os, const RGB& color);
	friend istream& operator>>(istream& is, RGB& color);

};

int Clamp(int x) {
	if (x > 255)
		x = 255;
	if (x < 0)
		x = 0;
	return x;
}

RGB::RGB() {

	r = g = b = 0;
}

RGB::RGB(int r0, int g0, int b0) {

	r = r0;
	g = g0;
	b = b0;
}

void RGB::RGB_Clamp() {

	r = Clamp(r);
	g = Clamp(g);
	b = Clamp(b);
}

bool RGB::is_correct() {

	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return false;
	return true;
}

bool RGB::operator==(RGB& color) {

	if (r == color.r && g == color.g && b == color.b)
		return true;
	return false;
}

bool RGB::operator!=(RGB& color) {

	if (r != color.r || g != color.g || b != color.b)
		return true;
	return false;
}

ostream& operator<<(ostream& os, const RGB& color) {

	os << "Color in RGB: (" <<color.r << ", " << color.g << ", " << color.b << ")" << endl;
	return os;
}

istream& operator>>(istream& is, RGB& color) {

	is >> color.r >> color.g >> color.b;
	return is;
};