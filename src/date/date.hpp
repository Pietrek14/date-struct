#pragma once

#include <istream>
#include <ostream>

struct Date {
	int day;
	int month;
	int year;
};

std::ostream& operator<<(std::ostream& os, const Date& d);
std::istream& operator>>(std::istream& is, Date& d);

// Excluding the end day. (Wylaczajac ostatni dzien)
int operator-(const Date& date1, const  Date& date2);
Date& operator++(Date& date, int unused);

bool operator==(const Date& date1, const Date& date2);
bool operator<(const Date& date1, const Date& date2);
bool operator>(const Date& date1, const Date& date2);