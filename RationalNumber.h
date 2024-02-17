#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

#include <vector>

// Comment 1: I decided to outsource this reduction work to a non-member function. This doesn't need to access to private data, so doesn't need to be a friend function.
std::vector<int> reduceFraction(int, int);
int findGCD(int, int);

class RationalNumber {
public:
  RationalNumber();
  RationalNumber(int, int);

  void setNumeDeno(int, int);
  std::vector<int> getNumeDeno() const;

  void printRational() const;

  // Comment 2: We just want to pass the outcome by value because the outcome will be stored in another object. These don't change anything inside the function, so it should be const functions.
  RationalNumber operator+(const RationalNumber&) const;
  RationalNumber operator-(const RationalNumber&) const;
  RationalNumber operator*(const RationalNumber&) const;
  RationalNumber operator/(const RationalNumber&) const;

  const RationalNumber& operator=(const RationalNumber&);

  // Comment 3: These assessment functions don't change anything either, so they should be const functions.
  bool operator<(const RationalNumber&) const;
  bool operator>(const RationalNumber&) const;
  bool operator==(const RationalNumber&) const;
  bool operator!=(const RationalNumber&) const;
  bool operator<=(const RationalNumber&) const;
  bool operator>=(const RationalNumber&) const;
  
private:
  // Comment 4: I decided to store numerator and denominator in a vector.
  std::vector<int> numeDeno;
};

#endif