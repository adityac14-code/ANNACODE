/* Name: yash yogesh sonawane
Seat no  - S190274279
Computer department 

Practical 12:Company maintains employee information as employee ID, name, designation and salary. Allow
user to add, delete information of employee. Display information of particular employee. If
employee does not exist an appropriate message is displayed. If it is, then the system displays the
employee details. Use index sequential file to maintain the data....*/


#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

const int MAX_NAME_LENGTH = 50;
const int MAX_DESIGNATION_LENGTH = 50;

class Employee {
private:
    int id;
    char name[MAX_NAME_LENGTH];
    char designation[MAX_DESIGNATION_LENGTH];
    float salary;

public:
    void read();
    void display();
    int getId() 
	{ 
	return id;
	}
};

void Employee::read() {
    cout << "Enter employee ID: ";
    cin >> id;
    cin.ignore(); // Clear the input buffer
    cout << "Enter employee name: ";
    cin.getline(name, MAX_NAME_LENGTH);
    cout << "Enter employee designation: ";
    cin.getline(designation, MAX_DESIGNATION_LENGTH);
    cout << "Enter employee salary: ";
    cin >> salary;
}

void Employee::display() {
    cout << setw(10) << id << setw(20) << name << setw(30) << designation << setw(15) << fixed << setprecision(2) << salary << endl;
}

void appendToFile(const char* filename, Employee& emp) {
    ofstream file(filename, ios::binary | ios::app);
    if (!file) {
        cerr << "Error opening file for writing: " << filename << endl;
        return;
    }
    file.write(reinterpret_cast<char*>(&emp), sizeof(emp));
    file.close();
}

void displayAll(const char* filename) {
    Employee emp;
    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "Error opening file for reading: " << filename << endl;
        return;
    }
    cout << setw(10) << "ID" << setw(20) << "Name" << setw(30) << "Designation" << setw(15) << "Salary" << endl;
    while (file.read(reinterpret_cast<char*>(&emp), sizeof(emp))) {
        emp.display();
    }
    file.close();
}

int findEmployee(const char* filename, int id) {
    Employee emp;
    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "Error opening file for reading: " << filename << endl;
        return -1;
    }
    int position = 0;
    while (file.read(reinterpret_cast<char*>(&emp), sizeof(emp))) {
        if (emp.getId() == id) {
            file.close();
            return position;
        }
        position++;
    }
    file.close();
    return -1;
}

void deleteEmployee(const char* filename, const char* indexFilename, int id) {
    int position = findEmployee(indexFilename, id);
    if (position == -1) {
        cout << "Employee with ID " << id << " not found." << endl;
        return;
    }

    // Delete from data file
    ifstream dataFile(filename, ios::binary);
    ofstream tempFile("temp.dat", ios::binary);
    if (!dataFile || !tempFile) {
        cerr << "Error opening file." << endl;
        return;
    }

    Employee emp;
    int currentPosition = 0;
    while (dataFile.read(reinterpret_cast<char*>(&emp), sizeof(emp))) {
        if (currentPosition != position) {
            tempFile.write(reinterpret_cast<char*>(&emp), sizeof(emp));
        }
        currentPosition++;
    }
    dataFile.close();
    tempFile.close();

    remove(filename);
    rename("temp.dat", filename);

    // Delete from index file
    ifstream indexFile(indexFilename, ios::binary);
    ofstream tempIndexFile("tempindex.dat", ios::binary);
    if (!indexFile || !tempIndexFile) {
        cerr << "Error opening index file." << endl;
        return;
    }

    int index;
    currentPosition = 0;
    while (indexFile.read(reinterpret_cast<char*>(&index), sizeof(index))) {
        if (currentPosition != position) {
            tempIndexFile.write(reinterpret_cast<char*>(&index), sizeof(index));
        }
        currentPosition++;
    }
    indexFile.close();
    tempIndexFile.close();

    remove(indexFilename);
    rename("tempindex.dat", indexFilename);

    cout << "Employee with ID " << id << " deleted successfully." << endl;
}

int main() {
    char choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Add Employee\n";
        cout << "2. Delete Employee\n";
        cout << "3. Display All Employees\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case '1': {
                Employee emp;
                emp.read();
                appendToFile("employees.dat", emp);
                break;
            }
            case '2': {
                int id;
                cout << "Enter Employee ID to delete: ";
                cin >> id;
                deleteEmployee("employees.dat", "index.dat", id);
                break;
            }
            case '3':
                displayAll("employees.dat");
                break;
            case '4':
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '4');

    return 0;
}

/*OUTPUT*/

/*ENTER CHOICE     
1.ADD AN EMPLOYEE
2.DISPLAY        
3.SEARCH
4.INCREASE SALARY
5.INSERT RECORD  
Make a choice: 1 
Enter employee code: 236
Enter name: rahul
Enter salary: 50000
Record added successfully.
Do you want to continue ? : y
ENTER CHOICE
1.ADD AN EMPLOYEE
2.DISPLAY
3.SEARCH
4.INCREASE SALARY
5.INSERT RECORD
Make a choice: 3
Enter employee code: 236
RECORD FOUND
236 RAHUL       50633
Do you want to continue ? : y
ENTER CHOICE
1.ADD AN EMPLOYEE
2.DISPLAY
3.SEARCH
4.INCREASE SALARY
5.INSERT RECORD
Make a choice: 4
enter employee code 
236
Salary hike? 10000
Salary updated successfully.
Do you want to continue ? :*/
