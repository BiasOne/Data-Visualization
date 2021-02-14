#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include <cmath>

//FIXME: stream manipulation library
using namespace std;
using std::right;
using std::left;

string columnOne;
string columnTwo;
string title;

string dataInput = "";
vector<string> colOneData;
vector<int> colTwoData;

unsigned int i;
unsigned int j;

stringstream iss(dataInput);
string tempColOne;
string tempColTwo;
int tempColTwoInt;

int main()
{

	cout << "Enter a title for the data:" << endl;
	getline(cin, title);
	cout << "You entered: " << title << endl;
	cout << endl;
	cout << "Enter the column 1 header:" << endl;
	getline(cin, columnOne);
	cout << "You entered: " << columnOne << endl;
	cout << endl;
	cout << "Enter the column 2 header:" << endl;
	getline(cin, columnTwo);
	cout << "You entered: " << columnTwo << endl;
	cout << endl;


	while (dataInput != "-1")
	{
		cout << "Enter a data point (-1 to stop input):" << endl;
		getline(cin, dataInput);

		if (dataInput != "-1")
		{
			if (dataInput.find(',') == string::npos)
			{
				cout << "Error: No comma in string." << endl;
				cout << endl;
				continue;
			}
			//

			int found = dataInput.find(',');

			tempColOne = dataInput.substr(0, found);
			tempColTwo = dataInput.substr(found + 2);

			if (tempColTwo.find(',') != string::npos)
			{
				cout << "Error: Too many commas in input." << endl;
				cout << endl;
				continue;

			}


			try
			{
				tempColTwoInt = stoi(tempColTwo);

			}
			catch (...)
			{
				cout << "Error: Comma not followed by an integer." << endl;
				cout << endl;
				continue;
			}
			//

			colOneData.push_back(tempColOne);
			colTwoData.push_back(tempColTwoInt);

			cout << "Data string: " << tempColOne << endl;
			cout << "Data integer: " << tempColTwoInt << endl;
			cout << endl;

			//Will exit the while loop to print tables/histogram
		}
		else
		{
			break;
		}

	}
	cout << endl;
	//prints table
	cout << right << setw(33) << title << endl;
	cout << left << setw(20) << columnOne;
	cout << "|";
	cout << right << setw(23) << columnTwo << endl;
	cout << "--------------------------------------------" << endl;

	for (i = 0; i < static_cast<unsigned int>(colOneData.size()); i++)
	{
		cout << left << setw(20) << colOneData.at(i);
		cout << right << "|";
		cout << right << setw(23) << colTwoData.at(i) << endl;
	}
	cout << endl;


	//prints histogram
	for (i = 0; i < static_cast<unsigned int>(colOneData.size()); i++)
	{
		cout << right << setw(20) << colOneData.at(i) << " ";

		for (j = 0; j < static_cast<unsigned int>(colTwoData.at(i)); j++)
		{
			cout << "*";

		}
		cout << endl;

	}

	return 0;
}