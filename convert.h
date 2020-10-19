#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <string>
using namespace std;

//a generic template used to  container contents
template<typename T>
void DisplayContents(const T& container)
{
	for (auto element = container.cbegin(); element != container.cend(); ++element)
	{
		cout << *element << ' ';
	}
	cout << endl;
}

//this explicitly shows the empty values, hard to see with other display method
template<typename T>
void IndexedContents(const T &container) {
	cout << "Number of items in deque: " << container.size() << endl;
	int index = 0;
	for (auto element = container.cbegin(); element != container.cend(); element++) {
		cout << "index " << index << ": " << *element << endl;
		index++;
	}
}

//This template will convert the contents of a container into a single string
template<typename T1, typename T2>
void AccessConents(const T1 &container, T2 &str) {
	int index = 0;
	for (auto element = container.cbegin(); element != container.cend(); ++element) {
		str.append(container[index]);
		str.push_back(',');
		index++;
	}
	str.pop_back();
}

//Convert the contents of a container into a single string with comma separated values
template<typename T1, typename T2>
void MakeCommaSeparatedValues(const T1 &container, T2 &str) {
	int index = 0;
	for (auto element = container.cbegin(); element != container.cend(); ++element) {
		str.append(container[index]);
		str.push_back(',');
		index++;
	}
	str.pop_back();
}



//A template for finding and storing position of commas
template<typename T1, typename T2>
void StoreCommaPos(const T1 &container, T2 &destination)
{
	size_t charPos = container.find(",", 0);
	while (charPos != string::npos)
	{
		//cout << ", at: " << charPos << endl;//uncomment to also print on-screen
		destination.push_back(charPos);
		size_t searchOffset = charPos + 1;
		charPos = container.find(",", searchOffset);
	}
}


//template works with 1st parameter is string input, 2nd parameter is container name, already defined
//for example:  deque<string> myNewContainer;
//				StoreInContainer(inputString, myNewContainer);
//now myNewContainer can be accessed and also be modified while in main();
template<typename T1, typename T2>
void StoreInContainer(T1 &stringInput, T2 &contType)
{
	string myString(stringInput);
	vector<char> build1;
	deque<string> build2;
	//using myString as input example
	string cpyStr3(myString);//first make a copy of the original string
	size_t charPos3 = myString.find(",", 0);//now find the end of the first cell, AKA where the first comma is
	cpyStr3.resize(charPos3);//delete everything after the first cell
	build2.push_back(cpyStr3);//storing the first cell in a deque(could be any container)
	string copyStr4(myString);//making a copy of the original
	size_t charPos4 = myString.find(",", charPos3);//finding the end of the second cell

	vector<int> commaPositions;//making a vector to store the comma postions
	deque<string> testDeque1;//making a deque to store the values I actually want

	StoreCommaPos(myString, commaPositions);//using template to read string and store comma postions into container

	//cuts out the values from the string and stores them into a container
	for (int index = 0; index < commaPositions.size(); index++) {
		string copyStr4(myString);
		copyStr4.resize(commaPositions[index]);
		if (index > 0) {
			copyStr4.erase(0, commaPositions[index - 1] + 1);
			contType.push_back(copyStr4);
		}
		else
			contType.push_back(copyStr4);
	}
	copyStr4.erase(0, commaPositions[commaPositions.size() - 1] + 1);//this last bit captures the final element
	contType.push_back(copyStr4);//adding the final element to the container
}

//Separates elements into two containers
template<typename T1, typename T2, typename T3>
void MakeTwoColumns(const T1 &container1, T2 &container2, T3 &container3) {
	for (int index = 0; index < container1.size(); index++) {
		container2.push_back(container1[index]);
		if (index != container1.size() - 1) {
			container3.push_back(container1[index + 1]);
			index = index + 1;
		}
		else if (index == container1.size()) {}
	}
}


