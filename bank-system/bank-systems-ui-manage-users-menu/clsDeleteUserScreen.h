#pragma once
#include <iostream>
#include <iomanip>
#include "clsUser.h"
#include "../../utility-libraries/clsInputValidate.h"
#include "../bank-system-ui-main-menu/clsScreen.h" 
using namespace std;


class clsDeleteUserScreen : protected clsScreen
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
        static void showDeleteUserScreen()
        {
            _drawScreenHeader("\tDelete User Screen");
                        
            cout << "\nPlease enter a username: ";
            string username = clsInputValidate::readString();

            while (!clsUser::isUserExist(username))
            {
                cout << "\nUsername is not found, please enter another one: ";
                username = clsInputValidate::readString();
            }

            clsUser user = user.find(username);
            _printUser(user);

            char answer;
            cout << "\nAre you sure you want to delete this User: ";
            cin >> answer;

            if (tolower(answer) == 'y')
            {
                bool isDeleted = user.deleteIt();

                if (isDeleted)
                {
                    cout << "User is deleted successfully\n";
                    _printUser(user);
                }
                else
                {
                    cout << "Failed to delete the User\n";
                }
            } 
        }

};