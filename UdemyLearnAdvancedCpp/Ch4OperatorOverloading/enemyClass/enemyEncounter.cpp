/*enemyEncounter.cpp
 * Use the Enemy class, a while loop, and some random 
 * number generation to do a simple RPG battle system
 *
 */
#include "enemy.h"
#include <vector>
#include <time.h>

void printPlayerPrompt(){
	cout << "Player Attacks!" << endl;
	cout << "1. Attack" << endl;
	cout << "2. Run Away" << endl;
}

int main(){
	//We create this vector and researve enough memory as not
	//to call the copy constructor when a new element is
	//added
	vector<Enemy> enemyVec;
	enemyVec.reserve(100);
	//This should push the object into the vector without calling
	//the copy constructor.
	//Otherwise we must use pointers
	enemyVec.emplace_back("Bat A",10,1);

	cout << enemyVec[0] << endl;

	int UserHealth = 20;
	int UserDamage = 5;
	int command;
	
	printPlayerPrompt();
	while(cin>>command){
		if(enemyVec.empty() || UserHealth <= 0){
			break;
		}	
		//Declare this up here so if they choose to exit we can
		//set to true in the switch-case
		bool exiting = false;
		//Using a switch-case, although this may be less performant
		switch(command){
		case 1:
			{
			//Pick a random enemy to target
			int targetEnemy = (rand() % enemyVec.size()) - 1;
			int remainingHealth = enemyVec[targetEnemy].TakeDamage(UserDamage);
			if(remainingHealth <= 0){
				enemyVec.erase(enemyVec.begin() + targetEnemy);
				break;
			}
			printPlayerPrompt();
			}
			break;
		case 2:
			exiting = true;
			break;
		default:
			cout << "Invalid command" << endl;
			break;
		}

		if(exiting){
			break;
		}	
	}
	
	/*
	while(cin>>command){
		cout << "Type \"exit\" to end" << endl;
		if(command.compare("exit")){
			cout << "exiting" << endl;
			break;
		}
		cout << "loop continues" << endl;
	}
	*/

}


