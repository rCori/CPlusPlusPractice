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

	friend std::ostream& operator<<(std::ostream &lhs, const Sales_item &rhs);
	friend std::istream& operator>>(std::istream &lhs, Sales_item &rhs);
	friend Sales_item operator+(const Sales_item &rhs);

};

#endif
