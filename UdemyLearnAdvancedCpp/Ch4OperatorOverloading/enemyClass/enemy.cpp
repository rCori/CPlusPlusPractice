/* enemy.cpp
 */

#include "enemy.h"

Enemy::Enemy():name(""),startingHealth(1),health(1),damage(1){
}


Enemy::Enemy(const Enemy &other){
	name = other.name;
	char lastChar = name.back();
	lastChar++;
	name = name.substr(0,name.size()-1) + lastChar;
	
	health = other.startingHealth;
	startingHealth = other.startingHealth;
	damage = other.damage;

	cout << name << " has joined " << other.name << endl; 
}


Enemy::Enemy(string name,int health,int damage):name(name),startingHealth(health),health(health),damage(damage){
	cout << name << " starts a fight" << endl;
}

const Enemy &Enemy::operator=(const Enemy &other){
	string originalName = name;
	name = other.name;
	char lastChar = name.back();
	lastChar++;
	name = name.substr(0,name.size()-1) + lastChar;
	
	health = other.startingHealth;
	startingHealth = other.startingHealth;
	damage = other.damage;

	cout << originalName << " has become " << name << endl; 

	return *this;
}


ostream &operator<<(ostream &out, const Enemy &c){
	out << c.name << " has " << c.health << "/" 
			<< c.startingHealth << " and has damage level "
			<< c.damage << endl;
	
	return out;
}
