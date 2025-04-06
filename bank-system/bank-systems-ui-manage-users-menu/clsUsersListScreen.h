#pragma once
#include <iostream>
#include <iomanip>
#include "../bank-system-ui-main-menu/clsScreen.h" 
#include "clsUser.h"
using namespace std;


class clsUsersListScreen : protected clsScreen
{
    private:
        static void _printUserRecordLine(clsUser user)
        {

            cout << "| " << setw(15) << left << user.getUsername();
            cout << "| " << setw(20) << left << user.getFullName();
            cout << "| " << setw(16) << left << user.getPhone();
            cout << "| " << setw(20) << left << user.getEmail();
            cout << "| " << setw(10) << left << user.getPassword();
            cout << "| " << setw(12) << left << user.getPermissions();

        }

    public:
        static void showUsersList()
        {
            vector <clsUser> vUsers = clsUser::getUsersList();

            string title = "\tUsers List Screen";
            string subtitle = "\n\t\t\t\t\t\tUsers List (" + to_string(vUsers.size()) + ") User(s).";

            _drawScreenHeader(title, subtitle);
            cout << "\n_______________________________________________________";
            cout << "_________________________________________\n" << endl;

            cout << "| " << left << setw(15) << "Username";
            cout << "| " << left << setw(20) << "Full Name";
            cout << "| " << left << setw(16) << "Phone";
            cout << "| " << left << setw(20) << "Email";
            cout << "| " << left << setw(10) << "Password";
            cout << "| " << left << setw(12) << "Permissions";
            cout << "\n_______________________________________________________";
            cout << "_________________________________________\n" << endl;

            if (vUsers.size() == 0)
                cout << "\t\t\t\tNo Users Available In the System!";
            else
            {
                for (clsUser user : vUsers)
                {
                    _printUserRecordLine(user);
                    cout << endl;
                }
            }

            cout << "\n_______________________________________________________";
            cout << "_________________________________________\n" << endl;

        }

};