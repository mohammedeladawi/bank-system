//ProgrammingAdivces.com
//Mohammed Abu-Hadhoud

#pragma warning(disable : 4996)
#pragma once

#include<iostream>
#include<string>
#include "clsString.h"

using namespace std;

class clsDate
{

private:
	short _day = 1;
	short _month = 1;
	short _year = 1900;

public:

	clsDate()
	{
		time_t t = time(0);
		tm* now = localtime(&t);
		_day = now->tm_mday;
		_month = now->tm_mon + 1;
		_year = now->tm_year + 1900;
	}

	clsDate(string sDate)
	{
		vector <string> vDate;
		vDate = clsString::split(sDate, "/");

		_day = stoi(vDate[0]);
		_month = stoi(vDate[1]);
		_year = stoi(vDate[2]);
	}

	clsDate(short day, short month, short year)
	{
		
		_day = day;
		_month = month;
		_year = year;
		
	}

	clsDate(short dateOrderInYear, short year)
	{
		//This will construct a date by date order in year
		clsDate date1 = getDateFromDayOrderInYear(dateOrderInYear, year);
	    _day = date1.getDay();
		_month = date1.getMonth();
		_year = date1.getYear();
	}

	void setDay(short day) {
		_day = day;
	}

	short getDay() {
		return _day;
	}

	void setMonth(short month) {
		_month = month;
	}

	short getMonth() {
		return _month;
	}

	void setYear(short year) {
		_year = year;
	}

	short getYear() {
		return _year;
	}

   void print()
	{
		cout << dateToString() << endl;
	}

	static clsDate getSystemDate()
	{
		//system date
		time_t t = time(0);
		tm* now = localtime(&t);
		
		short day, month, year;

		year = now->tm_year + 1900;
		month = now->tm_mon + 1;
		day = now->tm_mday;

		return clsDate(day, month, year);
	}

    static	bool isValidDate(clsDate date)
	{

		if (date.getDay() < 1 || date.getDay() >31)
			return false;

		if (date.getMonth() < 1 || date.getMonth() >12)
			return false;

		if (date.getMonth() == 2)
		{
			if (isLeapYear(date.getYear()))
			{
				if (date.getDay() > 29)
					return false;
			}
			else
			{
				if (date.getDay() > 28)
					return false;
			}
		}

		short daysInMonth = numberOfDaysInAMonth(date.getMonth(), date.getYear());

		if (date.getDay() > daysInMonth)
			return false;

		return true;

	}
	
	bool isValid()
	{
		return isValidDate(*this);
	}

	static string dateToString(clsDate date)
	{
		return  to_string(date.getDay()) + "/" + to_string(date.getMonth()) + "/" + to_string(date.getYear());
	}

    string dateToString()
	{
		return  dateToString(*this);
	}

	static bool isLeapYear(short year)
	{

		// if year is divisible by 4 AND not divisible by 100
	  // OR if year is divisible by 400
	  // then it is a leap year
		return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	}

	bool isLeapYear()
	{
		return isLeapYear(_year);
	}

	static short numberOfDaysInAYear(short year)
	{
		return  isLeapYear(year) ? 365 : 364;
	}

	short numberOfDaysInAYear()
	{
		return  numberOfDaysInAYear(_year);
	}

	static short numberOfHoursInAYear(short year)
	{
		return  numberOfDaysInAYear(year) * 24;
	}

	short numberOfHoursInAYear()
	{
		return  numberOfHoursInAYear(_year);
	}

	static int numberOfMinutesInAYear(short year)
	{
		return  numberOfHoursInAYear(year) * 60;
	}

	int numberOfMinutesInAYear()
	{
		return  numberOfMinutesInAYear(_year);
	}

	static int numberOfSecondsInAYear(short year)
	{
		return  numberOfMinutesInAYear(year) * 60;
	}

	int numberOfSecondsInAYear()
	{
		return  numberOfSecondsInAYear();
	}

	static short numberOfDaysInAMonth(short month, short year)
	{

		if (month < 1 || month>12)
			return  0;

		int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		return (month == 2) ? (isLeapYear(year) ? 29 : 28) : days[month - 1];

	}

