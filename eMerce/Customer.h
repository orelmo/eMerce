#ifndef _CUSTOMER_H
#define _CUSTOMER_H

#include "User.h"
#include<vector>
#include<string>

class Seller;
class Feedback;
class Product;

class Customer:virtual public User {
protected:
	std::vector<Product*> m_cart;
	std::vector<Product*> m_order;
	std::vector<Seller*> m_purchaseHistory;

public:
	Customer(const std::string& username,const std::string& password,const Address& address);
	Customer(const Customer& other) = delete;
	virtual ~Customer();


	const std::vector<Product*>& getCart()const;
	unsigned int getCartSize() const;
	const std::vector<Product*>& getOrder() const;
	unsigned int getOrderSize() const;
	unsigned int getOrderPrice() const;
	unsigned int getCartPrice() const;
	std::vector<Seller*>& getPurchaseHistory();
	unsigned int getPurchaseHistorySize() const;

	void addToCart(Product& product);
	bool removeFromCart(const Product& product);
	void addFeedback(unsigned int sellerNum, Feedback& feedback);
	void printCart() const;
	void addToOrder(int prodNum);
	void payment();
	void showPurchaseHistory();

	bool operator>(const Customer& other);

	virtual void toOs(std::ostream& os) const override;
};
#endif // !_CUSTOMER_H

