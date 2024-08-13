#include <iostream>
using namespace std;

bool IsLeapYear(short Year)
{
	// 1- if year is divisible by 4 AND not divisible by 100
	// OR if year is divisible by 400
	// then it is a leap year
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
	// 2- Or use  This Code
	//return (Year % 400 == 0) ? true : (Year % 100 == 0) ? false : (Year % 4 == 0) ?  true : false;
}

int ReadYear()
{
	int Year;
	cout << "Enter a Year to check? ";
	cin >> Year;
	return Year;
}

int main()
{
	short Year = ReadYear();

	if (IsLeapYear(Year))
		cout << "\nYes, Year [" << Year << "] is a leap year.\n";
	else
		cout << "\nNo, Year [" << Year << "] is NOT a leap year.\n"; 

	return 0;
}

