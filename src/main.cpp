#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


void trim(string str) {
	str.erase(remove(str.begin(), str.end(), ' '), str.end());
}


int check(string str) {
	auto delimiter = "/";

	trim(str);

	try {
		double left = stoi(str);
	}
	catch (out_of_range const& e)
	{
		cout << "overflow: number out of range (i.e. either too high or too low)" << endl;
		return 1;
	}
	catch (...)
	{
		auto result = strtok(strcpy(&str[0], str.c_str()), delimiter);
		while (result != NULL)
		{
			printf("%s\n", result);
			result = strtok(NULL, "/");
		}
	}
	return 0;
}


int main() {

	string lhs, operator_str, rhs;
	// asks user for fraction
	cout << "This is a fractions calculator. Input the entire equation or one line at a time" << endl;
	cout << "First number or fraction: ";
	cin >> lhs;
	cout << "Operator (+, -, *, or /):";
	cin >> operator_str;
	cout << "Second number or fraction: ";
	cin >> rhs;

	// removes all whitespace
	auto left = check(lhs);
	trim(operator_str);
	auto right = check(rhs);

	if (left == 1 || right == 1) {
		puts("The number provided is not valid");
		return 1;
	}


	cout << lhs << operator_str << endl;

	char operators[] = "+-*/";

	// switch does not work, so if statements
	

	/* if (operator_str.compare(operators[0]) == 0) {
		lhs = 0;

	} */

	return 0;

}