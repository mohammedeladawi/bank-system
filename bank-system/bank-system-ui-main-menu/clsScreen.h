#pragma once 
#include <iostream>
#include "../bank-system-login-and-permissions/global.h"
#include "../bank-systems-ui-manage-users-menu/clsUser.h"
#include "../../utility-libraries/clsDate.h"
using namespace std;


class clsScreen
{
    protected:
        static void _drawScreenHeader(string title, string subtitle = "")
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  " << title;
            if (subtitle != "")
            {
                cout << "\n\t\t\t\t\t  " << subtitle;
            }
            cout << "\n\t\t\t\t\t______________________________________\n\n";

            cout << "\t\t\t\t\tUser: " << currentUser.getUsername() << "\n";
            // printf("\t\t\t\t\tDate: %0*d/%0*d/%0*d\n", 2, date.getDay(), 2, date.getMonth(), 4, date.getYear());
            cout << "\t\t\t\t\tDate: " << clsDate::dateToString(clsDate()) << endl;
        }

        static bool _checkAccessRights(clsUser::enPermission permission)
        {
                if (!currentUser.checkAccessPermission(permission))
                {
                    cout << "\t\t\t\t\t______________________________________";
                    cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";   
                    cout << "\n\t\t\t\t\t______________________________________\n\n";
                    return false;
                }
                else
                {
                    return true;
                }
        }
};