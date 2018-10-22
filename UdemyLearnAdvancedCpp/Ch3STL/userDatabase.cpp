/* Using a STL Map to create a "database" of users that
 * can be edited and read from.
 *
 * by: Ryan Cori
 */

#include <stdexcept>
#include <iostream>
#include <map>

/*
 * Basic class to demonstrate a custom type as a value in
 * a map
 */
class User
{
private:
	std::string name;
	int age;
public:
	//Constructors using initializer lists
	User():name(""),age(0){};
	User(std::string _name,int _age):name(_name),age(_age){};
	
	//Simple getters and setters
	std::string GetName(){ return name; };
	int GetAge(){ return age; };
	void SetName(std::string name){
		this->name = name;
	}
	void SetAge(int age){
		this->age = age;
	}
};

/*
 * Attempt to view a user record
 * UserID must be entered to display
 * User can exit before entering a userID by entering "exit"
 */
int viewUser(std::map<int,User>& userMap){
	std::cout << "Enter a UserID to view" << std::endl;
	std::cout << "Type \"exit\" to go back to previous menu" << std::endl;
	//Need a valid positive integer and a userID that is not used
	bool acceptedID = false;
	int userID = 0;
	while(!acceptedID){
		std::string userIDStr;
		std::cin >> userIDStr;
		//return early if this is "exit"
		if(userIDStr.compare("exit") == 0){
			return 0;
		}
		//This try-catch block handles the case that the
		//user has not entered something can be converted
		//to a proper integer
		try{
			userID = std::stoi(userIDStr);
			//Ensure the usedID exists
			if(userMap.find(userID) == userMap.end()){
				std::cout << "UserID not found" << std::endl;
				continue;
			}
			acceptedID = true;
		}
		catch(const std::invalid_argument& e){
			std::cout << "Invalid Command" << std::endl;
		}
	}
	//Get the user from the map and print out it's information
	//std::map can be accessed with the [] operator overloaded
	//so it behaves like an array would. We are using integers
	//as keys but unlike an array they do not define an ordering
	//or map location. Value at key "1" should not be thought of
	//as "next to 2"
	User& user = userMap[userID];
	std::cout << "User Name: " << user.GetName() << std::endl;
	std::cout << "User Age: " << user.GetAge() << std::endl;
	return 0;
}


/*
 * Add a game to the user map
 * Error and general input checking must be done on
 * the UserID and age
 */
int addUser(std::map<int,User>& userMap){
	//Print prompt to user
	std::cout << "Adding game:" << std::endl;
	std::cout << "Enter UserID:" << std::endl;
	//Need a valid positive integer and a userID that is not used
	bool acceptedID = false;
	int userID = 0;
	while(!acceptedID){
		std::string userIDStr;
		std::cin >> userIDStr;
		//This try-catch block handles the case that the
		//user has not entered something can be converted
		//to a proper integer
		try{
			userID = std::stoi(userIDStr);
			//Is this userID positive and unique
			//If not a different userID will be needed
			if(userID < 1){
				std::cout << "UserID must be positive" << std::endl;
				continue;
			}
			if(userMap.find(userID) != userMap.end()){
				std::cout << "UserID must be unique" << std::endl;
				continue;
			}
			acceptedID = true;
		}
		catch(const std::invalid_argument& e){
			std::cout << "Invalid Command" << std::endl;
		}
	}

	//Name is a string so we can do straightforward input acceptance
	std::cout << "Enter name:"<<std::endl;
	std::string name;
	std::cin >> name;
	//Safely get the age as an integer
	std::cout << "Enter age:" << std::endl;
	bool acceptedAge = false;
	int age = 0;
	while(!acceptedAge){
		std::string ageStr;
		std::cin >> ageStr;	
		//This try-catch block handles the case that the
		//user has not entered something can be converted
		//to a proper integer
		try{
			age = std::stoi(ageStr);
			acceptedAge = true;
		} catch(const std::invalid_argument& e){
			std::cout << "Invalid Command" << std::endl;
		}
	}
	//Finally create the User and add it to the map
	//We can add to a std::map the same we assign a value
	//in an array with the [] operator overloaded
	userMap[userID] = User(name,age);
	return 0;	
}

