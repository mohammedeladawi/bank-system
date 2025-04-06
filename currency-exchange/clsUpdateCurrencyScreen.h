#pragma once
#include <iostream>
#include <iomanip>
#include "../bank-system/bank-system-ui-main-menu/clsScreen.h"
#include "../utility-libraries/clsInputValidate.h"
#include "../utility-libraries/clsString.h"
#include "clsCurrency.h"

class clsUpdateCurrencyScreen : protected clsScreen
{
    private:
        static void _updateCurrencyRate(clsCurrency &currency)
        {
            cout << "\nUpdate currency rate:";
            cout << "\n_______________________________";

            cout << "\nEnter new rate: ";
            currency.updateRate(clsInputValidate::readFloatNumber());
        }

        static void _printCurrency(clsCurrency currency)
        {
            cout << "\nCurrency Card: ";
            cout << "\n__________________________";
            cout << "\nCountry   : " << currency.getCurrencyName();
            cout << "\nCode      : " << currency.getCurrencyCode();
            cout << "\nName      : " << currency.getCountry();
            cout << "\nRate(1$)  = " << currency.getRate();
            cout << "\n__________________________" << endl;
        }
    
    public:
       static void showUpdateCurrencyScreen()
       {
            _drawScreenHeader("\tUpdate Currency Screen");

            cout << "\nPlease enter currency code: ";
            string currencyCode = clsInputValidate::readString();

            while(!clsCurrency::isCurrencyExist(currencyCode))
            {
                cout << "\nCurrency is not exist, enter another one: ";
                currencyCode = clsInputValidate::readString();
            }
            
            clsCurrency currency = clsCurrency::findByCode(currencyCode);
            _printCurrency(currency);

            char answer;
            cout << "\nAre you sure you want to update the rate of this currency [y/n]:";
            cin >> answer;

            if (toupper(answer) == 'Y')
            {
                _updateCurrencyRate(currency);
                cout << "\nCurrency Rate Updated Successfully : -)" << endl;
                _printCurrency(currency);
            }
            else
            {
                cout << "\nOperation was cancelled\n";
            }
       }
};