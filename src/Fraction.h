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
  int gcd (int, int);
  int lcm (int, int);
  Fraction apply_lcm (int, Fraction const &, Fraction const &);
  std::vector <int> comparison_test (int, Fraction const &, Fraction const &);
public:
  Fraction (int, int);
  Fraction (int);
  Fraction operator - ();
  Fraction operator + (Fraction const &);
  Fraction operator - (Fraction &);
  Fraction operator * (Fraction const &);
  Fraction operator / (Fraction const & );
  bool operator == (Fraction const & );
  bool operator != (Fraction const & );
  bool operator < (Fraction const & );
  bool operator > (Fraction const & );
  bool operator <= (Fraction const & );
  bool operator >= (Fraction const & );
  ~ Fraction ();
  float toDecimal () const;
  void print ();
  friend std::ostream & operator << (std::ostream & , Fraction );
};
std::ostream & operator << (std::ostream & , Fraction );
#undef LZZ_INLINE
#endif
