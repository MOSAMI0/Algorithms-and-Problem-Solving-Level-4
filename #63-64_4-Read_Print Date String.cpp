#include <iostream>
#include<string>
#include<vector>

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

vector <string> SplitString(string Name, string Delim)
{
	vector<string>Vstring;

	short pos = 0;
	string sWord; // define a string variable 

	// use find() function to get the position of the delimiters  
	while ((pos = Name.find(Delim)) != std::string::npos)
	{
		sWord = Name.substr(0, pos); // store the word   
		if (sWord != "")
		{
			Vstring.push_back(sWord);
		}

		Name.erase(0, pos + Delim.length()); /* erase() until
		 positon and move to next word. */
	}

	if (Name != "")
	{
		Vstring.push_back(Name);

	}

	return Vstring;
}

string DateToString(sDate Date)
{
	return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}

sDate StringToDate(string DataString)
{
	sDate Date;
	vector<string> vDate;

	vDate = SplitString(DataString, "/");
	Date.Day = stoi(vDate[0]);
	Date.Month = stoi(vDate[1]);
	Date.Year = stoi(vDate[2]);

	return Date;
}

string ReadStringDate(string Message)
{
	string DataString;
	cout << Message;
	getline(cin >> ws, DataString);
	return DataString;
}

int main()
{
	string DateString = ReadStringDate("\nPlease Enter Date dd/mm/yyyy? ");
	sDate Date = StringToDate(DateString); 

	cout << "\nDay:" << Date.Day << endl; 
	cout << "Month:" << Date.Month << endl;
	cout << "Year:" << Date.Year << endl;  
	
	cout << "\nYou Entered: " << DateToString(Date) << "\n";

	return 0;
}

