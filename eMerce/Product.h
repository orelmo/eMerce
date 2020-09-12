#ifndef _PRODUCT_H
#define _PRODUCT_H

#pragma warning(disable: 4996)

#include<string.h>
#include<string>
#include<iostream>

class Seller;

class Product {
public:
	enum eCategory{Kids,Electricity,Office,Clothing};

private:
	static int prodIDMaker;
	Seller* m_seller;
	std::string m_name;
	eCategory m_category;
	unsigned int m_price;
	int m_productID;

public:
	
	Product(Seller* seller, const std::string& name, eCategory category, int price);
	Product(const Product& other) = delete;

	bool setSeller(Seller* seller) ;
	bool setName(const std::string& name);
	bool setCategory(eCategory category);
	bool setPrice(unsigned int price);

	Seller* getSeller() const;
	const std::string& getName() const;
	eCategory getCategory() const;
	unsigned int getPrice() const;
	int getProductID() const;

	static void printCategory();
};
#endif // !_PRODUCT_H

