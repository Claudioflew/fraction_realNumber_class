#include "RationalNumber.h"
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

vector<int> reduceFraction(int nume, int deno) {
  int gcd = findGCD(nume, deno);

  vector<int> reduced{nume/gcd, deno/gcd};
  return reduced;
}

int findGCD(int num1, int num2) {
    while (num2 != 0) {
        int rem = num1 % num2;
        num1 = num2;
        num2 = rem;
    }
    return num1;
}

// Comment 5: Default constructor which doesn't require any argument passed.
// Constructors should call the member function to initialize member data.
RationalNumber::RationalNumber() { setNumeDeno(1, 1); }

RationalNumber::RationalNumber(int nume, int deno) { setNumeDeno(nume, deno); }

void RationalNumber::setNumeDeno(int nume, int deno) {
  if (deno > 0) {
    numeDeno.clear();
    if (nume == 0) {
      numeDeno.push_back(0);
      numeDeno.push_back(1);
    } else {
      // Comment 6: We need this reduction operation everywhere in this program,
      // so it should be worked off by a function.
      vector<int> temp = reduceFraction(nume, deno);
      for (int num : temp) {
        numeDeno.push_back(num);
      }
    }
  } else {
    cout << "Please enter a natural number for denominator.";
  }
}

vector<int> RationalNumber::getNumeDeno() const { return numeDeno; }

void RationalNumber::printRational() const {
  if (getNumeDeno()[1] == 1) {
    cout << getNumeDeno()[0];
  } else {
    cout << getNumeDeno()[0] << "/" << getNumeDeno()[1];
  }
}

RationalNumber RationalNumber::operator+(const RationalNumber& mou) const {
  // Comment 7: Simply multiple those two denominators to produce the big
  // denominator and multiple numerators by the denominators. The outcome will
  // need to be reduced, but we have the function to do that!
  int deno = getNumeDeno()[1] * mou.getNumeDeno()[1];
  int nume = getNumeDeno()[0] * mou.getNumeDeno()[1] +
                getNumeDeno()[1] * mou.getNumeDeno()[0];

  vector<int> temp = reduceFraction(nume, deno);
  return RationalNumber(temp[0], temp[1]);
}

RationalNumber RationalNumber::operator-(const RationalNumber& mou) const {
  int deno = getNumeDeno()[1] * mou.getNumeDeno()[1];
  int nume = getNumeDeno()[0] * mou.getNumeDeno()[1] -
                getNumeDeno()[1] * mou.getNumeDeno()[0];

  vector<int> temp = reduceFraction(nume, deno);
  return RationalNumber(temp[0], temp[1]);
}

RationalNumber RationalNumber::operator*(const RationalNumber &mou) const {
  // Comment 8: Multiplication is simple. If the outcome needs to be reduced, it
  // is no problem. We have the function to outsource.
  int nume = getNumeDeno()[0] * mou.getNumeDeno()[0];
  int deno = getNumeDeno()[1] * mou.getNumeDeno()[1];

  vector<int> temp = reduceFraction(nume, deno);
  return RationalNumber(temp[0], temp[1]);
}

RationalNumber RationalNumber::operator/(const RationalNumber& mou) const {
  int nume = getNumeDeno()[0] * mou.getNumeDeno()[1];
  int deno = getNumeDeno()[1] * mou.getNumeDeno()[0];

  vector<int> temp = reduceFraction(nume, deno);
  return RationalNumber(temp[0], temp[1]);
}

const RationalNumber& RationalNumber::operator=(const RationalNumber& mou) {
  numeDeno.clear();
  for (int num : mou.getNumeDeno()) {
    numeDeno.push_back(num);
  }
  return *this;
}

bool RationalNumber::operator<(const RationalNumber &mou) const {
  // Comment 9: We can't compare fractions, so convert them to decimals.
  double thisFloat = (double)getNumeDeno()[0] / (double)getNumeDeno()[1];
  double mouFloat = (double)mou.getNumeDeno()[0] / (double)mou.getNumeDeno()[1];

  if (thisFloat < mouFloat) {
    return true;
  } else {
    return false;
  }
}

bool RationalNumber::operator>(const RationalNumber &mou) const {
  // Comment 10: If we define these correctly, remaining syntax will be easier
  // (< and >)
  double thisFloat = (double)getNumeDeno()[0] / (double)getNumeDeno()[1];
  double mouFloat = (double)mou.getNumeDeno()[0] / (double)mou.getNumeDeno()[1];

  if (thisFloat > mouFloat) {
    return true;
  } else {
    return false;
  }
}

bool RationalNumber::operator==(const RationalNumber &mou) const {
  double thisFloat = (double)getNumeDeno()[0] / (double)getNumeDeno()[1];
  double mouFloat = (double)mou.getNumeDeno()[0] / (double)mou.getNumeDeno()[1];

  if (thisFloat == mouFloat) {
    return true;
  } else {
    return false;
  }
}

bool RationalNumber::operator!=(const RationalNumber& mou) const {
  return !(*this == mou);
}

bool RationalNumber::operator>=(const RationalNumber& mou) const {
  return !(*this < mou);
}
bool RationalNumber::operator<=(const RationalNumber& mou) const {
  return !(*this > mou);
}