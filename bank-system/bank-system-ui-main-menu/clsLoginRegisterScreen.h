#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include "../bank-system-ui-main-menu/clsScreen.h"
#include "../bank-systems-ui-manage-users-menu/clsUser.h"
using namespace std;


class clsLoginRegisterScreen : protected clsScreen
{
    private:
        static void _printLoginRegisterRecord(clsUser::stLoginRegisterRecord loginRegisterRecord)
        {
            cout << "| " << setw(35) << left << loginRegisterRecord.dateTime;
            cout << "| " << setw(20) << left << loginRegisterRecord.username;
            cout << "| " << setw(20) << left << loginRegisterRecord.password;
            cout << "| " << setw(20) << left << loginRegisterRecord.permissions;
        }

    public:
        static void showLoginRegisterScreen()
        {
            vector<clsUser::stLoginRegisterRecord> vLoginRegisterRecords = clsUser::getLoginRegisterList();

            _drawScreenHeader("\tLogin Register List Screen");
            cout << "\n_______________________________________________________";
            cout << "_________________________________________\n" << endl;

            cout << "| " << left << setw(35) << "Date-Time";
            cout << "| " << left << setw(20) << "Username";
            cout << "| " << left << setw(20) << "Password";
            cout << "| " << left << setw(20) << "Permissions";
            cout << "\n_______________________________________________________";
            cout << "_________________________________________\n" << endl;

            if (vLoginRegisterRecords.size() == 0)
                cout << "\t\t\t\tNo Records Available In the System!";
            else
            {
                for (clsUser::stLoginRegisterRecord record : vLoginRegisterRecords)
                {

                    _printLoginRegisterRecord(record);
                    cout << endl;
                }
            }

            cout << "\n_______________________________________________________";
            cout << "_________________________________________\n" << endl;

        }

};