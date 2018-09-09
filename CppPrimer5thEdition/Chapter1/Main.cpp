#include "Sales_item.h"
#include <iostream>

int main(){
	Sales_item item1, item2;
	std::cin >> item1 >> item2;
	//First check item1 and item2 represent the same book
	if(item1.isbn() == item2.isbn()){
		//Here we are using both the << and + operators for the Sales_item class
		std::cout << item1 + item2 << std::endl;
		return 0;
	} else {
		std::cerr << "Data must refer to same ISBN" << std::endl;
		return 0;
	}
        
}
