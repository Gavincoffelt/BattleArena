#include <iostream>
#include <string>
#include <ctime>
#include "Classes.h"
#include <thread>

using namespace std;
void healthrand();
void intro();
void sorting();
void gameLoop();
void attackrand();

int main() {

	healthrand();
	attackrand();
	intro();
	gameLoop();

	system("pause");
}
