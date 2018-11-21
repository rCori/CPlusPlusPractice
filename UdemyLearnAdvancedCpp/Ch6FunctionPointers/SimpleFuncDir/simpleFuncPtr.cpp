/* simpleFuncPtr.cpp
 *
 * Just a basic demonstration of using function pointers
 * Also a simple example of lambda expressions
 */

#include <iostream>
#include <vector>

//Returns count of how many integers in a vector meet
//the conditions of the condition function
int meetsConditions(std::vector<int> &intVec, bool (*condition)(int candidate)){
	int count = 0;
	//Iterate through all integers and test if they meet the condition 
	for(std::vector<int>::iterator iter = intVec.begin(); iter != intVec.end(); iter++){
		bool conditionMet = condition(*iter);
		//If the condition is met then add to the count
		if(conditionMet){
			count++;
		}
	}
	return count;
}

bool greaterThan5(int candidate){
	return (candidate > 5);
}

int main(){
	//Test our function that uses a function pointer parameter
	std::vector<int> intVec1{1,2,3,4,5,6,7,8};
	int candidatesMet = meetsConditions(intVec1,greaterThan5);
	std::cout << "From the vector {1,2,3,4,5,6,7,8}, "
			<< candidatesMet << " meet the criteria of greaterThan5."
			<< std::endl;
	
	std::vector<int> intVec2{-1,1,-2,2,-3};
	candidatesMet = meetsConditions(intVec2, [](int i) -> bool {return i > 0;});
	std::cout << "From the vector {-1,1,-2,2,-3}, "
			<< candidatesMet << " meet the criteria of "
			"the lamda expression: [](int i) -> bool {return i > 0;}"
			<< std::endl;
}
