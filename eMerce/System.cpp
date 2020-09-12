#include "System.h"
#include"Seller.h"
#include"CustomerSeller.h"
#include"Customer.h"
#include"Product.h"
#include"Feedback.h"

const std::string category[] = { "Kids","Electricity","Office","Clothing" };

System::System(const std::string& name) : m_name(name)
{}

System::~System()
{
	for (auto a : m_UsersArr)
		delete a;
}

const std::string& System::getName() const
{
	return m_name;
}

const std::vector<User*>& System::getUsersArr() const
{
	return m_UsersArr;
}

unsigned int System::getUserArrSize() const
{
	return (unsigned int)m_UsersArr.size();
}

bool System::setName(const std::string& name)
{
	if (!name.size())
		return false;
	m_name = name;
	return true;
}

void System::compareCustomers()
{//the function get two customers in compare their cart price.
	Customer* c1 = nullptr, *c2 = nullptr, *temp = nullptr;
	int c1num, c2num, counter1 = 0;
	if (!printAndGetCustomersToCompare(c1num, c2num))
		return;
	std::cout << "The customer with more expensive cart is: ";
	for (int i = 0; i < m_UsersArr.size() && (!c1 || !c2); i++)
	{
		temp = dynamic_cast<Customer*>(m_UsersArr[i]);
		if (temp)
			counter1++;
		if (counter1 == c1num)
			c1 = temp;
		else if (counter1 == c2num)
			c2 = temp;
	}
	if (*c1 > *c2)
		std::cout << c1->getUserName() << "\n";
	else if (*c2 > *c1)
		std::cout << c2->getUserName() << "\n";
	else
		std::cout << "No one, the carts price is equal!\n";
}

bool System::printAndGetCustomersToCompare(int & c1num, int & c2num)
{// the function find the customers places in relative to the other customers and return false if not possible.  
	if (m_numOfCustomers+m_numOfCustomerSellers < 2)
	{
		std::cout << "There are no enough customers in the system!\n";
		return false;
	}
	std::cout << "Please select the two customers you want compare their cart price by enter their numbers: \n";
	Customer* c = nullptr;
	int counter = 1;
	for (auto a:m_UsersArr)
	{
		c = dynamic_cast<Customer*>(a);
		if (c)
			std::cout << counter++ << ") " << c->getUserName() << "\n";
	}
	std::cin >> c1num >> c2num;
	std::cin.ignore();
	if (c1num<1 || c1num>counter - 1 || c2num < 1 || c2num > counter - 1)
	{
		std::cout << "Illegal customers!\n";
		return false;
	}
	return true;
}

Date System::getAndCheckDate(bool& flag)
{
	int year, month, day;
	std::cout << "Please enter the date as day month year with space between them\n";
	std::cin >> day >> month >> year;
	std::cin.ignore();
	if (day < 1 || day > 31)
	{
		std::cout << "The day is illigal\n";
		flag = false;
	}
	if (month < 1 || month > 12)
	{
		std::cout << "The month is illigal\n";
		flag = false;
	}
	if (year != 2020)
	{
		std::cout << "The year is illigal\n";
		flag = false;
	}
	if (flag)
		return Date(day, month, year);
	else
		return Date(22, 1, 2020);//fictive date.
}

void System::printUser(eUserType type) const
{
	User* temp=nullptr;
	int counter = 1;
	for (auto a:m_UsersArr)
	{
		if (type == seller)
			temp = dynamic_cast<Seller*>(a);
		else if (type == customer)
			temp = dynamic_cast<Customer*>(a);
		else
			temp = dynamic_cast<CustomerSeller*>(a);
		if (temp)
			std::cout << counter++ << ") " << *temp << "\n";
	}
}

