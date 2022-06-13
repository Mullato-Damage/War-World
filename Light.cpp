#include "Light.h"

//This is the Light's new hp or the amount of health they'll take. This overrides the hp and health that is declered in the character parent class.
Light::Light(string name) :Character(name) {
	this->hp = 15;
	this->health = 125;
};

//The Light's method of attack that is displayed when they attacks.
void Light::FlashBurn() {
	cout << "SHALL MY LIGHT BURN YOU!" << endl;
}
//The info that is displayed at the end of the game if the user asks for it.
void Light::Help(){
	cout << "Help: Light outshines like their great health.\n" << endl;
}

int LightBattle() {
	
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
			C.Talk("Venti", "Bloodbath");
		}
		//The round integer will be displayed here.
		cout << "Round " << round << ", fight!!!" << endl;
		//This calls on the TurnRoll in GameStructure, where a characters turn is decided. The if loop decides what occurs when the random umber gives a 1 or 0 as a signal.
		if (GS.TurnRoll()) {
			//If a 1 is returned, or the number is greater than or equal to 5, the Light will attack.
			//This will display the Lights name
			cout << L.getName() << " attacks.\n";
			//This calls on the FlashBurn function in Light, which is their power.
			L.FlashBurn();
			//This means that Dark will lose as much health as Light has for hp.
			D.loseHealth(L.Attack());
		}
		//If the first staement isn't true or if a 0 is returned instead of a 1, then this will occur, which means that the dark will attack.
		else {
			//This displays the Dark name.
			cout << D.getName() << " attacks.\n";
			//This calls on the ShadowSpike function from the Dark class. This is the Darks prefered method of attack.
			D.ShadowSpike();
			//This means that the Light loses as much health as the pirate has for hp, which is 25.
			L.loseHealth(D.Attack());
		}
		try {
			//These two if loops will scan the new health and see if any of the characters are at 0. If any of them are at 0, the loop will break and go back to the main funtion, when the user will be asked to leave or restart the game.
			if (D.getHealth() <= 0) {
				cout <<"Our light has outshined "<< D.getName() << "!" << endl;
				cout << "A strong breeze passes by as a grey slash cuts into the ground before you." << endl;
				cout << "A strong being emerges from the blast, glaring at you and your lifeless enemy. \nHe raises his hands and you watch your enemy come back to life." << endl;
				break;
			}
			if (L.getHealth() <= 0) {
				cout << L.getName() << " has been slain!" << endl;
				throw 101;
			}
		}
		catch (int Loser) {
			cout << Loser << " You Have Lost!" << endl;
			L.Help();
			break;
		}

		//If both characters still have health, their health is displayed and the loop is back at the top.
		cout << L.getName() << "'s health is now " << L.getHealth() << "." << endl;
		cout << D.getName() << "'s health is now " << D.getHealth() << ". \n" << endl;
		
		//This the program to add a number to the round every time a round or the loop starts over.
		round++;
	}
}
int Light::LightWorld() {
    int LightMngr;
	Character C("Buggy");
	Dark D("Venti");
	Light L("Aura");
	Boss B("Nuet");
    //This again integar tells the program to og back to the beginning of the while loop, when the user gives a 1 as their choice. Without this, the program will break and go into a loop until the program is closed.
    int again = 1;
    //The beginning of while loop, which enables the user to come back to the point if the user wants to restart the program.
    while (again == 1) {
        cout << "Our glorious world owes you a great depth as you spread our light!\nNow Rise " <<L.getName() << ", our grand warrior of the light!" << endl;
		cout << "The Dark's top fighter is " << D.getName() << ", so be careful! " << endl;
		cout << "Prepare to fight for our world!\n" << endl;
		LightBattle();
		B.GreyWorld();
        //This is the portion that tells the user if they want to use again to restart teh section, game or the exit(0) to exit the program.
        cout << "You can now make the choice to 1.restart this section, 2.quit, or 3.restart the game \nChoose the number that corresponds with what you want to do." << endl;
        //The input that the user will give to restart this section, the entire game, or exit the game.
        cin >> LightMngr;
        //With a 1, the program will go to the top of the while loop.
        if (LightMngr == 1) {
            //This restarts this section fromm the beginning of the function.
            again;
        }
        //With a 2, the program will end, using the end(0) at the end. 
        else if (LightMngr == 2) {
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