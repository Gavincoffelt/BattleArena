
#pragma once
#include <iostream>
#include <string>

using namespace std;
class hero {
public:
	string name; int health; int attack; int strength; int endurance;
	void takeDamage(int damage) {
		health -= damage;
		if (health < 0) {
			health = 0;
		}
	}
	bool remainingHealth(int health) {
		if (health > 0) {
			return true;
		}
		else {
			return false;
		}
	};
	bool hasHealth() {
		if (health > 0) {
			return true;
		}
		else {
			return false;
		}
	}
};


void sorting();
void intro();
void healthrand();
void attackrand();
void gameLoop();
