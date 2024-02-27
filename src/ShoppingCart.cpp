#include "ShoppingCart.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

ShoppingCart::ShoppingCart()
{
}

void ShoppingCart::printBalance()
{
    cout << "Balance: " << balance << " Pounds\n";
}

void ShoppingCart::viewCart()
{
    string outputItem;
    int amountOfItems = -1;
    ifstream CartItems;

    CartItems.open("CartItems.txt");

    cout << "Your cart contains:\n"
         << endl;
    while (!CartItems.eof())
    {
        amountOfItems++;

        getline(CartItems, outputItem);

        cout << outputItem << endl;
    }
    cout << "Amount of Items in cart: " << amountOfItems << "\n"
         << endl;
    CartItems.close();
}

void ShoppingCart::ClearCart()
{
    string outputItem;
    ofstream CartItems;

    CartItems.open("CartItems.txt");
    CartItems.close();
    cout << "Your cart has been cleared!\n"
         << endl;
    this->balance = 0;
}
void ShoppingCart::CheckCartOut(){
    string outputItem;
    ofstream CartItems;

    CartItems.open("CartItems.txt");
    CartItems.close();
    this->balance = 0;
}
void ShoppingCart::updateCurrentBalance(int price)
{
    balance += price;
    printBalance();
}
void ShoppingCart::AddItem(string whichFile)
{
    int lengthB4Price;
    string priceAsString;
    string itemToAdd;
    ofstream CartItems;
    ifstream fileToPrice;
    string compareName;
    int toAdd;
    bool found = false;

    cout << "Enter name of item to be added\nName: ";
    getline(cin, itemToAdd);
    cout << "\n"
         << endl;

    fileToPrice.open(whichFile);

    while (!fileToPrice.eof() || found == true)
    {
        getline(fileToPrice, compareName); // used to verify length of line with price
        lengthB4Price = compareName.length() - 2; //used to verify length of line without price



        if (itemToAdd == compareName.substr(0, itemToAdd.length()))
        {

            CartItems.open("CartItems.txt", ios::app);
            CartItems << itemToAdd << endl;
            CartItems.close();

            found = true;
            cout << "Item added to Cart!\n";
            priceAsString = compareName.substr(lengthB4Price, compareName.length());
            toAdd = stoi(priceAsString); //converts string to int

            updateCurrentBalance(toAdd);
            fileToPrice.close();
            return;
        }
    }

    fileToPrice.close();
    if (found == false)
    {
        cout << "Incorrect input or item doesnt exist!" << endl;
    }
}

void ShoppingCart::RemoveItem(string whichFile)
{

    string deleteLine;
    string line;
    ifstream originalFile;
    originalFile.open("CartItems.txt");
    ofstream tempFile;
    tempFile.open("temp.txt");

    viewCart();
    cout << endl;

    cout << "Which item would you like to remove?\nItem: ";
    cin >> deleteLine;

    while (getline(originalFile, line))
    {
        if (deleteLine != line)
        {

            tempFile << line << endl;
        }
    }

    tempFile.close();
    originalFile.close();
    remove("CartItems.txt");
    rename("temp.txt", "CartItems.txt");

    cout << "You cart has been updated!\n"
         << endl;

    ifstream fileForPrice;
    string stringWithPrice;
    int lengthB4Price;
    int balance;
    bool found = false;
    string priceAsString;
    int toRemove;

    fileForPrice.open(whichFile);

    while (!fileForPrice.eof() || found == true)
    {
        getline(fileForPrice, stringWithPrice);
        lengthB4Price = stringWithPrice.length() - 2;
        if (deleteLine == stringWithPrice.substr(0, deleteLine.length()))
        {
            found = true;
            priceAsString = stringWithPrice.substr(lengthB4Price, stringWithPrice.length());
            toRemove = stoi(priceAsString);
            toRemove = toRemove * -1;
            cout << balance << endl;

        }
    }
    if (found == false)
    {
        cout << "Incorrect input or item not in cart\n"
             << endl;
    }
}

void ShoppingCart::CheckOut()
{
    cout << "You have paid: " << balance << " Pounds" << endl;
    ShoppingCart::CheckCartOut();
    system("exit");
}
