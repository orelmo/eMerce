#include "User.h"

User::User(const std::string& userName, const std::string& password, const Address& address):m_address(address)
{
	setUserName(userName);
	setPassword(password);
}

User::User(const User & other):m_address(other.getAddress())
{
	m_userName = other.getUserName();
	m_password = other.getPassword();
}

User::~User(){}

bool User::setUserName(const std::string& userName)
{
	if (!userName.size())
		return false;
	m_userName = userName;
	return true;
}

bool User::setPassword(const std::string& password)
{
	if (!password.size())
		return false;
	m_password = password;
	return true;
}

bool User::setAddress(const Address & address)
{
	m_address = address;
	return true;
}

const std::string& User::getUserName() const
{
	return m_userName;
}

const std::string& User::getPassword() const
{
	return m_password;
}

const Address & User::getAddress() const
{
	return m_address;
}

std::ostream & operator<<(std::ostream & os, const User & user)
{
	if (typeid(os) == typeid(std::ostream))
	{
		user.toOs(os);
		os << "Username: " << user.getUserName() << ", Address: " << user.getAddress();
	}
	else//is file
		os << user.getUserName() << "\n" << user.getPassword() << "\n" << user.getAddress();
	return os;
}