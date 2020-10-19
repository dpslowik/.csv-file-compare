#include <fstream>
#include <iostream>
#include <string>
#include "convert.h"
#include "IndexCompare.h"
#include "OtherFunctions.h"
using namespace std;

int main()
{
	cout << "This program can read two different Excel files (as .csv), compare the values stored";
	cout << "\nin those files to each other, and then store the results in a new .csv file." << endl;
	cout << "\nUsage: name of 1st file, name of 2nd file, name of new file to hold results.";
	cout << "\n       Files need to be located in the same directory as the program.";
	cout << "\n       Default comparison will return values that are the same or greater" << endl;

	cout << "\nEnter the name of the first file, including .csv at the end: ";
	string firstFile;
	cin >> firstFile;
	cout << "\nEnter the name of the second file, including .csv at the end: ";
	string secondFile;
	cin >> secondFile;
	cout << "\nEnter the name of the file to store the results, without .csv at the end: ";
	string userFileName;
	cin >> userFileName;

	//reading and displaying file
	ifstream myFile;
	ifstream myOtherFile;
	myFile.open(firstFile, ios_base::in);
	myOtherFile.open(secondFile, ios_base::in);

	if (myFile.is_open() && myOtherFile.is_open())
	{
		//reading first file
		cout << "Comparing data from '" << firstFile << "' and '" << secondFile << "'" << endl;
		string fileContents;
		string fileContentsCopy;
		deque<string> fileContents2;
		while (myFile.good())
		{
			getline(myFile, fileContents);
			string fileContentsCopy(fileContents);
			fileContents2.push_back(fileContents);
			//cout << fileContents << endl; //uncomment to display file on screen
		}
		//reading second file
		//cout << "File open sucessfull. '" << secondFile << "' contains: " << endl;
		string fileContents3;
		string fileContentsCopy3;
		deque<string> fileContents4;
		while (myOtherFile.good())
		{
			getline(myOtherFile, fileContents3);
			string fileContentsCopy(fileContents3);
			fileContents4.push_back(fileContents3);
			//cout << fileContents3 << endl;//uncomment to display file on screen
		}

		deque<string> testDeck1;//making containers to ultimatly store elements to compare
		deque<string> testDeck2;

		string testStr1;//making strings to hold data from the files 
		string testStr2;

		AccessConents(fileContents2, testStr1);//converts container elements into string
		AccessConents(fileContents4, testStr2);

		StoreInContainer(testStr1, testDeck1);//parses out data from string into container
		StoreInContainer(testStr2, testDeck2);

		deque<string> holdResults;
		CompareAndStoreEqualOrGreater(testDeck1, testDeck2, holdResults);
		ColumnRight(holdResults, userFileName);//saving results to new file

		cout << "Finished!" << endl;
		myFile.close();
		myOtherFile.close();
	}
	else
		cout << "open() failed: check if file is in correct folder" << endl;
	return 0;
}