void System::iterativeMenu()
{
	int function;
	std::cout << "Please select the wanted function from the menu below:\n";
	printMenu();
	std::cin >> function;
	std::cin.ignore();
	std::string username;
	std::string password;
	while (function != 14)
	{
		switch (function)
		{
		case 1:
		case 2:
		case 3:
			*this += *(readAccount(System::eUserType(function-1)));//0 for seller, 1 for customer, 2 for customerSeller.
			std::cout << "\n";
			break;
		case 4:
			if (getLoginAndCheck(username, password))
			{
				eUserType type = getUserType(username);
				if (type == seller|| type==customerSeller)
					addProductToSeller(username);
				else
					std::cout << "No permission for the function selected!\n";
			}
			std::cout << "\n";
			break;
		case 5:
			if (getLoginAndCheck(username, password))
			{
				eUserType type = getUserType(username);
				if (type == customer || type == customerSeller)
					addFeadbackToSeller(username);
				else
					std::cout << "No permission for the function selected!\n";
			}
			std::cout << "\n";
			break;
		case 6:
			if (getLoginAndCheck(username, password))
			{
				eUserType type = getUserType(username);
				if (type == customer || type == customerSeller)
					addProductToCart(username);
				else
					std::cout << "No permission for the function selected!\n";
			}
			std::cout << "\n";
			break;
		case 7:
			if (getLoginAndCheck(username, password))
			{
				eUserType type = getUserType(username);
				if (type == customer || type == customerSeller)
					makeOrder(username);
				else
					std::cout << "No permission for the function selected!\n";
			}
			std::cout << "\n";
			break;
		case 8:
			if (getLoginAndCheck(username, password))
			{
				eUserType type = getUserType(username);
				if (type == customer || type == customerSeller)
					payForOrder(username);
				else
					std::cout << "No permission for the function selected!\n";
			}
			std::cout << "\n";
			break;
		case 9:
			printUser(System::eUserType(customer));
			std::cout << "\n";
			break;
		case 10:
			printUser(System::eUserType(seller));
			std::cout << "\n";
			break;
		case 11:
			printUser(System::eUserType(customerSeller));
			std::cout << "\n";
			break;
		case 12:
			printProductsByName();
			std::cout << "\n";
			break;
		case 13:
			compareCustomers();
			std::cout << "\n";
			break;
		default:
			break;
			std::cout << "Undefined function was selected. Please try again.\n ";
		}
		std::cout << "Please select the wanted function from the menu below:\n";
		printMenu();
		std::cin >> function;
		std::cin.ignore();
	}
}

void System::loadSystem(const std::string& systemFileName)
{
	std::ifstream inFile(systemFileName);
	if (!inFile.good())
		return;
	int numOfUsers;
	inFile >> numOfUsers;
	inFile.ignore();
	for(int i=1;i<=numOfUsers;i++)
	{
		std::string type,username,password,country,city,street;
		int houseNum;
		std::getline(inFile,type);
		std::getline(inFile, username);
		std::getline(inFile, password);
		std::getline(inFile, country);
		std::getline(inFile, city);
		std::getline(inFile, street);
		inFile >> houseNum;
		inFile.ignore();
		if (type.compare("Customer") == 0)
		{
			*this += *(new Customer(username, password, Address(country, city, street, houseNum)));
			++m_numOfCustomers;
		}
		else if (type.compare("Seller") == 0)
		{
			*this += *(new Seller(username, password, Address(country, city, street, houseNum)));
			++m_numOfSellers;
		}
		else  // CustomerSeller
		{
			*this += *(new CustomerSeller(username, password, Address(country, city, street, houseNum)));
			++m_numOfCustomerSellers;
		}
	}
	inFile.close();
}

void System::saveSystem(const std::string & systemFileName)
{
	std::ofstream outFile(systemFileName, std::ios::trunc);
	outFile << m_UsersArr.size()<<"\n";
	for (auto a : m_UsersArr)
		outFile <<typeid(*a).name() + 6 << "\n" << *a<<"\n";
	outFile.close();
}

System& System::operator+=(User & other)
{
	m_UsersArr.push_back(&other);
	return *this;
}

