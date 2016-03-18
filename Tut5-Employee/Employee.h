#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>

using namespace std;

class Employee {
protected: 

		   string nameOfEmployee;  //Employee name -- to be set by constructor
		   float salaryOfEmployee;   //Salary of employee by month end
		   int employeeNumber;  //Number assinged to each employee -- to be set by constructor

public: 
	    static int numberOfEmployees;  //Only one copy available to keep track of number of employees--Better to make public
		                               //since we didn't make an accessor function for this attribute according to specs
	    //Employee();                    
		//Employee(string, int);
		//~Employee();

		//Pure Virtual Functions for Abstract Class
	    virtual string name() = 0;
		virtual int staffNumber() = 0;  //Returns staff number of employee --POSITIVE INTEGER
		virtual float salary() = 0;    //Returns amount of money PAID AT MONTH END
};

class SalaryEmployee : public Employee{
private: float monthlySalary; //FIXED MONTHLY SALARY
public:
	SalaryEmployee();
	SalaryEmployee(string, int);
	~SalaryEmployee();

	//Methods for this subclass
	float setSalary(const float);  //Set employees FIXED monthly salary -- can also be used to override Abstract class value

	//Overriding Functions
	float salary();    //Overide the monthly salary based on employees unique profile
	string name();
	int staffNumber();
};

class HourlyEmployee :public Employee{
private: float hourlySalary;
		 int hoursWorked;

public: HourlyEmployee();
		HourlyEmployee(string, int);
		~HourlyEmployee();

		//Methods for this sub class
	    float setHourlyRate(float);  //Returns hourly rate
		int setHoursWorked(int);   //Returns hours worked

		//Overriding functions
		float salary();       //Overide the monthly salary based on employees unique profile
		string name();
		int staffNumber();	
};

class CommissionEmployee : public Employee{
private: float baseSalary;   
		 float commRate;     
		 float revGenerated;  

public: CommissionEmployee();
		CommissionEmployee(string, int);
		~CommissionEmployee();

		//Methods for this sub class
		float setBaseSalary(float);  //Set the basic
		float setRate(float);        // Set the commission
		float setRevenue(float);       // Set revenue

		//Overriding functions
		float salary();       //Overide the monthly salary based on employees unique profile
		string name();
		int staffNumber();
};

#endif