#include <iostream>
using namespace std;

bool IsLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);	
}

short NumberOfDaysInAYear(short Year)
{
	return IsLeapYear(Year) ? 366 : 355;
}

short NumberOfDaysInAMonth(short Year, short Month)
{
	if (Month < 1 || Month > 12)
	{
		return 0;
	}
	if (Month == 2)
	{
		return IsLeapYear(Year) ? 29 : 28;
	}
	short arr31Days[7] = { 1, 3, 5, 7, 8, 10, 12 };
	for (short i = 1; i <= 7; i++)
	{
		if (arr31Days[i -1] == Month)
		{
			return 31;
		}
	}

	//if you reach here then its 30 days.
	return 30;
}

short NumberOfHoursInAMonth(short Year, short Month)
{
	return NumberOfDaysInAMonth(Year, Month) * 24;
}

int NumberOfMinutesInAMonth(short Year, short Month)
{
	return NumberOfHoursInAMonth(Year, Month) * 60;
}

int NumberOfSecondsInAMonth(short Year, short Month)
{
	return NumberOfMinutesInAMonth(Year, Month) * 60;
}
	
short ReadYear()
{
	short Year;
	cout << "Enter a Year to check? ";
	cin >> Year;
	return Year;
}

short ReadMonth()
{
	short Month;
	cout << "\nEnter a Month to check? ";
	cin >> Month;
	return Month;
}

int main()
{
	short Year = ReadYear();
	short Month = ReadMonth();


	cout << "\nNumber of Days    in Month [" << Month << "] is " 
		<< NumberOfDaysInAMonth(Year, Month);
	cout << "\nNumber of Hours   in Month [" << Month << "] is " 
		<< NumberOfHoursInAMonth(Year, Month); 
	cout << "\nNumber of Minutes in Month [" << Month << "] is " 
		<< NumberOfMinutesInAMonth(Year, Month);
	cout << "\nNumber of Seconds in Month [" << Month << "] is " 
		<< NumberOfSecondsInAMonth(Year, Month);

	return 0;
}

