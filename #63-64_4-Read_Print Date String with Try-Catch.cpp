#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>  // To use the standard exceptions

using namespace std;

struct sDate
{
    short Day;
    short Month;
    short Year;
};

vector<string> SplitString(string Name, string Delim)
{
    vector<string> Vstring;
    short pos = 0;
    string sWord;

    while ((pos = Name.find(Delim)) != string::npos)
    {
        sWord = Name.substr(0, pos);
        if (sWord != "")
        {
            Vstring.push_back(sWord);
        }
        Name.erase(0, pos + Delim.length());
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

    // Check if the input string has exactly two '/' characters
    if (count(DataString.begin(), DataString.end(), '/') != 2)
    {
        throw invalid_argument("Invalid date format. Please use dd/mm/yyyy.");
    }

    vDate = SplitString(DataString, "/");

    // Convert string to integer and assign to the date structure
    Date.Day = stoi(vDate[0]);
    Date.Month = stoi(vDate[1]);
    Date.Year = stoi(vDate[2]);

    return Date;
}

string ReadStringDate(string Message)
{
    string DateString;
    cout << Message;
    getline(cin >> ws, DateString);
    return DateString;
}

int main()
{
    try
    {
        string DateString = ReadStringDate("\nPlease Enter Date (dd/mm/yyyy): ");
        sDate Date = StringToDate(DateString);

        cout << "\nDay: " << Date.Day << endl;
        cout << "Month: " << Date.Month << endl;
        cout << "Year: " << Date.Year << endl;

        cout << "\nYou Entered: " << DateToString(Date) << "\n";
    }
    catch (const invalid_argument& e)
    {
        cout << "\nError: " << e.what() << endl;
    }

    return 0;
}
