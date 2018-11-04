/* enemy.h
 */
#ifndef __ENEMY_H__
#define __ENEMY_H__

#include <iostream>

using namespace std;
class Enemy{
public:
	Enemy();
	Enemy(string name,int health,int damage);
	Enemy(const Enemy &other);
	~Enemy();
	const Enemy &operator=(const Enemy &other);
	string GetName() const;
	int DoDamage(int playerHealth) const;
	int TakeDamage(int playerDamage);

private:
	string name;
	int health;
	int startingHealth;
	int damage;

//This operator is not a class function
//Our implementation of the left-bit shift operator << requires
//access of private members of the Enemy class so we must declare
//it as a friend to get that access outside of a class function
//otherwise this prototype would need to be declared outside of this
//class
friend ostream &operator<<(ostream &out, const Enemy &c);

};


#endif
