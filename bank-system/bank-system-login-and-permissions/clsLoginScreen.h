#pragma once 
#include <iostream>
#include <iomanip>
#include "../../utility-libraries/clsInputValidate.h"
#include "../../utility-libraries/clsUtil.h"
#include "../bank-system-ui-main-menu/clsMainScreen.h"
#include "../bank-system-ui-main-menu/clsScreen.h"
#include "global.h"
using namespace std;


class clsLoginScreen : protected clsScreen
{
    private:
        static bool _login()
        {
            string username, password;
            bool loginFailed = false;
            short tries = 3;
            do 
            {
                if (loginFailed)
                {
                    tries--;
                    cout << "\nInvalid Username/Password!";
                    cout << "\nYou have " << tries << " trial(s) to login\n";
                    if (tries == 0) 
                    {
                        cout << "\nYou have locked after 3 failed trials\n";
                        return false;
                    }
                }


                cout << "Please enter your username: ";
                username = clsInputValidate::readString();
                
                cout << "Please enter your password: ";
                password = clsInputValidate::readString();
            
                currentUser = clsUser::find(username, password);
                loginFailed = currentUser.isEmpty();

            } while(loginFailed);

            currentUser.registerLogin();
            clsMainScreen::showMainMenu();
            return true;
        }

    public:
        static bool showLoginScreen()
        {
            system("clear");
            _drawScreenHeader("\tLogin Screen");
            return _login();
        }
};