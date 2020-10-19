#pragma once

//Template uses containers with elements stored as strings
//Function will fail if container elements are not strings
template<typename T1, typename T2>
void CompareContents(const T1 &container1, const T2 &container2) {
	auto element1 = container1.cbegin();
	auto element2 = container2.cbegin();
	while (element1 != container1.cend() && element2 != container2.cend()) {
		try {
			double doubleElement1 = stod(*element1);
			double doubleElement2 = stod(*element2);
			if (doubleElement1 == doubleElement2)
				cout << doubleElement1 << " = " << doubleElement2 << endl;
			else if (doubleElement1 > doubleElement2)
				cout << doubleElement1 << " > " << doubleElement2 << endl;
			else if (doubleElement1 < doubleElement2)
				cout << doubleElement1 << " < " << doubleElement2 << endl;
		}
		catch (invalid_argument) {
			cout << "Cannot convert text to number" << endl;
		}
		element1++;
		element2++;
	}
}

//Container of values to compare, Container of values to compare to, Container to hold results
template<typename T1, typename T2, typename T3>
void CompareAndStoreEqualOrGreater(const T1 &container1, const T2 &container2, T3 &container3) {
	auto element1 = container1.cbegin();
	auto element2 = container2.cbegin();
	while (element1 != container1.cend() && element2 != container2.cend()) {
		try {
			double doubleElement1 = stod(*element1);
			double doubleElement2 = stod(*element2);
			if (doubleElement1 == doubleElement2) {
				cout << doubleElement1 << " = " << doubleElement2 << endl;
				container3.push_back(*element1);
			}
			else if (doubleElement1 > doubleElement2) {
				cout << doubleElement1 << " > " << doubleElement2 << endl;
				container3.push_back(*element1);
			}
			else if (doubleElement1 < doubleElement2) {
				cout << doubleElement1 << " < " << doubleElement2 << endl;
				container3.push_back(*element2);
			}
		}
		catch (invalid_argument) {
			cout << "Cannot convert text to number" << endl;
		}
		element1++;
		element2++;
	}
}


