#include "Boss.h"
//This is the Bosses new hp or the amount of health they'll take. This overrides the hp and health that is declered in the character parent class.
Boss::Boss(string name) :Character(name) {
	this->hp = 35;
	this->health = 55;
};

//The Bosses method of attack that is displayed when they attacks.
void Boss::DividingSlash() {
	cout << "I shall balance this world with my DIVIDING SLASH!!!." << endl;
}
//The info that is displayed at the end of the game if the user asks for it.
void Boss::Help() {
	cout << "The World Slayer!" << endl;
}

int GreyBattle() {
	
	//The initials for GameStructure, which makes it easier to call on.
	GmStrct GS;
	//This is what I use for the while loop when I need the user to give an input for if they want it to restart or end the game.
	//The name and initial for the basic character
	Character C("Buggy");
	Dark D("Venti");
	Light L("Aura");
	Boss B("Nuet");

	//This integer will tll us which round we're on as the fight goes on.
	int round = 1;
	//This while loop will repeat until a character loses all of their health.
	while (true) {
		//The round integar will be displayed here.
		cout << "Round " << round << ", fight!!!" << endl;
		//This calls on the TurnRoll in GameStructure, where a characters turn is decided. The if loop decides what occurs when the random umber gives a 1 or 0 as a signal.
		if (GS.TurnRoll()) {
			//If a 1 is returned, or the number is greater than or equal to 5, the Dark & Light will attack.
			//This will display the Dark's and Light's name.
			cout << D.getName() << " attacks.\n";
			cout << L.getName() << " attacks.\n";
			//This calls on the ThrowStars function in Dark and Light, which is their power.
			D.ShadowSpike();
			L.FlashBurn();
			//This means that Boss will lose as much health as Dark and Light has for hp.
			B.loseHealth(D.Attack());
			B.loseHealth(L.Attack());
		}
		//If the first staement isn't true or if a 0 is returned instead of a 1, then this will occur, which means that the Boss will attack.
		else {
			//This displays the Bosses name.
			cout << B.getName() << " attacks.\n";
			//This calls on the UseSword function from the Boss class. This is the Bosses prefered method of attack.
			B.DividingSlash();
			//This means that the Dark & Light loses as much health as the Boss has for hp.
			D.loseHealth(B.Attack());
			L.loseHealth(B.Attack());
		}
		try {
			//These two if loops will scan the new health and see if any of the characters are at 0. If any of them are at 0, the loop will break and go back to the main funtion, when the user will be asked to leave or restart the game.
			if (L.getHealth() <= 0) {
				cout << "Darkness has consumed " << L.getName() << "!" << endl;
				throw 101;
			}
			if (D.getHealth() <= 0) {
				cout << D.getName() << " has been slain!" << endl;
				throw 101;
			}
			if (B.getHealth() <= 0) {
				cout << B.getName() << " Has fallen and the outer worlds have won!" << endl;
				break;
			}
		}
		catch (int Loser) {
			cout << Loser << " You Have Lost!" << endl;
			B.Help();
			break;
		}

		//If both characters still have health, their health is displayed and the loop is back at the top.
		cout << D.getName() << "'s health is now " << D.getHealth() << "." << endl;
		cout << L.getName() << "'s health is now " << L.getHealth() << ". \n" << endl;
		
		//This the program to add a number to the round every time a round or the loop starts over.
		round++;
	}
}

void Boss::GreyWorld() {
    int WarMngr;
    Character C("Buggy");
    Dark D("Venti");
    Light L("Aura");
    Boss B("Nuet");
    //This again integar tells the program to go back to the beginning of the while loop, when the user gives a 1 as their choice. Without this, the program will break and go into a loop until the program is closed.
    int again = 1;
    //The beginning of while loop, which enables the user to come back to the point if the user wants to restart the program.
	while (again == 1) {
		cout << "So you have slain your enemy, but can you slay me, " << B.getName() << "?" << endl;
		cout << "I represent this grey world and I'm seeing your people look down on us and lay waste." << endl;
		cout << "Prepare to fight for your world along side your enemy!\n" << endl;
		GreyBattle();
		cout << "You have slain the World Destroyer and have found an ally that you once called foe. \nShall this start a new era of peace!" << endl;
		break;
	}
}
