#pragma once
#include <iostream>
#include <iomanip>
#include "../../utility-libraries/clsInputValidate.h"
#include "../bank-system-ui-main-menu/clsScreen.h"
#include "clsUser.h"
using namespace std;


class clsFindUserScreen : protected clsScreen
{
    private:
        static void _printUser(clsUser user)
        {
            cout << "\nUser Card:";
            cout << "\n___________________";
            cout << "\nFirstName   : " << user.getFirstName();
            cout << "\nLastName    : " << user.getLastName();
            cout << "\nFull Name   : " << user.getFullName();
            cout << "\nEmail       : " << user.getEmail();
            cout << "\nPhone       : " << user.getPhone();
            cout << "\nUsername    : " << user.getUsername();
            cout << "\nPassword    : " << user.getPassword();
            cout << "\nPermissions : " << user.getPermissions();
            cout << "\n___________________\n";
        }

    public:
        static void showFindUserScreen()
        {
            _drawScreenHeader("\tFind User Screen");

            cout << "\nPlease enter a username: ";
            string username = clsInputValidate::readString();

            while (!clsUser::isUserExist(username))
            {
                cout << "\nUsername is not found, please enter another one: ";
                username = clsInputValidate::readString();
            }

            clsUser user =  clsUser::find(username);

            if (user.isEmpty())
            {
                cout << "\nUser is not found\n";
            }
            else
            {
                cout << "\nUser is found :-)\n";
            }
            _printUser(user);
        }
};