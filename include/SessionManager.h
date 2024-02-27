#ifndef SESSIONMANAGER_H
#define SESSIONMANAGER_H
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
class SessionManager
{
public:
    SessionManager();
    void whichLogin();
    void addUser();
    float whatNext();
    float sessionAction();
    void logOut();
    bool login(string usernameTry, string passwordTry, string fileToOpen1, string fileToOpen2); //Function used to login a user
    int compareUsername(const string usernameTry, string fileToOpen);          //Function used to compare username attempt to exisiting usernames
    bool comparePasswords(string passwordtry, int lineNum, string fileToOpen); //Function used to compare password attempt to exisiting and corresponding password
private:

};

#endif // SESSIONMANAGER_H
