#pragma once
#include <iostream>
#include <iomanip>
#include "../bank-system/bank-system-ui-main-menu/clsScreen.h"
#include "../utility-libraries/clsInputValidate.h"
#include "../utility-libraries/clsString.h"
#include "clsCurrency.h"

class clsCurrencyCalculatorScreen : protected clsScreen
{
    private:
        static void _printCurrency(clsCurrency currency)
        {
            cout << "\n__________________________";
            cout << "\nCountry   : " << currency.getCountry();
            cout << "\nCode      : " << currency.getCurrencyCode();
            cout << "\nName      : " << currency.getCurrencyName();
            cout << "\nRate(1$)  = " << currency.getRate();
            cout << "\n__________________________" << endl;
        }

        static string _readCurrencyCode()
        {
            string currencyCode = clsInputValidate::readString();
            while(!clsCurrency::isCurrencyExist(currencyCode))
            {
                cout << "\nCurrency is not exist, enter another one: ";
                currencyCode = clsInputValidate::readString();
            }

            return currencyCode;
        }

        static clsCurrency _getCurrency(string msg)
        {
            cout << msg;
            clsCurrency currency = clsCurrency::findByCode(_readCurrencyCode());

            return currency;
        }

        static void _printCalculationResults(float amount, clsCurrency currency1, clsCurrency currency2)
        {
            float amountInUSD = currency1.convertToUSD(amount);
            float amountInCurrency2 = currency1.convertToOtherCurrency(amount, currency2);

            if (currency1.getCurrencyCode() != "USD")
            {               
                cout << "\nConvert From To USD:";
                _printCurrency(currency1);
                cout << amount << " " << currency1.getCurrencyCode() << " = " << amountInUSD << " USD" << endl;
            }

            if (currency2.getCurrencyCode() != "USD")
            {
                cout << "\nConvert From USD To:";
                _printCurrency(currency2);
                cout << amount << " " << currency1.getCurrencyCode() << " = " << amountInCurrency2 << " " << currency2.getCurrencyCode() << endl;
            }
        }
    
    public:
       static void showCurrencyCalculatorScreen()
       {
            char answer = 'y';
            while (toupper(answer) == 'Y')
            {
                system("clear");
                _drawScreenHeader("\tCurrency Calculator Screen");

                clsCurrency currency1 = _getCurrency("\nPlease enter currency1 code: ");
                clsCurrency currency2 = _getCurrency("\nPlease enter currency2 code: ");

                while (currency1.getCurrencyCode() == currency2.getCurrencyCode())
                {
                    currency2 = _getCurrency("\nYou can't exchange the same currency, Please enter another one: ");
                }

                cout << "\nPlease enter amount to exchange: ";
                float amount = clsInputValidate::readFloatNumber();

                _printCalculationResults(amount, currency1, currency2);
                
                cout << "\nDo you want to perform another calculation [y/n]: ";
                cin >> answer;
            }

       }
};