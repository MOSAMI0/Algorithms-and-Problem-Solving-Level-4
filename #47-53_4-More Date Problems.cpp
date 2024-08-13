#pragma warning(disable : 4996)

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

bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
	return  (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
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

bool IsLastDayInMonth(sDate Date1)
{
	return (Date1.Day == NumberOfDaysInAMonth(Date1.Month, Date1.Year));
}

bool IsLastMonthInYear(short Month)
{
	return (Month == 12);
}

sDate IncreaseDateByOneDay(sDate Date)
{
	if (IsLastDayInMonth(Date))
	{
		if (IsLastMonthInYear(Date.Month))
		{
			Date.Day = 1;
			Date.Month = 1;
			Date.Year++;
		}
		else
		{
			Date.Day = 1;
			Date.Month++;
		}
	}
	else
	{
		Date.Day++;
	}

	return Date;
}

int GetDifferenceInDays(sDate Date1, sDate Date2, bool IncludeEndDay = false)
{
	int Days = 0;
	while (IsDate1BeforeDate2(Date1, Date2))
	{
		Days++;
		Date1 = IncreaseDateByOneDay(Date1);
	}

	return IncludeEndDay ? ++Days : Days;
}

short DayOfWeekOrder(short Day, short Month, short Year)
{
	short a, y, m;
	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;

	// Gregorian:
	//0:sun, 1:Mon, 2:Tue...etc
	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

}

short DayOfWeekOrder(sDate Date)
{
	return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
}

string  DayShortName(short DayOfWeekOrder)
{
	string arrDaysName[] = { "Sat","Sun","Mon","Tue","Wed","Thu","Fri" };
	return arrDaysName[DayOfWeekOrder];
}

short IsEndOfWeek(sDate Date)
{
	return DayOfWeekOrder(Date) == 6;
}

bool IsWeekEnd(sDate Date)
{
	//Weekends are Thu and Fri
	short DayIndex = DayOfWeekOrder(Date);
	return(DayIndex == 4 || DayIndex == 5);
}

bool IsBusinessDay(sDate Date)
{
	//Weekends are Sun,Mon,Tue,Wed and Thur
	/* short DayIndex = DayOfWeekOrder(Date);
	return  (DayIndex >= 6 && DayIndex <= 3);
	*/
	//shorter method is to invert the IsWeekEnd: this will save updating code.
	return !IsWeekEnd(Date);
}

short DaysUntilTheEndOfWeek(sDate Date)
{
	return 6 - DayOfWeekOrder(Date);
}

short DaysUntilTheEndOfMonth(sDate Date)
{
	sDate EndOfMonth;
	EndOfMonth.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
	EndOfMonth.Month = Date.Month;
	EndOfMonth.Year = Date.Year;

	return GetDifferenceInDays(Date, EndOfMonth, true);
}

short DaysUntilTheEndOfYear(sDate Date)
{
	sDate EndOfYearDate;
	EndOfYearDate.Day = 31;
	EndOfYearDate.Month = 12;
	EndOfYearDate.Year = Date.Year;

	return GetDifferenceInDays(Date, EndOfYearDate, true);
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

sDate GetSystemDate()
{
	sDate Date;
	time_t t = time(0);
	tm* now = localtime(&t);

	Date.Year = now->tm_year + 1900;
	Date.Month = now->tm_mon + 1;
	Date.Day = now->tm_mday;

	return Date;
}

int main()
{
	sDate Date1 = GetSystemDate();
	cout << "\nToday is " << DayShortName(DayOfWeekOrder(Date1))
		<< " , " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	//---------------------
	cout << "\nIs it End of Week?\n";
	if (IsEndOfWeek(Date1))
		cout << "Yes it is Saturday, it's of Week.";
	else
		cout << "No it's Not end of week.";
	//---------------------
	cout << "\n\nIs it Weekend?\n";
	if (IsWeekEnd(Date1))
		cout << "Yes it is a week end.";
	else
		cout << "No today is " << DayShortName(DayOfWeekOrder(Date1))
		<< ", Not a weekend.";
	//---------------------
	cout << "\n\nIs it Business Day?\n";
	if (IsBusinessDay(Date1))
		cout << "Yes it is a business day.";
	else
		cout << "No it is NOT a business day.";
	//---------------------
	cout << "\n\nDays until end of week : "
		<< DaysUntilTheEndOfWeek(Date1) << " Day(s).";
	//---------------------   
	cout << "\nDays until end of month : "
		<< DaysUntilTheEndOfMonth(Date1) << " Day(s).";
	//--------------------- 
	cout << "\nDays until end of year : "
		<< DaysUntilTheEndOfYear(Date1) << " Day(s).";


	//system("pause>0");
	return 0;
}

