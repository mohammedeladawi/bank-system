//ProgrammingAdivces.com
//Mohammed Abu-Hadhoud

#pragma once
#include <iostream>
#include <string>
#include "clsString.h"
#include "clsDate.h"

class clsInputValidate
{

public:

	static bool isNumberBetween(short number, short from, short to)
	{
		if (number >= from && number <= to)
			return true;
		else
			return false;
	}

	static bool isNumberBetween(int number, int from, int to)
	{
		if (number >= from && number <= to)
			return true;
		else
			return false;

	}

	static bool isNumberBetween(float number, float from, float to)
	{
		if (number >= from && number <= to)
			return true;
		else
			return false;
	}

	static bool isNumberBetween(double number, double from, double to)
	{
		if (number >= from && number <= to)
			return true;
		else
			return false;
	}

	static bool isDateBetween(clsDate Date, clsDate from, clsDate to)
	{
		//Date>=from && Date<=to
		if ((clsDate::isDate1AfterDate2(Date, from) || clsDate::isDate1EqualDate2(Date, from)) 
			&&
			(clsDate::isDate1BeforeDate2(Date, to) || clsDate::isDate1EqualDate2(Date, to))
		  )
		{
			return true;
		}
		
		//Date>=to && Date<=from
		if ((clsDate::isDate1AfterDate2(Date, to) || clsDate::isDate1EqualDate2(Date, to)) 
			&&
			(clsDate::isDate1BeforeDate2(Date, from) || clsDate::isDate1EqualDate2(Date, from))
		   )
		{
			return true;
		}

		return false;
	}

	static int readIntNumber(string errorMessage="Invalid number, Enter again\n")
	{
		int number;
		while (!(cin >> number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << errorMessage ;
		}
		return number;
	}

	static int readIntNumberBetween(int from, int to, string errorMessage="number is not within range, Enter again:\n")
	{
		int number=readIntNumber();

		while (!isNumberBetween(number, from, to)) 
		{
			cout << errorMessage;
			number = readIntNumber();
		}
		return number;
	}

	static double readDblNumber(string errorMessage = "Invalid number, Enter again\n")
	{
		double number;
		while (!(cin >> number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << errorMessage;
		}
		return number;
	}

	static double readDblNumberBetween(double from, double to, string errorMessage = "number is not within range, Enter again:\n")
	{
		double number = readDblNumber();

		while (!isNumberBetween(number, from, to)) {
			cout << errorMessage;
			number = readDblNumber();
		}
		return number;
	}

	static bool isValideDate(clsDate Date)
	{
		return	clsDate::isValidDate(Date);
	}

	static string readString()
	{
		string s1;
		getline(cin >> ws, s1);

		return s1;
	}

	static float readFloatNumber()
	{
		float number;
		while (!(cin >> number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		return number;
	}

	static short readShortNumber(string errorMessage="Invalid number, Enter again\n")
	{
		short number;
		while (!(cin >> number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << errorMessage ;
		}
		return number;
	}

	static short readShortNumberBetween(short from, short to, string errorMessage = "number is not within range, Enter again:\n")
	{
		short number = readShortNumber();

		while (!isNumberBetween(number, from, to)) {
			cout << errorMessage;
			number = readShortNumber();
		}
		return number;
	}

};

