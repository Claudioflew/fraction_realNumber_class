// Exercise 10.10 Solution: ex10_10.cpp
// RationalNumber test program.
#include <iostream> 
#include "RationalNumber.h"
using namespace std;

int main()
{
   RationalNumber c(56, 4), d(27, 72), x;

   c.printRational();
   cout << " + " ;
   d.printRational();
   cout << " = ";
   x = c + d; // test overloaded operators + and =
   x.printRational();

   cout << '\n';
   c.printRational();
   cout << " - " ;
   d.printRational();
   cout << " = ";
   x = c - d; // test overloaded operators - and =
   x.printRational();

   cout << '\n';
   c.printRational();
   cout << " * " ;
   d.printRational();
   cout << " = ";
   x = c * d; // test overloaded operators * and =
   x.printRational();

   cout << '\n';
   c.printRational();
   cout << " / " ;
   d.printRational();
   cout << " = ";
   x = c / d; // test overloaded operators / and =
   x.printRational();

   cout << '\n';
   c.printRational();
   cout << " is:\n";

   // test overloaded greater than operator
   cout << ( ( c > d ) ? "  > " : "  <= " );
   d.printRational();
   cout << " according to the overloaded > operator\n";

   // test overloaded less than operator
   cout << ( ( c < d ) ? "  < " : "  >= " );
   d.printRational();
   cout << " according to the overloaded < operator\n";

   // test overloaded greater than or equal to operator
   cout << ( ( c >= d ) ? "  >= " : "  < " );
   d.printRational();
   cout << " according to the overloaded >= operator\n";

    // test overloaded less than or equal to operator
   cout << ( ( c <= d ) ? "  <= " : "  > " );
   d.printRational();
   cout << " according to the overloaded <= operator\n";
   
   // test overloaded equality operator
   cout << ( ( c == d ) ? "  == " : "  != " );
   d.printRational();
   cout << " according to the overloaded == operator\n";

   // test overloaded inequality operator
   cout << ( ( c != d ) ? "  != " : "  == " );
   d.printRational();
   cout << " according to the overloaded != operator" << endl;

   cin.get();
  // system("PAUSE");
   return 0;
}
