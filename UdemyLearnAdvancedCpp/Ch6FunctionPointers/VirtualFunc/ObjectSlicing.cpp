/* ObjectSlicing.cpp
 * Defining a parent and child class to show what
 * object slicing is. When you define a child class
 * with some extra data the parent does not have there
 * is a way that casting can make it lose some data.
 */

#include <iostream>

class Building{
protected:
	int doors;
public:
	
	//We must create a default constructor for the child
	//class to use for initialzation
	Building():doors(0){}

	Building(int doors):doors(doors){
	}	

	Building(const Building &other){
		doors = other.doors;
		std::cout << "copy building" << std::endl;
	}

	virtual void Display() const{
		std::cout << "Number of doors is " << doors << std::endl;
	}
};

class Library: public Building{
private:
	int books;
public:
	Library(int doors, int books): Building(doors),books(books){
	}

	void Display() const override{
		std::cout << "Number of books this library has is: " << books << std::endl;
		std::cout << "Number of doors this library has is " << doors << std::endl;
	}
};

int main(){
	Building buildingA = Building(3);
	//prints "Number of doors is 1"
	buildingA.Display(); 

	Library libraryA = Library(5,1000);
	//prints "Number of books in this library has is 1000"
	//prints "Number of doors this library has is 5"
	libraryA.Display(); 

	//The Library part of libraryA is sliced off
	Building libraryBuilding = libraryA;
	//prints "Number of doors is 5"
	libraryBuilding.Display();

	

}