	short numberOfDaysInAMonth()
	{
		return numberOfDaysInAMonth(_month, _year);
	}

	static short numberOfHoursInAMonth(short month, short year)
	{
		return  numberOfDaysInAMonth(month, year) * 24;
	}

	short numberOfHoursInAMonth()
	{
		return  numberOfDaysInAMonth(_month, _year) * 24;
	}

	static int numberOfMinutesInAMonth(short month, short year)
	{
		return  numberOfHoursInAMonth(month, year) * 60;
	}

	int numberOfMinutesInAMonth()
	{
		return  numberOfHoursInAMonth(_month, _year) * 60;
	}

	static int numberOfSecondsInAMonth(short month, short year)
	{
		return  numberOfMinutesInAMonth(month, year) * 60;
	}

	int numberOfSecondsInAMonth()
	{
		return  numberOfMinutesInAMonth(_month, _year) * 60;
	}

	static short dayOfWeekOrder(short day, short month, short year)
	{
		short a, y, m;
		a = (14 - month) / 12;
		y = year - a;
		m = month + (12 * a) - 2;
		// Gregorian:
		//0:sun, 1:Mon, 2:Tue...etc
		return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}

	short dayOfWeekOrder()
	{
		return dayOfWeekOrder(_day, _month, _year);
	}

	static string dayShortName(short dayOfWeekOrder)
	{
		string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

		return arrDayNames[dayOfWeekOrder];

	}

	static string dayShortName(short day, short month, short year)
	{

		string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

		return arrDayNames[dayOfWeekOrder(day, month, year)];

	}

	string dayShortName()
	{

		string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

		return arrDayNames[dayOfWeekOrder(_day, _month, _year)];

	}

	static string monthShortName(short monthNumber)
	{
		string months[12] = { "Jan", "Feb", "Mar",
						   "Apr", "May", "Jun",
						   "Jul", "Aug", "Sep",
						   "Oct", "Nov", "Dec"
		};

		return (months[monthNumber - 1]);
	}

	string monthShortName()
	{

		return monthShortName(_month);
	}

	static void printMonthCalendar(short month, short year)
	{
		int numberOfDays;

		// Index of the day from 0 to 6
		int current = dayOfWeekOrder(1, month, year);

		numberOfDays = numberOfDaysInAMonth(month, year);

		// print the current month name
		printf("\n  _______________%s_______________\n\n",
			monthShortName(month).c_str());

		// print the columns
		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

		// print appropriate spaces
		int i;
		for (i = 0; i < current; i++)
			printf("     ");

		for (int j = 1; j <= numberOfDays; j++)
		{
			printf("%5d", j);


			if (++i == 7)
			{
				i = 0;
				printf("\n");
			}
		}

		printf("\n  _________________________________\n");

	}

	void printMonthCalendar()
	{
		printMonthCalendar(_month, _year);
	}

	static void printYearCalendar(int year)
	{
		printf("\n  _________________________________\n\n");
		printf("           Calendar - %d\n", year);
		printf("  _________________________________\n");


		for (int i = 1; i <= 12; i++)
		{
			printMonthCalendar(i, year);
		}

		return;
	}

	void printYearCalendar()
	{
		printf("\n  _________________________________\n\n");
		printf("           Calendar - %d\n", _year);
		printf("  _________________________________\n");


		for (int i = 1; i <= 12; i++)
		{
			printMonthCalendar(i, _year);
		}

		return;
	}

	static short daysFromTheBeginingOfTheYear(short day, short month, short year)
	{


		short totalDays = 0;

		for (int i = 1; i <= month - 1; i++)
		{
			totalDays += numberOfDaysInAMonth(i, year);
		}

		totalDays += day;

		return totalDays;
	}

	short daysFromTheBeginingOfTheYear()
	{
		short totalDays = 0;

		for (int i = 1; i <= _month - 1; i++)
		{
			totalDays += numberOfDaysInAMonth(i, _year);
		}

		totalDays += _day;

		return totalDays;
	}

