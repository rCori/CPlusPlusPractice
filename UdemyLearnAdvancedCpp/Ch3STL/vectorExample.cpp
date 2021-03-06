/* vectorExample.cpp
 * Not sure what to do with this other than make use
 * of and explain thing about vectors.
 * stl vectors are likearrays that dynamically size themselves
 * as new elements are added. The user is not responsible
 * for allocating memory on the heap for these. The internal
 * array is initialized as something small to start if it
 * is not initialized with a list of values.
 * In "typical" implementation the array size doubles each time
 * it's capacity is reached. If a vector will start empty
 * and quickly receive many more elements you may want to researve
 * the space up front with the std::vector.researve(int) method.
 * Some small performance increase in some situations.
 */

#include <iostream>
#include <vector>
int main(){
	//Starting off showing basic usage of the class
	//This is a vector of ints but as a template class this
	//could be a vector of any primitive or user defined type.
	//No operators need to be overridden for a user-defined type
	//with vecotrs the way that some other templates require
	std::vector<int> integerVector;
	if(integerVector.empty()){
		std::cout << "integerVector was initialized empty" << std::endl;
		std::cout << "integerVector has an initialial capacity of "
			<< integerVector.capacity() << std::endl;

	}

	//Here we can do list initialization
	std::vector<int> initializeVector(7,100);

	
	//Print every element to show that working
	for(int i = 0; i < initializeVector.size(); i++){
		std::cout << "initializeVector[" << i << "] "
			<< initializeVector[i] << std::endl;
	}
	
	//vector size is how many elements are in the vector
	//vector capacity is how many elements can be in the
	//vector without resizing. These are not always the same
	//Because we initialize with these values, in this case
	//they are the same
	std::cout << "Capacity of initializeVector is " 
			<< initializeVector.capacity() << " and size "
			"of initializeVector is "
			<< initializeVector.size() << std::endl;
	
	//After adding an additional value this changes
	//We can use std::vector<>.push_back to add elements
	//to the end vector
	initializeVector.push_back(2);

	std::cout << "Capacity of initializeVector is " 
			<< initializeVector.capacity() << " and size "
			"of initializeVector is "
			<< initializeVector.size() << std::endl;
	
	//pop_back will remove and return off the end of the vector
	std::cout << "The last element of initialize vector before "
			"pop_back is " << initializeVector.back()
			<< std::endl;
	initializeVector.pop_back();
	std::cout << "After pop_back the last element is: "
			<< initializeVector.back() << std::endl;

	//Using an iterator to iterate through a vector
	std::vector<int> inOrderVector;
	int initArray[] = {0,1,2,3,4,5,6};
	inOrderVector.insert(inOrderVector.begin(),initArray,initArray+7);

	//The simplest standard for loop
	std::cout << "Iterating through vector using standard "
		   "iterator techniques." << std::endl;
	for(std::vector<int>::iterator it = inOrderVector.begin(); it != inOrderVector.end(); it++){
		//We use std::vector's overloaded dereference operator * to get the object
		//that our iterator points to, in our case these will be integers
		std::cout << *it << std::endl;
	}

}
