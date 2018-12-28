
#include <iostream>
using namespace std;

class Shape{
	string color;
public:
	Shape():Shape("red"){
		cout << "No parameter constructor" << endl;
	}

	Shape(string color){
		this->color = color;
		cout << "Using string constructor" << endl;
	}
};

class Rectangle: public Shape{
public:
	int sideLength;
	Rectangle():Shape("green"){
		cout << "Rectangle constructor" << endl;
	}
};

int main(){
	cout << "shape1 constructor" << endl;
	Shape shape1;
	cout << endl;
	cout << "shape2 constructor" << endl;
	Shape shape2("blue");
	cout << endl;
	cout << "rectangle3 constructor" << endl;
	Rectangle rectangle3;
}