	static clsDate getDateFromDayOrderInYear(short dateOrderInYear, short year)
	{

		clsDate date;
		short remainingDays = dateOrderInYear;
		short monthDays = 0;

		date.setYear(year);
		date.setMonth(1);

		while (true)
		{
			monthDays = numberOfDaysInAMonth(date.getMonth(), year);

			if (remainingDays > monthDays)
			{
				remainingDays -= monthDays;
				date.setMonth(date.getMonth() + 1);
			}
			else
			{
				date.setDay(remainingDays);
				break;
			}

		}

		return date;
	}

	void addDays(short days)
	{
		short remainingDays = days + daysFromTheBeginingOfTheYear(_day, _month, _year);
		short monthDays = 0;

		_month = 1;

		while (true)
		{
			monthDays = numberOfDaysInAMonth(_month, _year);

			if (remainingDays > monthDays)
			{
				remainingDays -= monthDays;
				_month++;

				if (_month > 12)
				{
					_month = 1;
					_year++;

				}
			}
			else
			{
				_day = remainingDays;
				break;
			}
		}
	}

	static bool isDate1BeforeDate2(clsDate date1, clsDate date2)
	{
		return  (date1.getYear() < date2.getYear()) ? true : ((date1.getYear() == date2.getYear()) ? (date1.getMonth() < date2.getMonth() ? true : (date1.getMonth() == date2.getMonth() ? date1.getDay() < date2.getDay() : false)) : false);
	}

	bool isDateBeforeDate2(clsDate date2)
	{
		//note: *this sends the current object :-) 
		return  isDate1BeforeDate2(*this, date2);

	}

	static bool isDate1EqualDate2(clsDate date1, clsDate date2)
	{
		return  (date1.getYear() == date2.getYear()) ? ((date1.getMonth() == date2.getMonth()) ? ((date1.getDay() == date2.getDay()) ? true : false) : false) : false;
	}

	bool isDateEqualDate2(clsDate date2)
	{
		return  isDate1EqualDate2(*this, date2);
	}

	static bool isLastDayInMonth(clsDate date)
	{

		return (date.getDay() == numberOfDaysInAMonth(date.getMonth(), date.getYear()));

	}

	bool isLastDayInMonth()
	{

		return isLastDayInMonth(*this);

	}

	static bool isLastMonthInYear(short month)
	{
		return (month == 12);
	}

	static clsDate addOneDay(clsDate date)
	{
		if (isLastDayInMonth(date))
		{
			if (isLastMonthInYear(date.getMonth()))
			{
				date.setMonth(1);
				date.setDay(1);
				date.setYear(date.getYear() + 1);
			}
			else
			{
				date.setDay(1);
				date.setMonth(date.getMonth() + 1);
			}
		}
		else
		{
			date.setDay(date.getDay() + 1);
		}

		return date;
	}

	void addOneDay()

	{
		*this = addOneDay(*this);
	}

	static void  swapDates(clsDate & date1, clsDate & date2)
	{

		clsDate tempDate;
		tempDate = date1;
		date1 =	date2;
		date2 = tempDate;

	}

	static int getDifferenceInDays(clsDate date1, clsDate date2, bool includeEndDay = false)
	{
		//this will take care of negative diff
		int days = 0;
		short SawpFlagValue = 1;

		if (!isDate1BeforeDate2(date1, date2))
		{
			//Swap Dates 
			swapDates(date1, date2);
			SawpFlagValue = -1;

		}

		while (isDate1BeforeDate2(date1, date2))
		{
			days++;
			date1 = addOneDay(date1);
		}

		return includeEndDay ? ++days * SawpFlagValue : days * SawpFlagValue;
	}

	int getDifferenceInDays(clsDate date2, bool includeEndDay = false)
	{
		return getDifferenceInDays(*this, date2, includeEndDay);
	}

	static short calculateMyAgeInDays(clsDate dateOfBirth)
	{
		return getDifferenceInDays(dateOfBirth, clsDate::getSystemDate(), true);
	}
	//above no need to have nonstatic function for the object because it does not depend on any data from it.

	static clsDate increaseDateByOneWeek(clsDate & date)
	{

		for (int i = 1; i <= 7; i++)
		{
			date = addOneDay(date);
		}

		return date;
	}

	void increaseDateByOneWeek()
	{
		increaseDateByOneWeek(*this);
	}

