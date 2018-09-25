#include <iostream>
#include <fstream>

int main(){

	std::string outputFile = "output.txt";

	std::fstream output;
	output.open(outputFile,std::fstream::out);

	if(!output.is_open()){
		std::cout << "Could not open file to write " 
			<< outputFile << std::endl;
		return 1;
	}
}
