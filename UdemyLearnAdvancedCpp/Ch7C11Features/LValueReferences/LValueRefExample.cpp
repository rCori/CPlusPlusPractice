/* LValueRefExample.cpp
 * Quick example of LValue references and their properties
 */

class Test{
private:
	int someVal;
public:
	Test():someVal(0){};
	Test(int someVal):someVal(someVal){};
	Test(const Test &other){
		someVal = other.someVal;
	}
};

Test getTest(){
	return Test();
}

int main(){

	/* The following const scenario would be the same if
	 * we used the Test() constructor instead of the getTest()
	 * function. It just illustrates clearer(to me) when using
	 * the function getTest() instead.
	 */
	//This will fail, mutable lvalues references cannot
	//bind to rvalues
	//Test &test1 = getTest();
	
	//This however will work because an lvalue reference
	//can bind to an rvalue if that lvalue is const.
	//This works because by making this const the lifetime
	//of the temporary value returned by getTest() is extended. 
	const Test &test1 = getTest();

	/*
	 * This constructor usage looks very typical but it demonstrates
	 * something specific about the copy constructor. This only works
	 * because the parameter for a copy constructor is a const reference.
	 * When we create the temporary Test with the constructor Test(1), thats
	 * an unnamed temporary value, a mutable lvalue. But the parameter it
	 * is assigned to is a const reference. By making that assignment the
	 * lifetime of this temporary value is extended so we can actually use
	 * it inside of the copy constructor itself to construct test2.
	 */
	Test test2(Test(1));

}
