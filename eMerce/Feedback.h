#ifndef _FEEDBACK_H
#define _FEEDBACK_H

#include<string.h>
#include<string>
#include "Date.h"

class Customer;

class Feedback {
private:
	const Customer* m_customer;
	Date m_date;
	std::string m_comment;

public:
	Feedback(const Customer& customer, const Date& date,const std::string& commnet);
	Feedback(const Feedback& other) = delete;

	bool setCustomer(const Customer& customer);
	bool setDate(const Date& date);
	bool setComment(const std::string& comment);
	  
	const Customer* getCustomer()const;
	const Date& getDate()const;
	const std::string& getComment()const;

	friend std::ostream& operator<<(std::ostream& os,const Feedback& feedback);
};

#endif // !_FEEDBACK_H
