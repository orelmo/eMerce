#include "CustomerSeller.h"

CustomerSeller::CustomerSeller(const std::string& username, const std::string& password, const Address & address)
	:User(username, password, address), Customer(username, password, address), Seller(username, password, address)
{}

void CustomerSeller::toOs(std::ostream & os) const
{
	os << "CustomerSeller`s ";
}