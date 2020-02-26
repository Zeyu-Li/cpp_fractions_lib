// Fraction.cpp
//

#include "Fraction.h"
#define LZZ_INLINE inline
using namespace std;
int Fraction::gcd (int first, int second)
                                       {
		if (second == 0) {
			return first;
		}
		return gcd(second, first % second);
	}
int Fraction::lcm (int first, int second)
                                       {
		return (first * second) / gcd(first, second);
	}
Fraction Fraction::apply_lcm (int lcm, Fraction const & rhs, Fraction const & lhs)
                                                                              {
		int top1 = rhs._num * (lcm / rhs._den);
		int top2 = lhs._num * (lcm / lhs._den);
		int bottom = rhs._den * (lcm / rhs._den);
		Fraction fraction(top1 + top2, bottom);
		return fraction;
	}
Fraction Fraction::apply_lcm_minus (int lcm, Fraction const & rhs, Fraction const & lhs)
                                                                              {
		int top1 = rhs._num * (lcm / rhs._den);
		int top2 = lhs._num * (lcm / lhs._den);
		int bottom = rhs._den * (lcm / rhs._den);
		Fraction fraction(top2 - top1, bottom);
		return fraction;
	}
vector <int> Fraction::comparison_test (int lcm, Fraction const & rhs, Fraction const & lhs)
                                                                                        {
		int top1 = rhs._num * (lcm / rhs._den);
		int top2 = lhs._num * (lcm / lhs._den);
		vector<int> comparsions {top2, top1};
		return comparsions;
	}
Fraction::Fraction() {
	this->_num = 0;
	this->_den = 1;
}

Fraction::Fraction (int top, int bottom)
                                              {
		if (bottom == 0) {
			throw "You cannot have 0 as a denomator. Try Again.";
		} else if (bottom < 0) {
			top = -top;
			bottom = -bottom;
		}
		// gets gcd and simplifies if gcd not 1 or 0
		const int gcd = this->gcd(abs(top), abs(bottom));
		if (gcd != 1 && gcd != 0) {
			top /= gcd;
			bottom /= gcd;
		}
		this->_num = top;
		this->_den = bottom;
	}
Fraction::Fraction (int top)
                              {
		this->_num = top;
		this->_den = 1;
	}
Fraction Fraction::operator - ()
                             {
		return Fraction(-this->_num, this->_den);
	}
Fraction Fraction::operator + (Fraction const & rhs)
                                                  {
		int lcm = this->lcm(rhs._den, this->_den);
		return apply_lcm(lcm, rhs, (*this));
	}
Fraction Fraction::operator - (Fraction const& rhs)
                                            {
		int lcm = this->lcm(rhs._den, this->_den);
		return apply_lcm_minus(lcm, rhs, (*this));
	}
Fraction Fraction::operator * (Fraction const & rhs)
                                                  {
		Fraction newFraction(this->_num * rhs._num, this->_den * rhs._den);
		return newFraction;
	}
Fraction Fraction::operator / (Fraction const & rhs)
                                                  {
		Fraction newFraction(this->_num * rhs._den, this->_den * rhs._num);
		return newFraction;
	}
bool Fraction::operator == (Fraction const & rhs)
                                               {
		int lcm = this->lcm(rhs._den, this->_den);
		vector<int> results = this->comparison_test(lcm, rhs, (*this));
		int left = results[0];
		int right = results[1];
		return (left == right);
	}
bool Fraction::operator != (Fraction const & rhs)
                                               {
		int lcm = this->lcm(rhs._den, this->_den);
		vector<int> results = this->comparison_test(lcm, rhs, (*this));
		int left = results[0];
		int right = results[1];
		return (left != right);
	}
bool Fraction::operator < (Fraction const & rhs)
                                              {
		int lcm = this->lcm(rhs._den, this->_den);
		vector<int> results = this->comparison_test(lcm, rhs, (*this));
		int left = results[0];
		int right = results[1];
		return (left < right);
	}
bool Fraction::operator > (Fraction const & rhs)
                                              {
		int lcm = this->lcm(rhs._den, this->_den);
		vector<int> results = this->comparison_test(lcm, rhs, (*this));
		int left = results[0];
		int right = results[1];
		return (left > right);
	}
bool Fraction::operator <= (Fraction const & rhs)
                                               {
		int lcm = this->lcm(rhs._den, this->_den);
		vector<int> results = this->comparison_test(lcm, rhs, (*this));
		int left = results[0];
		int right = results[1];
		return (left <= right);
	}
bool Fraction::operator >= (Fraction const & rhs)
                                               {
		int lcm = this->lcm(rhs._den, this->_den);
		vector<int> results = this->comparison_test(lcm, rhs, (*this));
		int left = results[0];
		int right = results[1];
		return (left >= right);
	}
Fraction::~ Fraction ()
                    {
		_num = 0;
		_den = 1;
	}
float Fraction::toDecimal () const
                                {
		return this->_num /(float) this->_den;
	}
void Fraction::print ()
                     {
		cout << _num << "/" << _den << endl;
	}

ostream& operator << (ostream& os, Fraction fraction) {
	if (fraction._den == 1) {
		os << fraction._num;
	} else {
		os << fraction._num << "/" << fraction._den;
	}
	return os;
}
#undef LZZ_INLINE
