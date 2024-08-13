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

bool IsLastDayInMonth(sDate Date1)
{
	return (Date1.Day == NumberOfDaysInAMonth(Date1.Month, Date1.Year));
}

bool IsLastMonthInYear(short Month)
{
	return (Month == 12);
}

sDate DecreaseDateByOneDay(sDate Date)
{
	if (Date.Day == 1)
	{
		if (Date.Month == 1)
		{
			Date.Month = 12;
			Date.Day = 31;
			Date.Year--;
		}
		else
		{
			Date.Month--;
			Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
		}
	}
	else
	{
		Date.Day--;
	}

	return Date;
}

sDate DecreaseDateByXDays(short Days, sDate Date)
{
	for (short i = 1; i <= Days; i++)
	{
		Date = DecreaseDateByOneDay(Date);
	}
	return Date;
}

sDate DecreaseDateByOneWeek(sDate Date)
{
	for (short i = 1; i <= 7; i++)
	{
		Date = DecreaseDateByOneDay(Date);
	}
	return Date;
}

sDate DecreaseDateByXWeeks(short Weeks, sDate Date)
{
	for (short i = 1; i <= Weeks; i++)
	{
		Date = DecreaseDateByOneWeek(Date);
	}
	return Date;
}

sDate DecreaseDateByOneMonth(sDate Date)
{
	if (Date.Month == 1)
	{
		Date.Month = 12;
		Date.Year--;
	}
	else
	{
		Date.Month--;
	}

	//last check day in date should not exceed max days in the current month
	// example if date is 31/1/2022 increasing one month should not be 31/2/2022, it should
	// be 28/2/2022
	short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
	if (Date.Day > NumberOfDaysInCurrentMonth)
	{
		Date.Day = NumberOfDaysInCurrentMonth;
	}

	return Date;
}

sDate DecreaseDateByXMonths(short Months, sDate Date)
{
	for (short i = 1; i <= Months; i++)
	{
		Date = DecreaseDateByOneMonth(Date);
	}

	return Date;
}

sDate DecreaseDateOneYear(sDate Date)
{
	Date.Year--;
	return Date;
}

sDate DecreaseDateByXYears(short Years, sDate Date)
{
	for (short i = 1; i <= Years; i++)
	{
		Date = DecreaseDateOneYear(Date);
	}
	return Date;
}

sDate DecreaseDateByXYearsFaster(short Years, sDate Date)
{
	Date.Year -= Years;
	return Date;
}

sDate DecreaseDateByOneDecade(sDate Date)
{
	//Period of 10 years
	Date.Year -= 10;
	return Date;
}

sDate DecreaseDateByXDecades(short Decade, sDate Date)
{
	for (short i = 1; i <= Decade * 10; i++)
	{
		Date = DecreaseDateOneYear(Date);
	}
	return Date;
}

sDate DecreaseDateByXDecadesFaster(short Decade, sDate Date)
{
	Date.Year -= Decade * 10;
	return Date;
}

sDate DecreaseDateByOneCentury(sDate Date)
{
	//Period of 100 years
	Date.Year -= 100;
	return Date;
}

sDate DecreaseDateByOneMillennium(sDate Date)
{
	//Period of 1000 years
	Date.Year -= 1000;
	return Date;
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
	cout << "\nDate After: \n";

	Date1 = DecreaseDateByOneDay(Date1);
	cout << "\n01-Subtracting one day is:"
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByXDays(10, Date1);   
	cout << "\n02-Subtracting 10 days is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByOneWeek(Date1);
	cout << "\n03-Subtracting 1 Week is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByXWeeks(10, Date1);
	cout << "\n04-Subtracting 10 Week is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;


	Date1 = DecreaseDateByOneMonth(Date1);
	cout << "\n05-Subtracting One Month is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByXMonths(5, Date1);
	cout << "\n06-Subtracting 5 Months is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateOneYear(Date1);
	cout << "\n07-Subtracting One Year is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByXYears(10, Date1);
	cout << "\n08-Subtracting 10 Years is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByXYearsFaster(10, Date1);
	cout << "\n09-Subtracting 10 Years (Faster) is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByOneDecade(Date1);
	cout << "\n10-Subtracting One Decade is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByXDecades(10, Date1);
	cout << "\n11-Subtracting 10 Decades is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByXDecadesFaster(10, Date1);
	cout << "\n12-Subtracting 10 Decades (Faster) is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByOneCentury(Date1);
	cout << "\n13-Subtracting One Century is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByOneMillennium(Date1);
	cout << "\n14-Subtracting One Millennium is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	//system("pause>0");
	return 0;
}

