/*
TASK 2
SIMPLE CALCULATOR

 Develop a calculator program that performs basic arithmetic
 operations such as addition, subtraction, multiplication, and
 division. Allow the user to input two numbers and choose an
 operation to perform
*/

#include <iostream>
using namespace std;

int main() {

  cout<<"\n\t\tTASK 2";
  cout << "\n\t\tSIMPLE CALCULATOR\n" << endl;

  float num1, num2;
  char operation, another;

  do {
    cout << "\nEnter first number:  ";
    cin >> num1;
    cout << "Choose correct operation ('+', '-', '*', '/') : ";
    cin >> operation;
    cout << "Enter second number:   ";
    cin >> num2;

    if (operation == '+')
      cout << "Addition is:   " << num1 + num2 << endl;
    else if (operation == '-')
      cout << "Subtraction is:   " << num1 - num2 << endl;
    else if (operation == '*')
      cout << "Multiplication is:   " << num1 * num2 << endl;
    else if (operation == '/') {
      if (num2 != 0)
        cout << "Division is:   " << num1 / num2 << endl;
      else
        cout << "Error!! Divide by zero!!" << endl;
    } else
      cout << "Invalid Operation!!" << endl;

    cout << "\n\tDo you want to perform another operation? "
         << "\n\t\tIf yes then press -> 'y' "
         << "\n\t\tIf no then press -> 'n' "
         << "\n\t\t\t ";
    cin >> another;
  } while (another == 'y');

  return 0;
}