#include <iostream>
using namespace std;

class Employee {
protected:
	int ID;
	string name, email;

public:
	Employee(string n, int id, string e) : name(n), ID(id), email(e) {}

	virtual ~Employee() {
		cout << "[Destructor] cleaning up an employee " << name << endl;
	}

	virtual void displayInfo() {
		cout << "Employee Name: " << name << endl;
		cout << "Employee ID: " << ID << endl;
		cout << "Employee Email: " << email << endl;
	}

	virtual double calculatePay() = 0;
	virtual string getEmployeeType() = 0;
};

class FullTimeEmployee : public Employee {
private:
	int monthlySalary;

public:
	FullTimeEmployee(string n, int id, string e, int salary) : Employee(n, id, e), monthlySalary(salary) {}

	double calculatePay() {
		return monthlySalary;
	}

	string getEmployeeType() {
		return "Full-Time";
	}

	void displayInfo() override {
		Employee::displayInfo();
		cout << "Employee Type: " << getEmployeeType() << endl;
	}
};

class PartTimeEmployee : public Employee {
private:
	double hourlyRate, hoursWorked;

public:
	PartTimeEmployee(string n, int id, string e, double rate, double work) : Employee(n, id, e), hourlyRate(rate), hoursWorked(work) {}

	double calculatePay() {
		return hourlyRate * hoursWorked;
	}

	string getEmployeeType() {
		return "Part-Time";
	}

	void displayInfo() override {
		Employee::displayInfo();
		cout << "Employee Type: " << getEmployeeType() << endl;
		cout << "Hours Rate: " << hourlyRate << endl;
		cout << "Hours worked: " << hoursWorked << endl;
	}
};

class Contractor : public Employee {
private:
	int projectFee;

public:
	Contractor(string n, int id, string e, int fee) : Employee(n, id, e), projectFee(fee) {}

	double calculatePay() {
		return projectFee;
	}

	string getEmployeeType() {
		return "Contractor";
	}

	void displayInfo() override {
		Employee::displayInfo();
		cout << "Employee Type: " << getEmployeeType() << endl;
	}
};

void displayPayrollReport(Employee* em, int n) {
	cout << "________________________________" << endl;
	cout << endl;
	cout << "Employee #" << n << endl;
	em->displayInfo();

	double pay = em->calculatePay();
	cout << "Monthly Pay: $" << pay << endl;
}

void summary(int num, double total) {
	cout << endl;
	cout << "Payroll Summary" << endl;
	cout << "========================================\n";
	cout << "ToTal Employees: " << num << endl;
	cout << "ToTal Monthly Payroll: " << total << endl;
	cout << "Average Pay per Employee: " << total / num << endl;
	cout << endl;
	cout << endl;
}

int main() {
	const int employee_num = 3;
	Employee* emp[employee_num];
	emp[0] = new FullTimeEmployee("Ahmed Samir", 1111, "ahmed123flash@gmail.com", 5000);
	emp[1] = new PartTimeEmployee("Mahmoud Samir", 2222, "mm235u@er.cok", 50.0, 80);
	emp[2] = new Contractor("Noha Samir", 3333, "nohaiiu@hght.gok", 4000);

	double totalPay = 0;

	for (int i = 0; i < employee_num; i++) {
		displayPayrollReport(emp[i], i + 1);
		totalPay += emp[i]->calculatePay();
	}

	summary(employee_num, totalPay);

	cout << "EMPLOYEE TYPE BREAKDOWN: " << endl;
	cout << "========================================\n";
	for (int i = 0; i < employee_num; i++) {
		cout << emp[i]->getEmployeeType() << ": $";
		cout << emp[i]->calculatePay() << endl;
	}
	cout << endl;

	cout << "Cleaning Process" << endl;
	for (int i = 0; i < employee_num; i++) {
		delete emp[i];
	}
	cout << endl;
	cout << "All Resorcess Cleaned" << endl;
	return 0;
}