void System::printMenu()
{
	std::cout << "1) Add seller.\n2) Add customer.\n3) Add custmerSeller.\n4) Add Product.\n5) Add feedback.\n" <<
		"6) Add product to cart.\n7) Make order.\n8) Pay for order.\n9) Show all customers.\n" <<
		"10) Show all sellers.\n11) Show all customerSellers.\n12) Show products by name."<<
		"\n13) Compare two customers carts price.\n14) Exit.\n";
}

const User* System::CheckIfUsernameExist(const std::string& username)
{//return the pointer to the user if exist.
	for (auto a : m_UsersArr)
		if (!a->getUserName().compare(username))
			return a;
	return nullptr;
}

bool System::CheckString(const std::string& string)
{
	return string.size();
}

void System::readLogin(std::string& username, std::string& password)
{
	std::cout << "Enter your username: ";
	std::getline(std::cin, username);
	std::cout << "Enter your password: ";
	std::getline(std::cin, password);
}

void System::addProductToSeller(const std::string& username)
{
	std::string name;
	std::cout << "Please enter your product name: ";
	std::getline(std::cin, name);
	if (!CheckString(name))
	{
		std::cout << "The product name you entered is too short!\n";
		return;
	}
	std::cout << "Please select the product category:\n";
	Product::printCategory();
	int category;
	std::cin >> category;
	std::cin.ignore();
	if (category < 1 || category>4)
	{
		std::cout << "The category you entered is invalid!\n";
		return;
	}
	std::cout << "Please enter the product`s price: ";
	int price;
	std::cin >> price;
	std::cin.ignore();
	if (price < 0)
	{
		std::cout << "The price you entered is invalid!\n";
		return;
	}
	for (auto a:m_UsersArr)
		if(!a->getUserName().compare(username))
		{
			Seller* temp = dynamic_cast<Seller*>(a);
			Product* prod = new Product(temp, name, (Product::eCategory) (category - 1), price);
			temp->addProduct(*prod);
			break;
		}
}

bool System::CheckLogin(const std::string& username, const std::string& password)
{//return true if the username exist and the password appropriate.
	const User* user = CheckIfUsernameExist(username);
	if (user == nullptr)
	{
		std::cout << "User is not exist!\n";
		return false;
	}
	else//user exist
	{
		if (!user->getPassword().compare(password))
			return true;
		else
		{
			std::cout << "Password is not correct!\n";
			return false;
		}
	}
}

bool System::CheckLoginStrings(const std::string& username, const std::string& password)
{//return true if the function check the string is legal.
	if (!CheckString(username))
	{
		std::cout << "Empty username.\n";
		return false;
	}
	if (!CheckString(password))
	{
		std::cout << "Empty password.\n";
		return false;
	}
	return true;
}

void System::addFeadbackToSeller(const std::string& username)
{
	Customer* c1 = nullptr;
	for (auto a : m_UsersArr)
		if (!a->getUserName().compare(username))
		{
			c1 = dynamic_cast<Customer*>(a);
			break;
		}
	if (c1->getPurchaseHistorySize() < 1)
	{
		std::cout << "You didn`t buy any items so you can`t leave feedback!\n";
		return;
	}
	std::cout << "Please select the number of the seller you want to add feedback to:\n";
	c1->showPurchaseHistory();
	int sellerNum;
	std::cin >> sellerNum;
	std::cin.ignore();
	if (sellerNum<1 || sellerNum>c1->getPurchaseHistorySize())
	{
		std::cout << "Invalid seller.\n";
		return;
	}
	if (!c1->getPurchaseHistory()[sellerNum - 1]->getUserName().compare(c1->getUserName()))
	{
		std::cout << "You can't leave feedback to yourself!\n";
		return;
	}
	std::string comment;
	std::cout << "Please enter your comment :\n";
	std::getline(std::cin,comment);
	if (!CheckString(comment))
	{
		std::cout << "The comment you entered is too short!\n";
		return;
	}
	bool flag=true;
	Feedback* feedback = new Feedback(*c1, getAndCheckDate(flag), comment);
	if(flag)
		c1->getPurchaseHistory()[sellerNum - 1]->addFeedback(*feedback);
}

