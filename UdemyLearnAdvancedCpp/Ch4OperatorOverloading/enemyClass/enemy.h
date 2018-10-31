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
	const Enemy &operator=(const Enemy &other);

private:
	string name;
	int health;
	int startingHealth;
	int damage;

friend ostream &operator<<(ostream &out, const Enemy &c);

};


#endif
