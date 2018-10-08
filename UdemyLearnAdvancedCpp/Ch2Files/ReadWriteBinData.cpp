/*ReadWriteBinData.cpp
 * Accomplishes 3 tasks
 * 1. Read character data from a text file 
 * 2. Write it to a binary file
 * 3. Read that binary back out to console
 */

#include <iostream>
#include <fstream>
#include <string.h>

#pragma pack(push,1)
struct PlayerData {
	char name[25];
	int level;
	int gold;
};
#pragma pack(pop)


int main(){
	
	/** 1. Read character data from a text file */ 
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


	//Declare PlayerData struct for us to write as binary
	PlayerData playerData;

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
			playerData.level = level;
		} else if(line.compare("Name") == 0){
			std::string name;
			input >> name;
			strcpy(playerData.name,name.c_str());
		} else if(line.compare("Gold") == 0){
			int gold;
			input >> gold;
			playerData.gold = gold;
		}
		input >> std::ws;
	}
	input.close();


 	/** 2. Write it to a binary file */
	std::string binaryFileName = "playerCharacter.bin";

	std::fstream binaryOutputFile;
	binaryOutputFile.open(binaryFileName,std::ios::out|std::ios::binary);
	
	if(!binaryOutputFile.is_open()){
		std::cout << "Failed to open file " << binaryFileName << std::endl;
		return 1;
	}

	//Write binary data to file
	//We must cast the struct as a char* to write the binary
	//data correctly
	binaryOutputFile.write(reinterpret_cast<char*>(&playerData),
		sizeof(PlayerData));
	binaryOutputFile.close();

	/** #3 Read that binary back to console */
	//Now we must reopen the file again and read it to the console
	PlayerData otherPlayerData = {};

	std::fstream binaryInputFile;
	binaryInputFile.open(binaryFileName,std::ios::in|std::ios::binary);

	if(!binaryInputFile.is_open()){
		std::cout << "Failed to open file " << binaryFileName << std::endl;
		return 1;
	}
	
	//Read looks a lot like the write
	binaryInputFile.read(reinterpret_cast<char*>(&otherPlayerData),
		sizeof(PlayerData));
	binaryInputFile.close();

	//Write data from PlayerData struct we just read from the binary file
	std::cout << "From the binary file saved we have:" << std::endl;
	std::cout << "Character's name is " << otherPlayerData.name 
		<< std::endl;
	std::cout << "Character's has " << otherPlayerData.gold
		<< " gold" << std::endl;
	std::cout << "Character has attained level " 
		<< otherPlayerData.level << std::endl; 	
}
