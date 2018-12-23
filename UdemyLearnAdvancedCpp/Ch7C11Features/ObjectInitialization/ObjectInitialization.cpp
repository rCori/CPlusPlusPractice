/* ObjectInitialization.cpp
 * This is a basic demonstration of initializing an object
 * which provides C++11 style defaults
 */

#include <iostream>

class Ball{
private:
	float radius{2.0};
	std::string color{"red"};
public:
	//We implement the default constructor because by
	//defining the single argument float constructor we lose it
	//This is required for that one argument constructor to work
	//because otherwise it cannot construct with the default value
	//of color we gave
	Ball() = default;
	//We can explicitly delete the implicit assignment operator
	//This prevents one instance from being assigned the other
	//with the default shallow copy, but it does not prevent
	//copy-initialization, that comes from the copy constructor.
	Ball &operator=(const Ball &other) = delete;
	Ball(float radius):radius(radius){};

	//operator<< defined as a friend because it needs private members
	//of ball	
	friend std::ostream &operator<<(std::ostream &out, const Ball &ball){
		out << ball.color << " Ball has radius of " 
				<< ball.radius;
		return out;
	}

};

int main(){
	Ball ball1(3.5);
	std::cout << ball1 << std::endl;

	Ball ball2;
	std::cout << ball2 << std::endl;

	//This will throw an error becuase we explicitly deleted &operator=
	//ball1 = ball2;
}
