/* ClassHierarchy.cpp
 * Demonstrate how abstract classes and class parent 
 * relationships can work together. A multi-part hierarchy
 * where the bottom-most child is the only non abstract
 * class 
 */

#include <iostream>

//Vehicle defines all pure-virtual functions that
//it's children must define. Only a class with
//definitions for all coming from whatever source
//will be non-abstract
class Vehicle{
public:
	virtual void Accelerate() = 0;
	virtual void Brake() = 0;
	virtual void ChangeTires() = 0;
	virtual void Sell() = 0;
};

//Car implements two pure virtual functions but it
//leaves the two other's not implemented.
//Car is still abstract
class Car:public Vehicle{
public:
	virtual void Accelerate(){
		std::cout << "Car goes forward" << std::endl;
	}

	virtual void Brake(){
		std::cout << "Car stops going forward" << std::endl;
	}
};

//Honda implements one more pure-virtual and inherits
//the two definitions from Car. That leaves one more.
//Honda is also abstract
class Honda:public Car{
public:
	virtual void ChangeTires(){
		std::cout << "New tires for your Honda" << std::endl;
	}
};

//Civic inherits all virtual function definitions from
//car and Honda as well as implementing the last of the
//pure-virtual functions Vehicle defined.
//Civic is not abstract. It can be instantiated
class Civic:public Honda{
public:
	virtual void Sell(){
		std::cout << "A new Honda Civic sells for about $19,000" << std::endl;
	}
};

int main(){

	//None of the following are allowed because they are
	//instantiations of abstract classes
	//Vehicle vehicle;
	//Car car;
	//Honda honda;
	
	//This one however is allowed
	Civic myCivic;
	

	//Containers of abstract classes are not allowed
	//Vehicle vehicleArr[3];
	//Car carArr[3];
	//Honda honda[3];

	//Unless they are pointers, which allows for abstract
	//classes to toake advantage of polymorphism the same way
	//a non-abstract parent class can
	Vehicle *vehiclePtrArr[3];
	Civic *myCivicPtr = new Civic();
	vehiclePtrArr[0] = myCivicPtr;
	vehiclePtrArr[0]->Accelerate();
	vehiclePtrArr[0]->Brake();
	vehiclePtrArr[0]->ChangeTires();
	vehiclePtrArr[0]->Sell();

	delete myCivicPtr;


	return 0;
}
