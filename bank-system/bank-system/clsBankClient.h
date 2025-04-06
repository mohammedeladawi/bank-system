#pragma once
#include <iostream>
#include "clsPerson.h"
#include <fstream>
#include <vector>
#include "../../utility-libraries/clsString.h"
#include "../bank-system-login-and-permissions/global.h"
using namespace std;

class clsBankClient: public clsPerson
{
    private:
        enum enMode { EmptyMode = 0, UpdateMode = 1, AddNew = 3};

        enMode _mode;
        string _accountNumber;
        string _pinCode;
        double _accountBalance;
        bool _markForDelete = false;

        static clsBankClient _convertLineToClientObject(string line, string seperator = "#//#")
        {
            vector<string> vClientDate = clsString::split(line, seperator);

            return clsBankClient(vClientDate[0], vClientDate[1], vClientDate[2], vClientDate[3],
                                 enMode::UpdateMode, vClientDate[4], vClientDate[5], stof(vClientDate[6]));
        }
        
        string _convertClientObjectToLine(clsBankClient client, string seperator = "#//#")
        {
            string stClientRecord = "";
            stClientRecord += client.getFirstName() + seperator;
            stClientRecord += client.getLastName() + seperator;
            stClientRecord += client.getEmail() + seperator;
            stClientRecord += client.getPhone() + seperator;
            stClientRecord += client.getAccountNumber() + seperator;
            stClientRecord += client.getPinCode() + seperator;
            stClientRecord += to_string(client.getAccountBalance());

            return stClientRecord;
        }

        static clsBankClient _getEmptyClientObject()
        {
            return clsBankClient("", "", "", "", enMode::EmptyMode, "", "", 0);
        }

        static vector<clsBankClient> _loadClientsDataFromFile()
        {
            fstream myFile;
            vector<clsBankClient> vClients;    

            myFile.open("bank-system/bank-files/Clients.txt", ios::in);

            if (myFile.is_open())
            {
                string line;
                while(getline(myFile, line))
                {
                    vClients.push_back(_convertLineToClientObject(line));
                }
                myFile.close();
            }

            return vClients;
        }

        void _saveClientsDataToFile(vector<clsBankClient> vClients)
        {
            fstream myFile;
            myFile.open("bank-system/bank-files/Clients.txt", ios::out);

            if (myFile.is_open())
            {
                for (clsBankClient client : vClients)
                {
                    if (!client.getMarkForDelete())
                        myFile << _convertClientObjectToLine(client) << endl;
                }

                myFile.close();
            }

        }

        void _update()
        {
            vector<clsBankClient> vClients = _loadClientsDataFromFile();

            for (clsBankClient& client: vClients)
            {
                if (client.getAccountNumber() == _accountNumber)
                {
                    client = *this;
                    break;
                }
            }

            _saveClientsDataToFile(vClients);
        }

        void _addNewClientToFile(string stClientLine)
        {
            fstream myFile;
            myFile.open("bank-system/bank-files/Clients.txt", ios::out | ios::app);

            if (myFile.is_open())
            {
                myFile << stClientLine << endl;
                myFile.close();
            }
        }

        void _addNew()
        {
            _addNewClientToFile(_convertClientObjectToLine(*this));
        }

        string _prepareTransferLogLine(float amount, clsBankClient destinationClient, string seperator = "#//#")
        {
            string line = "";
            line += clsDate::getSystemDateTimeString() + seperator;
            line += _accountNumber + seperator;
            line += destinationClient.getAccountNumber() + seperator;
            line += to_string(amount) + seperator;
            line += to_string(_accountBalance) + seperator;
            line += to_string(destinationClient.getAccountBalance()) + seperator;
            line += currentUser.getUsername();

            return line;
        } 

        void _registerTransferLog(float amount, clsBankClient destinationClient)
        {
            fstream myFile;
            
            myFile.open("bank-system/bank-files/TransferLogs.txt", ios::out | ios::app);
            if(myFile.is_open())
            {
                myFile << _prepareTransferLogLine(amount, destinationClient) << endl;
                myFile.close();
            }
        }

        public: struct stTransferLogRecord {
            string dateTime;
            string srcAccountNumber;
            string destAccountNumber;
            float amount;
            float srcBalanceAfter;
            float destBalanceAfter;
            string username;
        };

    private:
        static stTransferLogRecord _convertTransferLogsLineToRecord(string transferLogLine)
        {
            stTransferLogRecord transferLogRecord; 
            vector<string> vTransferLog = clsString::split(transferLogLine, "#//#");

            transferLogRecord.dateTime = vTransferLog[0];
            transferLogRecord.srcAccountNumber = vTransferLog[1];
            transferLogRecord.destAccountNumber = vTransferLog[2];
            transferLogRecord.amount = stoi(vTransferLog[3]);
            transferLogRecord.srcBalanceAfter = stoi(vTransferLog[4]);
            transferLogRecord.destBalanceAfter = stoi(vTransferLog[5]);
            transferLogRecord.username = vTransferLog[6];

            return transferLogRecord;
        }

