/* LambdaTest.cpp
 * C++ 11 started supporting lambda expressions
 * Labda expressions are a functional programming construct
 * that was brought over to more typical OOP and procedural
 * languages
 */

#include <iostream>

void doMath(int (*mathFuncPtr)(int first,int second),int first,int second){
	std::cout << "Result of the math: " 
			<< mathFuncPtr(first,second) << std::endl;
}

int main(){
	//Create a lambda for adding 2 ints together
	//The actual type of a lambda is complicated so
	//it's a good idea to use auto here.
	auto addFunc = [](int x, int y) { return x+y; };
	
	//We can now use addFunc like a regular function even
	//though it's variable of a lambda type
	int addResult = addFunc(2,3);
	std::cout << "The result of calling addFunc lambda: " 
			<< addResult << std::endl;

	//Here we use the lambda expression as a functor or function
	//pointer like object
	doMath(addFunc,10,20);

	//We can also create it directly as an impllicit function
	//Very javascript like usage here.
	doMath([](int x, int y){return x-y;},12,4);

}
