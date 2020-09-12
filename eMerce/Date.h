#ifndef _DATE_H
#define _DATE_H
#pragma warning(disable: 4996)

#include<iostream>

class Date {
private:
	unsigned int m_day;
	unsigned int m_month;
	unsigned int m_year;

public:
	Date(unsigned int day, unsigned int month, unsigned int year);
	Date(const Date& other);

	unsigned int getDay()	const;
	unsigned int getMonth()	const;
	unsigned int getYear()	const;

	bool setDay(unsigned int day);
	bool setMonth(unsigned int month);
	bool setYear(unsigned int year);

	void show() const;
};

#endif // !_DATE_H

