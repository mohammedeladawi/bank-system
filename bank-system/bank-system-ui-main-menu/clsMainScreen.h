#pragma once
#include <iostream>
#include <iomanip>
#include "../../utility-libraries/clsInputValidate.h"
#include "clsScreen.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "../bank-system-ui-transaction-menu/clsTransactionsScreen.h"
#include "../bank-systems-ui-manage-users-menu/clsManageUsers.h"
#include "../bank-system-login-and-permissions/global.h"
#include "../bank-system-ui-main-menu/clsLoginRegisterScreen.h"
#include "../../currency-exchange/clsCurrencyExchangeMainScreen.h"
using namespace std;

class clsMainScreen : protected clsScreen
{
    private:
        enum enMainMenuOption {
            eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
            eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
            eManageUsers = 7, eLoginRegister = 8, eCurrencyExchange = 9, eExit = 10
        };

        static short _readMainMenuOption()
        {
            cout << "Please enter your choice [1 to 10]: ";
            short option = clsInputValidate::readIntNumberBetween(1, 10, "Enter number between 1 to 10: ");
            return option;
        }

        static void _goBackToMainMenu()
        {
            system("read -p 'Press Enter for going back to main menu...' var");
            showMainMenu();
        }

        static void _showAllClientsScreen()
        {
            if (!_checkAccessRights(clsUser::enPermission::pClientsList))
            {
                return;
            }

            clsClientListScreen::showClientsList();
        }

        static void _showAddNewClientScreen()
        {
            if (!_checkAccessRights(clsUser::enPermission::pAddClient))
            {
                return;
            }
            clsAddNewClientScreen::showAddNewClientScreen();
        }

        static void _showDeleteClientScreen()
        {
            if (!_checkAccessRights(clsUser::enPermission::pDeleteClient))
            {
                return;
            }
            clsDeleteClientScreen::showDeleteClientScreen();
        }

        static void _showUpdateClientScreen()
        {
            if (!_checkAccessRights(clsUser::enPermission::pUpdateClient))
            {
                return;
            }
            clsUpdateClientScreen::showUpdateClientScreen();
        }

        static void _showFindClientScreen()
        {
            if (!_checkAccessRights(clsUser::enPermission::pFindClient))
            {
                return;
            }
            clsFindClientScreen::findClientScreen();
        }

        static void _showTransactionsMenue()
        {
            if (!_checkAccessRights(clsUser::enPermission::pTransactions))
            {
                return;
            }
            clsTransactionsScreen::showTransactionMenu();
        }

        static void _showManageUsersMenue()
        {
            if (!_checkAccessRights(clsUser::enPermission::pManageUsers))
            {
                return;
            }
            clsManageUsersScreen::showManageUsersMenu();

        }

        static void _logout()
        {
            currentUser = clsUser::find("", "");
            // clsLoginScreen::showLoginScreen(); // Circular Referrence (X)
        }

        static void _showLoginRegisterScreen()
        {
            if (!_checkAccessRights(clsUser::enPermission::pLoginRegister))
            {
                return;
            }
            clsLoginRegisterScreen::showLoginRegisterScreen();
        }

        static void _showCurrencyExchangeScreen()
        {
            clsCurrencyExchangeMainScreen::showCurrenciesMenu();
        }

        static void _perfromMainMenuOption(enMainMenuOption mainMenuOption)
        {
            switch (mainMenuOption)
            {
            case enMainMenuOption::eListClients:
            {
                system("clear");
                _showAllClientsScreen();
                _goBackToMainMenu();
                break;
            }
            case enMainMenuOption::eAddNewClient:
                system("clear");
               _showAddNewClientScreen();
                _goBackToMainMenu();
                break;

            case enMainMenuOption::eDeleteClient:
                system("clear");
                _showDeleteClientScreen();
                _goBackToMainMenu();
                break;

            case enMainMenuOption::eUpdateClient:
                system("clear");
                _showUpdateClientScreen();
                _goBackToMainMenu();
                break;

            case enMainMenuOption::eFindClient:
                system("clear");
                _showFindClientScreen();
                _goBackToMainMenu();
                break;

            case enMainMenuOption::eShowTransactionsMenue:
                system("clear");
                _showTransactionsMenue();
                _goBackToMainMenu();
                break;

            case enMainMenuOption::eManageUsers:
                system("clear");
                _showManageUsersMenue();
                _goBackToMainMenu();
                break;

            case enMainMenuOption::eLoginRegister:
                system("clear");
                _showLoginRegisterScreen();
                _goBackToMainMenu();
                break;

            case enMainMenuOption::eCurrencyExchange:
                system("clear");
                _showCurrencyExchangeScreen();
                _goBackToMainMenu();
                break;
            
            case enMainMenuOption::eExit:
                system("clear");
                _logout();
                break;
            }

        }

    public:
        static void showMainMenu()
        {
            system("clear");
            _drawScreenHeader("\t\tMain Screen");

            cout << setw(37) << left <<""<< "===========================================\n";
            cout << setw(37) << left << "" << "\t\t\tMain Menu\n";
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
            cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
            cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
            cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
            cout << setw(37) << left << "" << "\t[5] Find Client.\n";
            cout << setw(37) << left << "" << "\t[6] Transactions.\n";
            cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
            cout << setw(37) << left << "" << "\t[8] Login Register.\n";
            cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
            cout << setw(37) << left << "" << "\t[10] Logout.\n";
            cout << setw(37) << left << "" << "===========================================\n";

            _perfromMainMenuOption((enMainMenuOption) _readMainMenuOption());
        }

};
