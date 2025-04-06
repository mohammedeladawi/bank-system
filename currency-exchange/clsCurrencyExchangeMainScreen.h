#pragma once
#include <iostream>
#include <iomanip>
#include "../bank-system/bank-system-ui-main-menu/clsScreen.h"
#include "../utility-libraries/clsInputValidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyScreen.h"
#include "clsCurrencyCalculatorScreen.h"
using namespace std;

class clsCurrencyExchangeMainScreen :protected clsScreen
{

private:
    enum enCurrenciesMainMenuOption {
        eListCurrencies = 1, eFindCurrency = 2, eUpdateCurrencyRate = 3,
        eCurrencyCalculator = 4, eMainMenu = 5
    };

    static short readCurrenciesMainMenuOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate::readShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");
        return Choice;
    }

    static void _goBackToCurrenciesMenu()
    {
        system("read -p 'Press Enter for going back to currencies menu...' var");
        showCurrenciesMenu();
    }

    static void _showCurrenciesListScreen()
    {
        // cout << "\nCurriencies List Screen Will Be Here.\n";
        clsCurrenciesListScreen::showCurrenciesListScreen();
    }

    static void _showFindCurrencyScreen()
    {
        // cout << "\nFind Currency Screen Will Be Here.\n";
        clsFindCurrencyScreen::showFindCurrencyScreen();

    }

    static void _showUpdateCurrencyRateScreen()
    {
        // cout << "\nUpdate Currency Rate Screen Will Be Here.\n";
        clsUpdateCurrencyScreen::showUpdateCurrencyScreen();
    }

    static void _showCurrencyCalculatorScreen()
    {
        // cout << "\nCurrency Calculator Screen Will Be Here.\n";
    
        clsCurrencyCalculatorScreen::showCurrencyCalculatorScreen();    

    }

    static void _performCurrenciesMainMenuOption(enCurrenciesMainMenuOption currenciesMainMenuOption)
    {

        switch (currenciesMainMenuOption)
        {
        case enCurrenciesMainMenuOption::eListCurrencies:
        {
            system("clear");
            _showCurrenciesListScreen();
            _goBackToCurrenciesMenu();
            break;
        }

        case enCurrenciesMainMenuOption::eFindCurrency:
        {
            system("clear");
            _showFindCurrencyScreen();
            _goBackToCurrenciesMenu();
            break;
        }

        case enCurrenciesMainMenuOption::eUpdateCurrencyRate:
        {
            system("clear");
            _showUpdateCurrencyRateScreen();
            _goBackToCurrenciesMenu();
            break;
        }

        case enCurrenciesMainMenuOption::eCurrencyCalculator:
        {
            system("clear");
            _showCurrencyCalculatorScreen();
            _goBackToCurrenciesMenu();
            break;
        }

        case enCurrenciesMainMenuOption::eMainMenu:
        {
            //do nothing here the main screen will handle it :-) ;
        }
        }

    }

public:
    static void showCurrenciesMenu()
    {

        system("clear");
        _drawScreenHeader("\tCurrancy Exhange Main Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Currency Exhange Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _performCurrenciesMainMenuOption((enCurrenciesMainMenuOption)readCurrenciesMainMenuOption());
    }

};

