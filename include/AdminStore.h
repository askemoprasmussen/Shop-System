#ifndef ADMINUSER_H
#define ADMINUSER_H
#include <string>
#include <fstream>
#include <iostream>
#include "Store.h"
using namespace std;

class AdminStore : public Store
{
public:
    AdminStore();
    void adminOptions();
    void adminAdd(string nameAndPrice, string whichfile);
    void adminRemove(string whichFile, string itemToDelete);
    void adminDisplayCategories(string whichFile);
    void storeOptions();

protected:
private:
};

#endif // ADMINUSER_H
