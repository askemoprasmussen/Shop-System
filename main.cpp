#include <iostream>
#include "SessionManager.h"
#include "AdminStore.h"
#include "ShoppingCart.h"
#include "Store.h"
#include "User.h"
using namespace std;

//BOOST TESTING!! IMPORTANT FOR UNIT TEST TO WORK THE FOLLOWING LINES MUST BE COMMENTED OUT
//main.cpp lines 273-317
//AdminStore.cpp line 201
//Store.cpp line 75
//Otherwise autoscroll will make result unreadable
//BOOST TESTING!! IMPORTANT FOR UNIT TEST TO WORK THE FOLLOWING LINES MUST BE UNCOMMENTED
//main.cpp lines 19-272
//SessionManager.cpp lines 102-106, 113-117, 145-154, 181-190
//AdminStore.cpp lines 172-181, 230-239, 245-250
//Store.cpp lines 62-67
//Otherwise no tests will run


/* #include <Exception.h>
#define BOOST_TEST_MODULE SRSTesting
#include <boost/test/included/unit_test.hpp>

//SessionManager TESTING
BOOST_AUTO_TEST_CASE( UsernameShouldSucceed ){
       SessionManager SessionManager1;
       SessionManager1.compareUsername("TestingA", "usernames.txt");
}

BOOST_AUTO_TEST_CASE( UsernameError ){
       SessionManager SessionManager1;
       BOOST_CHECK_THROW(SessionManager1.compareUsername("Testing", "usernames.txt"),std::exception);
}
BOOST_AUTO_TEST_CASE( UserFilePathError ){
       SessionManager SessionManager1;
       BOOST_CHECK_THROW(SessionManager1.compareUsername("TestingA", "username.txt"),std::exception);
}

//SessionManager PASSWORD TESTING
BOOST_AUTO_TEST_CASE( PasswordShouldSucceed ){
       SessionManager SessionManager1;
       SessionManager1.comparePasswords("TestPassA",1,"passwords.txt");
}
BOOST_AUTO_TEST_CASE( PasswordError ){
       SessionManager SessionManager1;
       BOOST_CHECK_THROW(SessionManager1.comparePasswords("testpassa",1,"passwords.txt"),std::exception);
}
BOOST_AUTO_TEST_CASE( PassFilePathError ){
       SessionManager SessionManager1;
       BOOST_CHECK_THROW(SessionManager1.comparePasswords("TestingA",1,"passworlds.txt"),std::exception);
}

//SessionManager LOGIN TESTING
BOOST_AUTO_TEST_CASE( LoginShouldSucceed ){
       SessionManager SessionManager1;
       SessionManager1.login("TestingA","TestPassA","usernames.txt","passwords.txt");
}
BOOST_AUTO_TEST_CASE( LoginUsernameError ){
       SessionManager SessionManager1;
       BOOST_CHECK_THROW(SessionManager1.login("Testing","TestPassA","usernames.txt","passwords.txt"),std::exception);
}
BOOST_AUTO_TEST_CASE( LoginPasswordError ){
       SessionManager SessionManager1;
       BOOST_CHECK_THROW(SessionManager1.login("TestingA","TestPass","usernames.txt","passwords.txt"),std::exception);
}
BOOST_AUTO_TEST_CASE( LoginUserFilePathError ){
       SessionManager SessionManager1;
       BOOST_CHECK_THROW(SessionManager1.login("TestingA","TestPassA","username.txt","passwords.txt"),std::exception);
}
BOOST_AUTO_TEST_CASE( LoginPassFilePathError ){
       SessionManager SessionManager1;
       BOOST_CHECK_THROW(SessionManager1.login("TestingA","TestPassA","usernames.txt","password.txt"),std::exception);
}


//ADMIN SessionManagerNAME TESTING
BOOST_AUTO_TEST_CASE( AdminUsernameShouldSucceed ){
       SessionManager SessionManager1;
       BOOST_CHECK(SessionManager1.compareUsername("TestAdmin", "AdminUsers.txt"));
}
BOOST_AUTO_TEST_CASE( AdminUsernameError ){
       SessionManager SessionManager1;
       BOOST_CHECK_THROW(SessionManager1.compareUsername("TestAdmi", "AdminUsers.txt"),std::exception);
}
BOOST_AUTO_TEST_CASE( AdminUserFilePathError ){
       SessionManager SessionManager1;
       BOOST_CHECK_THROW(SessionManager1.compareUsername("TestAdmin", "AdminUserst.txt"),std::exception);
}

//ADMIN PASSWORD TESTING
BOOST_AUTO_TEST_CASE( AdminPasswordShouldSucceed ){
       SessionManager SessionManager1;
       BOOST_CHECK(SessionManager1.comparePasswords("AdminPass",1,"adminPasswords.txt"));
}
BOOST_AUTO_TEST_CASE( AdminPasswordError ){
       SessionManager SessionManager1;
       BOOST_CHECK_THROW(SessionManager1.comparePasswords("adminPass",1,"adminPasswords.txt"),std::exception);
}
BOOST_AUTO_TEST_CASE( AdminPassFilePathError ){
       SessionManager SessionManager1;
       BOOST_CHECK_THROW(SessionManager1.comparePasswords("AdminPass",1,"adminPassworlds.txt"),std::exception);
}

//ADMIN LOGIN TESTING
BOOST_AUTO_TEST_CASE( AdminLoginShouldSucceed ){
       SessionManager SessionManager1;
       SessionManager1.login("TestAdmin","AdminPass","AdminUsers.txt","adminPasswords.txt");
}
BOOST_AUTO_TEST_CASE( AdminLoginSessionManagernameError ){
       SessionManager SessionManager1;
       BOOST_CHECK_THROW(SessionManager1.login("TestAdmon","AdminPass","AdminUsers.txt","adminPasswords.txt"),std::exception);
}
BOOST_AUTO_TEST_CASE( AdminLoginPasswordError ){
       SessionManager SessionManager1;
       BOOST_CHECK_THROW(SessionManager1.login("TestAdmin","Adminpass","AdminUsers.txt","adminPasswords.txt"),std::exception);
}
BOOST_AUTO_TEST_CASE( AdminLoginSessionManagerFilePathError ){
      SessionManager SessionManager1;
       BOOST_CHECK_THROW(SessionManager1.login("TestAdmin","AdminPass","AdinUser.txt","adminPasswords.txt"),std::exception);
}
BOOST_AUTO_TEST_CASE( AdminLoginPassFilePathError ){
       SessionManager SessionManager1;
       BOOST_CHECK_THROW(SessionManager1.login("TestAdmin","AdminPass","AdminUsers.txt","adminPassword.txt"),std::exception);
}

//ADMIN ADDITEM TESTING
BOOST_AUTO_TEST_CASE( AddBathroomItemShouldPass ){
      AdminStore AdminStore1;
      AdminStore1.adminAdd("Gold Statue 20","BathroomItems.txt");
}
BOOST_AUTO_TEST_CASE( AddBathroomItemPathFailure ){
      AdminStore AdminStore1;
       BOOST_CHECK_THROW(AdminStore1.adminAdd("Gold Statue 20","BathroomItems.tt"),std::exception);
}
BOOST_AUTO_TEST_CASE( AddBathroomItemNameFailure ){
      AdminStore AdminStore1;
       BOOST_CHECK_THROW(AdminStore1.adminAdd("old Statue 20","BathroomItems.txt"),std::exception);
}
//BEDROOM
BOOST_AUTO_TEST_CASE( AddBedroomItemShouldPass ){
      AdminStore AdminStore1;
      AdminStore1.adminAdd("Gold Statue 20","BedroomItems.txt");
}
BOOST_AUTO_TEST_CASE( AddBedroomItemPathFailure ){
      AdminStore AdminStore1;
       BOOST_CHECK_THROW(AdminStore1.adminAdd("Gold Statue 20","BedroomItems.tt"),std::exception);
}
BOOST_AUTO_TEST_CASE( AddBedroomItemNameFailure ){
      AdminStore AdminStore1;
       BOOST_CHECK_THROW(AdminStore1.adminAdd("old Statue 20","BedroomItems.txt"),std::exception);
}
//LIVINGROOM
BOOST_AUTO_TEST_CASE( AddLivingRoomItemShouldPass ){
      AdminStore AdminStore1;
       AdminStore1.adminAdd("Gold Statue 20","LivingRoomItems.txt");
}
BOOST_AUTO_TEST_CASE( AddLivingRoomItemPathFailure ){
      AdminStore AdminStore1;
       BOOST_CHECK_THROW(AdminStore1.adminAdd("Gold Statue 20","LivingRoomItems.tt"),std::exception);
}
BOOST_AUTO_TEST_CASE( AddLivingRoomItemNameFailure ){
      AdminStore AdminStore1;
       BOOST_CHECK_THROW(AdminStore1.adminAdd("old Statue 20","LivingRoomItems.txt"),std::exception);
}
//KITCHEN
BOOST_AUTO_TEST_CASE( AddKitchenItemShouldPass ){
      AdminStore AdminStore1;
       AdminStore1.adminAdd("Gold Statue 20","KitchenItems.txt");
}
BOOST_AUTO_TEST_CASE( AddKitchenItemPathFailure ){
      AdminStore AdminStore1;
       BOOST_CHECK_THROW(AdminStore1.adminAdd("Gold Statue 20","LivingRoomItems.tt"),std::exception);
}
BOOST_AUTO_TEST_CASE( AddKitchenItemNameFailure ){
      AdminStore AdminStore1;
       BOOST_CHECK_THROW(AdminStore1.adminAdd("old Statue 20","LivingRoomItems.txt"),std::exception);
}

//ADMIN REMOVEITEM TESTING
//BATHROOM
BOOST_AUTO_TEST_CASE( RemoveBathroomItemShouldPass ){
      AdminStore AdminStore1;
       AdminStore1.adminRemove("BathroomItems.txt","Gold Statue");
}
BOOST_AUTO_TEST_CASE( RemoveBathroomItemPathError ){
      AdminStore AdminStore1;
       BOOST_CHECK_THROW(AdminStore1.adminRemove("BathroomItems.tt","Gold Statue"),std::exception);
}
BOOST_AUTO_TEST_CASE( RemoveBathroomItemNameError ){
      AdminStore AdminStore1;
       BOOST_CHECK_THROW(AdminStore1.adminRemove("BathroomItems.txt","old Statue"),std::exception);
}
//BEDROOM
BOOST_AUTO_TEST_CASE( RemoveBedroomItemShouldPass ){
      AdminStore AdminStore1;
       AdminStore1.adminRemove("BedroomItems.txt","Gold Statue");
}
BOOST_AUTO_TEST_CASE( RemoveBedroomItemPathError ){
      AdminStore AdminStore1;
       BOOST_CHECK_THROW(AdminStore1.adminRemove("BedroomItems.tt","Gold Statue"),std::exception);
}
BOOST_AUTO_TEST_CASE( RemoveBedroomItemNameError ){
      AdminStore AdminStore1;
       BOOST_CHECK_THROW(AdminStore1.adminRemove("BedroomItems.txt","old Statue"),std::exception);
}
//LIVINGROOM
BOOST_AUTO_TEST_CASE( RemoveLivingRoomItemShouldPass ){
      AdminStore AdminStore1;
       AdminStore1.adminRemove("LivingRoomItems.txt","Gold Statue");
}
BOOST_AUTO_TEST_CASE( RemoveLivingRoomItemPathError ){
      AdminStore AdminStore1;
       BOOST_CHECK_THROW(AdminStore1.adminRemove("LivingRoomItems.tt","Gold Statue"),std::exception);
}
BOOST_AUTO_TEST_CASE( RemoveLivingRoomItemNameError ){
      AdminStore AdminStore1;
       BOOST_CHECK_THROW(AdminStore1.adminRemove("LivingRoomItems.txt","old Statue"),std::exception);
}
//KITCHEN
BOOST_AUTO_TEST_CASE( RemoveKitchenItemShouldPass ){
      AdminStore AdminStore1;
       AdminStore1.adminRemove("KitchenItems.txt","Gold Statue");
}
BOOST_AUTO_TEST_CASE( RemoveKitchenItemPathError ){
      AdminStore AdminStore1;
       BOOST_CHECK_THROW(AdminStore1.adminRemove("KitchenItems.tt","Gold Statue"),std::exception);
}
BOOST_AUTO_TEST_CASE( RemoveKitchenItemNameError ){
      AdminStore AdminStore1;
       BOOST_CHECK_THROW(AdminStore1.adminRemove("KitchenItems.txt","old Statue"),std::exception);
}
//DISPLAYCATEGORIES TESTING
//BATHROOM
BOOST_AUTO_TEST_CASE( DisplayBathroomShouldPass ){
      AdminStore AdminStore1;
       AdminStore1.adminDisplayCategories("BathroomItems.txt");
}
BOOST_AUTO_TEST_CASE( DisplayBathroomPathError ){
      AdminStore AdminStore1;
       BOOST_CHECK_THROW(AdminStore1.adminDisplayCategories("BathroomIems.txt"),std::exception);
}
//BEDROOM
BOOST_AUTO_TEST_CASE( DisplayBedroomShouldPass ){
      AdminStore AdminStore1;
       AdminStore1.adminDisplayCategories("BedroomItems.txt");
}
BOOST_AUTO_TEST_CASE( DisplayBedroomPathError ){
      AdminStore AdminStore1;
       BOOST_CHECK_THROW(AdminStore1.adminDisplayCategories("BedroomIems.txt"),std::exception);
}
//LIVINGROOM
BOOST_AUTO_TEST_CASE( DisplayLivingRoomShouldPass ){
      AdminStore AdminStore1;
       AdminStore1.adminDisplayCategories("LivingRoomItems.txt");
}
BOOST_AUTO_TEST_CASE( DisplayLivingRoomPathError ){
      AdminStore AdminStore1;
       BOOST_CHECK_THROW(AdminStore1.adminDisplayCategories("LivingRoomIems.txt"),std::exception);
}
//KITCHEN
BOOST_AUTO_TEST_CASE( DisplayKitchenShouldPass ){
      AdminStore AdminStore1;
       AdminStore1.adminDisplayCategories("KitchenItems.txt");
}
BOOST_AUTO_TEST_CASE( DisplayKitchenPathError ){
      AdminStore AdminStore1;
       BOOST_CHECK_THROW(AdminStore1.adminDisplayCategories("KitchenIems.txt"),std::exception);
}
BOOST_AUTO_TEST_CASE( CartItemsPathError ){
    Store Store1;
   BOOST_CHECK_THROW(Store1.items("CartIems.txt"),std::exception);
}
*/

//Comment Out Main function to Boost Test
int main()
{
    ofstream emptyCart;
    emptyCart.open("tempo.txt");
    emptyCart.close();
    remove("CartItems.txt");
    rename("tempo.txt" , "CartItems.txt");

    Store store;
    AdminStore adminStore;
    SessionManager session;
    AdminStore adminUserlog;
    bool running = true;

    while (running)
    {
        ofstream emptyCart;
        emptyCart.open("tempo.txt");
        emptyCart.close();
        remove("CartItems.txt");
        rename("tempo.txt","CartItems.txt");
        int loginStatus = 0;
        cout << "Welcome to Omens!\n"
             << endl;

        loginStatus = session.sessionAction(); //Calls for userAction() to check what type of login is made

        switch (loginStatus)
        {

        case 1:
            store.setUser(User());
            store.storeOptions();
            // if logout we restart
            break;

        case 2:
            adminStore.setUser(User());
            adminStore.storeOptions(); //Admin user login so admin user is taken to admin user options
            break;

        case 4:
            running = false;
            break;
        }
    }

    return 0;
}


