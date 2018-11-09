/* calculatorTest.cpp
 * Showing usage of the SimpleCalculator class
 */

#include "simpleCalculator.h"
#include <iostream>

int main(){
	SimpleCalculator<float> simpleCalc(1.5,2.5);
	std::cout << "1.5 + 2.5 = " << simpleCalc.Add() << std::endl;
	std::cout << "1.5 - 2.5 = " << simpleCalc.Subtract() << std::endl;
	std::cout << "1.5 * 2.5 = " << simpleCalc.Multiply() << std::endl;
	std::cout << "1.5 / 2.5 = " << simpleCalc.Divide() << std::endl;

	SimpleCalculator<int> simpleCalcInt(2,5);
	std::cout << "2 + 5 = " << simpleCalcInt.Add() << std::endl;

	simpleCalcInt.SetNumbers(3,10);
	std::cout << "3 + 10 = " << simpleCalcInt.Add() << std::endl;
}
