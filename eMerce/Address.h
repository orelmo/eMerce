#ifndef _ADDRESS_H
#define _ADDRESS_H

#pragma warning(disable: 4996)

#include<string.h>
#include<string>
#include<iostream>
#include<algorithm>

class Address {
private:
	std::string			m_country;
	std::string			m_city;
	std::string			m_street;
	unsigned int	m_houseNumber;

public:

	static bool isNameOk(const std::string& name);

	Address(const std::string& country,const std::string& city, const std::string& street, int houseNumber);
	Address(const Address& other);

	const std::string& getCountry()	const;
	const std::string& getCity()	const;
	const std::string& getStreet()	const;
	int getHouseNumber()	const;

	bool setCountry(const std::string& country);
	bool setCity(const std::string& city);
	bool setStreet(const std::string& street);
	bool setHouseNumber(unsigned int houseNumber);

	void operator=(const Address& other);
	friend std::ostream& operator<<(std::ostream& os,const Address& address);
};

#endif // !_ADDRESS_H

