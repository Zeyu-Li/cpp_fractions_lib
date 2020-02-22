
# Fractions C++ Library

## About

This project is a fractions library. Simply put:

```c++
#include "Fraction.h"
```

In the header, and the library is implemented

The header lists all of the library's methods and functions

Header: 

```c
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
```



## Project files

* includes - placeholder txt file
* libs - placeholder txt file, replace with libraries
* src - source code
* test - place to stage tests

Nothing more, nothing less

## Licence

The rules for copy and distributing this project licence are
outlined in the licence.txt file.

This project is under an MIT licence

## Other Notes

.exe files are not kept so you will have to build from source (src)
