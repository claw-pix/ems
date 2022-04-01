#include <iostream>
#include <iomanip>
using namespace std;

// Base Class
template <class T>
class Employee{
public:
	int Id, age;
	string Name, Dept;

	// Display Function
	virtual void Display_List(Employee emp[], int n){
		int i;
		cout << "\n----------------------------\n Employee Details\n---------------------------\n";
		cout << setw(10) << "Id" << setw(10) << "Name" << setw(10) << "Age" << setw(15) << "Department" << endl;
		for (i = 0; i < n; i++){
			cout << setw(10) << emp[i].Id << setw(10) << emp[i].Name << setw(10) << emp[i].age << setw(10) << emp[i].Dept << endl;
		}
	}
	
	// Search Function
	void Search(Employee emp[], int n){
		int Id;
		bool flag = false;
		cout << "Enter Employee ID: ";
		cin >> Id;
		for (int i = 0; i < n; i++){
			if (emp[i].Id == Id){
				flag = true;
				cout << setw(10) << "Id" << setw(10) << "Name" << setw(10) << "Age" << setw(15) << "Department" << endl;
				cout << setw(10) << emp[i].Id << setw(10) << emp[i].Name << setw(10) << emp[i].age << setw(10) << emp[i].Dept << endl;
			}
		}
		if (flag == false){
			cout << "ID not exist" << endl;
		}
	}

	// Declaration of Employee Management and Department Management Functions
	virtual int Add_Employee(Employee emp[], int n){};
	virtual T Edit_Employee(Employee emp[], int n){};
	virtual int Delete_Employee(Employee emp[], int n){};
	virtual T Add_Dept(Employee emp[], int n){};
	virtual T Edit_Dept(Employee emp[], int n){};
	virtual int Delete_Dept(Employee emp[], int n){};
};

// Derived Class 1
template <class T>
class Employee_Management : public Employee<T>{
private:
	string Name;
	int age;

public:
	virtual int Add_Employee(Employee<int> emp[], int n){
		cout << "Enter Employee ID: ";
		cin >> emp[n].Id;
		for (int i = 0; i < n; i++){
			if (emp[i].Id == emp[n].Id){
				cout << "Data already exists!\n";
				return 0;
			}
		}
		cout << "Employee Name: ";
		cin >> emp[n].Name;
		cout << "Employee Age: ";
		cin >> emp[n].age;
		cout << endl;
		n++;
		return n;
	}
	virtual T Edit_Employee(Employee<int> emp[], int n){
		int Id;
		bool flag = false;
		cout << "Enter employee ID: ";
		cin >> Id;
		for (int i = 0; i < n; i++){
			if (emp[i].Id == Id){
				cout << "Employee Name: ";
				cin >> emp[i].Name;
				cout << "Employee Age: ";
				cin >> emp[i].age;
				flag = true;
			}
		}
		if (flag == false){
			cout << "Id Not found!" << endl;
		}
	}
	virtual int Delete_Employee(Employee<int> emp[], int n){
		int i, Id;
		bool flag = false;
		cout << "Enter employee ID: ";
		cin >> Id;
		for (i = 0; i < n; i++){
			if (emp[i].Id == Id){
				flag = true;
				break;
			}
		}
		if (i < n && flag == true){
			n = n - 1;
			for (int j = i; j < n; j++){
				emp[j] = emp[j + 1];
			}
		}
		else if (flag == false){
			cout << "ID does not exist" << endl;
		}
		return n;
	}
};

// Derived Class 2
template <class T>
class Department_Management : public Employee<T>
{
private:
	int Id, age;
	string Name[20], Dept[20];

public:
	virtual T Add_Dept(Employee<int> emp[], int n){
		int Id;
		bool flag = false;
		cout << "Enter Employee ID: ";
		cin >> Id;
		for (int i = 0; i < n; i++){
			if (emp[i].Id == Id){
				cout << "Enter Employee Department: ";
				cin >> emp[i].Dept;
				flag = true;
			}
		}
		if (flag == false){
			cout << "Id does not exist" << endl;
			return 0;
		}
	}
	virtual T Edit_Dept(Employee<int> emp[], int n){
		int Id;
		bool flag = false;
		cout << "Enter Employee ID: ";
		cin >> Id;
		for (int i = 0; i < n; i++){
			if (emp[i].Id == Id && !emp[i].Dept.empty()){
				cout << "Enter Employee Department: ";
				cin >> emp[i].Dept;
				cout << endl;
				flag = true;
			}
		}
		if (flag == false){
			cout << "Department does not exist" << endl;
			return 0;
		}
	}
	virtual int Delete_Dept(Employee<int> emp[], int n){
		int i, Id;
		bool flag = false;
		cout << "Enter Employee ID: ";
		cin >> Id;
		for (i = 0; i < n; i++){
			if (emp[i].Id == Id && !emp[i].Dept.empty()){
				flag = true;
				break;
			}
		}
		if (i < n && flag == true){
			n = n - 1;
			for (int j = i; j < n; j++){
				emp[j] = emp[j + 1];
			}
		}
		else if (flag == false){
			cout << "Department does not exist" << endl;
		}
		return n;
	}
};

// Driver Function
int main()
{
	Employee<int> emp[20];
	Employee<int> *e1 = new Employee<int>();
	int n = 0;
	int Option;
	do
	{
		cout << "\n----------------------------\nEmployee Management System\n---------------------------\n";
		cout << "1. Add Employee\n";
		cout << "2. Edit Employee\n";
		cout << "3. Delete Employee\n";
		cout << "4. Add Department\n";
		cout << "5. Edit Department\n";
		cout << "6. Delete Department\n";
		cout << "7. Display Employee Details\n";
		cout << "8. Search Employee\n";
		cout << "9. Exit\n\n";
		cout << "Enter Your Option: ";
		cin >> Option;
		switch (Option){
		case 1:
			e1 = new Employee_Management<int>();
			n = e1->Add_Employee(emp, n);
			break;
		case 2:
			e1 = new Employee_Management<int>();
			e1->Edit_Employee(emp, n);
			break;
		case 3:
			e1 = new Employee_Management<int>();
			n = e1->Delete_Employee(emp, n);
			break;
		case 4:
			e1 = new Department_Management<int>();
			e1->Add_Dept(emp, n);
			break;
		case 5:
			e1 = new Department_Management<int>();
			e1->Edit_Dept(emp, n);
			break;
		case 6:
			e1 = new Department_Management<int>();
			n = e1->Delete_Dept(emp, n);
			break;
		case 7:
			e1->Display_List(emp, n);
			break;
		case 8:
			e1->Search(emp, n);
			break;
		case 9:
			exit(0);
			break;
		default:
			cout << "Invalid choice... Please Enter again!" << endl;
		}
	} while (true);
	return 0;
}
