#pragma once
#include <iostream>
#include <iomanip>
#include "../bank-system/bank-system-ui-main-menu/clsScreen.h"
#include "../utility-libraries/clsInputValidate.h"
#include "../utility-libraries/clsString.h"
#include "clsCurrency.h"

class clsFindCurrencyScreen : protected clsScreen
{
    private:
        enum enFindCurrencyOption { eCode = 1, eCountry = 2};
        
        static short _readFindOption()
        {
            cout << "Find by [1] Code or [2] Country: ";
            short option = clsInputValidate::readShortNumberBetween(1, 2);
            return option;
        }

        static clsCurrency _getCurrencyObject(enFindCurrencyOption findCurrencyOption)
        {   
            if (findCurrencyOption == enFindCurrencyOption::eCode)
            {  
                cout << "\nPlease enter currency code: ";
                string currencyCode = clsString::upperAllString(clsInputValidate::readString());
                return clsCurrency::findByCode(currencyCode);
            }
            else 
            {
                cout << "\nPlease enter country name: ";
                string countryName = clsString::upperAllString(clsInputValidate::readString());
                return clsCurrency::findByCode(countryName);
            }

            return clsCurrency::findByCode("");
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
       static void showFindCurrencyScreen()
       {
            _drawScreenHeader("\tFind Currency Screen");
            clsCurrency currency = _getCurrencyObject((enFindCurrencyOption) _readFindOption());

            if (currency.isEmpty())
            {
                cout << "\nCurrency is not found :-(" << endl;
            }
            else
            {
                cout << "\nCurrency is found :-)";
                _printCurrency(currency);
            }
       }
};