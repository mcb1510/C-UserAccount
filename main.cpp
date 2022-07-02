#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include "userAccount.h"
using namespace std;

list<string> l;

/****************************************************************************************
* Check if the credentials exit and if they match.                                      *
****************************************************************************************/
bool canWeLogin(string username, string password)
{
    string text;
    ifstream readFile("userAccounts.txt");      // we read our file with the info
    while (getline(readFile, text))
    {
        l.push_back(text);          // put all the info into a list
    }
    readFile.close();

    for (list<string>::iterator i = l.begin(); i!= l.end(); ++i)
    {   
        if (*i ==  (username + password))       // go through all the list and check if
        {                                       // the info is correct.
            return true;
        }
    }
    return false;
}

/****************************************************************************************
* Here the user can log in. It will ask for the user information and send it to check.  *
****************************************************************************************/
void optionTwo()
{   
    cout << "Perfect!" << endl;
    cout << "Let's log in into your account\n";
    bool canWe = false;
    int attempts = 0;

    while (canWe == false && attempts < 3)
    {
        string username;
        string password;
        
        cout << "What is your username? >> ";
        getline(cin, username);
        cout << "What is your password? >> ";
        getline(cin, password);
        canWe = canWeLogin(username, password);     // we call canWeLogin() to check if 
        if (canWe == false)                         // the pass and username match
        {
            cout << "Sorry, your credentials are not valid.\n";
            attempts++;
        }
        else if (canWe == true){                                // if they match, then log in
            cout << "Perfect! You have logged in" << endl;
            cout << "Stay alert for uncoming updates. BYE!";
            exit(0);
        }
    }

    if(attempts == 3)               // if the user enters the info 3 times wrong, then quit
    {
        cout << "You have enter wrong your credentials too many times.\n";
        cout << "You will be redirected to our Home Menu\n";
    }

}

/****************************************************************************************
* Here the user can create an account. It will append his credentials to a file.        *
****************************************************************************************/
void createAccount(User user)
{
    string answer;
    cout << endl;
    cout << "Enter a username for your profile >> ";
    getline(cin, answer);
    user.setUserName(answer);
    cout << "Enter a password >> ";
    getline(cin,answer);
    user.setPassword(answer);
    
    fstream file("userAccounts.txt",file.out| file.app);
    file << user.getUserName();
    file << user.getPassword();
    file << endl;
    file.close();

    cout <<"Your profile has been successfully created.";
    cout <<" You will be redirected to our Home Menu.\n";
}

/****************************************************************************************
* Here the user can start creating an account.                                          *
****************************************************************************************/
void optionOne()
{
    User user;
    string answer;
    string canWe = "";

    cout << "Perfect!" << endl;
    cout << "Let's create your account. What is your name? >> ";
    getline(cin,answer);
    user.setName(answer);
   
    cout << "Please enter your ID number >> ";
    getline(cin, answer);
    user.setId(answer);
    
    cout << "Please enter your birthday year >> ";
    getline(cin, answer);
    user.setBirthday(answer);

    cout << endl;
    cout << "Make sure your personal information is displayed correctly below" << endl;
    user.displayInformation(); // display all user's information
    cout << endl;
    cout << "Do you want to continue? "; 
    while(canWe != "Y")
    {
        cout << "Y/N : ";
        getline(cin, canWe);

        if (canWe == "Y")       // if the info is correct, we continue.
            createAccount(user);
        else if (canWe == "N")
        {
            cout << "Bye!";
            break;
        }
        else
        {
            cout << "Sorry I did not understand that." << endl;
        }
    }
}

/****************************************************************************************
* This is the Home Menu of the program.                                                 *
****************************************************************************************/
void interact()
{
    string choice = "0";
    while (choice != "3")
    {
        cout << endl;
        cout << "What do you want to do? " << endl;
        cout << "1.- Sign Up" << endl;
        cout << "2.- Log in" << endl;
        cout << "3.- Exit" << endl;
        cout << "Enter the number option >> ";
        getline(cin,choice);
        
        if (choice == "1")
        {
            optionOne();
        }
        else if (choice == "2")
        {
            optionTwo();
        }
        else if (choice == "3")
        {
            cout << "Bye! See you soon.";
        }
        else
        {
            cout << "Please enter a valid option.";
            cout << endl;
        }
        cin.clear();
    }
}

/****************************************************************************************
* This function will display a banner when the program starts.                          *
****************************************************************************************/
void displayBanner()
{   
    cout << endl;
    cout << "                   Welcome to TeAyudo!" << endl;
    cout <<"-------------------------------------------------------------"<< endl;
    cout <<"     ---------                           --------"<< endl;
    cout <<"    | SIGN UP |                         | LOG IN |"<< endl;
    cout <<"     ---------                           --------"<< endl;
    cout <<" I don't have an account         I already have an account "<< endl;
    cout <<"-------------------------------------------------------------"<< endl;
}

/****************************************************************************************
* This is the main function. This will call all the other function to run the program.  *
****************************************************************************************/
int main()
{
    displayBanner();
    interact();
    return 0; 
}