#include <iostream>
#include <fstream>

int main(){

	std::string fileName = "playerData.txt";

	//For the sake of example we will use an fstream and open
	//with the argument ios::in instead of using an ifstream
	std::fstream input;
	input.open(fileName, std::fstream::in);

	//If we failed to open return now with an error code 1
	if(!input.is_open()){
		std::cout << "Failed to open file " << fileName << std::endl;
		return 1;
	}

	//Now read the lines of the file
	while(input){
		std::string line;
		//Use getline's delimetter param to take advantage of how
		//we put '-' between data name and value
		getline(input, line, '-');
		
		//C++ cannot use a string in a switch case so we must
		//cascade if statements using the compare function
		//on the expected names to print out the values correctly
		if(line.compare("Level") == 0){
			int level;
			input >> level;
			std::cout << "This character has reached the level of " 
				<< level << std::endl;
		} else if(line.compare("Name") == 0){
			std::string name;
			input >> name;
			std::cout << "The character's name is " << name
				<< std::endl;
		} else if(line.compare("Gold") == 0){
			int gold;
			input >> gold;
			std::cout << "Character is holding " << 
				gold << " gold" << std::endl;
		}
		input >> std::ws;
	}
	input.close();
	return 0;
}
