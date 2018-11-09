/* simpleCalculator.h
 * Template class example with addition, subtraction, multiplication,
 * and division.
 * This is by no means a useful class, but it demonstrates how
 * template classes canb asically be used
 */

#ifndef __SIMPLE_CALC_H__
#define __SIMPLE_CALC_H__

template<class T>
class SimpleCalculator{
private:
	T a;
	T b;

public:
	/* Having only 1 template type restricts what
	 * kind of operations we can do (we can only add
	 * floats to floats, not ints to floats), but it
	 * simplifies the return types of all member functions
	 */
	SimpleCalculator(T a, T b){
		this->a = a;
		this->b = b;
	}
	
	/* Ugly we to reassign the numbers(but not the type!)
	 * in case we want to reuse the object
	 */
	void SetNumbers(T a, T b){
		this->a = a;
		this->b = b;
	}
	
	/* Not much to say on any of these functions except we 
	 * have made the assumption that the result of any of the
	 * binary operators +, -, *, / with any template class T
	 * we use is another T. This may not always be true.   
	 */
	T Add(){
		return a + b;
	}

	T Subtract(){
		return a - b;
	}

	T Multiply(){
		return a * b;
	}

	T Divide(){
		return a / b;
	}
};

#endif
