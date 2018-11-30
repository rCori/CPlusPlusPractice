/* NestedTemplateClass.cpp
 * Example of a nested template class
 * The top level class will be a template class and
 * the nested class will not be.
 * We will be able to use the template type in the nested class
 */

#include <iostream>

template<class T>
class OuterClass{
public:
	//This is like a foward declaration of the class
	class NestedClass;
};

template<class T>
class OuterClass<T>::NestedClass{
public:
	//This will understand the template type T of OuterClass
	void printType(){
		std::cout << "Type of T is: " << typeid(T).name() << std::endl;
	}
};

int main(){
	//Demonstrate
	OuterClass<int>::NestedClass intNested;
	intNested.printType();

	OuterClass<char>::NestedClass charNested;
	charNested.printType();
}
