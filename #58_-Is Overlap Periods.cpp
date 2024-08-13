#include <iostream>
using namespace std;

struct sDate
{
	short Day;
	short Month;
	short Year;
};

struct sPeriod
{
	sDate StartDate;
	sDate EndDate;
};

bool IsLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAMonth(short Month, short Year)
{
	if (Month < 1 || Month > 12)
	{
		return 0;
	}
	short NumberOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];

}

short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
{
	int TotalDays = 0;

	for (int i = 1; i <= Month - 1; i++)
	{
		TotalDays += NumberOfDaysInAMonth(i, Year);
	}

	TotalDays += Day;

	return TotalDays;
}

bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
	return  (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

bool IsDate1EqualDate2(sDate Date1, sDate Date2)
{
	return	(Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
}

bool IsDate1AfterDate2(sDate Date1, sDate Date2)
{
	return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
}

short ReadDay()
{
	short Day;
	cout << "\nPlease Enter a Day? ";
	cin >> Day;
	return Day;
}

short ReadMonth()
{
	short Month;
	cout << "\nPlease Enter a Month? ";
	cin >> Month;
	return Month;
}

short ReadYear()
{
	short Year;
	cout << "\nPlease Enter a Year? ";
	cin >> Year;
	return Year;
}

sDate ReadFullDate()
{
	sDate Date;
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();
	return Date;
}

sPeriod ReadPeriod()
{
	sPeriod Period;
	cout << "\nEnter Start Date\n";
	Period.StartDate = ReadFullDate();

	cout << "\nEnter End Date\n";
	Period.EndDate = ReadFullDate();

	return Period;
}

enum enDateCompare {
	After = -1,
	Before = 1,
	Equal = 0 
};

enDateCompare CompareDates(sDate Date1, sDate Date2)
{
	if (IsDate1BeforeDate2(Date1, Date2))
		return enDateCompare::Before;

	if (IsDate1AfterDate2(Date1, Date2))
		return enDateCompare::After;

 /* if (IsDate1AfterDate2(Date1,Date2))     
	return enDateCompare::Equal;*/

	//this is faster
	return enDateCompare::Equal;
	
}

bool IsOverlapPeriods(sPeriod Period1, sPeriod Period2)
{
	if (
		CompareDates(Period1.EndDate, Period2.StartDate) == enDateCompare::Before 
		||
		CompareDates(Period1.StartDate, Period2.EndDate) == enDateCompare::After
		)
		return false;

	return true;
}

int main()
{
	cout << "\nEnter Period 1:";
	sPeriod Period1 = ReadPeriod(); 

	cout << "\nEnter Period 2:"; 
	sPeriod Period2 = ReadPeriod();
	
	if (IsOverlapPeriods(Period1, Period2))    
		cout << "\nYes, Periods Overlap\n";
	else    
		cout << "\nNo, Periods do not Overlap\n";

	return 0;
}

