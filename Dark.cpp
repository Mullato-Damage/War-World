#include "Dark.h"
#include "Character.h"


//This is the Dark's new hp or the amount of health they'll take. This overrides the hp that is declered in the character parent class.
Dark::Dark(string name) :Character(name) {
	this->hp = 25;
};

//The Dark's method of attack that is displayed when they attacks.
void Dark::ShadowSpike() {
	cout << "SHADOW SPIKES GO!!!" << endl;
}
//The info that is displayed at the end of the game if the user asks for it.
void Dark::Help(){
	cout << "Help: Darkness consumes the light with it's great power!\n" << endl;
}

int DarkBattle() {
	//The integer that tells the timer to hold for 2 seconds.
	//int delay = 3;
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
		//When round turns to 3, this will display the characters banter.
		if (round == 3) {
			C.Talk("Aura", "Bloodbath");
		}
		//The round integer will be displayed here.
		cout << "Round " << round << ", fight!!!" << endl;
		//This calls on the TurnRoll in GameStructure, where a characters turn is decided. The if loop decides what occurs when the random umber gives a 1 or 0 as a signal.
		if (GS.TurnRoll()) {
			//If a 1 is returned, or the number is greater than or equal to 5, the Dark will attack.
			//This will display the Dark's name
			cout << D.getName() << " attacks.\n";
			//This calls on the ShadowSpike function in Dark, which is their power.
			D.ShadowSpike();
			//This means that Light will lose as much health as Dark has for hp.
			L.loseHealth(D.Attack());
		}
		//If the first staement isn't true or if a 0 is returned instead of a 1, then this will occur, which means that the Light will attack.
		else {
			//This displays the Lights name.
			cout << L.getName() << " attacks.\n";
			//This calls on the FlashBurn function from the Light class. This is the Light prefered method of attack.
			L.FlashBurn();
			//This means that the Dark loses as much health as the Light has for hp.
			D.loseHealth(L.Attack());
		}
		try {
			//These two if loops will scan the new health and see if any of the characters are at 0. If any of them are at 0, the loop will break and go back to the main funtion, when the user will be asked to leave or restart the game.
			if (L.getHealth() <= 0) {
				cout << "Darkness has consumed " << L.getName() << "!" << endl;
				cout << "A strong breeze passes by as a grey slash cuts into the ground before you." << endl;
				cout << "A strong being emerges from the blast, glaring at you and your lifeless enemy. \nHe raises his hands and you watch your enemy come back to life." << endl;
				break;
			}
			if (D.getHealth() <= 0) {
				cout << D.getName() << " has been slain!" << endl;
				throw 101;
			}
		}
		catch (int Loser) {
			cout << Loser << " You Have Lost!" << endl;
			D.Help();
			break;
		}

		//If both characters still have health, their health is displayed and the loop is back at the top.
		cout << D.getName() << "'s health is now " << D.getHealth() << "." << endl;
		cout << L.getName() << "'s health is now " << L.getHealth() << ". \n" << endl;
		//The prupose of the timer is so the user can have a chance to follow the battle instead of getting all of the data at once.
		//This tells the program that whatever int/number delay is, it will be counted in seconds.
		//delay *= CLOCKS_PER_SEC;
		//This tells the program that clock_t now is the same thing as clock().
		//clock_t now = clock();
		//while the program is going, the clock or current time will decrease by the current time, which should be less than the delay int. Once it isn't less than the delay, it'll stop the delay.
		//while (clock() - now < delay);
		//This the program to add a number to the round every time a round or the loop starts over.
		round++;
	}
}

int Dark::DarkWorld() {
	int WarMngr;
    Character C("Buggy");
    Dark D("Venti");
    Light L("Aura");
    Boss B("Nuet");
	//This again integar tells the program to go back to the beginning of the while loop, when the user gives a 1 as their choice. Without this, the program will break and go into a loop until the program is closed.
	int again = 1;
	//The beginning of while loop, which enables the user to come back to the point if the user wants to restart the program.
	while (again == 1) {
		cout << "Our enemies are strong, but we will reign supreme! \nNow Stand Tall " << D.getName() << ", you shall fight for us!" << endl;
        cout << "The Light's top fighter is " << L.getName() << ". so watch your step." << endl;
		cout << "Prepare to fight for our world!\n" << endl;
		DarkBattle();
		B.GreyWorld();
        //This is the portion that tells the user if they want to use again to restart the test or the exit(0) to exit the program.
        cout << "You can now make the choice to 1.restart this section, 2.quit, or 3.restart the game \nChoose the number that corresponds with what you want to do." << endl;
        //The input that the user will give to restart this section, the entire game, or exit the game.
        cin >> WarMngr;
        //With a 1, the program will go to the top of the while loop.
        if (WarMngr == 1) {
            //This restarts this section fromm the beginning of the function.
            again;
        }
        //With a 2, the program will end, using the end(0) at the end. 
        else if (WarMngr == 2) {
            cout << "Goodbye Warriors!" << endl;
            //This takes the user out of the program entirely.
            exit(0);
        }
        else {
            cout << "Back To The Beginning!!\n" << endl;
            main();
        }
	}

}