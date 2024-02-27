#ifndef STORE_H
#define STORE_H
#include <string>
#include <fstream>
#include <iostream>
#include "SessionManager.h"
#include "User.h"

class Store
{
public:
    Store();
    void ViewCategories();
    void items(string filename);
    void BathroomItems();
    void BedroomItems();
    void KitchenItems();
    void LivingRoomItems();
    void setUser(User user);
    void storeOptions();

protected:
private:
    User user;
};

#endif // STORE_H
