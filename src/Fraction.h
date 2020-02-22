// Fraction.h

#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

#ifndef LZZ_Fraction_h
#define LZZ_Fraction_h
#define LZZ_INLINE inline
class Fraction
{
private:
  int _num;
  int _den;
  int gcd (int first, int second);
  int lcm (int first, int second);
  Fraction apply_lcm (int lcm, Fraction const & rhs, Fraction const & lhs);
  std::vector <int> comparison_test (int lcm, Fraction const & rhs, Fraction const & lhs);
public:
  Fraction (int top = 0, int bottom = 1);
  Fraction (int top = 0);
  Fraction operator - ();
  Fraction operator + (Fraction const & rhs);
  Fraction operator - (Fraction & rhs);
  Fraction operator * (Fraction const & rhs);
  Fraction operator / (Fraction const & rhs);
  bool operator == (Fraction const & rhs);
  bool operator != (Fraction const & rhs);
  bool operator < (Fraction const & rhs);
  bool operator > (Fraction const & rhs);
  bool operator <= (Fraction const & rhs);
  bool operator >= (Fraction const & rhs);
  ~ Fraction ();
  float toDecimal () const;
  void print ();
  friend std::ostream & operator << (std::ostream & os, Fraction fraction);
};
std::ostream & operator << (std::ostream & os, Fraction fraction);
#undef LZZ_INLINE
#endif
