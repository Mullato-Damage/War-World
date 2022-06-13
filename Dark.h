#pragma once
#include "Character.h"
#include "GmStrct.h"
#include "Light.h"
#include "Boss.h"
#include <string>
#include <iostream>

class Dark : public Character {

public:
	//When Dark is called, a name is required in the parentheses for it to be used. After that, the Dark will have a name through the program.
	Dark(string name);
	//The Dark's method of attack that is displayed when they attacks.
	void ShadowSpike();
	//The info that is displayed at the end of the game if the user asks for it.
	void Help();
	int DarkWorld();
};

