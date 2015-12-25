
#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

vector<double> readExpenses(int numberOfTravellers)
{
  vector<double> expenses(numberOfTravellers, 0);
  for (int i = 0; i< numberOfTravellers; i++) {
    double currentExpense;
    cin >> currentExpense;
    expenses[i] = currentExpense;
  }
  return expenses;
}

double doubleWithMoneyPrecision(double value)
{
  return ((int)(value*100))/100.00;
}

double calculateAverage(vector<double> expenses)
{
  int expensesSize = expenses.size();
  double amount=0;
  for (int i = 0; i < expensesSize; i++) {
    amount += expenses[i];
  }
  return amount/expensesSize;
}


double calculateExchange(vector<double> expenses, double average)
{
  int expensesSize = expenses.size();
  double exchangeToPay = 0;
  double exchangeToReceive = 0;
  for (int i = 0; i < expensesSize; i++) {
    double diff = doubleWithMoneyPrecision(average - expenses[i]);
    if (diff > 0) {
      exchangeToPay += diff;
    }
    else {
      exchangeToReceive += -diff;
    }
  }
  return exchangeToPay > exchangeToReceive ? exchangeToPay : exchangeToReceive;
}

int main(int argc, char **argv)
{
  int numberOfTravellers;

  while (cin >> numberOfTravellers) {

    if (numberOfTravellers == 0) { break; }

    vector<double> expenses = readExpenses(numberOfTravellers);
    double average = calculateAverage(expenses);
    double exchange = calculateExchange(expenses, average);
    
    printf("$%.2lf\n", exchange);
  }
}
