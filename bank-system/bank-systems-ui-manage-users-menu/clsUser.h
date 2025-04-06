#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "../bank-system/clsPerson.h"
#include "../../utility-libraries/clsString.h"
#include "../../utility-libraries/clsUtil.h"
using namespace std;

class clsUser : public clsPerson
{
    private:
        enum enMode { EmptyMode = 0, UpdateMode = 1, AddNew = 3};

        enMode _mode;
        string _username;
        string _password;
        int _permissions;

        bool _markForDelete = false;

        static clsUser _convertLineToUserObject(string line, string seperator = "#//#")
        {
            vector<string> vUserDate = clsString::split(line, seperator);

            return clsUser(vUserDate[0], vUserDate[1], vUserDate[2], vUserDate[3],
                                 enMode::UpdateMode, vUserDate[4], clsUtil::decryptText(vUserDate[5]), stof(vUserDate[6]));
        }
        
        string _convertUserObjectToLine(clsUser user, string seperator = "#//#")
        {
            string stUserRecord = "";
            stUserRecord += user.getFirstName() + seperator;
            stUserRecord += user.getLastName() + seperator;
            stUserRecord += user.getEmail() + seperator;
            stUserRecord += user.getPhone() + seperator;
            stUserRecord += user.getUsername() + seperator;
            stUserRecord += clsUtil::encryptText(user.getPassword()) + seperator;
            stUserRecord += to_string(user.getPermissions());

            return stUserRecord;
        }

        static clsUser _getEmptyUserObject()
        {
            return clsUser("", "", "", "", enMode::EmptyMode, "", "", 0);
        }

        static vector<clsUser> _loadUsersDataFromFile()
        {
            fstream myFile;
            vector<clsUser> vUsers;    

            myFile.open("bank-system/bank-files/Users.txt", ios::in);

            if (myFile.is_open())
            {
                string line;
                while(getline(myFile, line))
                {
                    vUsers.push_back(_convertLineToUserObject(line));
                }
                myFile.close();
            }

            return vUsers;
        }

        void _saveUsersDataToFile(vector<clsUser> vUsers)
        {
            fstream myFile;
            myFile.open("bank-system/bank-files/Users.txt", ios::out);

            if (myFile.is_open())
            {
                for (clsUser user : vUsers)
                {
                    if (!user.getMarkForDelete())
                        myFile << _convertUserObjectToLine(user) << endl;
                }

                myFile.close();
            }

        }

        void _update()
        {
            vector<clsUser> vUsers = _loadUsersDataFromFile();

            for (clsUser& user: vUsers)
            {
                if (user.getUsername() == _username)
                {
                    user = *this;
                    break;
                }
            }

            _saveUsersDataToFile(vUsers);
        }

        void _addNewUserToFile(string stUserLine)
        {
            fstream myFile;
            myFile.open("bank-system/bank-files/Users.txt", ios::out | ios::app);

            if (myFile.is_open())
            {
                myFile << stUserLine << endl;
                myFile.close();
            }
        }

        void _addNew()
        {
            _addNewUserToFile(_convertUserObjectToLine(*this));
        }

        string _prepareLoginRegisterLine(string seperator = "#//#")
        {
            string line = "";
            line += clsDate::getSystemDateTimeString() + seperator;
            line += _username + seperator;
            line += clsUtil::encryptText(_password) + seperator;
            line += to_string(_permissions);

            return line;
        }
        
        public: struct stLoginRegisterRecord {
            string dateTime;
            string username;
            string password;
            short permissions;
        };

        private: static stLoginRegisterRecord _convertLoginRegisterLineToRecord(string line)
        {
            stLoginRegisterRecord loginRegisterRecord; 
            vector<string> vLoginRegisterRecordsLine = clsString::split(line, "#//#");

            loginRegisterRecord.dateTime = vLoginRegisterRecordsLine[0];
            loginRegisterRecord.username = vLoginRegisterRecordsLine[1];
            loginRegisterRecord.password = clsUtil::decryptText(vLoginRegisterRecordsLine[2]);
            loginRegisterRecord.permissions = stoi(vLoginRegisterRecordsLine[3]);

            return loginRegisterRecord;
        }

