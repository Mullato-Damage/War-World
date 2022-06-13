#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;
//The main function that is defined in the War Worlds.cpp file
int main();

class GmStrct
{
public:
	//This random number generator will pull a number from 1-100. If it lands exactly on 50, A disastorous alien will join the fight.
	//This is the extra credit requirement.
	int RandomRoll() {
		//This will tell the system to use the time cycle that is used by the computer.
		srand(time(0));
		//int Rroll is now the same as the random number generator, which means that we have a term that we can call if we want the number that is generated.
		// rand is the start of the cycle and 100 is our limit. In a normal number generator, this would pull numbrs from 0-99, but 1 is added to ours, so now it's 1-100
		int Rroll = (rand() % 100) + 1;
		//The return value is if Rroll or the random number is 50. if it is, then it will send a 1 or true signal to where it's called.
		return (Rroll == 50) ? 1 : 0;

	}
	//This random number generator pulls a number between 1-10. This will dictate who attacks, based on if the number is higher/equal to 5 or lower than 5.
	int TurnRoll() {
		srand(time(0));
		//This random number generator functions like RandomRoll, but goes through 1-10, instead of 1-100.
		int Troll = (rand() % 10) + 1;
		//The return value is if the number is greater than or equal to 5, which will send a signal if it is.
		return (Troll >= 5) ? 1 : 0;

	}
	//Help will tell the user what the character can do. details found in specific characters.
	void Help();

};

