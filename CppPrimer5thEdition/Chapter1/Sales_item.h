/* Sales_item.h
 * The first chapter of the C++ Primer Fifth Edition is very rudimentary.
 * It mostly goes over loop contrusts and conditionals.
 * It does explain how operators like << take 2 arguments, an ostream
 * and a string.
 *
 * It then gives an example of using a class called
 * Sales_item which overrides operators to make it behave like
 * a primitive type with functionality for + and << included.
 * It does not go into how to actually write this class, only
 * how it is used.
 *
 * For this chapter I will write an implementation of this class
 * by overriding those operators since that is more interesting than
 * a demostration of what an if, while, and for do
 */

#ifndef __SALESITEM_H__
#define __SALESITEM_H__

#include <iostream>

class Sales_item{
public:

	//I must create some kind of constructor although in my example all
	//instances will come from the >> operator
	Sales_item();

	//Since all of these overloads require access to private members
	//of the Sales_item class, we declare them all 
	friend std::ostream& operator<<(std::ostream &lhs, const Sales_item &rhs);
	friend std::istream& operator>>(std::istream &lhs, Sales_item &rhs);
	//+ operator actually can be implemented as a member function by
	//removing one of the operands. Compiler then turns the *this
	//pointer into a hidden leftmost operator.
	//Chose not to do that
	friend Sales_item operator+(const Sales_item &lhs, const Sales_item &rhs);
	std::string isbn();
private:
	std::string isbnString;
	int copiesSold;
	float price;
	float revenue;
};
#endif
