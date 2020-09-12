#ifndef _CUSTOMERSELLER_H
#define _CUSTOMERSELLER_H

#include "Customer.h"
#include "Seller.h"

class CustomerSeller : public Customer, public Seller {
public:
	CustomerSeller(const std::string& username, const std::string& password, const Address& address);
	CustomerSeller(const CustomerSeller& other) = delete;

	void toOs(std::ostream & os) const;

};
#endif // !_CUSTOMERSELLER_H
