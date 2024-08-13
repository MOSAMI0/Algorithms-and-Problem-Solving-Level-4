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

enum enDateCompare {
	After = -1,
	Before = 1,
	Equal = 0
};

enDateCompare CompareDates(sDate Date1, sDate Date2)
{
	if (IsDate1BeforeDate2(Date1, Date2))
		return enDateCompare::Before;

	if (IsDate1EqualDate2(Date1, Date2))
		return enDateCompare::After;

	/* if (IsDate1AfterDate2(Date1,Date2))
	   return enDateCompare::Equal;*/

	   //this is faster
	return enDateCompare::Equal;

}

int PeriodLengthInDays(sPeriod Period, bool IncludeEndDate = false)
{
	return GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeEndDate);
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

bool IsDateInPeriod(sDate Date, sPeriod Period)
{
	return !(CompareDates(Date, Period.StartDate) == enDateCompare::Before
		||
		CompareDates(Date, Period.EndDate) == enDateCompare::After);

}

int CountOverlapDays(sPeriod Period1, sPeriod Period2)
{
	int Period1Length = PeriodLengthInDays(Period1, true);
	int Period2Length = PeriodLengthInDays(Period2, true);
	int OverlapDays = 0;

	if (!IsOverlapPeriods(Period1, Period2))
		return 0;

	if (Period1Length < Period2Length)
	{
		while (IsDate1BeforeDate2(Period1.StartDate, Period1.EndDate))
		{
			if (IsDateInPeriod(Period1.StartDate, Period2))
				OverlapDays++;

			Period1.StartDate = IncreaseDateByOneDay(Period1.StartDate);
		}
	}
	else
	{
		while (IsDate1BeforeDate2(Period2.StartDate, Period2.EndDate))
		{
			if (IsDateInPeriod(Period2.StartDate, Period1))
				OverlapDays++;

			Period2.StartDate = IncreaseDateByOneDay(Period2.StartDate);
		}
	}
	return OverlapDays;
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

int main()
{
	cout << "\nEnter Period 1:";
	sPeriod Period1 = ReadPeriod();

	cout << "\nEnter Period 2:";
	sPeriod Period2 = ReadPeriod();

	cout << "\nOverlap Days Count Is: " << CountOverlapDays(Period1, Period2);

	return 0;
}