    public:
        clsUser(string firstName, string lastName, string email, string phone, enMode mode, string username, string password, float permissions)
            : clsPerson(firstName, lastName, email, phone)
        {
            _mode = mode;
            _username = username;
            _password = password;
            _permissions = permissions;
            
        }

        enum enPermission {
            pAll = -1, pClientsList = 1, pAddClient = 2, 
            pDeleteClient = 4, pUpdateClient = 8,
            pFindClient = 16, pTransactions = 32,
            pManageUsers = 64, pLoginRegister = 128
        };
        
        enMode getMode()
        {
            return _mode;
        }

        void setMode(enMode mode)
        {
            _mode  = mode;
        }
        
        // readonly
        string getUsername()
        {
            return _username;
        }

        string getPassword()
        {
            return _password;
        }

        void setPassword(string password)
        {
            _password = password;
        }

        short getPermissions()
        {
            return _permissions;
        }

        void setPermissions(float permissions)
        {
            _permissions = permissions;
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

        static clsUser find(string username)
        {
            fstream myFile;
            myFile.open("bank-system/bank-files/Users.txt", ios::in);


            if(myFile.is_open())
            {
                string line;
                while(getline(myFile, line))
                {
                    clsUser user = _convertLineToUserObject(line);
                    if (user.getUsername() == username)
                    {
                        myFile.close();
                        return user;
                    }
                    
                }

                myFile.close();
            }

            return _getEmptyUserObject();
        }

        static clsUser find(string username, string password)
        {
            fstream myFile;
            myFile.open("bank-system/bank-files/Users.txt", ios::in);

            cout << myFile.is_open() << endl;
            if(myFile.is_open())
            {
                string line;
                while(getline(myFile, line))
                {
                    clsUser user = _convertLineToUserObject(line);
                    if (user.getUsername() == username && user.getPassword() == password)
                    {
                        myFile.close();
                        return user;
                    }
                    
                }

                myFile.close();
            }
            return _getEmptyUserObject();
        }

        static bool isUserExist(string username)
        {
            clsUser user = clsUser::find(username);
            return (!user.isEmpty());
        }

        bool isExist()
        {
            return isUserExist(_username);
        }

        enum enSaveResult { svSucceeded = 1, svFailedEmptyObject = 2, svFailedUserIsExist = 3 };

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
                        return enSaveResult::svFailedUserIsExist;
                    }
                    
                    _addNew();
                    _mode = enMode::UpdateMode;
                    return enSaveResult::svSucceeded;
            }
        }

        static clsUser addNewUserObject(string username)
        {
            return clsUser("", "", "", "", enMode::AddNew, username, "", 0);
        }

        bool deleteIt()
        {
            if (isExist())
            {
                vector<clsUser> vUsers = _loadUsersDataFromFile();
                for(clsUser& c: vUsers)
                {
                    if (c.getUsername() == _username)
                    {
                        c.setMarkForDelete(true);
                        break;
                    }
                }

                _saveUsersDataToFile(vUsers);
                *this = _getEmptyUserObject();
                
                return true;
            }

            return false;
        }

        static vector<clsUser> getUsersList()
        {
            return _loadUsersDataFromFile();
        }

        bool checkAccessPermission(enPermission permission)
        {
            if (permission == enPermission::pAll)
            {
                return true;
            }

            if ((permission & this->_permissions) == permission)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        void registerLogin()
        {
            string stLineRecord = _prepareLoginRegisterLine();
            fstream myFile;

            myFile.open("bank-system/bank-files/LoginRegister.txt", ios::out | ios::app);
            if(myFile.is_open())
            {
                myFile << stLineRecord << endl;
                myFile.close();
            }
        }

        static vector<stLoginRegisterRecord> getLoginRegisterList()
        {
            fstream myFile;
            vector<stLoginRegisterRecord> vLoginRegisterRecords;    

            myFile.open("bank-system/bank-files/LoginRegister.txt", ios::in);

            if (myFile.is_open())
            {
                string line;

                while(getline(myFile, line))
                {
                    vLoginRegisterRecords.push_back(_convertLoginRegisterLineToRecord(line));
                }
                
                myFile.close();
            }

            return vLoginRegisterRecords;
        }

};