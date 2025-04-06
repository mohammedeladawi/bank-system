#pragma once
#include <iostream>
#include <iomanip>
#include "../bank-system/bank-system-ui-main-menu/clsScreen.h"
#include "clsCurrency.h"

class clsCurrenciesListScreen :protected clsScreen
{

private:
    static void _printCurrencyRecordLine(clsCurrency Currency)
    {

        cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.getCountry();
        cout << "| " << setw(8) << left << Currency.getCurrencyCode();
        cout << "| " << setw(45) << left << Currency.getCurrencyName();
        cout << "| " << setw(10) << left << Currency.getRate();

    }

public:
    static void showCurrenciesListScreen()
    {
        vector <clsCurrency> vCurrencies = clsCurrency::getCurrenciesList();
        string title = "\t  Currencies List Screen";
        string subtitle = "\t    (" + to_string(vCurrencies.size()) + ") Currency.";

        _drawScreenHeader(title, subtitle);
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
        cout << "| " << left << setw(8) << "Code";
        cout << "| " << left << setw(45) << "Name";
        cout << "| " << left << setw(10) << "Rate/(1$)";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n" << endl;

        if (vCurrencies.size() == 0)
            cout << "\t\t\t\tNo Currencies Available In the System!";
        else

            for (clsCurrency currency : vCurrencies)
            {

                _printCurrencyRecordLine(currency);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n" << endl;

    }

};

