#ifndef _User_H
#define _User_H

#include"Address.h"
#include <string>

class User
{
protected:
	std::string m_userName;
	std::string m_password;
	Address m_address;

protected:
	User(const std::string& userName, const std::string& password,const Address& address);
	User(const User& other);

public:
	virtual ~User();

	bool setUserName(const std::string& userName);
	bool setPassword(const std::string& password);
	bool setAddress(const Address& address);

	const std::string& getUserName() const;
	const std::string& getPassword() const;
	const Address& getAddress() const;

	friend std::ostream& operator<<(std::ostream& os, const User& user);
	virtual void toOs(std::ostream& os) const {}
};

#endif //_User_H
