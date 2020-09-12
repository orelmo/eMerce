#ifndef _SELLER_H
#define _SELLER_H

#include"Address.h"
#include"User.h"
#include"Array.h"
#include<vector>

class Feedback;
class Product;

class Seller :virtual public User{
protected:
	Array<Feedback*> m_feedbackArr;
	std::vector<Product*> m_productArr;

public:

	Seller(const std::string& username, const std::string& password, const Address& address);
	Seller(const Seller& other) = delete;
	virtual ~Seller();

	bool addProduct(Product& product);
	bool addFeedback( Feedback& feedback);

	std::vector<Product*>& getProductArr();
	const Array<Feedback*>& getFeedbackArr() const;
	int getNumOfProducts() const;

	void toOs(std::ostream & os) const;
};
#endif // _SELLER_H
