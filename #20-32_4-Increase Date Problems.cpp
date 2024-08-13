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

sDate IncreaseDateByXDays(short Days, sDate Date)
{
	for (short i = 1; i <= Days; i++)
	{
		Date = IncreaseDateByOneDay(Date);
	}
	return Date;
}

sDate IncreaseDateByOneWeek(sDate Date)
{
	for (short i = 1; i <= 7; i++)
	{
		Date = IncreaseDateByOneDay(Date);
	}
	return Date;
}

sDate IncreaseDateByXWeeks(short Weeks, sDate Date)
{
	for (short i = 1; i <= Weeks; i++)
	{
		Date = IncreaseDateByOneWeek(Date);
	}
	return Date;
}

sDate IncreaseDateByOneMonth(sDate Date)
{
	if (Date.Month == 12)
	{
		Date.Month = 1;
		Date.Year++;
	}
	else
	{
		Date.Month++;
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

sDate IncreaseDateByXMonths(short Months, sDate Date)
{
	for (short i = 1; i <= Months; i++)
	{
		Date = IncreaseDateByOneMonth(Date);
	}

	return Date;
}

sDate IncreaseDateOneYear(sDate Date)
{
	Date.Year++;
	return Date;
}

sDate IncreaseDateByXYears(short Years, sDate Date)
{
	for (short i = 1; i <= Years; i++)
	{
		Date = IncreaseDateOneYear(Date);
	}
	return Date;
}

sDate IncreaseDateByXYearsFaster(short Years, sDate Date)
{
	Date.Year += Years;
	return Date;
}

sDate IncreaseDateByOneDecade(sDate Date)
{
	/*for (short i = 1; i <= 10; i++)
	{
		Date.Year += 1;
	}*/
	//Period of 10 years
	Date.Year += 10;
	return Date;
}

sDate IncreaseDateByXDecades(short Decade, sDate Date)
{
	for (short i = 1; i <= Decade * 10; i++)
	{
		Date = IncreaseDateOneYear(Date);
	}
	return Date;
}

sDate IncreaseDateByXDecadesFaster(short Decade, sDate Date)
{
	Date.Year += Decade * 10;
	return Date;
}

sDate IncreaseDateByOneCentury(sDate Date)
{
	//Period of 100 years
	Date.Year += 100;
	return Date;
}

sDate IncreaseDateByOneMillennium(sDate Date)
{
	//Period of 1000 years
	Date.Year += 1000;
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

	Date1 = IncreaseDateByOneDay(Date1);
	cout << "\n01-Adding one day is:"
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByXDays(10, Date1);   
	cout << "\n02-Adding 10 days is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByOneWeek(Date1);
	cout << "\n03-Adding 1 Week is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByXWeeks(10, Date1);
	cout << "\n04-Adding 10 Week is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;


	Date1 = IncreaseDateByOneMonth(Date1);
	cout << "\n05-Adding One Month is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByXMonths(5, Date1);
	cout << "\n06-Adding 5 Months is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateOneYear(Date1);
	cout << "\n07-Adding One Year is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByXYears(10, Date1);
	cout << "\n08-Adding 10 Years is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByXYears(10, Date1);
	cout << "\n09-Adding 10 Years (Faster) is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByOneDecade(Date1);
	cout << "\n10-Adding One Decade is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByXDecades(10, Date1);
	cout << "\n11-Adding 10 Decades is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByXDecadesFaster(10, Date1);
	cout << "\n12-Adding 10 Decades (Faster) is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByOneCentury(Date1);
	cout << "\n13-Adding One Century is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByOneMillennium(Date1);
	cout << "\n14-Adding One Millennium is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	//system("pause>0");
	return 0;
}

