/* assignmentOverload.cp
 * Simple example of overloading the assignment(=) operator
 * Rule of 3: If you implement one of the following: A 
 * destructor, a copy constructor, or the assignment operator
 * (operator=), then you should implement.
 */

#include <iostream>
using namespace std;

class Test {
private:
	int id;
	string name;

public:
	Test(): id(0), name(""){
	
	}

	Test(int id, string name): id(id), name(name) {
	
	}

	//Even if parameter was not const, this is still used
	//as copy constructor
	Test(const Test &other){
		cout << "Using copy constructor" << endl;
		id = other.id;
		name = other.name;
	}

	void print(){
		cout << id << ": " << name << endl;
	}

	const Test &operator=(const Test &other){
		//This print statement is to show when our overloaded
		//assignment operator is being used.
		//It overwrites the default shallow-copy implementation
		cout << "Assignment running" << endl;
		//Assign all the values of this to the values of other
		id = other.id;
		name = other.name;
		//Dereference this and return it
		return *this;
	}

};

int main(){
	Test test1(10, "Mike");
	test1.print();

	Test test2(20, "Bob");
	test2 = test1;
	test2.print();

	Test test3;

	test3.operator=(test2);
	cout << "Print test3: " << flush;
	test3.print();

	cout << endl;
	//Copy initialization
	/* Does not use the overloaded assignment operator
	 * Uses the copy constructor, either theone created
	 * automatically or the consturctor we make with the one
	 * parameter being a reference to it's own class
	 */
	Test test4 = test1;
	test4.print();

	return 0;
}
