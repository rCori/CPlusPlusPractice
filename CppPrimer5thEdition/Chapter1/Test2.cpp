/*
 * The text also provided some other main functions that were much simpler
 * than the final program. I am reusing these as a means to test functionality
 *
 * This one tests the <<, >>, and + operator overloads
 */

#include <iostream>
#include "Sales_item.h"

int main(){
	Sales_item item1, item2;
	std::cin >> item1 >> item2;
	std::cout << item1 + item2 << std::endl;
	return 0;
}
