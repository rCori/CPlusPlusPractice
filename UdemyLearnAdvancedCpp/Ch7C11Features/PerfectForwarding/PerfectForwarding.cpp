/* PerfectForwarding.cpp
 * An example of how perfect forwarding works in c++ 11
 * with reference collapsing and all that 
 */

#include <iostream>
using namespace std;

class Test{
};


/* c++ 11 reference collapsing rules are such that if template
 * type T is an lvalue, the entire type of arg will collapse
 * down to an lvalue reference.
 * By surrounding the parameter in out call to check() with
 * forward, we static cast that type T so an lvalue will remain
 * an lvalue in reference to check()
 *
 */
template<typename T>
void call(T &&arg){
	check(forward<T>(arg));
}

void check(Test &test){
	cout << "lvalue" << endl;
}

void check(Test &&test){
	cout << "rvalue" << endl;
}

int main(){

	Test test;

	call(test);
	call(Test());

	return 0;

}
