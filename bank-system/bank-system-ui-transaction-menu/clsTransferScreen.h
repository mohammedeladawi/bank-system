#pragma once 
#include <iostream>
#include <iomanip>
#include <vector>
#include "../bank-system/clsBankClient.h"
#include "../../utility-libraries/clsInputValidate.h"
#include "../../utility-libraries/clsUtil.h"
#include "../bank-system-ui-main-menu/clsScreen.h"



class clsTransferScreen : protected clsScreen
{
    private:
        static string _readAccountNumber()
        {
            string accountNumber = clsInputValidate::readString()
;
            while (!clsBankClient::isClientExist(accountNumber))
            {
                cout << "\nAccount number is not exist, please enter another one: ";
                accountNumber = clsInputValidate::readString();
            }

            return accountNumber;
        }

        static float _readAmount(clsBankClient sourceClient)
        {
            cout << "\nPlease enter transfer amount: ";
            float amount = clsInputValidate::readFloatNumber();

            while (amount > sourceClient.getAccountBalance())
            {
                cout << "\nAmount exceeds the available balance, please enter another amount: ";
                amount = clsInputValidate::readFloatNumber();
            }

            return amount;
        }
        
        static void _printClient(clsBankClient client)
        {
            cout << "\nClient Card: ";
            cout << "\n____________________________________________________________";
            cout << "\nFull Name  : " << client.getFullName();
            cout << "\nAcc. Number:" << client.getAccountNumber();
            cout << "\nBalance    :" << client.getAccountBalance();
            cout << "\n____________________________________________________________\n";
        }

    public:
        static void showTransferScreen()
        {
            _drawScreenHeader("\tTransfer Screen");

            cout << "\nPlease enter account number to transfer from: ";
            clsBankClient sourceClient = clsBankClient::find(_readAccountNumber());
            _printClient(sourceClient);

            cout << "\nPlease enter account number to transfer to: ";
            clsBankClient destinationClient = clsBankClient::find(_readAccountNumber());
            while(sourceClient.getAccountNumber() == destinationClient.getAccountNumber())
            {
                cout << "\nYou can't transfer money to this account, please enter another one: ";
                destinationClient = clsBankClient::find(_readAccountNumber());
            }
            
            _printClient(destinationClient);

            float amount = _readAmount(sourceClient);
            
            char answer;
            cout << "\nAre you sure you want perform this operation [y/n]: ";
            cin >> answer;

            if (tolower(answer) == 'y')
            {
                if (sourceClient.transfer(amount, destinationClient))
                {
                    cout << "\nTransfer done successfully\n"; 
                }
                else 
                {
                    cout << "\nTransfer failed\n";
                }

                _printClient(sourceClient);
                _printClient(destinationClient);
            
            }
            else
            {
                cout << "\nOperation is cancelled\n";
            }

        }
};