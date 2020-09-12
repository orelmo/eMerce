#include "Seller.h"
#include"Feedback.h"
#include"Product.h"

Seller::Seller(const std::string& username, const std::string& password, const Address& address) : User(username, password, address), m_feedbackArr(0,'\n')
{}

Seller:: ~Seller()
{
	for (auto a: m_productArr)
		delete a;
}

bool Seller::addProduct(Product & product)
{
	m_productArr.push_back(&product);
	return true;
}

bool Seller::addFeedback( Feedback & feedback)
{
	m_feedbackArr += &feedback;
	return true;
}

std::vector<Product*>& Seller::getProductArr()
{
	return m_productArr;
}

const Array<Feedback*>& Seller::getFeedbackArr() const
{
	return m_feedbackArr;
}

int Seller::getNumOfProducts() const
{
	return m_productArr.size();
}

void Seller::toOs(std::ostream & os) const
{
	os << "Seller`s ";
}