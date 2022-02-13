#include "date.hpp"

std::ostream& operator<<(std::ostream& os, const Date& d) {
	os << (d.day < 10 ? "0" : "") << d.day << "-" << (d.month < 10 ? "0" : "") << d.month << "-" << d.year;
	return os;
}

std::istream& operator>>(std::istream& is, Date& d) {
	is >> d.day >> d.month >> d.year;
	return is;
}

bool isLeapYear(int year) {
	return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

/**
 * @brief Calculates the number of leap years before the given year (excluding the given year). Leap years are years divisible by 4, except years divisible by 100 unless they are also divisible by 400.
 * 
 * @param year The year to calculate the number of leap years before.
 * @return The number of leap years before the given year.
 */
int leapYearsBefore(int year) {
	int result = year / 4 - year / 100 + year / 400;

	if(isLeapYear(year))
		result--;

	return result;
}

/// @brief Calculates the number of days in a given month. Ignores leap years.
/// @param month The month to calculate the number of days in.
int daysInMonth(int month) {
	if(month == 2)
		return 28;

	if(month <= 7) {
		if(month % 2 == 0)
			return 30;
		else
			return 31;
	}

	if(month % 2 == 0)
		return 31;
	
	return 30;
}

int daysInMonthWithLeapYears(int month, int year) {
	if(month == 2 && isLeapYear(year))
		return 29;
	
	return daysInMonth(month);
}

long long daysFromDate(const Date& d) {
	long long days = d.year * 365 + leapYearsBefore(d.year);

	for(int i = 1; i < d.month; i++)
		days += daysInMonthWithLeapYears(i, d.year);

	days += d.day;
	return days;
}

Date& operator++(Date& date, int unused) {
	Date copy = date;

	if(date.day == daysInMonthWithLeapYears(date.month, date.year)) {
		date.day = 1;
		if(date.month == 12) {
			date.month = 1;
			date.year++;
		} else
			date.month++;
	} else
		date.day++;

	return copy;
}

int operator-(const Date& date1, const  Date& date2) {
	return daysFromDate(date1) - daysFromDate(date2);
}

bool operator==(const Date& date1, const Date& date2) {
	return date1.day == date2.day && date1.month == date2.month && date1.year == date2.year;
}

bool operator<(const Date& date1, const Date& date2) {
	return daysFromDate(date1) < daysFromDate(date2);
}

bool operator>(const Date& date1, const Date& date2) {
	return daysFromDate(date1) > daysFromDate(date2);
}