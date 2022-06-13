#pragma once
#include "Character.h"
#include "Light.h"
#include "Dark.h"
#include <iostream>
#include <string>
class Boss :
    public Character
{
public:
	//When Light is called, a name is required in the parentheses for it to be used. After that, the Light will have a name through the program.
	Boss(string name);
	//The Light's method of attack that is displayed when they attacks.
	void DividingSlash();
	//The info that is displayed at the end of the game if the user asks for it.
	void Help();
	void GreyWorld();
};

