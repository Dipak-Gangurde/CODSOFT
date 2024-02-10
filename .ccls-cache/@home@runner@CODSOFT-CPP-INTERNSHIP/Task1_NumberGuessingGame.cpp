/*
TASK 1
NUMBER GUESSING GAME

Create a program that generates a random number and asks the
 user to guess it. Provide feedback on whether the guess is too
 high or too low until the user guesses the correct number.
*/

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main() {

  int guess, control;
  control = 1;

  srand(static_cast<int>(time(0)));
  int random = rand() % 10 + 1;

  cout << "\n\t\tTASK 1";
  cout << "\n\t\tNUMBER GUESSING GAME\n";
  do {
    cout << "\nEnter a number between 1 to 20  : ";
    cin >> guess;

    if (guess == random) {
      cout << "Congratulations! You guessed the correct number.\n" << endl;
      control = 0;
    } else if (guess < random)
      cout << "Your guess is too low! Try to enter a bigger number." << endl;
    else if (guess > random)
      cout << "Your guess is too high! Try to enter a smaller number." << endl;
    else
      cout << "Invalid input!!" << endl;

  } while (control == 1);

  return 0;
}

/*
~/CODSOFT-CPP-INTERNSHIP$ g++ Task1_NumberGuessingGame.cpp
~/CODSOFT-CPP-INTERNSHIP$ ./a.out

        TASK 1
        NUMBER GUESSING GAME

Enter a number between 1 to 20  : 5
Your guess is too low! Try to enter a bigger number.

Enter a number between 1 to 20  : 7
Your guess is too low! Try to enter a bigger number.

Enter a number between 1 to 20  : 9
Congratulations! You guessed the correct number.

~/CODSOFT-CPP-INTERNSHIP$ g++ Task1_NumberGuessingGame.cpp
~/CODSOFT-CPP-INTERNSHIP$ ./a.out

        TASK 1
        NUMBER GUESSING GAME

Enter a number between 1 to 20  : 8
Your guess is too high! Try to enter a smaller number.

Enter a number between 1 to 20  : 1
Your guess is too low! Try to enter a bigger number.

Enter a number between 1 to 20  : 2
Your guess is too low! Try to enter a bigger number.

Enter a number between 1 to 20  : 7
Your guess is too high! Try to enter a smaller number.

Enter a number between 1 to 20  : 3
Congratulations! You guessed the correct number.

~/CODSOFT-CPP-INTERNSHIP$

*/