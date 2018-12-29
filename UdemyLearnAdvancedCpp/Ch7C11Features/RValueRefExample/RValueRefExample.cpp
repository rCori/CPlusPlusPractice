/* RValueRefExample.cpp
 * This was an example I was suggested to try out
 * in order to get an intuition on how rvalue references
 * really work
 */

#include <iostream>

void check(const int &value){
	std::cout << "lvalue ref example" << std::endl;
}

void check(int &&value){
	std::cout << "rvalue ref example" << std::endl;
}

int main(){
	check(1);
	int value1 = 2;
	check(value1);
	//postfix is an rvalue but prefix is an lvalue
	check(value1++);
	check(++value1);
	//By adding a +1 this is no longer something we
	//can make a traditional reference value so it
	//will be an rvalue
	check(value1+1);
}
