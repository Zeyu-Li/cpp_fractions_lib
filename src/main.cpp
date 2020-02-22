#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include "main.h"
using namespace std;


class Fraction {
	// fractions lib
private:
	// inits
	int _num = 0;
	int _den = 1;
	// cals gcd
	int gcd(int first, int second) {
		if (second == 0) {
			return first;
		}
		return gcd(second, first % second);
	}
	//cals lcm
	int lcm(int first, int second) {
		return (first * second) / gcd(first, second);
	}
	// applies lcm to both fractions
	Fraction apply_lcm(int lcm, const Fraction& rhs, const Fraction& lhs) {
		int top1 = rhs._num * (lcm / rhs._den);
		int top2 = lhs._num * (lcm / lhs._den);
		int bottom = rhs._den * (lcm / rhs._den);
		Fraction fraction(top1 + top2, bottom);
		return fraction;
	}

public:
	// inits frac, but if den is 0, throw error
	Fraction(int top = 0, int bottom = 1) {
		if (bottom == 0) {
			throw "You cannot have 0 as a denomator. Try Again.";
		}
		// gets gcd and simplifies if gcd not 1 or 0
		const int gcd = this->gcd(top, bottom);
		if (gcd != 1 && gcd != 0) {
			top /= gcd;
			bottom /= gcd;
		}
		this->_num = top;
		this->_den = bottom;
	}

	// inits fraction if it is an int
	Fraction(int top = 0) {
		this->_num = top;
		this->_den = 1;
	}

	// operator overloading
	//negative
	Fraction operator-() {
		return Fraction(-this->_num, this->_den);
	}
	// addition
	Fraction operator + (Fraction const& rhs) {
		int lcm = this->lcm(rhs._den, this->_den);
		return apply_lcm(lcm, rhs, (*this));
	}
	// end of overloading
	~Fraction() {
		_num = 0;
		_den = 1;
	};

	// various prints
	void print() {
		cout << _num << "/" << _den << endl;
	}
	friend ostream& operator << (ostream& os, Fraction fraction);
};

// overload cout
ostream& operator << (ostream& os, Fraction fraction) {
	os << fraction._num << "/" << fraction._den;
	return os;
}

int main() {

	Fraction fraction1(5, 2);
	Fraction fraction2(4, 7);

	// test print
	cout << (fraction1 + fraction2) << endl;

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