// War Worlds.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

#include "Character.h"
#include "GmStrct.h"
#include "RsrchQst.h"
#include "Dark.h"
#include "Light.h"
#include "Boss.h"

using namespace std;


int main()
{
    RsrchQst RQ;
    Character C("Buggy");
    Dark D("Venti");
    Light L("Aura");
    Boss B("Nuet");
    int HmWrld;
    //This again integar tells the program to og back to the beginning of the while loop, when the user gives a 1 as their choice. Without this, the program will break and go into a loop until the program is closed.
    int again = 1;
    //The beginning of while loop, which enables the user to come back to the point if the user wants to restart the program.
    while (again == 1) {
        cout << "This is the world we live in. A place ruined from the constant fights.\nThose beyond our world plague the ground we stand on! This is War Worlds!" << endl;
        cout << "War Worlds is a turn-based fighting game that takes place between different worlds. You will choose yours. \nWhich world would you like to represent 1.Dark, 2.Light, or 3.Take notes (Type 1, 2, or 3)?" << endl;
        cin >> HmWrld;
        if (HmWrld == 1) {
            cout << "Welcome to the shadows, we will consume the light and take back what's ours!" << endl;
            D.DarkWorld();
        }
        else if (HmWrld == 2) {
            cout << "Welcome to the light, where we shall eradicate the darkness!" << endl;
            L.LightWorld();
        }
        else if (HmWrld == 3) {
            cout << "A Studious Fighter Is The Best Fighter!" << endl;
            RQ.ResearchQst();
        }
        
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
