/* Using a STL Map to create a "database" of users that
 * can be edited and read from.
 *
 * by: Ryan Cori
 */

#include <stdexcept>
#include <iostream>
#include <map>

class User
{
private:
	std::string name;
	int age;
public:
	std::string GetName(){ return name; };
	int GetAge(){ return age; };

	void SetName(std::string name){
		this->name = name;
	}

	void SetAge(int age){
		this->age = age;
	}
};

int readCommand(int command, std::map<int,User>& userMap){
	switch(command){
		case 1:
		break;
		case 5:
			return 1;
		default:
		break;
	}
	return -1;
}

int main(){
	std::map<int, User> userMap;
	int status = 0;
	while(status != 1){
		std::cout << "Please enter number for a command" << std::endl;
		std::cout << "1: View user" << std::endl;
		std::cout << "2: Add user" << std::endl;
		std::cout << "3: Edit user" << std::endl;
		std::cout << "4: Delete user" << std::endl;
		std::cout << "5: Exit program" << std::endl;
		std::string command;
		std::cin >> command;
		try{
			int cmdInt = std::stoi(command);
			status = readCommand(cmdInt,userMap);
		} catch(const std::invalid_argument& e){
			std::cout << "Invalid Command" << std::endl;
		}
	}
	return 0;
}
