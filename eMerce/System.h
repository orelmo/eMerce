#ifndef _SYSTEM_H
#define _SYSTEM_H

#include"User.h"
#include"Date.h"
#include<string.h>
#include <vector>
#include<fstream>

class Seller;
class CustomerSeller;
class Customer;

class System {
private:
	std::string				 m_name;
	std::vector<User*>		 m_UsersArr;
	unsigned int			 m_numOfSellers;
	unsigned int			 m_numOfCustomers;
	unsigned int			 m_numOfCustomerSellers;

public:
	System(const std::string& name);
	System(const System& other) = delete;
	~System();

	enum eUserType { seller, customer, customerSeller };

	const std::string& getName() const;
	const std::vector<User*>& getUsersArr() const;
	unsigned int getUserArrSize() const;

	bool setName(const std::string& name);

	void printUser(eUserType type) const;
	void iterativeMenu();
	void loadSystem(const std::string& systemFileName);
	void saveSystem(const std::string& systemFileName);

	System& operator+=(User& other);

private:
	eUserType getUserType(const std::string& username);
	void printMenu();
	User* readAccount(eUserType type);
	const User* CheckIfUsernameExist(const std::string& username);
	bool CheckString(const std::string& string);
	bool readAddress( std::string& country,  std::string& city,  std::string& street, int* houseNumber);
	void readLogin(std::string& username, std::string& password);
	void addProductToSeller(const std::string& username);
	bool CheckLogin(const std::string& username, const std::string& password);
	bool CheckLoginStrings(const std::string& username, const std::string& password);
	void addFeadbackToSeller(const std::string& username);
	bool getLoginAndCheck( std::string& username,  std::string& password);
	void printAllProducts(int &numOfActiveSellers);
	bool getAndCheckSelectedProduct(int *sellerNum, int* prodNum,int* sellerPlace,int &numOfActiveSellers);
	void addProductToCart(const std::string& username);
	void makeOrder(const std::string& username);
	void payForOrder(const std::string& username);
	void printProductsByName();
	void cleanBuffer();
	void compareCustomers();
	bool printAndGetCustomersToCompare(int& c1num,int& c2num);
	Date getAndCheckDate(bool& flag);
};

#endif // _SYSTEM_H