/*
 * User a user to the user map
 * Error and general input checking must be done on
 * the UserID and age
 */
int editUser(std::map<int,User>& userMap){
	//Print prompt to the user
	std::cout << "Editing game:" << std::endl;
	std::cout << "Enter UserID:" << std::endl;
	//Need a valid positive integer and a userID that is not used
	bool acceptedID = false;
	int userID = 0;
	while(!acceptedID){
		std::string userIDStr;
		std::cin >> userIDStr;
		//This try-catch block handles the case that the
		//user has not entered something can be converted
		//to a proper integer
		try{
			userID = std::stoi(userIDStr);
			if(userMap.find(userID) == userMap.end()){
				std::cout << "UserID not found" << std::endl;
				continue;
			}
			acceptedID = true;
		}
		catch(const std::invalid_argument& e){
			std::cout << "Invalid Command" << std::endl;
		}
	}
	//Get the selected User(class) from the map so the
	//user(individual at computer) can see what he/she is editing
	User& user = userMap[userID];
	std::cout << "User Name: " << user.GetName() << std::endl;
	std::cout << "User Age: " << user.GetAge() << std::endl;
	
	//Name is a string so we can do straightforward input acceptance
	std::cout << "Enter name:"<<std::endl;
	std::string name;
	std::cin >> name;
	user.SetName(name);
	//Safely get the age as an integer
	std::cout << "Enter age:" << std::endl;
	bool acceptedAge = false;
	int age = 0;
	while(!acceptedAge){
		std::string ageStr;
		std::cin >> ageStr;
		//This try-catch block handles the case that the
		//user has not entered something can be converted
		//to a proper integer
		try{
			age = std::stoi(ageStr);
			acceptedAge = true;
			user.SetAge(age);
		} catch(const std::invalid_argument& e){
			std::cout << "Invalid Command" << std::endl;
		}
	}	
	return 0;	
}

/*
 * Attempt to view a user record
 * UserID must be entered to display
 * User can exit before entering a userID by entering "exit"
 */
int deleteUser(std::map<int,User>& userMap){
	//Print prompt to the user telling them to enter a UserID
	//and that "exit" will bring them out
	std::cout << "Enter a UserID to view" << std::endl;
	std::cout << "Type \"exit\" to go back to previous menu" << std::endl;
	//Need a valid positive integer and a userID that is not used
	bool acceptedID = false;
	int userID = 0;
	while(!acceptedID){
		std::string userIDStr;
		std::cin >> userIDStr;
		//return early if this is "exit"
		if(userIDStr.compare("exit") == 0){
			return 0;
		}
		//This try-catch block handles the case that the
		//user has not entered something can be converted
		//to a proper integer
		try{
			userID = std::stoi(userIDStr);
			//Ensure the usedID exists
			if(userMap.find(userID) == userMap.end()){
				std::cout << "UserID not found" << std::endl;
				continue;
			}
			acceptedID = true;
		}
		catch(const std::invalid_argument& e){
			std::cout << "Invalid Command" << std::endl;
		}
	}
	//std::map::erase removes an element, both key and value
	//from a map by key.
	userMap.erase(userID);
	return 0;
}


int readCommand(int command, std::map<int,User>& userMap){
	int status = 0;
	switch(command){
		//View user
		case 1:
			status = viewUser(userMap);
			return status;
		break;
		//Add user
		case 2:
			status = addUser(userMap);
			return status;
		break;
		//Edit user
		case 3:
			status = editUser(userMap);
			return status;
		break;
		//Delete user
		case 4:
			status = deleteUser(userMap);
			return status;
		break;
		//Exit program
		case 5:
			return 1;
		default:
		break;
	}
	return -1;
}

int main(){
	//Define the map we will use everywhere with pass-by-reference
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
		//We use a try-catch to handle the case of the
		//user not entering something that can be cleanly
		//converted to an int
		try{
			int cmdInt = std::stoi(command);
			status = readCommand(cmdInt,userMap);
		} catch(const std::invalid_argument& e){
			std::cout << "Invalid Command" << std::endl;
		}
	}
	return 0;
}
