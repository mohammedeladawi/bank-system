#pragma once 
#include <iostream>
#include <iomanip>
#include <vector>
#include "../bank-system/clsBankClient.h"
#include "../../utility-libraries/clsInputValidate.h"
#include "../../utility-libraries/clsUtil.h"
#include "../bank-system-ui-main-menu/clsScreen.h"

class clsTransferLogScreen : protected clsScreen
{
    private:
        static void _printTransferLogLine(clsBankClient::stTransferLogRecord transferLog)
        {
            cout << "| " << left << setw(20) << transferLog.dateTime;
            cout << "| " << left << setw(15) << transferLog.srcAccountNumber;
            cout << "| " << left << setw(15) << transferLog.destAccountNumber;
            cout << "| " << left << setw(12) << transferLog.amount;
            cout << "| " << left << setw(15) << transferLog.srcBalanceAfter;
            cout << "| " << left << setw(15) << transferLog.destBalanceAfter;
            cout << "| " << left << setw(15) << transferLog.username;
        }
        
    public:
        static void showTotalBalancesScreen()
        {
            vector <clsBankClient::stTransferLogRecord> vTransferLogs = clsBankClient::getTransferLogsList();
            string title = "\tTransfer Log List Screen";
            string subtitle = "\n\t\t\t\t\t(" + to_string(vTransferLogs.size()) + ") Record(s).";
            
            _drawScreenHeader(title, subtitle);


            cout << "\n_______________________________________________________";
            cout << "_________________________________________\n" << endl;

            cout << "| " << left << setw(20) << "Date-Time";
            cout << "| " << left << setw(15) << "s. Acc Number";
            cout << "| " << left << setw(15) << "d. Acc Number";
            cout << "| " << left << setw(12) << "Amount";
            cout << "| " << left << setw(15) << "s. Balance";
            cout << "| " << left << setw(15) << "d. Balance";
            cout << "| " << left << setw(15) << "User";
            cout << "\n_______________________________________________________";
            cout << "_________________________________________\n" << endl;


            if (vTransferLogs.size() == 0)
                cout << "\t\t\t\tNo Records Available In the System!";
            else

                for (clsBankClient::stTransferLogRecord log : vTransferLogs)
                {
                    _printTransferLogLine(log);
                    cout << endl;
                }

            cout << "\n_______________________________________________________";
            cout << "_________________________________________\n" << endl;
        }   

};