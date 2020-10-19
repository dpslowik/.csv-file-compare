#pragma once
#include <fstream>
#include <iostream>

//First parameter is string to write to file, Second parameter is new file name as "string"
template <typename T1, typename T2>
void Right(const T1 &writeString, const T2 &userFileName) {

	string addCSV = ".csv";
	string newFileName = userFileName + addCSV;
	ofstream myNewFile;
	myNewFile.open(newFileName, ios_base::out);//creating new file

	if (myNewFile.is_open())
	{
		cout << "Storing results in new file: " << userFileName << ".csv" << endl;
		myNewFile << writeString << endl;//writing string to file

		//cout << "Finished writing to file, will close now" << endl;
		myNewFile.close();

	}
}
//Writes container values as a column in user specified new file
template <typename T1, typename T2>
void ColumnRight(const T1 &writeContainer, const T2 &userFileName) {

	string addCSV = ".csv";
	string newFileName = userFileName + addCSV;
	ofstream myNewFile;
	myNewFile.open(newFileName, ios_base::out);//creating new file

	if (myNewFile.is_open())
	{
		cout << "Storing results in new file: " << userFileName << ".csv" << endl;
		string tempStr;
		int index = 0;
		for (; index < writeContainer.size(); index++) {
			tempStr.append(writeContainer[index]);
			myNewFile << tempStr << endl;//writing string to file
			tempStr.erase();
		}
		//cout << "Finished writing to file, will close now" << endl;
		myNewFile.close();
	}
}


