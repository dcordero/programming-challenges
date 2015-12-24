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

  var firstValueInt = 0
  if let value = firstValue {
    firstValueInt = Int(value) ?? 0
  }
  
  var secondValueInt = 0
  if let value = secondValue {
    secondValueInt = Int(value) ?? 0
  }

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
