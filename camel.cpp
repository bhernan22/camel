// Bianca Hernandez
// Noe Lomeli
// Created: November 06, 2015
// Summary: Camel_game
//
//*******************************************************************************************************


#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

//*******************************************************************************************************
void canteen(int& drinks, int& thirst);
// PreConditions: drinks in canteen > 0
// Postconditions:
//
//*******************************************************************************************************

//*******************************************************************************************************
void speed(int& milesTraveled, int& camelTiredness, int& natives, int& thirst, char);
// PreConditions:
// Postconditions:
//
//*******************************************************************************************************

//*******************************************************************************************************
void sleeping(int& camelTiredness, int& natives);
// PreConditions:
// Postconditions:
//
//*******************************************************************************************************

//*******************************************************************************************************
void status(int milesTraveled, int drinks, int natives);
// PreConditions:
// Postconditions:
//
//*******************************************************************************************************

//*******************************************************************************************************

int main()
{
    srand(time(0));
    bool done = false;
    int milesTraveled = 0;
    int thirst = 0;
    int camelTiredness = 0;
    int natives = -20;
    int drinks = 3;
    char choice;
    
    cout << "\nWelcome to Camel!" << endl;
    cout << "You have stolen a camel to make your way across the great Mobi desert." << endl;
    cout << "The natives want their camel back and are chasing you down! Survive your" << endl;
    cout << "desert trek and outrun the natives." << endl; 
    
    while (done == false)
    {
        int oasis = rand()% 50 + 1;
        int companion = rand()% 50 + 1;
        int storm = rand()% 25 + 1;
        int robbed = rand()% 100 + 1;
        int shootingStar = rand()% 75 + 1;
        int snake = rand()% 40 + 1;
        
        cout << "\nA. Drink from your canteen." << endl;
        cout << "B. Ahead moderate speed." << endl;
        cout << "C. Ahead full speed." << endl;
        cout << "D. Stop and rest." << endl;
        cout << "E. Status check." << endl;
        cout << "Q. Quit." << endl;  
        cout << "Your choice: ";
        cin >> choice;
        
        switch(toupper(choice))
        {
            case 'A': 
                canteen(drinks, thirst);
                break;
        
            case 'B':
                speed(milesTraveled, camelTiredness, natives, thirst, 'm');
                break;
            
             case 'C':
                speed(milesTraveled, camelTiredness, natives, thirst, 'f');
                break;
        
             case 'D':
                sleeping(camelTiredness, natives);
                break;
            
            case 'E':
                status(milesTraveled, drinks, natives);
                break;
            
            case 'Q':
                done = true;
                break;
            default: cout << "\nWrong Input" << endl;

        }// end switch
        
        if(milesTraveled >= 200)
         {
            cout << "\nYou Made It Across the Desert!" << endl;
            done = true;
         }// End of Winning status 
         
        else if
        {
            if(thirst > 4 && thirst <= 6)
             {
                cout << "/nYou're Thirsty!" << endl;
             }
             else if(thirst > 6)
             {
                cout << "You Died of Thirst!" << endl;
                done = true;
             } // End of thirst status check
             
             if(camelTiredness >= 5 && camelTiredness < 8)
             {
                cout << "\nYour Camel is Getting Tired!" << endl << endl;
             }
             else if(camelTiredness > 8)
             {
                cout << "Your Camel is Dead!!" << endl;
                cout << "You Couldn't Outrun the Natives!" << endl;
                done = true;
             }// End camelTiredness status check
             
             else if(milesTraveled == natives)
             {
                cout << "\nThe Natives Have Caught You!" << endl;
                done = true;
             }
             else if(milesTraveled - natives < 15)
             {
                cout << "\nThe Natives Are Getting Close!" << endl;
             }// End of Natives  status
             
             if(oasis == 5)
             {
                cout << "Luck Is On Your Side Today. You Found an Oasis!\n All Your Supplies Have Been Replenished!" << endl;
                drinks = 3;
                camelTiredness = 0;
                thirst = 0;
             }
             if(companion == 22)
             {
                cout << "\nYou Found a Gorgeous Companion at the Oasis!!" << endl;
             }
             if(storm == 24)
             {
                 cout << "\nYou Got Hit By a Sand Storm!!" << endl;
                 thirst += rand() % 2 + 1;
                 camelTiredness += rand() % 2 + 1;
                 
             }
             if(snake == 3)
             {
                 camelTiredness = 5;
                 cout << "You Got Bit by a Snake and Your Camel is Not Well Rested." << endl;
                 cout << "What Goes Around Comes Around! Don't Steal Other People's Camels!" << endl; 
             }
        }
    }//end while
    cout << "\nThank You For Playing!" << endl;
    return 0;
} // End of Main

//*******************************************************************************************************
void canteen(int& drinks, int& thirst)
{
    if(drinks == 0)
    {
        cout << "Sorry, You Drank All Your Water!!" << endl;
        cout << "Hope You Make It Across Before You...Die of Dehydration!!" << endl;
    }
    else
    {
        drinks -= 1;
        thirst =0;
        cout << "\nAhhh! That Was Refreshing!" << endl;
    }
    return;
} // End of Canteen

//*******************************************************************************************************
void speed(int& milesTraveled, int& camelTiredness, int& natives, int& thirst, char type)
{
    if(type == 'm')
    {
        milesTraveled += rand() % 8 + 5;
        camelTiredness += 1;
    }
    else if(type == 'f')
    {
        milesTraveled += rand() % 11 + 10;
        camelTiredness += rand() % 3 + 1;
    }
    
    natives += rand() % 8 + 7;
    thirst += 1;
    cout << "\nMiles Traveled: " << milesTraveled << endl;    
    return;
}// End of speed

//*******************************************************************************************************
void sleeping(int& camelTiredness, int& natives)
{
    camelTiredness = 0;
    natives += rand() % 8 + 7; 
    cout << endl;
    cout << "Your Camel is Happy!" << endl;
    
    return;
}// End of sleeping

//*******************************************************************************************************
void status(int milesTraveled, int drinks, int natives)
{
   cout << "\nMiles Traveled: " << milesTraveled << endl;
   cout << "Drinks in Canteen: " << drinks << endl;
   cout << "The Natives are " << milesTraveled - natives << " Miles Behind You!" << endl;
    return;
} // End of status