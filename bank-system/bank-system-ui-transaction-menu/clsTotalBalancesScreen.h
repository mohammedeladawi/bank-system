#pragma once 
#include <iostream>
#include <iomanip>
#include <vector>
#include "../bank-system/clsBankClient.h"
#include "../../utility-libraries/clsInputValidate.h"
#include "../../utility-libraries/clsUtil.h"
#include "../bank-system-ui-main-menu/clsScreen.h"

class clsTotalBalancesScreen : protected clsScreen
{
    private:
        static void _printClientRecordBalanceLine(clsBankClient Client)
        {

            cout << "| " << setw(15) << left << Client.getAccountNumber();
            cout << "| " << setw(40) << left << Client.getFullName();
            cout << "| " << setw(12) << left << Client.getAccountBalance();

        }
        
    public:
        static void showTotalBalancesScreen()
        {
            vector <clsBankClient> vClients = clsBankClient::getClientsList();
            string title = "\tTotal Balances Screen";
            string subtitle = "\n\t\t\t\t\tBalances List (" + to_string(vClients.size()) + ") Client(s).";
            
            _drawScreenHeader(title, subtitle);


            cout << "\n_______________________________________________________";
            cout << "_________________________________________\n" << endl;

            cout << "| " << left << setw(15) << "Accout Number";
            cout << "| " << left << setw(40) << "Client Name";
            cout << "| " << left << setw(12) << "Balance";
            cout << "\n_______________________________________________________";
            cout << "_________________________________________\n" << endl;

            double totalBalances = clsBankClient::getTotalBalances();

            if (vClients.size() == 0)
                cout << "\t\t\t\tNo Clients Available In the System!";
            else

                for (clsBankClient Client : vClients)
                {
                    _printClientRecordBalanceLine(Client);
                    cout << endl;
                }

            cout << "\n_______________________________________________________";
            cout << "_________________________________________\n" << endl;
            cout << "\t\t\t\t\t   Total Balances = " << totalBalances << endl;
            cout << "\t\t\t\t\t   ( " << clsUtil::numberToText(totalBalances) << ")" << endl;
        }   

};