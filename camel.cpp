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
// PreConditions: Drinks and thirst are passed by reference while drinks > 0
// Postconditions: Drinks will decrease by one and thirst will be reset to 0
//
//*******************************************************************************************************

//*******************************************************************************************************
void speed(int& milesTraveled, int& camelTiredness, int& natives, int& thirst, char);
// PreConditions: Four arguments will be passed by reference. The char at the end will dictate which of two 
// speed functions to call
// Postconditions: Arguments will be increased or decreased depending upon which function has been called
//
//*******************************************************************************************************

//*******************************************************************************************************
void sleeping(int& camelTiredness, int& natives, int& drinks, bool& done);
// PreConditions: Three arguments will be called by reference
// Postconditions: Camel tiredness will be reset. Canteen will be set to 0. Natives distance will increase depending on the random
// generator
//*******************************************************************************************************

//*******************************************************************************************************
void status(int milesTraveled, int drinks, int natives);
// PreConditions: Three arguments will be passed by value
// Postconditions: Function will output the values that were passed by the arguments
//
//*******************************************************************************************************

//*******************************************************************************************************
void levels(char level, int& drinks, int& natives);
// PreConditions: User input is expected. Two arguments are passed by reference
// Postconditions: Level of difficulty will be set according to user input
//
//*******************************************************************************************************

//*******************************************************************************************************
void levels(char level, int& oasis, int& companion, int& storm, int& luckyCharm);
// PreConditions: User input is expected.  Four arguments will be passed by reference
// Postconditions: Level of difficulty will be set according to user input
//
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
    char choice, level;
   
    int oasis = rand() % 75 +1;
    int companion = rand() % 75 +1;
    int storm = rand() % 75 +1;
    int luckyCharm = rand() % 75 +1;
    
    cout << "\nWelcome to Camel!" << endl;
    cout << "You have stolen a camel to make your way across the great Mobi desert." << endl;
    cout << "The natives want their camel back and are chasing you down! Survive your" << endl;
    cout << "desert trek and outrun the natives." << endl; 
    
    cout << "\nH - Hard" << endl;
    cout << "M - Medium" << endl;
    cout << "E - Easy" << endl;
    cout << "Choose a Level: ";
    cin >> level;
    
    levels(level, drinks, natives);
    
    while (done == false)
    {
        levels(level, oasis, companion, storm, luckyCharm);
        
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
                sleeping(camelTiredness, natives, drinks, done);
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
         
        else if(milesTraveled < 200)
        {
            if(thirst > 4 && thirst <= 6)
             {
                cout << "\nYou're Thirsty!" << endl;
             }
             else if(thirst > 6)
             {
                cout << "You Died of Thirst!" << endl;
                done = true;
             } // End of thirst status check
             
             if(camelTiredness >= 5 && camelTiredness < 8)
             {
                cout << "\nYour Camel is Getting Tired!" << endl;
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
                if(companion == 22)
             	{
                	cout << "\nYou Found a Gorgeous Companion at the Oasis!!" << endl;
                	cout << "They Have Extra Water!" << endl;
                	drinks += 3;
             	}
             } // End of Oasis
             
             if(storm == 24)
             {
                 cout << "\nYou Got Hit By a Sand Storm!!" << endl;
                 cout << "Your Thirst has Increased!" << endl;
                 cout << "And Your Camel Is More Tired!" << endl;
                 thirst += rand() % 2 + 1;
                 camelTiredness += rand() % 2 + 1;  
             } // End of storm
             if(luckyCharm == 13)
             {
                cout << "\nYou Found a Lucky Charm! You Have One Wish Only So Select Wisely!" << endl;
                cout << "N. Natives Get Pushed Back 20 Miles" << endl;
                cout << "W. You Get Three Extra Drinks of Water" << endl;
                cout << "R. Your Camel is Fully Rested" << endl;  
                cout << "Your choice: ";
                cin >> choice;
                
                switch(toupper(choice))
                {
                    case 'N': 
                    natives = natives - 20;
                    break;
        
                    case 'W':
                    drinks += 3;
                    break;
            
                    case 'R':
                    camelTiredness = 0;
                    break;
                    
                    default: cout << "\nWrong Input" << endl;

                }// end switch
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
void sleeping(int& camelTiredness, int& natives, int& drinks, bool& done)
{
    int snake = rand()% 90 + 1;
    int robbed = rand()% 100 + 1;
    camelTiredness = 0;
    natives += rand() % 8 + 7; 
    cout << endl;
    cout << "Your Camel is Happy!" << endl;
    if(robbed == 48)
    {
        drinks = 0;
        cout << "While You Were Resting Karma Paid a Visit!" << endl;
        cout << "Someone Stole Your Camel and Water!  Game Over!" << endl;
        done = true;
    }
    if(snake == 3)
        {
            camelTiredness = 5;
            cout << "\nYou Got Bit by a Snake and Your Camel is Not Well Rested." << endl;
            cout << "What Goes Around Comes Around! Don't Steal Other People's Camels!" << endl; 
        } // End of snake
    
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
void levels(char level, int& drinks, int& natives )
{
    switch(toupper(level))
    {
        case 'H':drinks = 2;
                 natives = -10;
                 break;
        case 'M':drinks = 3;
                 break;
        case 'E':drinks = 6;
                 natives = -30;
                 break;
    }
}// End of Levels
void levels(char level, int& oasis, int& companion, int& storm, int& luckyCharm)
{
    switch(toupper(level))
    {
        case 'H':
                 oasis = rand() % 150 +1;
                 companion = rand() % 200 + 1;
                 storm = rand() % 25 + 1;
                 luckyCharm = rand() % 100 + 1; 
                 break;
        case 'M':
                 oasis = rand() % 100 +1;
                 companion = rand() % 100 + 1;
                 storm = rand() % 50 + 1;
                 luckyCharm = rand() % 75 + 1; 
                 break;
        case 'E':
                oasis = rand() % 50 +1;
                companion = rand() % 30 + 1;
                storm = rand() % 100 + 1;
                luckyCharm = rand() % 25 + 1; 
                break;
    }
}
