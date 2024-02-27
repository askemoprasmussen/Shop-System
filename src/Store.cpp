#include "Store.h"
#include <string>
#include <fstream>
#include <iostream>
#include "SessionManager.h"
#include "ShoppingCart.h"
#include "User.h"
#include "Exception.h"
using namespace std;
Store::Store()
{
    //ctor
}

void Store::ViewCategories()
{
    int whichCategory;

    cout << "List of Categories: \n 1. Bathroom Items \n 2. Bedroom Items \n 3. Kitchen Items \n 4. Living Room Items\n 5. Go Back <- " << endl;
    cout << "Enter the number corresponding to the category you would like to see. \nNumber: ";
    cin >> whichCategory;
    cout << "\n"
         << endl;
    cin.clear();
    cin.ignore();

    switch (whichCategory)
    {
    case 1:
        items("BathroomItems.txt");
        break;

    case 2:
        items("BedroomItems.txt");
        break;

    case 3:
        items("KitchenItems.txt");
        break;

    case 4:
        items("LivingRoomItems.txt");
        break;

    case 5:
        return;

    default:
        cout << "Incorrect input! Choose from 1-5\n"
             << endl;
        break;
    }

    ViewCategories();
}

void Store::items(string fileName)
{
    ifstream file;
    string bLine;
    int choice;
    /*
    if (fileName != "CartItems.txt")
    {
        throw Exception("File Path Validation failed");
    }
    */
    file.open(fileName);
    cout << "List of Items: \n"
         << endl;
    while (!file.eof())
    {
        getline(file, bLine);
        //Comment out line 75 when unit testing for clear output
        cout << bLine << endl;
    }
    cout << "\n"
         << endl;

    cout << "1. Add Item\n2. Remove Item\n3. Go Back <-\nNumber: ";
    cin >> choice;
    cin.clear();
    cin.ignore();

    switch (choice)
    {
    case 1:
        this->user.shoppingCart.AddItem(fileName);
                cout <<"\n";
        user.shoppingCart.printBalance();

        break;

    case 2:

        this->user.shoppingCart.RemoveItem(fileName);
        break;

    case 3:
        ViewCategories();
        break;

    default:
        cout << "Incorrect input! Choose from 1 to 3. \n"
             << endl;
        items(fileName);
        break;
    }
}

void Store::storeOptions()
{
    int choice;
    cout << "1. View Categories\n2. View Cart\n3. Clear Cart\n4. Check Balance\n5. Check Out\n6. Log out\nNumber: ";
    cin >> choice;
    cout << "\n"
         << endl;
    cin.clear();
    cin.ignore();

    switch (choice)
    {
    case 1:
        ViewCategories();
        break;

    case 2:
        this->user.shoppingCart.viewCart();
        break;

    case 3:
        this->user.shoppingCart.ClearCart();
        break;

    case 4:
        this->user.shoppingCart.printBalance();
        break;

    case 5:
        this->user.shoppingCart.CheckOut();
        break;

    case 6:
        cout << "You have logged out!\n";
        return;

    default:
        cout << "Incorrect input! Choose from 1-8\n " << endl;
        break;
    }

    storeOptions();
}

void Store::setUser(User user)
{
    // avoid name conflict
    this->user = user;
}
