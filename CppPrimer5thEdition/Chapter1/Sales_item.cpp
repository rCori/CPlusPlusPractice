#include "Sales_item.h"
#include <iostream>

Sales_item::Sales_item(){
	isbnString = "";
	copiesSold = 0;
	price = 0.0;
	revenue = 0.0;
}

std::ostream& operator<<(std::ostream& lhs, const Sales_item& rhs){
	lhs << rhs.isbnString << " " << rhs.copiesSold << " " << rhs.revenue << " " << rhs.price << std::endl;
	return lhs;
}

//All of these values in rhs will actually change because the & reference operator
//makes this pass by reference and not pass by value
std::istream& operator>>(std::istream &lhs, Sales_item &rhs){
	lhs >> rhs.isbnString >> rhs.copiesSold >> rhs.price;
	rhs.revenue = rhs.copiesSold * rhs.price;
	return lhs;
}

Sales_item operator+(const Sales_item &lhs, const Sales_item &rhs){
	Sales_item salesItem;
	salesItem.isbnString = lhs.isbnString;
	salesItem.revenue = (lhs.copiesSold * lhs.price) + (rhs.copiesSold * rhs.price);
	salesItem.copiesSold = lhs.copiesSold + rhs.copiesSold;
	salesItem.price = salesItem.revenue/salesItem.copiesSold;
	return salesItem;
}

std::string Sales_item::isbn(){
	return isbnString;
}
