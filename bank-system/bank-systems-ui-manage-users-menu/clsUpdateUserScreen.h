#pragma once
#include <iostream>
#include <iomanip>
#include "clsUser.h"
#include "../../utility-libraries/clsInputValidate.h"
#include "../bank-system-ui-main-menu/clsScreen.h" 
using namespace std;



class clsUpdateUserScreen : protected clsScreen
{
    private:
        static void _readUserInfo(clsUser& user)
        {
            cout << "Enter First Name: ";
            user.setFirstName(clsInputValidate::readString());
            
            cout << "Enter Last Name: ";
            user.setLastName(clsInputValidate::readString());
            
            cout << "Enter Email: ";
            user.setEmail(clsInputValidate::readString());
            
            cout << "Enter Phone Number: ";
            user.setPhone(clsInputValidate::readString());
            
            cout << "Enter Password: ";
            user.setPassword(clsInputValidate::readString());
            
            cout << "Enter Permissions: ";
            user.setPermissions(_readPermissionsToSet());
        }

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

        enum enMainMenuPermissions 
        { 
            pAll = -1, pUsersList = 1, pAddUser = 2, 
            pDeleteUser = 4, pUpdateUser = 8,
            pFindUser = 16, pTransactions = 32,
            pManageUsers = 64, pLogout = 128,
        };

        static short _readPermissionsToSet()
        {
            char answer;
            short permissions = 0;

            cout << "Do you want to give full access (y/n)? ";
            cin >> answer;

            if (toupper(answer) == 'Y')
            {
                return -1;
            }
            
            cout << "Do you want to give access to: \n";

            cout << "Show User list: [y/n]: ";
            cin >> answer;
            if (toupper(answer) == 'Y')
                permissions += enMainMenuPermissions::pUsersList; 

            cout << "Add new User: [y/n]: ";
            cin >> answer;
            if (toupper(answer) == 'Y')
                permissions += enMainMenuPermissions::pAddUser; 

            cout << "Delete User: [y/n]: ";
            cin >> answer;
            if (toupper(answer) == 'Y')
                permissions += enMainMenuPermissions::pDeleteUser; 

            cout << "Update User: [y/n]: ";
            cin >> answer;
            if (toupper(answer) == 'Y')
                permissions += enMainMenuPermissions::pUpdateUser; 

            cout << "Find User: [y/n]: ";
            cin >> answer;
            if (toupper(answer) == 'Y')
                permissions += enMainMenuPermissions::pFindUser; 

            cout << "Transactions: [y/n]: ";
            cin >> answer;
            if (toupper(answer) == 'Y')
                permissions += enMainMenuPermissions::pTransactions; 

            cout << "Manage Users: [y/n]: ";
            cin >> answer;
            if (toupper(answer) == 'Y')
                permissions += enMainMenuPermissions::pManageUsers;

            return permissions;
        }

    public:
        static void showUpdateUserScreen()
        {
            _drawScreenHeader("\tUpdate User Screen");

            cout << "\nPlease enter a username: ";
            string username = clsInputValidate::readString();

            while (!clsUser::isUserExist(username))
            {
                cout << "\nUsername is not found, please enter another one: ";
                username = clsInputValidate::readString();
            }

            clsUser user = clsUser::find(username);
            _printUser(user);

            _readUserInfo(user);

            clsUser::enSaveResult saveResult =  user.save();

            switch (saveResult)
            {
                case clsUser::enSaveResult::svSucceeded:
                    cout << "\nAccount updated successfully :-)\n";
                    _printUser(user);
                    break;
                
                case clsUser::enSaveResult::svFailedEmptyObject:
                    cout << "\nError account was not saved because it's Empty\n";
                    break;

                case clsUser::enSaveResult::svFailedUserIsExist:
                    cout << "\nFailed because username already in use\n";
                    break;
            }
        }

};