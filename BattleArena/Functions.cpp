#include <iostream>
#include <string>
#include <ctime>
#include "Classes.h"
#include <thread>
hero Ezio{ "Ezio Auditore",55,25,10,8 };
hero Edward{ "Edward James Kenway", 55,25,10,6 };
hero Altaire{ "Altaire Ibn-La'Ahad",50,20,10,9 };

hero Haythem{ "Grand Master Haythem Kenway",65,30,9,12 };
hero Shay{ "Shay Cormac The Rogue",65,30,10,12 };
hero Cesare{ "Lord Cesare Borgia",70,20,9,14 };

hero Assassins[3]{ Ezio,Edward,Altaire };
hero Templars[3]{ Haythem,Shay,Cesare };
int x, y, temp;
int assassinsAlive = 3;
int templarsAlive = 3;
int targetTemplar = 0;
int targetAssassin = 0;
bool assassinsRemaining(int assassins) {
	if (assassins > 0) {
		return true;
	}
	else if (assassins <= 0) {
		return false;
	}
}
bool templarsRemaining(int templars) {
	if (templars > 0) {
		return true;
	}
	else if (templars <= 0) {
		return false;
	}
}

void gameLoop() {
	while (assassinsAlive  && templarsAlive != 0) {
		if (assassinsRemaining(assassinsAlive >0))
		{
			cout << "<<<<ASSASSIN'S TURN>>>>" << endl;
			for (int i = 0; i < 3; i++)
			{

				if (templarsAlive > 0) {

					this_thread::sleep_for(std::chrono::seconds(1));
					if (Assassins[i].remainingHealth(Assassins[i].health)) {
						cout << Assassins[i].name << " Attacks: " << Templars[targetTemplar].name << " for " << Assassins[i].attack << " damage. " << endl;
						cout << " " << endl;
						this_thread::sleep_for(std::chrono::seconds(1));
						int damage = Assassins[i].attack;
						Templars[targetTemplar].takeDamage(damage);
						cout << Templars[targetTemplar].name << "'s Remaining Health is: " << Templars[targetTemplar].health << endl;
						cout << " " << endl;
						if (Templars[targetTemplar].hasHealth() == false)
						{
							--templarsAlive;

							cout << "The Templar " << Templars[targetTemplar].name << " falls" << endl;
							++targetTemplar;
							cout << " " << endl;
							cout << "There is " << templarsAlive << " Templars left" << endl;
							cout << " " << endl;
							this_thread::sleep_for(std::chrono::seconds(1));

						}
					}
				}
			}

		}
		if (assassinsAlive>0)
		{
			cout << "++++TEMPLAR'S TURN++++" << endl;

			for (int i = 0; i < 3; i++)

			{
				if (assassinsAlive > 0) {

					this_thread::sleep_for(std::chrono::seconds(1));
					if (Templars[i].remainingHealth(Templars[i].health)) {
						cout << Templars[i].name << " Attacks: " << Assassins[targetAssassin].name << " for " << Templars[i].attack << " damage." << endl;
						cout << " " << endl;
						this_thread::sleep_for(std::chrono::seconds(1));
						int damage = Templars[i].attack;
						Assassins[targetAssassin].takeDamage(damage);
						cout << Assassins[targetAssassin].name << "'s Remaining Health is:  " << Assassins[targetAssassin].health << endl;
						cout << " " << endl;
						if (Assassins[targetAssassin].hasHealth() == false)
						{
							--assassinsAlive;
							cout << "The Assasin " << Assassins[targetAssassin].name << " is bested" << endl;
							++targetAssassin;
							cout << "There is " << assassinsAlive << " Assassin's left." << endl;
							cout << " " << endl;
							this_thread::sleep_for(std::chrono::seconds(1));

						}
					}
				}

			}
		}



	}
	if (assassinsAlive <= 0) {
		cout << "The battle is over." << endl;
		cout << "The Templars have won." << endl;
	}
	else if (templarsAlive <= 0) {
		cout << "The battle is over." << endl;
		cout << "The Assassins have won." << endl;
	}



}
void attackrand() {
	for (int i = 0; i < 3; i++) {

		srand((int)time(0));
		Assassins[i].attack = Assassins[i].attack + rand() % Assassins[i].strength;
		Templars[i].attack = Templars[i].attack + rand() % Templars[i].strength;
	}
}
void healthrand() {
	for (size_t i = 0; i < 3; i++)
	{
		srand((int)time(0));
		Assassins[i].health = Assassins[i].health + rand() % Assassins[i].endurance;
		Templars[i].health = Templars[i].health + rand() % Templars[i].endurance;
	}


}
void intro() {
	cout << "ASSASSIN'S VS TEMPLARS" << endl;
	cout << "OUR ASSASSINS ARE" << endl;
	cout << Assassins[0].name << endl;
	cout << Assassins[1].name << endl;
	cout << Assassins[2].name << endl;
	cout << "AND OUR TEMPLARS ARE" << endl;
	cout << Templars[0].name << endl;
	cout << Templars[1].name << endl;
	cout << Templars[2].name << endl;
}
void sorting() {


	for (int i = 0; i<3; i++)
	{
		for (y = i + 1; y<3; y++)
		{
			if (Assassins[i].health>Assassins[y].health)
			{
				temp = Assassins[i].health;
				Assassins[i].health = Assassins[y].health;
				Assassins[y].health = temp;
			}
		}
	}
	for (int i = 0; i<3; i++)
	{
		for (y = i + 1; y<3; y++)
		{
			if (Templars[i].health>Templars[y].health)
			{
				temp = Templars[i].health;
				Templars[i].health = Templars[y].health;
				Templars[y].health = temp;
			}
		}
	}
}