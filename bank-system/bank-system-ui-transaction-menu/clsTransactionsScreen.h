#pragma once 
#include <iostream>
#include <iomanip>
#include "../../utility-libraries/clsInputValidate.h"
#include "../bank-system-ui-main-menu/clsScreen.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"

class clsTransactionsScreen : protected clsScreen
{
    private:
        enum enTransactionsMenuOption {
            eDeposit = 1, eWithdraw = 2,
            eShowTotalBalance = 3, eTransfer = 4, eTransferLog = 5, eShowMainMenue = 6
        };

        static short _readTransactionMenuOption()
        {
            cout << "Please enter your choice [1 to 6]: ";
            short option = clsInputValidate::readIntNumberBetween(1, 6, "Enter number between 1 to 6: ");
            return option;
        }

        static void _showDepositScreen()
        {
            clsDepositScreen::showDepositScreen();
        }
        
        static void _showWithdrawScreen()
        {
            clsWithdrawScreen::showWithdrawScreen();
        }
        
        static void _showTotalBalancesScreen()
        {
            // cout << "\nTotal balances screen will be here...\n";
            clsTotalBalancesScreen::showTotalBalancesScreen();
        }

        static void _showTransferScreen()
        {
            clsTransferScreen::showTransferScreen();
        }

        static void _showTransferLogScreen()
        {
            clsTransferLogScreen::showTotalBalancesScreen();
        }

        static void _goBackToTransactionsMenu()
        {
            system("read -p 'Press Enter for going back to transactions menu...' var");
            showTransactionMenu();
        }

        static void _performTransactionMenuOption(enTransactionsMenuOption transactionsMenueOption)
        {
            switch (transactionsMenueOption)
            {
            case enTransactionsMenuOption::eDeposit:
            {
                system("clear");
                _showDepositScreen();
                _goBackToTransactionsMenu();
                break;
            }

            case enTransactionsMenuOption::eWithdraw:
            {
                system("clear");
                _showWithdrawScreen();
                _goBackToTransactionsMenu();
                break;
            }

            case enTransactionsMenuOption::eShowTotalBalance:
            {
                system("clear");
                _showTotalBalancesScreen();
                _goBackToTransactionsMenu();
                break;
            }

            case enTransactionsMenuOption::eTransfer:
            {
                system("clear");
                _showTransferScreen();
                _goBackToTransactionsMenu();
                break;
            }

            case enTransactionsMenuOption::eTransferLog:
            {
                system("clear");
                _showTransferLogScreen();
                _goBackToTransactionsMenu();
                break;
            }

            case enTransactionsMenuOption::eShowMainMenue:
            {
                //do nothing here the main screen will handle it :-) ;
            }
            }
        }

    public:
        static void showTransactionMenu()
        {
            system("clear");
            _drawScreenHeader("\t  Transactions Screen");

            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t\t  Transactions Menu\n";
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t[1] Deposit.\n";
            cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
            cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
            cout << setw(37) << left << "" << "\t[4] Transfer.\n";
            cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
            cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
            cout << setw(37) << left << "" << "===========================================\n";
 
            _performTransactionMenuOption((enTransactionsMenuOption) _readTransactionMenuOption());
        }
};