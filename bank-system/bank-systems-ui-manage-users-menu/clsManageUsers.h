#pragma once
#include <iostream>
#include <iomanip>
#include "../bank-system-ui-main-menu/clsScreen.h"
#include "../../utility-libraries/clsInputValidate.h"
#include "clsUsersListScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"
using namespace std;


class clsManageUsersScreen : protected clsScreen
{
private:
    enum enManageUsersMenuOption {
        eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
        eUpdateUser = 4, eFindUser = 5, eMainMenue = 6
    };

    static short readManageUsersMenuOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::readShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }

    static void _goBackToManageUsersMenue()
    {
        system("read -p 'Press Enter for going back to manage users screen...' var");
        showManageUsersMenu();
    }

    static void _showListUsersScreen()
    {
        // cout << "\nList Users Screen Will Be Here.\n";
        clsUsersListScreen::showUsersList();
    }

    static void _showAddNewUserScreen()
    {
        // cout << "\nAdd New User Screen Will Be Here.\n";
        clsAddNewUserScreen::showAddNewUserScreen();
    }

    static void _showDeleteUserScreen()
    {
        // cout << "\nDelete User Screen Will Be Here.\n";
        clsDeleteUserScreen::showDeleteUserScreen();

    }

    static void _showUpdateUserScreen()
    {
        // cout << "\nUpdate User Screen Will Be Here.\n";
        clsUpdateUserScreen::showUpdateUserScreen();
    }

    static void _showFindUserScreen()
    {
        // cout << "\nFind User Screen Will Be Here.\n";
        clsFindUserScreen::showFindUserScreen();
    }

    static void _performManageUsersMenuOption(enManageUsersMenuOption manageUsersMenuOption)
    {

        switch (manageUsersMenuOption)
        {
        case enManageUsersMenuOption::eListUsers:
        {
            system("clear");
            _showListUsersScreen();
            _goBackToManageUsersMenue();
            break;
        }

        case enManageUsersMenuOption::eAddNewUser:
        {
            system("clear");
            _showAddNewUserScreen();
            _goBackToManageUsersMenue();
            break;
        }

        case enManageUsersMenuOption::eDeleteUser:
        {
            system("clear");
            _showDeleteUserScreen();
            _goBackToManageUsersMenue();
            break;
        }

        case enManageUsersMenuOption::eUpdateUser:
        {
            system("clear");
            _showUpdateUserScreen();
            _goBackToManageUsersMenue();
            break;
        }

        case enManageUsersMenuOption::eFindUser:
        {
            system("clear");

             _showFindUserScreen();
            _goBackToManageUsersMenue();
            break;
        }

        case enManageUsersMenuOption::eMainMenue:
        {
            //do nothing here the main screen will handle it :-) ;
        }
        }

    }

public:
    static void showManageUsersMenu()
    {

        system("clear");
        _drawScreenHeader("\t Manage Users Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Manage Users Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _performManageUsersMenuOption((enManageUsersMenuOption)readManageUsersMenuOption());
    }

};

