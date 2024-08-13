#include <iostream>
using namespace std;

struct sDate
{
	short Day;
	short Month;
	short Year;
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

	for (int i = 1; i <= Month - 1 ; i++)
	{
		TotalDays += NumberOfDaysInAMonth(i, Year);
	}

	TotalDays += Day;

	return TotalDays;
}

bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
	/* other Code
	short Da1 = NumberOfDaysFromTheBeginingOfTheYear(Date1.Day, Date1.Month, Date1.Year);
	short Da2 = NumberOfDaysFromTheBeginingOfTheYear(Date2.Day, Date2.Month, Date2.Year);
	if (Da1 < Da2)
	{
		return true;
	}

	return false;*/
	return  (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
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

int main()
{	
	sDate Date1 = ReadFullDate();
	sDate Date2 = ReadFullDate();

	if (IsDate1BeforeDate2(Date1, Date2))
	{
		cout << "\nYes, Date1 is Less than Date2.";
	}
	else
	{
		cout << "\nNo, Date1 is NOT Less than Date2.";
	}
	//system("pause>0");
	return 0;
}

