#include "Product.h"
#include "Seller.h"

int Product::prodIDMaker = 1;
const std::string category[] = { "Kids","Electricity","Office","Clothing" };

Product::Product(Seller * seller, const std::string& name, eCategory category, int price)
{
	setSeller(seller);
	setName(name);
	setCategory(category);
	setPrice(price);
	m_productID = prodIDMaker++;
}

bool Product::setSeller(Seller * seller)
{
	m_seller = seller;
	return true;
}

bool Product::setName(const std::string& name)
{
	if (!name.size())
		return false;
	m_name = name;
	return true;
}

bool Product::setCategory(eCategory category)
{
	if (category < 0 || category>3)
		return false;
	m_category = category;
	return true;
}

bool Product::setPrice(unsigned int price)
{
	m_price = price;
	return true;
}

Seller* Product::getSeller() const
{
	return m_seller;
}

const std::string& Product::getName() const
{
	return m_name;
}

Product::eCategory Product::getCategory() const
{
	return m_category;
}

unsigned int Product::getPrice() const
{
	return m_price;
}

int Product::getProductID() const
{
	return m_productID;
}

void Product::printCategory()
{
	std::cout << "1) " << category[0] << "\n2) " << category[1] << "\n3) " << category[2] << "\n4) " << category[3]<<"\n";
}
