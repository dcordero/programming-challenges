#!/usr/bin/env xcrun swift

func isOdd(number: Int) -> Bool
{
  return (number % 2 != 0)
}

func getCycleLength(number: Int) -> Int 
{
  if number <= 1 {
    return 1
  }
 
  if isOdd(number) {
    return 1 + getCycleLength(number * 3 + 1);
  }
  else {
    return 1 + getCycleLength(number / 2);
  }
}

func getMaxCycleLengthInRange(firstValue: Int, secondValue: Int) -> Int 
{
  var maxCycleLength = 0
  for currentNumber in firstValue...secondValue {
    let cycleLength = getCycleLength(currentNumber)
    if cycleLength > maxCycleLength {
      maxCycleLength = cycleLength
    }
  }
  return maxCycleLength
}

func readEntryValues() -> (Int, Int)
{
  let firstValue = readLine(stripNewline: true)
  let secondValue = readLine(stripNewline: true)

  let firstValueInt = Int(firstValue!)!
  let secondValueInt = Int(secondValue!)!

  return (firstValueInt, secondValueInt)
}

func main() 
{
  var (firstValue, secondValue) = readEntryValues() 
  if firstValue > secondValue {
    swap(&firstValue, &secondValue)
  }

  let result = getMaxCycleLengthInRange(firstValue, secondValue: secondValue)

  print(" -- result -- \(result)")
}

main()
