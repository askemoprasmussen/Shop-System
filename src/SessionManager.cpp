#include <string>
#include <fstream>
#include <iostream>
#include "SessionManager.h"
#include "AdminStore.h"
#include "ShoppingCart.h"
#include "Store.h"
#include <Exception.h>
using namespace std;

SessionManager::SessionManager() {}

float SessionManager::sessionAction()
{

    AdminStore admin;
    int statusOfInput;
    string usernameTry, passwordTry;
    int choice;

    cout << "1. Login\n2. Create Account\n3. Admin Login\n4. Exit\nNumber: ";
    cin >> choice;
    cin.clear();
    cin.ignore();

    switch (choice)
    {
    case 1:

        cout << "Please Enter Username and Password to login \nUsername:";
        cin >> usernameTry;
        cout << "Password:";
        cin >> passwordTry;
        statusOfInput = login(usernameTry, passwordTry, "usernames.txt", "passwords.txt");
        if (statusOfInput == 0)
        {
            cin.clear();
            cin.ignore();
            return sessionAction();
        }
        else
        {
            cout << "Login Successfull!\n"
                 << endl;
            return 1;
        }

    case 2:

        addUser();
        return sessionAction();

    case 3:

        cout << "Please enter admin details to login \nUsername: ";
        cin >> usernameTry;
        cout << "Password: ";
        cin >> passwordTry;
        statusOfInput = login(usernameTry, passwordTry, "adminUsers.txt", "adminPasswords.txt");
        if (statusOfInput == 0)
        {
            cin.clear();
            cin.ignore();
            return sessionAction();
        }
        else
        {
            cout << "Admin login Successfull!\n"
                 << endl;
            return 2;
        }

    case 4:
        return 4;

    default:

        cout << "Wrong input! Input number 1-4\n"
             << endl;
        return sessionAction();
    }
}

bool SessionManager::login(string usernameTry, string passwordTry, string fileToOpen1, string fileToOpen2) //function used to check for existing login
{
    string exisiting;
    string username;
    string password;
    bool access;

    int counter = compareUsername(usernameTry, fileToOpen1); //checks if username exists.

    if (counter != 0)
    {

        access = comparePasswords(passwordTry, counter, fileToOpen2); //Checks if password corresponding to inputted username check out

        if (access == true)
        {
            return true;
        }
        /*
        else if (fileToOpen2 != "passwords.txt"){
                throw Exception("File Path Authentication Failed.");
            }
        */
        else
        {
            cout << "Incorrect password!\n";
            return false;
        }
    }
    /*
    else if (fileToOpen1 != "usernames.txt"){
                throw Exception("File Path Authentication Failed.");
            }
    */
    else
    {
        cout << "Incorrect username. Try again! \n";
        cout << "\n";
        return false;
    }
}

int SessionManager::compareUsername(const string usernameTry, string fileToOpen) // function used to compare inputted username to exisiting usernames
{
    string nameOfUser;
    ifstream inputFile;

    int lineNum = 0;
    inputFile.open(fileToOpen);

    while (!inputFile.eof())
    {
        lineNum++;

        getline(inputFile, nameOfUser);

        if (usernameTry == nameOfUser)
        {
            inputFile.close();
            return lineNum;
        }
        /*
            // The code below checks for a correct filepath and an incorrect use
        else if (usernameTry != nameOfUser && fileToOpen == "usernames.txt"){
                throw Exception("Username Authentication Failed.");
            }
            // The code below checks for an incorrect filepath only. This way if the filepath AND the username are wrong, it flags the pathing error first.
        else if (fileToOpen != "usernames.txt"){
                throw Exception("File Path Authentication Failed.");
            }
        */
    }
    inputFile.close();
    return 0;
}

bool SessionManager::comparePasswords(string passwordTry, int lineNum, string fileToOpen) //function used to compare inputted password to exisiting and corresponding password to username
{
    string passwordOfUser;
    ifstream inputFile2;

    inputFile2.open(fileToOpen);

    for (int i = 0; i < lineNum; i++)
    {
        if (inputFile2.eof())
        {
            throw exception();
        }
        getline(inputFile2, passwordOfUser);
    }

    if (passwordTry == passwordOfUser)
    {
        inputFile2.close();
        return true;
    }
    // The code below checks for a correct filepath and an incorrect use
    /*
    else if (passwordTry != passwordOfUser && fileToOpen == "passwords.txt"){
                throw Exception("Password Authentication Failed.");
            }
            // The code below checks for an incorrect filepath only. This way if the filepath AND the username are wrong, it flags the pathing error first.
    else if (fileToOpen != "passwords.txt"){
                throw Exception("File Path Authentication Failed.");
            }
    */
    return false;
}

void SessionManager::addUser() //function used for a user to create an account
{
    string newUsername;
    string newPassword;

    cout << " Enter the following details to sign up\n Username: ";
    cin >> newUsername;
    cout << " Password: ";
    cin >> newPassword;

    ofstream usernameFile; // out file stream
    usernameFile.open("usernames.txt", ios::app);
    usernameFile << newUsername << endl;
    usernameFile.close();

    ofstream passwordFile; // out file stream
    passwordFile.open("passwords.txt", ios::app);
    passwordFile << newPassword << endl;
    passwordFile.close();
}
