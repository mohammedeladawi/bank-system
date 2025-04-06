#pragma once
#include <iostream>
#include <iomanip>
#include "../../utility-libraries/clsInputValidate.h"
#include "../bank-system/clsBankClient.h"
#include "clsScreen.h" 
using namespace std;


class clsFindClientScreen : protected clsScreen
{
    private:
        static void _printClient(clsBankClient client)
        {
            cout << "\nClient Card:";
            cout << "\n___________________";
            cout << "\nFirstName   : " << client.getFirstName();
            cout << "\nLastName    : " << client.getLastName();
            cout << "\nFull Name   : " << client.getFullName();
            cout << "\nEmail       : " << client.getEmail();
            cout << "\nPhone       : " << client.getPhone();
            cout << "\nAcc. Number : " << client.getAccountNumber();
            cout << "\nPassword    : " << client.getPinCode();
            cout << "\nBalance     : " << client.getAccountBalance();
            cout << "\n___________________\n";
        }
    
    public:
        static void findClientScreen()
        {
            _drawScreenHeader("\tFind Client Screen");

            cout << "\nPlease enter a client account number: ";
            string accountNumber = clsInputValidate::readString();

            while (!clsBankClient::isClientExist(accountNumber))
            {
                cout << "\nAccount number is not found, please enter another one: ";
                accountNumber = clsInputValidate::readString();
            }

            clsBankClient client =  clsBankClient::find(accountNumber);

            if (client.isEmpty())
            {
                cout << "\nClient is not found\n";
            }
            else
            {
                cout << "\nClient is found :-)\n";
            }
            _printClient(client);
        }
};