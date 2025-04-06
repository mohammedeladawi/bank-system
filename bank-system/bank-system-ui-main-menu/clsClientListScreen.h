#pragma once
#include <iostream>
#include <iomanip>
#include "../bank-system/clsBankClient.h"
#include "clsScreen.h" 
using namespace std;


class clsClientListScreen : protected clsScreen
{
    private:
        static void _printClientRecordLine(clsBankClient client)
        {

            cout << "| " << setw(15) << left << client.getAccountNumber();
            cout << "| " << setw(20) << left << client.getFullName();
            cout << "| " << setw(16) << left << client.getPhone();
            cout << "| " << setw(20) << left << client.getEmail();
            cout << "| " << setw(10) << left << client.getPinCode();
            cout << "| " << setw(12) << left << client.getAccountBalance();

        }

    public:
        static void showClientsList()
        {
            vector <clsBankClient> vClients = clsBankClient::getClientsList();

            string title = "\tClient List Screen";
            string subtitle = "\n\t\t\t\t\t\tClient List (" + to_string(vClients.size()) + ") Client(s).";

            _drawScreenHeader(title, subtitle);
            cout << "\n_______________________________________________________";
            cout << "_________________________________________\n" << endl;

            cout << "| " << left << setw(15) << "Accout Number";
            cout << "| " << left << setw(20) << "Client Name";
            cout << "| " << left << setw(16) << "Phone";
            cout << "| " << left << setw(20) << "Email";
            cout << "| " << left << setw(10) << "Pin Code";
            cout << "| " << left << setw(12) << "Balance";
            cout << "\n_______________________________________________________";
            cout << "_________________________________________\n" << endl;

            if (vClients.size() == 0)
                cout << "\t\t\t\tNo Clients Available In the System!";
            else
            {
                for (clsBankClient client : vClients)
                {

                    _printClientRecordLine(client);
                    cout << endl;
                }
            }

            cout << "\n_______________________________________________________";
            cout << "_________________________________________\n" << endl;

        }

};