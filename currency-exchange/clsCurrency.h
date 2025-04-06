#pragma once
#include <iostream>
#include <fstream>
#include "../utility-libraries/clsString.h"
using namespace std;

class clsCurrency
{
     private:
        enum enMode { EmptyMode = 0, UpdateMode = 1};

        enMode _mode;
        string _country;
        string _currencyCode;
        string _currencyName;
        float _rate;

        static clsCurrency _convertLineToCurrencyObject(string line, string seperator = "#//#")
        {
            vector<string> vCurrencyDate = clsString::split(line, seperator);

            return clsCurrency(enMode::UpdateMode, vCurrencyDate[0], vCurrencyDate[1], vCurrencyDate[2],
                                 stof(vCurrencyDate[3]));
        }
        
        string _convertCurrencyObjectToLine(clsCurrency currency, string seperator = "#//#")
        {
            string stCurrencyRecord = "";
            stCurrencyRecord += currency.getCountry() + seperator;
            stCurrencyRecord += currency.getCurrencyCode() + seperator;
            stCurrencyRecord += currency.getCurrencyName() + seperator;
            stCurrencyRecord += to_string(currency.getRate());
       
            return stCurrencyRecord;
        }

        static clsCurrency _getEmptyCurrencyObject()
        {
            return clsCurrency(enMode::EmptyMode, "", "", "", 0);
        }

        static vector<clsCurrency> _loadCurrenciesDataFromFile()
        {
            fstream myFile;
            vector<clsCurrency> vCurrenciesRecords;    

            myFile.open("../currency-files/Currencies.txt", ios::in);

            if (myFile.is_open())
            {
                string line;
                while(getline(myFile, line))
                {
                    vCurrenciesRecords.push_back(_convertLineToCurrencyObject(line));
                }
                myFile.close();
            }

            return vCurrenciesRecords;
        }

        void _saveCurrenciesDataToFile(vector<clsCurrency> vCurrencies)
        {
            fstream myFile;
            myFile.open("../currency-files/Currencies.txt", ios::out);

            if (myFile.is_open())
            {
                for (clsCurrency currency : vCurrencies)
                {
                    myFile << _convertCurrencyObjectToLine(currency) << endl;
                }

                myFile.close();
            }

        }

        void _update()
        {
            vector<clsCurrency> vCurrencies = _loadCurrenciesDataFromFile();

            for (clsCurrency& currency: vCurrencies)
            {
                if (currency.getCurrencyCode() == _currencyCode)
                {
                    currency = *this;
                    break;
                }
            }

            _saveCurrenciesDataToFile(vCurrencies);
        }

    public:
        clsCurrency(enMode mode, string country, string currencyCode, string currencyName, float rate)
        {
            _mode = mode;
            _country = country;
            _currencyCode = currencyCode;
            _currencyName = currencyName;
            _rate = rate;
        }

        static vector <clsCurrency> getAllUSDRates()
        {
            return _loadCurrenciesDataFromFile();
        }

        bool isEmpty()
        {
            return (_mode == enMode::EmptyMode);
        }

        string getCountry()
        {
            return _country;
        }
    
        string getCurrencyCode()
        {
            return _currencyCode;
        }
        
        string getCurrencyName()
        {
            return _currencyName;
        }
    
        void updateRate(float newRate)
        {
            _rate = newRate;
            _update();
        }

        float getRate()
        {
            return _rate;
        }

        static clsCurrency findByCode(string currencyCode)
        {
        
            currencyCode = clsString::upperAllString(currencyCode);

            fstream myFile;
            myFile.open("../currency-files/Currencies.txt", ios::in);//read Mode

            if (myFile.is_open())
            {
                string Line;
                while (getline(myFile, Line))
                {
                    clsCurrency currency = _convertLineToCurrencyObject(Line);
                    if (currency.getCurrencyCode() == currencyCode)
                    {
                        myFile.close();
                        return currency;
                    }
                }

                myFile.close();

            }

            return _getEmptyCurrencyObject();

        }

        static clsCurrency findByCountry(string country)
        {
            country = clsString::upperAllString(country);

            fstream myFile;
            myFile.open("currency-files/Currencies.txt", ios::in);//read Mode

            if (myFile.is_open())
            {
                string line;
                while (getline(myFile, line))
                {
                    clsCurrency currency = _convertLineToCurrencyObject(line);
                    if (clsString::upperAllString(currency.getCountry()) == country)
                    {
                        myFile.close();
                        return currency;
                    }

                }

                myFile.close();

            }

            return _getEmptyCurrencyObject();

        }

        static bool isCurrencyExist(string currencyCode)
            {
                clsCurrency c1 = clsCurrency::findByCode(currencyCode);
                return (!c1.isEmpty());

            }

        static vector <clsCurrency> getCurrenciesList()
        {
            return _loadCurrenciesDataFromFile();
        }

        float convertToUSD(float amount)
        {
            return amount / _rate;
        }

        float convertToOtherCurrency(float amount, clsCurrency currency2)
        {
            float amountInUSD = convertToUSD(amount);

            if (currency2.getCurrencyCode() == "USD")
            {
                return amountInUSD;
            }

            return amountInUSD * currency2.getRate();
        }
    };