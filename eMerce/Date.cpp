#include "Date.h"

Date::Date(unsigned int day, unsigned int month, unsigned int year)
{
	setDay(day);
	setMonth(month);
	setYear(year);
}

Date::Date(const Date & other)
{
	m_day = other.m_day;
	m_month = other.m_month;
	m_year = other.m_year;
}

unsigned int Date::getDay() const
{
	return m_day;
}

unsigned int Date::getMonth() const
{
	return m_month;
}

unsigned int Date::getYear() const
{
	return m_year;
}

bool Date::setDay(unsigned int day)
{
	if (day < 1 || day > 31)
		return false;
	m_day = day;
	return true;
	
}

bool Date::setMonth(unsigned int month)
{
	if (month < 1 || month > 12)
		return false;
	m_month = month;
	return true;
}

bool Date::setYear(unsigned int year)
{
	if (year!=2020)
		return false;
	m_year = year;
	return true;
}

void Date::show() const
{
	std::cout << "Date: " << getDay() << "/" << getMonth() << "/" << getYear();

}
