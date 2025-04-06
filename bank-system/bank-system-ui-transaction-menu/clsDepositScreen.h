#pragma once 
#include <iostream>
#include <iomanip>
#include "../bank-system/clsBankClient.h"
#include "../../utility-libraries/clsInputValidate.h"
#include "../bank-system-ui-main-menu/clsScreen.h"

class clsDepositScreen : protected clsScreen
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
        static void showDepositScreen()
        {
            _drawScreenHeader("\tDeposit Screen");
            

            cout << "Please enter the account number: ";
            string accountNumber = clsInputValidate::readString();
    
            while (!clsBankClient::isClientExist(accountNumber))
            {
                cout << "\nClient with Account Number (" << accountNumber << ") is Not Found!" << endl;
                cout << "Please enter another account number: ";
                accountNumber = clsInputValidate::readString();
            }
            
            clsBankClient client = clsBankClient::find(accountNumber);
            _printClient(client);

            cout << "Please enter deposite amount: ";
            double amount = clsInputValidate::readDblNumber();
            
            char answer;
            cout << "Are you sure you want to perform this transaction [Y/N]? ";
            cin >> answer;

            if (toupper(answer) == 'Y')
            {
                client.deposit(amount);
                cout << "\nAmount deposited successfully\n";
                cout << "\nNew balance is: " << client.getAccountBalance() << endl;
            }
            else 
            {
                cout << "\nOperation was canceled.\n";
            }
        }
};