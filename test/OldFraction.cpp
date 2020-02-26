#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Note, not working

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
	vector<int> comparison_test (int lcm, const Fraction& rhs, const Fraction& lhs) {
		int top1 = rhs._num * (lcm / rhs._den);
		int top2 = lhs._num * (lcm / lhs._den);
		vector<int> comparsions = {top1, top2};
		return comparsions;
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
	// subtraction also, rhs is not const
	Fraction operator - (Fraction& rhs) {
		int lcm = this->lcm(rhs._den, this->_den);
		rhs._num = - rhs._num;
		return apply_lcm(lcm, rhs, (*this));
	}
	// mult and divids
	Fraction operator * (Fraction const& rhs) {
		Fraction newFraction(this->_num * rhs._num, this->_den * rhs._den);
		return newFraction;
	}
	Fraction operator / (Fraction const& rhs) {
		Fraction newFraction(this->_num * rhs._den, this->_den * rhs._num);
		return newFraction;
	}
	// comparisons
	bool operator == (Fraction const& rhs) {
		int lcm = this->lcm(rhs._den, this->_den);
		vector<int> results = this->comparison_test(lcm, rhs, (*this));
		for (int i = 0; i < results.size(); i++) {
        	if (i == 0) {
				int left = results[i];
			} else {
				int right = results[i];
			}
		}
		return (left == right);
	}
	bool operator != (Fraction const& rhs) {
		int lcm = this->lcm(rhs._den, this->_den);
		vector<int> results = this->comparison_test(lcm, rhs, (*this));
		for (int i = 0; i < results.size(); i++) {
        	if (i == 0) {
				int left = results[i];
			} else {
				int right = results[i];
			}
		}
		return (left != right);
	}
	bool operator < (Fraction const& rhs) {
		int lcm = this->lcm(rhs._den, this->_den);
		vector<int> results = this->comparison_test(lcm, rhs, (*this));
		for (int i = 0; i < results.size(); i++) {
        	if (i == 0) {
				int left = results[i];
			} else {
				int right = results[i];
			}
		}
		return (left < right);
	}
	bool operator > (Fraction const& rhs) {
		int lcm = this->lcm(rhs._den, this->_den);
		vector<int> results = this->comparison_test(lcm, rhs, (*this));
		for (int i = 0; i < results.size(); i++) {
        	if (i == 0) {
				int left = results[i];
			} else {
				int right = results[i];
			}
		}
		return (left > right);
	}
	bool operator <= (Fraction const& rhs) {
		int lcm = this->lcm(rhs._den, this->_den);
		vector<int> results = this->comparison_test(lcm, rhs, (*this));
		for (int i = 0; i < results.size(); i++) {
        	if (i == 0) {
				int left = results[i];
			} else {
				int right = results[i];
			}
		}
		return (left <= right);
	}
	bool operator >= (Fraction const& rhs) {
		int lcm = this->lcm(rhs._den, this->_den);
		vector<int> results = this->comparison_test(lcm, rhs, (*this));
		for (int i = 0; i < results.size(); i++) {
        	if (i == 0) {
				int left = results[i];
			} else {
				int right = results[i];
			}
		}
		return (left >= right);
	}
	// end of overloading
	~Fraction() {
		_num = 0;
		_den = 1;
	};

	// to decimal
	float toDecimal() const {
		return this->_num /(float) this->_den;
	}

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
