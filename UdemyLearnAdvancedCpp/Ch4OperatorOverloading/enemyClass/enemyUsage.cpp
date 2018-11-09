/* enemyUsage.cpp
 * Simple example of using enemy class's copy constructor
 * left bit-shift(<<) operator and assignment(=) operator
 */

#include "enemy.h"

int main(){
	//Use the standard constructor
	Enemy enemyA = Enemy("Bat A", 10, 1);

	//Usage of copy constructor
	Enemy enemyB = enemyA;

	//Usage of left bit-shift operator
	std::cout << enemyA << std::endl;
	std::cout << enemyB << std::endl;

	//Use some of the encounter functions
	int playerHealth = 10;
	int playerDamage = 5;

	//Player takes some damage from "Bat A"
	playerHealth = enemyA.DoDamage(playerHealth);

	//Player does damamge to "Bat B"
	enemyB.TakeDamage(playerDamage);
}
