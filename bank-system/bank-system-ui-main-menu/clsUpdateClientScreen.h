#pragma once
#include <iostream>
#include <iomanip>
#include "../../utility-libraries/clsInputValidate.h"
#include "../bank-system/clsBankClient.h"
#include "clsScreen.h" 
using namespace std;

class clsUpdateClientScreen : protected clsScreen
{
    private:
        static void _readClientInfo(clsBankClient& client)
        {
            cout << "Enter First Name: ";
            client.setFirstName(clsInputValidate::readString());
            
            cout << "Enter Last Name: ";
            client.setLastName(clsInputValidate::readString());
            
            cout << "Enter Email: ";
            client.setEmail(clsInputValidate::readString());
            
            cout << "Enter Phone Number: ";
            client.setPhone(clsInputValidate::readString());
            
            cout << "Enter Pin Code: ";
            client.setPinCode(clsInputValidate::readString());
            
            cout << "Enter Account Balance: ";
            client.setAccountBalance(clsInputValidate::readFloatNumber());
        }
        
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
        static void showUpdateClientScreen()
        {
            _drawScreenHeader("\tUpdate Client Screen");

            cout << "\nPlease enter a client account number: ";
            string accountNumber = clsInputValidate::readString();

            while (!clsBankClient::isClientExist(accountNumber))
            {
                cout << "\nAccount number is not found, please enter another one: ";
                accountNumber = clsInputValidate::readString();
            }

            clsBankClient client = clsBankClient::find(accountNumber);
            _printClient(client);

            _readClientInfo(client);

            clsBankClient::enSaveResult saveResult =  client.save();

            switch (saveResult)
            {
                case clsBankClient::enSaveResult::svSucceeded:
                    cout << "\nAccount updated successfully :-)\n";
                    _printClient(client);
                    break;
                
                case clsBankClient::enSaveResult::svFailedEmptyObject:
                    cout << "\nError account was not saved because it's Empty\n";
                    break;

                case clsBankClient::enSaveResult::svFailedClientIsExist:
                    cout << "\nFailed because account number already in use\n";
                    break;
            }
        }

};