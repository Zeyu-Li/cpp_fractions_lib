#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include "main.h"
using namespace std;


class Fraction {
private:
	int numerator;
	int denominator;
	// cals gcd
	int gcd(int first, int second) {
		if (second == 0) {
			return first;
		}
		return (first, first % second);
	}
	//cals lcm
	int lcm(int first, int second) {
		return (first * second) / gcd(first, second);
	}
public:
	Fraction(int top = 0, int bottom = 1) {
		numerator = top;
		denominator = bottom;
	}
	void print() {
		cout << numerator << "/" << denominator << endl;
	}

	// operator overloading
	Fraction operator + (Fraction const& rhs) {
		/* if (typeid(rhs) == typeid(int)) {
			Fraction new_rhs(rhs);
			int lcd = lcm(rhs, this->denominator)
		} */
		int lcd = lcm(rhs.denominator, this->denominator);
		apply_lcm(lcd, rhs, *this);

		// new Fraction
		Fraction final_frac;
		final_frac.numerator = numerator + rhs.numerator;
		final_frac.denominator = this->denominator;
		return final_frac;
	}
	void apply_lcm(int lcd, Fraction rhs, Fraction lhs) {
		rhs.numerator *= lcd / rhs.numerator;
		rhs.denominator *= lcd / rhs.denominator;
		lhs.numerator *= lcd / lhs.numerator;
	}
	~Fraction() {
	
	};
};


int main() {

	Fraction fraction1(5, 2);
	Fraction fraction2(4, 7);

	// test print
	(fraction1 + fraction2).print();

	return 0;

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