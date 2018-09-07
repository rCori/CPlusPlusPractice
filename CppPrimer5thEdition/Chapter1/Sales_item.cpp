#include "Sales_item.h"

#include <iostream>

std::ostream& operator<<(std::ostream& lhs, const Sales_item& rhs){
	return lhs;
}

std::istream& operator>>(std::istream &lhs, Sales_item &rhs){
	return lhs;
}

Sales_item operator+(const Sales_item &rhs){
	Sales_item salesItem;
	return salesItem;
}
