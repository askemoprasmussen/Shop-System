#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class ShoppingCart
{
public:
    ShoppingCart();

    void viewCart();
    void ClearCart();
    void AddItem(string whichFile);
    void RemoveItem(string whichFile);
    void updateCurrentBalance(int price);
    void CheckOut();
    void CheckCartOut();
    void printBalance();

protected:
private:
    int balance=0;
};

#endif // SHOPPING_CART_H
