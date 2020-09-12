#include "Address.h"

bool IsNotChar(char c)
{
	return ((c<'A' && c>'Z') && (c<'a' && c>'z'));
}

std::ostream & operator<<(std::ostream & os, const Address & address)
{
	if (typeid(os) == typeid(std::ostream))
		os << "Country: " << address.getCountry() << ", City: " << address.getCity()
		<< ", Street: " << address.getStreet() << ", House Number: "
		<< address.getHouseNumber();
	else// is file
		os << address.getCountry() << "\n" << address.getCity() << "\n" << address.getStreet() << "\n" << address.getHouseNumber();
	return os;
}


bool Address::isNameOk(const std::string & name)
{
	if (name.length() == 0)
		return false;
	std::string::const_iterator found  = std::find_if(name.begin(), name.end(), IsNotChar);
	return found == name.end();
}

Address::Address(const std::string& country, const std::string& city, const std::string& street, int houseNumber)
{
	m_country = country;
	m_city = city;
	m_street = street;
	setHouseNumber(houseNumber);
}

Address::Address(const Address & other)
{
	*this = other;
}

const std::string& Address::getCountry() const
{
	return m_country;
}

const std::string& Address::getCity() const
{
	return m_city;
}

const std::string& Address::getStreet() const
{
	return m_street;
}

int Address::getHouseNumber() const
{
	return m_houseNumber;
}

bool Address::setCountry(const std::string& country)
{
	if(!isNameOk(country))
		return false;
	m_country=country;
	return true;
}

bool Address::setCity(const std::string& city)
{
	if (!isNameOk(city))
		return false;
	m_city=city;
	return true;
}

bool Address::setStreet(const std::string& street)
{
	if (!isNameOk(street))
		return false;
	m_street=street;
	return true;
}

bool Address::setHouseNumber(unsigned int houseNumber)
{
	m_houseNumber = houseNumber;
	return true;
}

void Address::operator=(const Address & other)
{
	m_country = other.m_country;
	m_city = other.m_city;
	m_street = other.m_street;
	m_houseNumber = other.m_houseNumber;
}