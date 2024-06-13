#pragma once
#include <iostream>
#include <string>
using namespace std;

class Time
{
	int hours, mins, secs;
	bool is_pm, format;

public:

	Time();
	Time(int hours0, int mins0, int secs0, bool format0, bool is_pm0);

	void to_ampm();
	void to_standart();
	bool getPM();

	Time operator+(Time& time0);
	Time operator+= (Time& time0);
	Time operator-(Time& time0);
	Time operator-= (Time& time0);

	bool operator<(Time& time0);
	bool operator>(Time& time0);
	bool operator==(Time& time0);
	bool operator!=(Time& time0);

	friend ostream& operator<<(ostream& os, const Time& time0);
	friend istream& operator>>(istream& is, Time& time0);

};

Time::Time()
{
	hours = mins = secs = 0;
	is_pm = format = false;
}

Time::Time(int hours0, int mins0, int secs0, bool format0, bool is_pm0)
{
	hours = hours0;
	mins = mins0;
	secs = secs0;
	format = format0;
	is_pm = is_pm0;
}

void Time::to_ampm() {

	if (!format) {
		if (hours > 12) {
			is_pm = true;
			hours = hours - 12;
		}
		else
			is_pm = false;
		format = true;
	}

}

void Time::to_standart() {

	if (format and is_pm)
		hours = hours + 12;
	format = false;
}

bool Time::getPM() {
	return is_pm;
}

//void CheckingThePeriod(int house, int minute, int second) {
//
//	//int optMinutes = 0;
//	if (second >= 60)
//	{
//		minute += second / 60;
//		second %= 60;
//	}
//	//int opthouse = 0;
//	if (minute >= 60) {
//		house += minute / 60;
//		minute %= 60;
//	}
//	if (house >= 24) {
//		house %= 24;
//	}

Time Time::operator+(Time& time0) {

	Time result = *new Time();
	int add_m = 0, add_h = 0;
	bool format0 = format, format1 = time0.format;

	if (format)
		to_standart();

	if (format1)
		time0.to_standart();

	result.secs = secs + time0.secs;
	if (result.secs >= 60) {
		add_m += 1;
		result.secs -= 60;
	}

	result.mins = mins + time0.mins + add_m;
	if (result.mins >= 60) {
		add_h += 1;
		result.mins -= 60;
	}

	result.hours = hours + time0.hours + add_h;
	if (result.hours >= 24)
		result.hours -= 24;

	if (format0)
		to_ampm();

	if (format1)
		time0.to_ampm();

	return result;
}

Time Time::operator+=(Time& time0) {

	Time result = *new Time();
	int add_m = 0, add_h = 0;
	bool format0 = format, format1 = time0.format;

	if (format)
		to_standart();

	if (format1)
		time0.to_standart();

	result.secs = secs + time0.secs;
	if (result.secs >= 60) {
		add_m += 1;
		result.secs -= 60;
	}

	result.mins = mins + time0.mins + add_m;
	if (result.mins >= 60) {
		add_h += 1;
		result.mins -= 60;
	}

	result.hours = hours + time0.hours + add_h;
	if (result.hours >= 24)
		result.hours -= 24;

	if (format0)
		to_ampm();

	if (format1)
		time0.to_ampm();

	return result;
}

Time Time::operator-(Time& time0) {

	Time result = *new Time();
	int add_m = 0, add_h = 0;
	bool format0 = format, format1 = time0.format;

	if (format)
		to_standart();

	if (format1)
		time0.to_standart();

	result.secs = secs - time0.secs;
	if (result.secs < 0) {
		add_m += -1;
		result.secs += 60;
	}

	result.mins = mins - time0.mins + add_m;
	if (result.mins < 60) {
		add_h += -1;
		result.mins += 60;
	}

	result.hours = hours - time0.hours + add_h;
	if (result.hours < 0)
		result.hours += 24;

	if (format0)
		to_ampm();

	if (format1)
		time0.to_ampm();

	return result;
}

Time Time::operator-=(Time& time0) {

	Time result = *new Time();
	int add_m = 0, add_h = 0;
	bool format0 = format, format1 = time0.format;

	if (format)
		to_standart();

	if (format1)
		time0.to_standart();

	result.secs = secs - time0.secs;
	if (result.secs < 0) {
		add_m += -1;
		result.secs += 60;
	}

	result.mins = mins - time0.mins + add_m;
	if (result.mins < 60) {
		add_h += -1;
		result.mins += 60;
	}

	result.hours = hours - time0.hours + add_h;
	if (result.hours < 0)
		result.hours += 24;

	if (format0)
		to_ampm();

	if (format1)
		time0.to_ampm();

	return result;
}

bool Time::operator<(Time& time0) {

	bool format0 = format, format1 = time0.format;

	if (format)
		to_standart();

	if (format1)
		time0.to_standart();

	bool result = false;

	if (hours < time0.hours)
		result = true;
	else if (hours == time0.hours) 
		if (mins < time0.mins)
			result = true;
		else if (mins == time0.mins)
			if (secs < time0.secs)
				result = true;
	
	if (format0)
		to_ampm();

	if (format1)
		time0.to_ampm();

	return result;
}

bool Time::operator>(Time& time0) {

	bool format0 = format, format1 = time0.format;

	if (format)
		to_standart();

	if (format1)
		time0.to_standart();

	bool result = false;

	if (hours > time0.hours)
		result = true;
	else if (hours == time0.hours)
		if (mins > time0.mins)
			result = true;
		else if (mins == time0.mins)
			if (secs > time0.secs)
				result = true;

	if (format0)
		to_ampm();

	if (format1)
		time0.to_ampm();

	return result;
}

bool Time::operator==(Time& time0) {

	bool format0 = format, format1 = time0.format;

	if (format)
		to_standart();

	if (format1)
		time0.to_standart();

	bool result = false;
	if (hours == time0.hours and mins == time0.mins and secs == time0.secs)
		result = true;

	if (format0)
		to_ampm();

	if (format1)
		time0.to_ampm();

	return result;

}

bool Time::operator!=(Time& time0) {

	bool format0 = format, format1 = time0.format;

	if (format)
		to_standart();

	if (format1)
		time0.to_standart();

	bool result = true;
	if (hours == time0.hours and mins == time0.mins and secs == time0.secs)
		result = false;

	if (format0)
		to_ampm();

	if (format1)
		time0.to_ampm();

	return result;
}

ostream& operator<<(std::ostream& os, const Time& time0) {

	string out_string = "";

	if (time0.hours < 10)
		out_string += "0";
	out_string += to_string(time0.hours) + ":";
	if (time0.mins < 10)
		out_string += "0";
	out_string += to_string(time0.mins) + ":";
	if (time0.secs < 10)
		out_string += "0";
	out_string += to_string(time0.secs) + " ";

	if (time0.format) {
		if (time0.is_pm) {
			out_string += " pm";
		}
		else {
			out_string += " am";
		}
	}
	os << out_string << endl;

	return os;
}
istream& operator>>(std::istream& is, Time& time0)
{
	is >> time0.hours >> time0.mins >> time0.secs;

	if (time0.secs >= 60) {
		time0.mins += (time0.secs / 60);
		time0.secs %= 60;
	}
	else if (time0.secs < 0)
		time0.secs = 0;
	if (time0.mins >= 60) {
		time0.hours += (time0.mins / 60);
		time0.secs %= 60;
	}
	else if (time0.mins < 0)
		time0.mins = 0;
	if (time0.hours >= 24)
		time0.hours %= 24;
	else if (time0.hours < 0)
		time0.hours = 0;

	return is;
}


