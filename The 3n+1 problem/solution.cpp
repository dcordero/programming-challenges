// @BEGIN_OF_SOURCE_CODE

#include <iostream>

using namespace std;

bool isOdd(int number)
{
  return (number % 2);
}

int getCycleLength(int number) 
{
  if (number <= 1) {
    return 1;
  }

  if (isOdd(number)) {
    return 1 + getCycleLength(number * 3 + 1);
  }
  else {
    return 1 + getCycleLength(number / 2);
  }
}

int getMaxCycleLengthInRange(int i, int j)
{
  int maxCycleLength = 0;
  for (int currentNumber=i; currentNumber<=j; currentNumber++) {
    int cycleLength = getCycleLength(currentNumber);
    if (cycleLength > maxCycleLength) {
      maxCycleLength = cycleLength;
    }
  }
  return maxCycleLength;
}

int main(int argc, char **argv) 
{
  int firstValue;
  int secondValue;

  while (cin >> firstValue >> secondValue) {
    int firstValueOrig = firstValue;
    int seconfValueOrig = secondValue;

    if ( firstValue > secondValue ) swap (firstValue, secondValue);
    
    int maxCycleLength = getMaxCycleLengthInRange(i, j);
    cout << iOrig << " " << jOrig << " " << maxCycleLength << endl;
  }
  return 0;
}

// @END_OF_SOURCE_CODE

