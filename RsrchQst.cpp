#include "RsrchQst.h"
#include "GmStrct.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int RsrchQst::ResearchQst()
{
    //f is our abreviation for fstream, to make it easier to code and understand.
    fstream f;
    //This is the first user input, which will need to store data and be displayed
    string us1;
    //This is my second user input, which will also store and display data, like the first input.
    string us2;
    //This is for the input that decides whether the user reads or writes.
    char usr_in;
    //This connects to my while loop, which is powered at the end of the program, where it will allow the user to decide if they want to restart or exit.
    int Noted;
    //This connects to the while loop and tells it that when the user puts 1 in IOtrain, it will trigger the again and restart the program from the top of the while loop.
    int again = 1;
    //This is the start of the while loop, which is restarted when the user gives IOtrain 1 as an input.
    while (again == 1)
    {
        cout << "This is where you can write down notes about the game and read them." << endl;
        cout << "Would you like to read what you wrote or would you like to write? \nType r to read or w to write." << endl;
        //The user input that decides if they want to read or write. It connects to the if/else.
        cin >> usr_in;
        //This if is triggered with r or if the user wants to read what has been stored.
        if (usr_in == 'r') {
            //f links to the fstream and open tells the program to open RsrchIO, which is the file that will be read.
            //The ios::in tells the program that we want ot read the file and it's data
            f.open("RsrchIO", ios::in);
            //This is our string which will become the data that is on the RsrchIO file, so it can be displayed.
            string s;
            //in the while loop, it uses the f or fstream so that it knows to call on files, and the "getline" will retrieve data from the file that was just opened.
            //The s tells the program that s will now become the data that is in the file.
            while (getline(f, s)) {
                //Here the data from the file will be displayed.
                cout << "Research Notes: " << s << endl;
            }
            //Here, it'll close the file.
            f.close();
        }
        //This will trigger if the user decides not to read, which will allow them to write.
        else
        {
            //As stated above, the f.open will open the file "RsrchIO" and the ios::out, in, and app tells the program to create a file that stores data that is given and can be opened and have the data retrieved to be displayed.
            f.open("RsrchIO", ios::out | ios::in | ios::app);
            cout << "The system will take one word/number at a time and can only do two words in each go, so it may take multiple goes." << endl;
            cout << "Write a number or word." << endl;
            //This is the first input that'll be stored into the file.
            cin >> us1;
            //This tells the program to apply a space after the data so that the next input isn't jumbled with it.
            us1.append(" ");
            cout << "You said: " << us1 << "." << endl;
            cout << "Type another word or number that you want recorded with the first." << endl;
            //The second input that'll be stored and displayed.
            cin >> us2;
            //With this, the two inputs are joined together and will now show up together instead of just one. As seen below, us2 isn't mentioned again because it's data is now in us1.
            us1.append(us2);
            //This applies a \n to make sure that if any other inputs that are added are put into a line below this one.
            us1.append(" \n");
            cout << "You joted down: " << us2 << "." << endl;
            cout << "Your full note is: " << us1 << endl;
            //This tells the program to apply this data to the file and save it.
            f << us1;
            //This will close the file so nothing can enter or exit.
            f.close();
        }
        //This is the portion that tells the user if they want to use again to restart the test or the exit(0) to exit the program.
        cout << "You can now make the choice to 1.restart this section, 2.quit, or 3.restart the game \nChoose the number that corresponds with what you want to do." << endl;
        //The input that the user will give to restart this section, the entire game, or exit the game.
        cin >> Noted;
        //With a 1, the program will go to the top of the while loop.
        if (Noted == 1) {
            //This restarts this section fromm the beginning of the function.
            again;
        }
        //With a 2, the program will end, using the end(0) at the end. 
        else if (Noted == 2) {
            cout << "Goodbye Warriors!" << endl;
            //This takes the user out of the program entirely.
            exit(0);
        }
        else {
            cout << "Back To The Beginning!!" << endl;
            main();
        }
    }
}
