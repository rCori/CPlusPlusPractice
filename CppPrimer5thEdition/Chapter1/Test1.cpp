/*
 * The text also provided some other main functions that were much simpler
 * than the final program. I am reusing these as a means to test functionality
 *
 * This one tests the << and >> operator overloads without involving the + operator
 */

#include <iostream>
#include "Sales_item.h"

int main()
{
	Sales_item book;
	//Read ISBN number, number of copies sold, and sales price
	std::cin >> book;
	std::cout << book << std::endl;
	return 0;
}