	clsDate increaseDateByXWeeks(short weeks, clsDate& date)
	{
		for (short i = 1; i <= weeks; i++)
		{
			date = increaseDateByOneWeek(date);
		}
		return date;
	}

	void increaseDateByXWeeks(short weeks)
	{
		increaseDateByXWeeks(weeks, *this);
	}

	clsDate increaseDateByOneMonth(clsDate& date)
	{
		if (date.getMonth() == 12)
		{
			date.setMonth(1);
			date.setYear(date.getYear() + 1);
		}
		else
		{
			date.setMonth(date.getMonth() + 1);
		}

		//last check day in date should not exceed max days in the current month
		// example if date is 31/1/2022 increasing one month should not be 31/2/2022, it should
		// be 28/2/2022
		short numberOfDaysInCurrentMonth = numberOfDaysInAMonth(date.getMonth(), date.getYear());
		if (date.getDay() > numberOfDaysInCurrentMonth)
		{
			date.setDay(numberOfDaysInCurrentMonth);
		}

		return date;
	}

	void increaseDateByOneMonth()
	{

		increaseDateByOneMonth(*this);

	}

	clsDate increaseDateByXDays(short days, clsDate& date)
	{
		for (short i = 1; i <= days; i++)
		{
			date = addOneDay(date);
		}
		return date;
	}

	void increaseDateByXDays(short days)
	{

		increaseDateByXDays(days, *this);
	}

	clsDate increaseDateByXMonths(short months, clsDate& date)
	{
		for (short i = 1; i <= months; i++)
		{
			date = increaseDateByOneMonth(date);
		}
		return date;
	}

	void increaseDateByXMonths(short months)
	{
		increaseDateByXMonths(months, *this);
	}

	static clsDate increaseDateByOneYear(clsDate& date)
	{
		date.setYear(date.getDay() + 1);
		return date;
	}

	void increaseDateByOneYear()
	{
		increaseDateByOneYear(*this);
	}

	clsDate increaseDateByXYears(short years, clsDate& date)
	{
		date.setYear(date.getYear() + years);
		return date;
		
	}

	void increaseDateByXYears(short years)
	{
		increaseDateByXYears(years);
	}

	clsDate increaseDateByOneDecade(clsDate& date)
	{
		//Period of 10 years
		date.setYear(date.getYear() + 10);
		return date;
	}

	void increaseDateByOneDecade()
	{
		increaseDateByOneDecade(*this);
	}

	clsDate increaseDateByXDecades(short decade, clsDate& date)
	{
		date.setYear(date.getYear() + decade * 10);
		return date;
	}

	void increaseDateByXDecades(short decade)
	{
		increaseDateByXDecades(decade, *this);
	}

	clsDate increaseDateByOneCentury(clsDate& date)
	{
		//Period of 100 years
		date.setYear(date.getYear() + 100);
		return date;
	}

	void increaseDateByOneCentury()
	{
		increaseDateByOneCentury(*this);
	}

	clsDate increaseDateByOneMillennium(clsDate& date)
	{
		//Period of 1000 years
		date.setYear(date.getYear() + 1000);
		return date;
	}

	void increaseDateByOneMillennium()
	{
		increaseDateByOneMillennium(*this);
	}

	static clsDate decreaseDateByOneDay(clsDate &date)
	{
		if (date.getDay() == 1)
		{
			if (date.getMonth() == 1)
			{
				date.setMonth(12);
				date.setDay(31);
				date.setYear(date.getYear() - 1);
			}
			else
			{

				date.setMonth(date.getMonth() - 1);
				date.setDay(numberOfDaysInAMonth(date.getMonth(), date.getYear()));
			}
		}
		else
		{
			date.setDay(date.getDay() - 1);
		}

		return date;
	}

	void decreaseDateByOneDay()
	{
		decreaseDateByOneDay(*this);
	}

	static clsDate decreaseDateByOneWeek(clsDate &date)
	{

		for (int i = 1; i <= 7; i++)
		{
			date = decreaseDateByOneDay(date);
		}

		return date;
	}

	void decreaseDateByOneWeek()
	{
		decreaseDateByOneWeek(*this);
	}

