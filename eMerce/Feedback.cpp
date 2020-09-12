#include "Feedback.h"
#include"Customer.h"

Feedback::Feedback(const Customer & customer, const Date & date, const std::string& commnet) : m_date(date)
{
	setCustomer(customer);
	setComment(commnet);
}

bool Feedback::setCustomer(const Customer & customer)
{
	m_customer = &customer;
	return true;
}

bool Feedback::setDate(const Date & date)
{
	m_date = date;
	return true;
}

bool Feedback::setComment(const std::string& comment)
{
	if (comment.begin()==comment.end())
		return false;
	m_comment = comment;
	return true;
}

const Customer * Feedback::getCustomer() const
{
	return m_customer;
}

const Date & Feedback::getDate() const
{
	return m_date;
}

const std::string& Feedback::getComment() const
{
	return m_comment;
}

std::ostream & operator<<(std::ostream & os, const Feedback & feedback)
{
	std::cout << "Date: ";
	feedback.getDate().show();
	std::cout << "\nCustomer Name: " << feedback.getCustomer()->getUserName()
		<< "\nComment: " << feedback.getComment();
	return os;
}