bool System::getLoginAndCheck(std::string& username, std::string& password)
{
	readLogin(username, password);
	if (!CheckString(username))
	{
		std::cout << "Your username is too short!\n";
		return false;
	}
	else if (!CheckString(password))
	{
		std::cout << "Your password is too short!\n";
		return false;
	}
	else if (!CheckLogin(username, password))
		return false;
	return true;
}

void System::addProductToCart(const std::string& username)
{
	bool flag = false;
	Seller* s1=nullptr;
	for (auto a:m_UsersArr)
	{
		s1 = dynamic_cast<Seller*>(a);
		if (s1)
			if (s1->getNumOfProducts() > 0)
			{
				flag = true;
				break;
			}
	}
	if (!flag) {
		std::cout << "There are no products in the system.\n";
		return;
	}
	int numOfActiveSellers;
	printAllProducts(numOfActiveSellers);
	int sellerNum,prodNum,sellerPlace;
	if (!getAndCheckSelectedProduct(&sellerNum, &prodNum,&sellerPlace,numOfActiveSellers))
		return;
	Customer* c1 = nullptr;
	for (auto a: m_UsersArr)
		if (!a->getUserName().compare(username))
		{
			c1 = dynamic_cast<Customer*>(a);
			break;
		}
	Seller* seller = dynamic_cast<Seller*>(m_UsersArr[sellerPlace]);
	c1->addToCart(*seller->getProductArr()[prodNum - 1]);
}

void System::printAllProducts(int& numOfActiveSellers)
{
	int counter = 1;
	for (auto a: m_UsersArr)
	{
		Seller* temp = dynamic_cast<Seller*>(a);
		if (temp)
		{
			if (temp->getNumOfProducts() > 0)
			{
				std::cout << counter << ") Products of " << temp->getUserName() << ":\n";
				unsigned int numOfProducts = temp->getNumOfProducts();
				std::vector< Product*> prodArr = temp->getProductArr();
				for (unsigned int j = 0; j < numOfProducts; j++)
					std::cout << "\t" << j + 1 << ") " << prodArr[j]->getName() << "\n";
				std::cout << "\n";
				counter++;
			}
		}
	}
	numOfActiveSellers = counter-1;
}

bool System::getAndCheckSelectedProduct(int * sellerNum,int * prodNum,int * sellerPlace,int& numOfActiveSellers)
{
	std::cout << "Please select the seller number: ";
	std::cin >> *sellerNum;
	std::cin.ignore();
	if (*sellerNum<1 || *sellerNum>numOfActiveSellers)
	{
		std::cout << "\nInvalid seller number!\n";
		return false;
	}
	std::cout << "\nPlease select the product number: ";
	std::cin >> *prodNum;
	int i = 0,counter=0;
	Seller* user=nullptr;
	while (i < m_UsersArr.size() && counter < *sellerNum)
	{
		user = dynamic_cast<Seller*>(m_UsersArr[i]);
		if (user && user->getNumOfProducts()>0)
			counter++;
		i++;
	}
	*sellerPlace = i-1;
	if (*prodNum<1 || *prodNum> user->getNumOfProducts())
	{
		std::cout << "\nInvalid product number!\n";
		return false;
	}
	return true;
}

void System::makeOrder( const std::string& username)
{
	Customer* user = nullptr;
	for (auto a: m_UsersArr)
		if (!a->getUserName().compare(username))
		{
			user =dynamic_cast<Customer*>(a);
			break;
		}
	if (user->getCartSize() == 0)
	{
		std::cout << "Your cart is empty.\n";
		return;
	}
	std::cout << "Please select product by enter product`s numeber."
		<< " If you want multiple products enter space between the numbers."
		<< " When finish enter -1 and press 'Enter'\n";
	user->printCart();
	int prodNum;
	unsigned int cartSize = user->getCartSize();
	std::cin >> prodNum;
	std::cin.ignore();
	while (prodNum != -1)
	{
		if (prodNum<-1 || prodNum == 0 || prodNum>cartSize)
			std::cout << "Product " << prodNum << " is invalid!\n";
		else
			user->addToOrder(prodNum);
		std::cin >> prodNum;
	}
}