	static clsDate decreaseDateByXWeeks(short weeks, clsDate &date)
	{
		for (short i = 1; i <= weeks; i++)
		{
			date = decreaseDateByOneWeek(date);
		}
		return date;
	}

	void decreaseDateByXWeeks(short weeks)
	{
		decreaseDateByXWeeks(weeks ,*this);
	}

	static clsDate decreaseDateByOneMonth(clsDate &date)
	{

		if (date.getMonth() == 1)
		{
			date.setMonth(12);
			date.setYear(date.getYear() - 1);
		}
		else
			date.setMonth(date.getMonth() - 1);


		//last check day in date should not exceed max days in the current month
	   // example if date is 31/3/2022 decreasing one month should not be 31/2/2022, it should
	   // be 28/2/2022
		short numberOfDaysInCurrentMonth = numberOfDaysInAMonth(date.getMonth(), date.getYear());
		if (date.getDay() > numberOfDaysInCurrentMonth)
		{
			date.setDay(numberOfDaysInCurrentMonth);
		}


		return date;
	}

	void decreaseDateByOneMonth()
	{
		decreaseDateByOneMonth(*this);
	}

	static clsDate decreaseDateByXDays(short days, clsDate &date)
	{
		for (short i = 1; i <= days; i++)
		{
			date = decreaseDateByOneDay(date);
		}
		return date;
	}

	void decreaseDateByXDays(short days)
	{
		decreaseDateByXDays(days, *this);
	}

	static clsDate decreaseDateByXMonths(short months, clsDate &date)
	{

		for (short i = 1; i <= months; i++)
		{
			date = decreaseDateByOneMonth(date);
		}
		return date;
	}

	void decreaseDateByXMonths(short months)
	{
		decreaseDateByXMonths( months, *this);
	}

	static clsDate decreaseDateByOneYear(clsDate &date)
	{

		date.setYear(date.getYear() - 1);
		return date;
	}

	void decreaseDateByOneYear()
	{
		decreaseDateByOneYear(*this);
	}

	static clsDate decreaseDateByXYears(short years, clsDate &date)
	{
		date.setYear(date.getYear() - years);
		return date;
	}

	void decreaseDateByXYears(short years)
	{
		decreaseDateByXYears(years ,*this);
	}

	static clsDate decreaseDateByOneDecade(clsDate &date)
	{
		//Period of 10 years
		date.setYear(date.getYear() - 10);
		return date;
	}

	void decreaseDateByOneDecade()
	{
		decreaseDateByOneDecade(*this);
	}

	static clsDate decreaseDateByXDecades(short decades, clsDate &date)
	{
		date.setYear(date.getYear() - decades * 10);
		return date;
	}

	void decreaseDateByXDecades(short decades)
	{
		decreaseDateByXDecades(decades, *this);
	}

	static clsDate decreaseDateByOneCentury(clsDate &date)
	{
		//Period of 100 years
		date.setYear(date.getYear() - 100);
		return date;
	}

	void decreaseDateByOneCentury()
	{
		decreaseDateByOneCentury(*this);
	}

	static clsDate decreaseDateByOneMillennium(clsDate &date)
	{
		//Period of 1000 years
		date.setYear(date.getYear() - 1000);
		return date;
	}

	void decreaseDateByOneMillennium()
	{
		decreaseDateByOneMillennium(*this);
	}

	static short isEndOfWeek(clsDate date)
	{
		return  dayOfWeekOrder(date.getDay(), date.getMonth(), date.getYear()) == 6;
	}

	short isEndOfWeek()
	{
		return isEndOfWeek(*this);
	}

	static bool isWeekEnd(clsDate date)
	{
		//Weekends are Fri and Sat
		short dayIndex = dayOfWeekOrder(date.getDay(), date.getMonth(), date.getYear());
		return  (dayIndex == 5 || dayIndex == 6);
	}

	bool isWeekEnd()
	{
		return  isWeekEnd(*this);
	}

	static bool isBusinessDay(clsDate date)
	{
		//Weekends are Sun,Mon,Tue,Wed and Thur

	   /*
		short dayIndex = dayOfWeekOrder(date.Day, Date.Month, Date.year);
		return  (dayIndex >= 5 && dayIndex <= 4);
	   */

	   //shorter method is to invert the isWeekEnd: this will save updating code.
		return !isWeekEnd(date);

	}

