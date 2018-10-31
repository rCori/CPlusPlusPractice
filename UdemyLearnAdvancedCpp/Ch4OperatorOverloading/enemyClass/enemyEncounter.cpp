#include "enemy.h"
#include <map>

int main(){
	Enemy enemy1 = Enemy("Bat A", 10, 1);
	Enemy enemy2 = enemy1;
	
	map<string,Enemy> enemyMap;

	cout << enemy1 << endl;

	int UserHealth = 20;

	string command = "";

	while(!enemyMap.empty()){
		cin >> command;
		cout << "Click enter to attack" << endl;
		if(command.compare("exit")==0){
			cout << "Player is attacking" << endl;
		}
	}
}