void System::payForOrder(const std::string& username)
{
	Customer* c1 = nullptr;
	for (auto a: m_UsersArr)
		if (!a->getUserName().compare(username))
		{
			c1 = dynamic_cast <Customer*>(a);
			break;
		}
	if (c1->getOrderSize() == 0)
	{
		std::cout << "Your order is empty!\n";
		return;
	}
	std::cout << "The order price is: " << c1->getOrderPrice() << "\n";
	c1->payment();
}

void System::printProductsByName()
{
	std::string prod;
	std::cout << "Please enter product name (up to 20 characters): ";
	std::cin >> prod;
	std::cin.ignore();
	if (!CheckString(prod))
	{
		std::cout << "The product name you entered is too short!\n";
		return;
	}
	unsigned int counter = 0;
	for (auto a: m_UsersArr)
	{
		Seller* seller = dynamic_cast<Seller*>(a);
		if (seller)
		{
			std::vector<Product*> prodArr = seller->getProductArr();
			for (unsigned int j = 0; j < seller->getNumOfProducts(); j++)
				if (!prodArr[j]->getName().compare(prod))
					std::cout << ++counter << ") Seller: " << seller->getUserName() <<
					"\n   Category: " << category[prodArr[j]->getCategory()] <<
					"\n   Product ID: " << prodArr[j]->getProductID() <<
					"\n   Price: " << prodArr[j]->getPrice() << "\n";
		}
	}	
	if (counter == 0)
		std::cout << "No products found by the name you entered\n";
}

void System::cleanBuffer()
{
	int c;
	do
	{
		c = getchar();
	} while (c != EOF && c != '\n');
}

bool System::readAddress(std::string& country, std::string& city, std::string& street, int* houseNumber)
{
	std::cout << "Please enter your country: ";
	std::getline(std::cin, country);
	if (!Address::isNameOk(country))
	{
		std::cout << "The country entered is too short!\n";
		return false;
	}
	std::cout << "Please enter your city: ";
	std::getline(std::cin,city);
	if (!Address::isNameOk(city))
	{
		std::cout << "The city entered is too short!\n";
		return false;
	}
	std::cout << "Please enter your street: ";
	std::getline(std::cin, street);
	if (!Address::isNameOk(street))
	{
		std::cout << "The street entered is too short!\n";
		return false;
	}
	std::cout << "Please enter your house number: ";
	std::cin >> *houseNumber;
	if (*houseNumber < 1)
	{
		std::cout << "The house number can't be negative!\n";
		return false;
	}
	return true;
}

User* System::readAccount(eUserType type)
{
	std::string username;
	std::string password;
	std::string country;
	std::string city;
	std::string street;
	int houseNumber;
	User* user;
	readLogin(username, password);
	if (!CheckLoginStrings(username, password))
		return nullptr;
	if (CheckIfUsernameExist(username))
	{
		std::cout << "Username already exist.\n";
		return nullptr;
	}

	if (!readAddress(country, city, street, &houseNumber))
		return nullptr;
	Address address(country, city, street, houseNumber);
	if (type == customer)
	{
		user = new Customer(username, password, address);
		m_numOfCustomers++;
	}
	else if (type == seller)
	{
		user = new Seller(username, password, address);
		m_numOfSellers++;
	}
	else
	{
		user = new CustomerSeller(username, password, address);
		m_numOfCustomerSellers++;
	}
	return user;
}

System::eUserType System::getUserType(const std::string& username)
{
	for (auto a: m_UsersArr)
		if (!a->getUserName().compare(username))
		{
			CustomerSeller* temp = dynamic_cast<CustomerSeller*>(a);
			if (temp)
				return customerSeller;
			Customer* temp2 = dynamic_cast<Customer*>(a);
			if (temp2)
				return customer;
			else
				return seller;
		}
}