/* SimpleVirtualFunc.cpp
 * This is just a simple demonstration of what virtual functions
 * are and how they differ from non-virtual functions.
 */

#include <iostream>
#include <cmath>

class Shape{
public:

	//This particular behavior makes no logical sense for a Shape
	//class, but it helps demonstrate virtual functions
	virtual void Area() const {
		std::cout << "Cannot give area. Shape is too generic!" << std::endl;
	}

	//By providing no definition to this method, we have made Shape
	//an abstract virtual class. This means Shape cannot be instantiated
	virtual void Circumference() const = 0;

	//Parent classes should always have virtual destructors defined
	//Despite that rule, this destructor actually does nothing.
	virtual ~Shape(){
	}
};

class Square:Shape{
public:
	//The constructor we will actually want to use
	Square(int sideLength){
		this->sideLength = sideLength;
	}

	void Area() const override {
		std::cout << "Area of Square: " << std::pow(sideLength,2) << std::endl;
	}

	void Circumference() const override {
		std::cout << "Circumference of Square: " << sideLength*4 << std::endl;
	}
	
	//This constructor does nothing, just like it's parent
	~Square(){
	}

private:
	int sideLength;
};


class OddShape:Shape{
public:
	OddShape(){
	}

	//We must define something here because Shape is a 
	//pure virtual class
	void Circumference() const override {
		std::cout << "I don't know what the circumference of this thing is!" << std::endl;
	}

	//This constructor does nothing, just like it's parent
	~OddShape(){
	}
};

int main(){
	
	//The virtual polymorphism works with pointers, references, and regular objects
	const Square &squareRef = Square(2);
	squareRef.Area(); //prints "Area of Square: 4"
	squareRef.Circumference(); //prints "Circumference of Square: 8"

	const Square *squarePtr = new Square(3);
	squarePtr->Area(); //prints "Area of Square: 9"
	squarePtr->Circumference(); //prints "Circumference of Square: 12"
	delete squarePtr;

	Square square = Square(4);
	square.Area(); //prints "Area of Square: 16"
	square.Circumference(); //prints "Circumference of Square: 12"

	//This will not work because Shape is abstract virtual, which makes this casting illegal
	//const Shape &oddShapeRed = OddShape();
	//OddShape can be instantiated because it defines the pure-virtual function Circumference
	const OddShape &oddShapeRef = OddShape();
	oddShapeRef.Circumference(); //prints "I don't know what the circumference of this thing is!"

	const OddShape *oddShapePtr = new OddShape();
	oddShapePtr->Circumference(); //prints "I don't know what the circumference of this thing is!"
	delete oddShapePtr;
	
	OddShape oddShape = OddShape();
	oddShape.Circumference(); //prints "I don't know what the circumference of this thing is!"
}