	bool isBusinessDay()
	{
		return  isBusinessDay(*this);
	}

	static short daysUntilTheEndOfWeek(clsDate date)
	{
		return 6 - dayOfWeekOrder(date.getDay(), date.getMonth(), date.getYear());
	}

	short daysUntilTheEndOfWeek()
	{
		return  daysUntilTheEndOfWeek(*this);
	}

	static short daysUntilTheEndOfMonth(clsDate date1)
	{

		clsDate endOfMonthDate;
		endOfMonthDate.setDay(numberOfDaysInAMonth(date1.getMonth(), date1.getYear()));
		endOfMonthDate.setMonth(date1.getMonth());
		endOfMonthDate.setYear(date1.getYear());

		return getDifferenceInDays(date1, endOfMonthDate, true);

	}

	short daysUntilTheEndOfMonth()
	{
		return daysUntilTheEndOfMonth(*this);
	}

	static short daysUntilTheEndOfYear(clsDate date1)
	{
		clsDate endOfYearDate;
		endOfYearDate.setDay(31);
		endOfYearDate.setMonth(12);
		endOfYearDate.setYear(date1.getYear());

		return getDifferenceInDays(date1, endOfYearDate, true);

	}

	short daysUntilTheEndOfYear()
	{
		return  daysUntilTheEndOfYear(*this);
	}

	//i added this method to calculate business days between 2 days
	static short calculateBusinessDays(clsDate dateFrom, clsDate dateTo)
	{
		short days = 0;
		while (isDate1BeforeDate2(dateFrom, dateTo))
		{
			if (isBusinessDay(dateFrom))
				days++;

			dateFrom = addOneDay(dateFrom);
		}

		return days;
	}

	static short calculateVacationDays(clsDate dateFrom, clsDate dateTo)
	{
		/*short days = 0;
		while (isDate1BeforeDate2(dateFrom, dateTo))
		{
			if (isBusinessDay(dateFrom))
				Days++;

			dateFrom = addOneDay(dateFrom);
		}*/

		return calculateBusinessDays(dateFrom, dateTo);

	}
	//above method is eough , no need to have method for the object

	static clsDate calculateVacationReturnDate(clsDate dateFrom, short vacationDays)
	{
		short weekEndCounter = 0;

		for (short i = 1; i <= vacationDays; i++)
		{

			if (isWeekEnd(dateFrom))
				weekEndCounter++;

			dateFrom = addOneDay(dateFrom);
		}

		// to add weekends 
		for (short i = 1; i <= weekEndCounter; i++)
			dateFrom = addOneDay(dateFrom);

		return dateFrom;
	}

	static bool isDate1AfterDate2(clsDate date1, clsDate date2)
	{
		return (!isDate1BeforeDate2(date1, date2) && !isDate1EqualDate2(date1, date2));

	}

	bool isDateAfterDate2( clsDate date2)
	{
		return isDate1AfterDate2(*this, date2);
	}

	enum enDateCompare { Before = -1, Equal = 0, After = 1 };

	static enDateCompare compareDates(clsDate date1, clsDate date2)
	{
		if (isDate1BeforeDate2(date1, date2))
			return enDateCompare::Before;

		if (isDate1EqualDate2(date1, date2))
			return enDateCompare::Equal;

		/* if (isDate1AfterDate2(date1,date2))
			 return enDateCompare::After;*/

			 //this is faster
		return enDateCompare::After;

	}

	enDateCompare compareDates( clsDate date2)
	{
		return compareDates(*this, date2);
	}

	static string getSystemDateTimeString()
	{
		//system datetime string
		time_t t = time(0);
		tm* now = localtime(&t);

		short Day, Month, Year,Hour,Minute,Second;

		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_mday;
		Hour = now->tm_hour;
		Minute = now->tm_min;
		Second = now->tm_sec;

		return (to_string(Day) + "/" + to_string(Month) + "/"
			+ to_string(Year) + " - "
			+ to_string(Hour) + ":" + to_string(Minute)
			+ ":" + to_string(Second));

	}

};

