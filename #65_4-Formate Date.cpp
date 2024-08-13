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

string ReplaceWordInString(string S1, string StringToReplace, string sReplaceTo)
{
	short pos = S1.find(StringToReplace);
	while (pos != std::string::npos)
	{
		S1 = S1.replace(pos, StringToReplace.length(), sReplaceTo);
		pos = S1.find(StringToReplace); //find next

	}

	return S1;
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

string FormateDate(sDate Date, string DateFormat = "dd/mm/yyyy")
{
	string FormattedDateString = "";
	FormattedDateString = ReplaceWordInString(DateFormat, "dd", to_string(Date.Day));
	FormattedDateString = ReplaceWordInString(FormattedDateString, "mm", to_string(Date.Month));
	FormattedDateString = ReplaceWordInString(FormattedDateString, "yyyy", to_string(Date.Year));
	return FormattedDateString;
}																							   

int main()
{
	string DateString = ReadStringDate("\nPlease Enter Date dd/mm/yyyy? ");
	sDate Date = StringToDate(DateString); 

	cout << "\n" << FormateDate(Date) << "\n";  
	cout << "\n" << FormateDate(Date, "yyyy/dd/mm") << "\n"; 
	cout << "\n" << FormateDate(Date, "mm/dd/yyyy") << "\n";   
	cout << "\n" << FormateDate(Date, "mm-dd-yyyy") << "\n";  
	cout << "\n" << FormateDate(Date, "dd-mm-yyyy") << "\n";  
	cout << "\n" << FormateDate(Date, "Day:dd, Month:mm, Year:yyyy") << "\n";

	return 0;
}