    public:
        clsBankClient(string firstName, string lastName, string email, string phone, enMode mode, string accountNumber, string pinCode, float accountBalance)
            : clsPerson(firstName, lastName, email, phone)
        {
            _mode = mode;
            _accountNumber = accountNumber;
            _pinCode = pinCode;
            _accountBalance = accountBalance;
            
        }

        enMode getMode()
        {
            return _mode;
        }

        void setMode(enMode mode)
        {
            _mode  = mode;
        }
        
        // readonly
        string getAccountNumber()
        {
            return _accountNumber;
        }

        string getPinCode()
        {
            return _pinCode;
        }

        void setPinCode(string pinCode)
        {
            _pinCode = pinCode;
        }

        float getAccountBalance()
        {
            return _accountBalance;
        }

        void setAccountBalance(float accountBalance)
        {
            _accountBalance = accountBalance;
        }
    
        void setMarkForDelete(bool mark)
        {
            _markForDelete = mark;
        }

        bool getMarkForDelete()
        {
            return _markForDelete;
        }

        bool isEmpty()
        {
            return (_mode == enMode::EmptyMode);
        }

        static clsBankClient find(string accountNumber)
        {
            fstream myFile;
            myFile.open("bank-system/bank-files/Clients.txt", ios::in);


            if(myFile.is_open())
            {
                string line;
                while(getline(myFile, line))
                {
                    clsBankClient client = _convertLineToClientObject(line);
                    if (client.getAccountNumber() == accountNumber)
                    {
                        myFile.close();
                        return client;
                    }
                    
                }

                myFile.close();
            }

            return _getEmptyClientObject();
        }

        static clsBankClient find(string accountNumber, string pinCode)
        {
            fstream myFile;
            myFile.open("bank-system/bank-files/Clients.txt", ios::in);

            if(myFile.is_open())
            {
                string line;
                while(getline(myFile, line))
                {
                    clsBankClient client = _convertLineToClientObject(line);
                    if (client.getAccountNumber() == accountNumber && client.getPinCode() == pinCode)
                    {
                        myFile.close();
                        return client;
                    }
                    
                }

                myFile.close();
            }

            return _getEmptyClientObject();
        }

        static bool isClientExist(string accountNumber)
        {
            clsBankClient client = clsBankClient::find(accountNumber);
            return (!client.isEmpty());
        }

        bool isExist()
        {
            return isClientExist(_accountNumber);
        }

        enum enSaveResult { svSucceeded = 1, svFailedEmptyObject = 2, svFailedClientIsExist = 3 };

        enSaveResult save()
        {
            switch (_mode)
            {                
                case enMode::EmptyMode:
                    if (isEmpty())
                    {
                        return enSaveResult::svFailedEmptyObject;
                    }
              
                case enMode::UpdateMode:
                    _update();
                    return enSaveResult::svSucceeded;
            
                case enMode::AddNew:
                    if (isExist())
                    {
                        return enSaveResult::svFailedClientIsExist;
                    }
                    
                    _addNew();
                    _mode = enMode::UpdateMode;
                    return enSaveResult::svSucceeded;
            }
        }

        static clsBankClient addNewClientObject(string accountNumber)
        {
            return clsBankClient("", "", "", "", enMode::AddNew, accountNumber, "", 0);
        }

        bool deleteIt()
        {
            if (isExist())
            {
                vector<clsBankClient> vClients = _loadClientsDataFromFile();
                for(clsBankClient& c: vClients)
                {
                    if (c.getAccountNumber() == _accountNumber)
                    {
                        c.setMarkForDelete(true);
                        break;
                    }
                }

                _saveClientsDataToFile(vClients);
                *this = _getEmptyClientObject();
                
                return true;
            }

            return false;
        }

        static vector<clsBankClient> getClientsList()
        {
            return _loadClientsDataFromFile();
        }

        static double getTotalBalances()
        {
            vector<clsBankClient> vClients = _loadClientsDataFromFile();
            double totalBalances = 0;

            for (clsBankClient client: vClients)
            {
                totalBalances += client.getAccountBalance();
            }
            
            return totalBalances;
        }
    
        void deposit(double amount)
        {
            _accountBalance += amount;
            save();

        }
        
        bool withdraw(double amount)
        {
            if (amount > _accountBalance)
            {
                return false;
            }
            else
            {
                _accountBalance -= amount;
                save();
                return true;
            }
        }
        
        bool transfer(float amount, clsBankClient& destinationClient)
        {
            if (amount > this->_accountBalance || this->_accountNumber == destinationClient.getAccountNumber())
            {
                return false;
            }

            withdraw(amount);
            destinationClient.deposit(amount);
            
            _registerTransferLog(amount, destinationClient);

            return true;
        }

        static vector<stTransferLogRecord> getTransferLogsList()
        {
            vector<stTransferLogRecord> vTransferLogsRecords;

            fstream myFile;
            myFile.open("bank-system/bank-files/TransferLogs.txt", ios::in);

            if (myFile.is_open())
            {
                string line;
                while(getline(myFile, line))
                {
                    vTransferLogsRecords.push_back(_convertTransferLogsLineToRecord(line));
                }

                myFile.close();
            }

            return vTransferLogsRecords;
        }

};