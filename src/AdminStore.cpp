#include "AdminStore.h"
#include <string>
#include <fstream>
#include <iostream>
#include "Store.h"
#include "ShoppingCart.h"
#include <Exception.h>
using namespace std;

AdminStore::AdminStore()
{
}

void AdminStore::storeOptions()
{
    int choice;
    cout << "1. Admin Panel\n2. Shopping\n3. Log out\nNumber: ";
    cin >> choice;
    cin.clear();
    cin.ignore();

    switch (choice)
    {
    case 1:
        adminOptions();
        break;
    case 2:
        Store::storeOptions();
        break;
    case 3:
        return;
    }
}

void AdminStore::adminOptions() //function used to provide admin user with admin options
{
    int choice;
    int choice2;
    int choice3;
    string newItem;
    string itemToDelete;
    cout << "1. Add Item\n2. Remove Item\n3. Log out\nNumber: ";
    cin >> choice;
    cin.clear();
    cin.ignore();

    switch (choice)
    {

    case 1:
        cin.ignore();
        cout << "Enter item name following with the price of the item.\n ";
        cout << "Example: Bathrobe 17\n Item and price: ";
        getline(cin, newItem);
        cout << "\n"
             << endl;
        cout << "Select which category to add item to\n";
        cout << "1.Bathroom Items\n2. Bedroom Items\n3. Kitchen Items\n4. Living Room Items\n5. Go back <-\nNumber:  ";
        cin >> choice2;
        cin.clear();
        cin.ignore();
        break;

        switch (choice2)
        {
        case 1:
            adminAdd(newItem, "BathroomItems.txt");
            cout << "Item added\n"
                 << endl;
            adminOptions();
            break;
        case 2:
            adminAdd(newItem, "BedroomItems.txt");
            cout << "Item added\n"
                 << endl;
            adminOptions();
            break;

        case 3:
            adminAdd(newItem, "KitchenItems.txt");
            cout << "Item added\n"
                 << endl;
            adminOptions();
            break;

        case 4:
            adminAdd(newItem, "LivingRoomItems.txt");
            cout << "Item added\n"
                 << endl;
            adminOptions();
            break;

        case 5:
            adminOptions();
            break;

        default:
            cout << "Incorrect input. Try again!";
            adminOptions();
            break;
        }

    case 2:
        cout << "List of Categories: \n 1. Bathroom Items \n 2. Bedroom Items \n 3. Kitchen Items \n 4. Living Room Items\n 5. Go Back <-\nNumer: ";
        cin >> choice3;
        cin.clear();
        cin.ignore();

        switch (choice3)
        {
        case 1:
            adminDisplayCategories("BathroomItems.txt");
            cout << "Enter name of item to remove\nName: ";
            cin >> itemToDelete;
            adminRemove("BathroomItems.txt", itemToDelete);
            cout << "\nCategory Updated" << endl;
            adminOptions();
            break;

        case 2:
            adminDisplayCategories("BedroomItems.txt");
            cout << "Enter name of item to remove\nName: ";
            cin >> itemToDelete;
            adminRemove("BedroomItems.txt", itemToDelete);
            cout << "\nCategory Updated" << endl;
            adminOptions();
            break;

        case 3:
            adminDisplayCategories("KitchenItems.txt");
            cout << "Enter name of item to remove\nName: ";
            cin >> itemToDelete;
            adminRemove("KitchenItems.txt", itemToDelete);
            cout << "\nCategory Updated" << endl;
            adminOptions();
            break;

        case 4:
            adminDisplayCategories("LivingRoomItems.txt");
            cout << "Enter name of item to remove\nName: ";
            cin >> itemToDelete;
            adminRemove("LivingRoomItems.txt", itemToDelete);
            cout << "\nCategory Updated" << endl;
            adminOptions();
            break;

        case 5:
            adminOptions();
            break;

        default:
            adminOptions();
            break;
        }

    case 3:
        cout << "Admin log out successful!\n"
             << endl;
             return;
    default:
        adminOptions();
        break;

    }
}
void AdminStore::adminAdd(string nameAndPrice, string whichFile) //function used for admin to add a new item to shop
{
    ofstream fileToModify;
    fileToModify.open(whichFile, ios::app);
    fileToModify << nameAndPrice << endl;
    fileToModify.close();
    /*
    if (nameAndPrice != "Gold Statue 20" && (whichFile == "LivingRoomItems.txt" || whichFile == "BathroomItems.txt" || whichFile == "BedroomItems.txt" || whichFile == "KitchenItems.txt"))
    {
        throw Exception("Item Validation failed");
    }
    else if (whichFile != "LivingRoomItems.txt" && whichFile != "BathroomItems.txt" && whichFile != "BedroomItems.txt" && whichFile != "KitchenItems.txt")
    {
        throw Exception("File Path Validation failed");
    }
    */
}

void AdminStore::adminRemove(string whichFile, string itemToDelete)
//function used for admin to remove an existing item in shop
{
    int lengthB4Price = 0;
    string compareLine;
    ifstream originalFile;
    originalFile.open(whichFile);
    ofstream tempFile;
    tempFile.open("tempfile2.txt");

    while (getline(originalFile, compareLine))
    {

        lengthB4Price = compareLine.length() - 3;
        if (itemToDelete != compareLine.substr(0, lengthB4Price))
        {
            //UNIT TESTING: Comment out line 201 to avoid auto-scrolling.
            cout << compareLine << endl;
            tempFile << compareLine << endl;
        }
    }

    tempFile.close();
    originalFile.close();

    if (whichFile == "BathroomItems.txt")
    {

        remove("BathroomItems.txt");
        rename("tempfile2.txt", "BathroomItems.txt"); // not replacing file
    }
    if (whichFile == "BedroomItems.txt")
    {
        remove("BedroomItems.txt");
        rename("tempfile2.txt", "BedroomItems.txt");
    }
    if (whichFile == "KitchenItems.txt")
    {
        remove("KitchenItems.txt");
        rename("tempfile2.txt", "KitchenItems.txt");
    }
    if (whichFile == "LivingRoomItems.txt")
    {
        remove("LivingRoomItems.txt");
        rename("tempfile2.txt", "LivingRoomItems.txt");
    }
    /*
    if (whichFile != "LivingRoomItems.txt" && whichFile != "BathroomItems.txt" && whichFile != "BedroomItems.txt" && whichFile != "KitchenItems.txt")
    {
        throw Exception("File Path Validation failed");
    }
    else if(itemToDelete != "Gold Statue")
    {
        throw Exception("Item Validation failed");
    }
    */
}
void AdminStore::adminDisplayCategories(string whichFile) //Function used to provide Admin with different categories
{
    ifstream fileToDisplay;
    string line;
    /*
    if (whichFile != "LivingRoomItems.txt" && whichFile != "BathroomItems.txt" && whichFile != "BedroomItems.txt" && whichFile != "KitchenItems.txt")
    {
        throw Exception("File Path Validation failed");
    }
    */
    fileToDisplay.open(whichFile);
    while (!fileToDisplay.eof())
    {
        getline(fileToDisplay, line);
    }
    fileToDisplay.close();

}
