#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>

using namespace std;

class Employee {
protected: static int numberOfEmployees;  //Only one copy available to keep track of employee number
		   string nameOfEmployee;
		   int salary;

public: Employee();
		Employee(string, int, int);

	    virtual string name() = 0;
		virtual int staffNumber() = 0;
		virtual float salary() = 0;
};

class SalaryEmployee : public Employee{
private: float monthlySalary;
public:
	SalaryEmployee();
	SalaryEmployee(string, int, int);
	~SalaryEmployee();

	//Methods for this subclass
	float setSalary();

	//Overriding Functions
	float salary();
	string name();
	int staffNumber();
};

class HourlyEmployee :public Employee{
private: float hourlySalary;
		 int hoursWorked;

public: HourlyEmployee();
		HourlyEmployee(string, int, int);
		~HourlyEmployee();

		//Methods for this sub class
	    float setHourlyRate();
		int setHoursWorked();

		//Overriding functions
		float salary();
		string name();
		int staffNumber();	
};

class CommissionEmployee : public Employee{
private: float baseSalary;
		 float commRate;
		 float revGenerated;

public: CommissionEmployee();
		CommissionEmployee(string, int, int);
		~CommissionEmployee();

		//Methods for this sub class
		float setBaseSalary();
		float setRate();
		float setRevenue;

		//Overriding functions
		float salary();
		string name();
		int staffNumber();
};

#endif