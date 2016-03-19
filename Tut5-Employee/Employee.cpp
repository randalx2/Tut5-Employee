/*Praneel Misthry
202515355
Computer Methods 3
Tut5-Employee
18 March 2016****************************************************************************************/

#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <ctime>

#include "Employee.h"

using namespace std;

//First Initialize the static variable OUTSIDE THE CLASS DECLARATION

int Employee::numberOfEmployees = 0;   //DON'T SPECIFY THE STATIC KEYWORD HERE
                                      //ONLY USE STATIC IN THE DECLARATION. Static variables are only
                                     //initialized once.
                                   //Can access static variable of class scope outside class without creating any object


Employee::Employee(){
	//For this eg its best to keep abstract class constructor blank
	//As the sub class constructors are meant to override it
	//Incrementing the numberofEmployees static variable was doubling here since this
	//was called as well besides the overriding constructors of the sub classes
}

/*Employee::Employee(string iname, int inumber){

	nameOfEmployee = iname;
	if (inumber >= 0)
	{
		employeeNumber = inumber;
	}
	else
	{
		cout << "Invalid Staff Number Input. Try again" << endl;
		cin >> employeeNumber;
	}
	numberOfEmployees++;
	salaryOfEmployee = 0.00;
}*/                                //Don't use overloading constructor of abstract class --> messes up employee count

Employee::~Employee(){
	numberOfEmployees--; //Employee lost when an object is destroyed
	                     //Can't keep this blank as a loss of ANY employee is counted
} 

//No Need to develop bodies for pure virtual functions in abstract base class
//Instead define their overriding functions in the sub classes

SalaryEmployee::SalaryEmployee(){

	nameOfEmployee = "Monthly";
	employeeNumber = 0;
	numberOfEmployees++;
	salaryOfEmployee = 0.00;
}

SalaryEmployee::SalaryEmployee(string iname, int inumber)
{
	nameOfEmployee = iname;

	if (inumber >= 0){
		employeeNumber = inumber;
	}
	else
	{
		cout << "Invalid Staff Number input. Ensure a positive number now" << endl;
		cin >> employeeNumber;
	}
	
	numberOfEmployees++;
	salaryOfEmployee = 0.00;
}

SalaryEmployee::~SalaryEmployee(){
	numberOfEmployees--;
}

float SalaryEmployee::setSalary(const float iSalary){
	monthlySalary = iSalary;
	return monthlySalary;
}

float SalaryEmployee::salary(){
	return monthlySalary;
}

string SalaryEmployee::name(){
	return nameOfEmployee;
}

int SalaryEmployee::staffNumber(){
	return employeeNumber;
}

HourlyEmployee::HourlyEmployee(){
	nameOfEmployee = "Hourly";
	employeeNumber = 0;
	numberOfEmployees++;
	salaryOfEmployee = 0.00;
}

HourlyEmployee::HourlyEmployee(string iname, int inumber)
{
	nameOfEmployee = iname;

	if (inumber >= 0){
		employeeNumber = inumber;
	}
	else
	{
		cout << "Invalid Staff Number input. Ensure a positive number now" << endl;
		cin >> employeeNumber;
	}

	numberOfEmployees++;
	salaryOfEmployee = 0.00;
}

HourlyEmployee::~HourlyEmployee()
{
	numberOfEmployees--;
}

float HourlyEmployee::setHourlyRate(float ihourlySalary)
{
	hourlySalary = ihourlySalary;
	return hourlySalary;
}

int HourlyEmployee::setHoursWorked(int ihours)
{
	hoursWorked = ihours;
	return hoursWorked;
}

float HourlyEmployee::salary()
{
	salaryOfEmployee = hourlySalary*hoursWorked;
	return salaryOfEmployee;
}

string HourlyEmployee::name()
{
	return nameOfEmployee;
}

int HourlyEmployee::staffNumber()
{
	return employeeNumber;
}

CommissionEmployee::CommissionEmployee()
{
	nameOfEmployee = "Commission";
	employeeNumber = 0;
	numberOfEmployees++;
	salaryOfEmployee = 0.00;
}

CommissionEmployee::CommissionEmployee(string iname, int inumber)
{
	nameOfEmployee = iname;

	if (inumber >= 0){
		employeeNumber = inumber;
	}
	else
	{
		cout << "Invalid Staff Number input. Ensure a positive number now" << endl;
		cin >> employeeNumber;
	}

	numberOfEmployees++;
	salaryOfEmployee = 0.00;
}

CommissionEmployee::~CommissionEmployee(){
	numberOfEmployees--;
}

float CommissionEmployee::setBaseSalary(float ibase)
{
	baseSalary = ibase;
	return baseSalary;
}

float CommissionEmployee::setRate(float irate)
{
	commRate = irate; //NB Send a decimal percentage value
	return commRate;
}

float CommissionEmployee::setRevenue(float irev)
{
	revGenerated = irev;   
	return revGenerated;
}

float CommissionEmployee::salary()
{
	salaryOfEmployee = baseSalary + commRate*revGenerated;
	return salaryOfEmployee;
}

string CommissionEmployee::name()
{
	return nameOfEmployee;
}

int CommissionEmployee::staffNumber()
{
	return employeeNumber;
}