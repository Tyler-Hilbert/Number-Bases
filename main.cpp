/**
   Converts a number in any base to any base.
   Does this by converting the number to base 10 and then to the desired base.

   For information on how to perform this conversion go to:
   http://www.purplemath.com/modules/numbbase.htm
*/ 

#include <iostream>
#include <string> 
#include <math.h>

using namespace std;


string convert(const string &inNum, int inBase, int outBase);


int main(int argc, const char** argv) {
  string inNum; // The number entered
  int inBase; // The base of the number entered
  int outBase; // The base being converted to

  cout << "Enter number:";
  cin >> inNum;
  cout << "Enter number base:";
  cin >> inBase;
  cout << "Enter base to convert to:";
  cin >> outBase;

  cout << convert(inNum, inBase, outBase);
  cout << "\n";

  return 0;
}

/**
   Converts the inNum from the inBase to the outBase
*/
string convert(const string &inNum, int inBase, int outBase) {
  string outNum = "";
  int base10Num = 0;

  // Convert number to base 10
  for (int i = 0; i < inNum.length(); i++) {
    char inChar = inNum.at(i);

    // Get value of char
    int num;
    if (inChar >= 48 && inChar <= 57) 
      num = inChar - 48;
    else if (inChar >= 65 && inChar <= 90) 
      num = inChar - 55;
    else 
      return "Input error";
      
    // Get ascii value of char then subtract 48 to get correct value 
    base10Num += num * pow(inBase, inNum.length() - i -1);
  }

  // Convert base 10 to outNum
  do {
    int remainder = (base10Num % outBase);
    // Convert remainder to ascii value
    if (remainder > 9) {
      remainder += 55;
    } else {
      remainder += 48;
    }

    char charNum = remainder;
    outNum = charNum + outNum;
    base10Num /= outBase;
  } while (base10Num != 0);

  return outNum;
}
