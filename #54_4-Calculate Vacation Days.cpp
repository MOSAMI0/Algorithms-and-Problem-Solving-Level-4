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
	string arrDaysName[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
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
	return(DayIndex == 5 || DayIndex == 6);
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

short CalculateVacationDays(sDate DateFrom, sDate DateTo)
{
	short DaysCount = 0;
	while (IsDate1BeforeDate2(DateFrom, DateTo))
	{
		if (IsBusinessDay(DateFrom))
			DaysCount++;

		DateFrom = IncreaseDateByOneDay(DateFrom);
		
	}
	return DaysCount;
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
	cout << "\nVacation Starts: ";
	sDate DateFrom = ReadFullDate();

	cout << "\nVacation Ends: ";
	sDate DateTo = ReadFullDate();
	cout << "\nToday is " << DayShortName(DayOfWeekOrder(DateFrom))
		<< " , " << DateFrom.Day << "/" << DateFrom.Month << "/" << DateFrom.Year << endl;

	cout << "Vaction To: "<< DayShortName(DayOfWeekOrder(DateTo)) << " , " 
		<< DateTo.Day << "/" << DateTo.Month << "/" << DateTo.Year << endl;

	cout << "\n\nActucal Vacation Days is: " 
		<< CalculateVacationDays(DateFrom, DateTo);


	//system("pause>0");
	return 0;
}

