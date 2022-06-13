#include "Character.h"

//This declares what a basic charcter has.
Character::Character(string name) {
	//This tells the program that name is the string name that is stored in private.
	this->name = name;
	//This tells the program that a characters health is 100.
	this->health = 50;
	//This tells the program that a normal charcter can deal 10 damage or hit points.
	this->hp = 10;

}
//The function that explains how much health a character loses. As explained in the character header, a charcters attack function will usually be placed in the parenthesis.
void Character::loseHealth(int hit) {
	//This tells the program that health is subtracted by hit, then the new health is declared and stored.
	this->health -= hit;
	//If a characters health ever reaches below 0, the program will stop it 0 and declare that the character has fallen and has no more health.
	if (this->health < 0) {
		//if 0 is greater than health, then the health is at 0 and the character has fallen.
		this->health = 0;
		cout << "character has fallen.\n";
	}
};

//This is my health getter, which will retrieve the health from the private sector and allow the player to know how much health they have.
int Character::getHealth() {
	return this->health;
}
//The amount of damage a charcter does. This is either displayed or placed in a "losehealth" function.
int Character::Attack() {
	return this->hp;
};
//This tells the system that when getName is called on, it will display the specific charcter's name that is stored in private.
string Character::getName() {
	return this->name;
};

