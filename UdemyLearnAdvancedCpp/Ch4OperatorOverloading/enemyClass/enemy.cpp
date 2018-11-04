/* enemy.cpp
 */

#include "enemy.h"

Enemy::Enemy():name(""),startingHealth(1),health(1),damage(1){
	cout << "A blank nothing enemy stares you down" << endl;
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

Enemy::~Enemy(){
	cout << "Destructor" << endl;
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

string Enemy::GetName() const {
	return name;
}

int Enemy::DoDamage(int playerHealth) const{
	int newPlayerHealth = playerHealth - damage;
	if(newPlayerHealth <= 0){
		cout << "Player has died" << endl;
	}
	return newPlayerHealth; 
}


int Enemy::TakeDamage(int playerDamage){
	health -= playerDamage;
	if(health <= 0){
		cout << name << " has been slain" << endl;
	}
	return health;
}

ostream &operator<<(ostream &out, const Enemy &c){
	out << c.name << " has " << c.health << "/" 
			<< c.startingHealth << " and has damage level "
			<< c.damage << endl;
	
	return out;
}
