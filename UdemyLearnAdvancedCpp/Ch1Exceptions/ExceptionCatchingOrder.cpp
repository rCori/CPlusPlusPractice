//ExceptionCatchingOrder.cpp

#include <iostream>
#include <exception>

void testErrorCode(int input) {
	switch(input){
		case 1:
			throw std::exception();
			break;
		case 2:
			throw std::runtime_error("runtime_error thrown");
			break;
		case 3:
			throw std::overflow_error("overflow_error thrown");
			break;
	}
}

/* This is the incorrect way to catch exceptions.
 * The ordering of the catch blocks is such that the first 
 * catch(std::exception) will catch everything
 */
void testErrorCatchingWrongOrder(int input){
	try{
		testErrorCode(input);
	} catch (std::exception &e){
		//This is the only catch that will get used.
		//It preceedes all other catch blocks which are
		//children of std::exception
		//You do not catch twice
		std::cout << "std::exception caught in testErrorCatchingWrongOrder" 
			<< std::endl;
	} catch (std::runtime_error &e){
		//Will never be caught here
		//runtime_error is a child class of exception
		std::cout << "std::runtime_error caught in testErrorCatchingWrongOrder" 
			<< std::endl;
	} catch (std::overflow_error &e){
		//Will never be caught here
		//overflow_error is a child class of runtime_error
		std::cout << "std::overflow_error caught in testErrorCatchingWrongOrder" 
			<< std::endl;
	}	
}


/* This will catch exceptions thrown by testErrorCode
 * in the correct manner
 * The catch blocks will be order from child to parent
 * so any child class exception will be used to catch it's
 * specific type
 * Exceptions not of that child type will go up the parent
 * tree until getting to std::exception which includes all
 * possible c++ exceptions, including user defined ones 
 */
void testErrorCatchingCorrectly(int input){
	try{
		testErrorCode(input);
	} catch(std::overflow_error &e){
		//Will catch overflow_errors and not runtime_errors
		//or base parent exceptions
		std::cout << "std::overflow_error caught in "
			"testErrorCatchingCorrectly" << std::endl;
	} catch(std::runtime_error &e){
		//Will catch runtime_errors but not overflow_errors
		//or base parent exceptions
		std::cout << "std::runtime_error caught in "
			"testErrorCatchingCorrectly" << std::endl;
	} catch(std::exception &e){
		//Will catch std::exception and any other exception
		//except for any type of runtime_error
		std::cout << "std::exception caught in "
			"testErrorCatchingCorrectly" << std::endl;
	}
}


int main(){
	//This is the wrong exception catch order
	testErrorCatchingWrongOrder(1);
	testErrorCatchingWrongOrder(2);
	testErrorCatchingWrongOrder(3);

	testErrorCatchingCorrectly(1);
	testErrorCatchingCorrectly(2);
	testErrorCatchingCorrectly(3);

	return 0;
}
