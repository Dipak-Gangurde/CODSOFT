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

  cout << "\n\t\tTASK 2";
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

/*
~/CODSOFT-CPP-INTERNSHIP$ g++ Task2_SimpleCalculator.cpp
~/CODSOFT-CPP-INTERNSHIP$ ./a.out

        TASK 2
        SIMPLE CALCULATOR


Enter first number:  4
Choose correct operation ('+', '-', '*', '/') : +
Enter second number:   6
Addition is:   10

    Do you want to perform another operation?
        If yes then press -> 'y'
        If no then press -> 'n'
             y

Enter first number:  8
Choose correct operation ('+', '-', '*', '/') : -
Enter second number:   6
Subtraction is:   2

    Do you want to perform another operation?
        If yes then press -> 'y'
        If no then press -> 'n'
             y

Enter first number:  9
Choose correct operation ('+', '-', '*', '/') : *
Enter second number:   5
Multiplication is:   45

    Do you want to perform another operation?
        If yes then press -> 'y'
        If no then press -> 'n'
             y

Enter first number:  8
Choose correct operation ('+', '-', '*', '/') : /
Enter second number:   4
Division is:   2

    Do you want to perform another operation?
        If yes then press -> 'y'
        If no then press -> 'n'
             y

Enter first number:  8
Choose correct operation ('+', '-', '*', '/') : /
Enter second number:   0
Error!! Divide by zero!!

    Do you want to perform another operation?
        If yes then press -> 'y'
        If no then press -> 'n'
             y

Enter first number:  3
Choose correct operation ('+', '-', '*', '/') : &
Enter second number:   3
Invalid Operation!!

    Do you want to perform another operation?
        If yes then press -> 'y'
        If no then press -> 'n'
             n
~/CODSOFT-CPP-INTERNSHIP$
*/