/*
TASK 4
 TO-DO LIST
 Build a simple console-based to-do list
 manager that allows users to add, view, and
 delete tasks
 Task Input: Allow users to input tasks they want to add to the list.
 Add Task: Implement a function to add tasks to the list.
 View Tasks: Display the list of tasks with their status (completed or
 pending).
 Mark Task as Completed: Allow users to mark tasks as completed.
 Remove Task: Provide an option to remove tasks from the list.
*/

#include <fstream>
#include <iostream>
using namespace std;

struct todolist {
  int id;
  string task;
};

int ID;
void banner();
void addTask();
void showTask();
int searchTask();
void deleteTask();
void updateTask();

int main() {

  cout << "\n\t\tTASK 4";
  cout << "\n\t\tTO-DO LIST\n" << endl;

  while (true) {
    banner();
    cout << "\n\t1. Add Task";
    cout << "\n\t2. Show Task";
    cout << "\n\t3. Search Task";
    cout << "\n\t4. Delete Task";
    cout << "\n\t5. Update Task";
    cout << "\n\t6. Exit from program";

    int choice;
    cout << "\n\nEnter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
      addTask();
      break;
    case 2:
      showTask();
      break;
    case 3:
      searchTask();
      break;
    case 4:
      deleteTask();
      break;
    case 5:
      updateTask();
      break;
    case 6:
      cout << "\nExiting the program." << endl;
      return 0; // Terminate the program when the user chooses to exit
    default:
      cout << "Invalid choice. Please try again." << endl;
      break;
    }
  }

  return 0;
}

void banner() {
  cout << "------------------------------------------------" << endl;
  cout << " \t          \tMy Todo" << endl;
  cout << "_________________________________________________" << endl;
}

void addTask() {
  banner();
  todolist todo;
  cout << "\nEnter your task: " << endl;
  cin.get();
  getline(cin, todo.task);
  char save;
  cout << "\nSave? (y/n): ";
  cin >> save;
  if (save == 'y') {
    ID++;
    ofstream fout;
    fout.open("todo.txt", ios::app);
    fout << "\n" << ID;
    fout << "\n" << todo.task;
    fout.close();

    char more;
    cout << "Add more task? (y/n) ";
    cin >> more;

    if (more == 'y')
      addTask();
    else {
      cout << "Task added successfully!" << endl;
      return;
    }
  }
}

void showTask() {
  banner();
  todolist todo;
  ifstream fin;
  fin.open("todo.txt");
  cout << "Task: " << endl;

  while (!fin.eof()) {
    fin >> todo.id;
    fin.ignore();
    getline(fin, todo.task);
    if (todo.task != "")
      cout << "\t" << todo.id << " : " << todo.task << endl;
    else
      cout << "\tEmpty!" << endl;
  }
  fin.close();
  char exit;
  cout << "\nExit (y/n): ";
  cin >> exit;
  if (exit != 'y')
    showTask();
}

int searchTask() {
  banner();
  int id;
  cout << "Enter task id: ";
  cin >> id;
  todolist todo;
  ifstream fin("todo.txt");
  while (!fin.eof()) {
    fin >> todo.id;
    fin.ignore();
    getline(fin, todo.task);
    if (todo.id == id) {
      cout << "\t" << todo.id << " : " << todo.task << endl;
      return id;
    }
  }
  cout << "Not found" << endl;
  return 0;
}

void deleteTask() {
  int id = searchTask();
  if (id != 0) {
    char del;
    cout << "\t Delete? (y/n): ";
    cin >> del;
    if (del == 'y') {
      todolist todo;
      ofstream tempFile;
      tempFile.open("temp.txt");
      ifstream fin;
      fin.open("todo.txt");
      int index = 1;
      while (!fin.eof()) {
        fin >> todo.id;
        fin.ignore();
        getline(fin, todo.task);
        if (todo.id != id) {
          tempFile << "\n" << index;
          tempFile << "\n" << todo.task;
          index++;
          ID--;
        }
      }
      fin.close();
      tempFile.close();
      remove("todo.txt");
      rename("temp.txt", "todo.txt");
      cout << "\n\tDeleted Successfully!" << endl;

    } else
      cout << "Not Deleted!" << endl;
  }
}

// Function to update the description of a specific task in the to-do list
void updateTask() {
  int id = searchTask(); // Call function to search for the task to update
  if (id != 0) {
    todolist todo;
    ofstream tempFile;
    tempFile.open("temp.txt");
    ifstream fin;
    fin.open("todo.txt");

    while (!fin.eof()) {
      fin >> todo.id; // Read task ID from file
      fin.ignore();
      getline(fin, todo.task); // Read task description from file

      if (todo.id == id) {
        cout << "Enter the updated task description: ";
        cin.ignore(); // Ignore any newline characters in the buffer
        getline(cin,
                todo.task); // Get the updated task description from the user
      }

      tempFile << "\n" << todo.id;   // Write task ID to temporary file
      tempFile << "\n" << todo.task; // Write task description to temporary file
    }

    fin.close();
    tempFile.close();
    remove("todo.txt");
    rename("temp.txt",
           "todo.txt"); // Rename temporary file to the original file

    cout << "\n\tTask Updated Successfully!" << endl;
  }
}
