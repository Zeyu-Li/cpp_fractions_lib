#include "Fraction.h"
using namespace std;

int main() {

	Fraction fraction1(5, 2);
	Fraction fraction2(4, 7);

	// test print
	cout << (fraction1 * fraction2) << endl;
	cout << fraction1.toDecimal() << endl;
	cout << (fraction1 < fraction2) << endl;

	return 0;

	// impliementation of the calculator can be done later
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
	auto left = lhs;
	auto right = rhs;

	char operators[] = "+-*/";

	// switch does not work, so if statements
	

	return 0;
}


/* void trim(string str) {
	// removies whitespace
	str.erase(remove(str.begin(), str.end(), ' '), str.end());
} */


/*

Fraction check(string str) {
	auto delimiter = "/";

	trim(str);

	try {
		double result = stoi(str);
		return result;
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
			fraction.push_back(stoi(result));
			result = strtok(NULL, "/");
		}
		return fraction;
	}
}
*/