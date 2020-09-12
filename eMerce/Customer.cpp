#include "Customer.h"
#include "Seller.h"
#include "Product.h"

Customer::Customer(const std::string& username, const std::string& password, const Address& address) : User(username,password,address)
{}

Customer::~Customer()
{
}

const std::vector<Product*>& Customer::getCart() const
{
	return m_cart;
}

unsigned int Customer::getCartSize() const
{
	return unsigned int(m_cart.size());
}

const std::vector<Product *>& Customer::getOrder() const
{
	return m_order;
}

unsigned int Customer::getOrderSize() const
{
	return unsigned int(m_order.size());
}

unsigned int Customer::getOrderPrice() const
{
	unsigned int price = 0;
	for(auto a:m_order)
		price += a->getPrice();
	return price;
}

unsigned int Customer::getCartPrice() const
{
	unsigned int price = 0;
	for (auto a:m_cart)
		price += a->getPrice();
	return price;
}

std::vector<Seller *>& Customer::getPurchaseHistory()
{
	return m_purchaseHistory;
}

unsigned int Customer::getPurchaseHistorySize() const
{
	return unsigned int(m_purchaseHistory.size());
}

void Customer::addToCart(Product & product)
{
	m_cart.push_back( &product);
}

bool Customer::removeFromCart(const Product & product)
{
	bool flag = false;
	for (auto a: m_cart) {
		if (a->getProductID() == product.getProductID())
		{
			a = m_cart[m_cart.size()-1];
			m_cart.pop_back();
			flag = true;
			break;
		}
	}
	return flag;
}

void Customer::addFeedback(unsigned int sellerNum, Feedback& feedback)
{
	m_purchaseHistory[sellerNum - 1]->addFeedback(feedback);
}

void Customer::printCart() const
{
	int i = 1;
	std::cout << "Your cart:\n";
	for (auto a:m_cart)
	{
		std::cout << i << ") Product: " << a->getName() << "\t\tSeller: "
			<< a->getSeller()->getUserName() << "\n";
		++i;
	}
}

void Customer::addToOrder(int prodNum)
{
	m_order.push_back(m_cart[prodNum - 1]);
}

void Customer::payment()
{
	for (auto a: m_order)
	{
		m_purchaseHistory.push_back(a->getSeller());
		removeFromCart(*(a));
	}
	m_order.clear();
}

void Customer::showPurchaseHistory()
{
	int i = 1;
	std::cout << "The sellers you bought from are:\n";
	for (auto a: m_purchaseHistory)
		std::cout << i << ") " << a->getUserName()<<"\n";
}

bool Customer::operator>(const Customer & other)
{
	if (this->getCartPrice() > other.getCartPrice())
		return true;
	else
		return false;
}

void Customer::toOs(std::ostream & os) const
{
	os << "Customer`s ";
}