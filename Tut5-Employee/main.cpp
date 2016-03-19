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

int main()
{
	float totalSalary;

	//Creating objects of each of the subclasses
	//Using Dynamic Memory so we can remove objects as we desire to demonstrate employee count

	SalaryEmployee *s1 = new SalaryEmployee("Praneel", 202515355);
	HourlyEmployee *h1 = new HourlyEmployee("Salesh", 200600366);
	CommissionEmployee *c1 = new CommissionEmployee("Riana", 203400666);

	//Check if the number of employees are correct
	//NB when created objects using the pointer method and DMA
	//you can only use the pointer arrow method to access its members

	cout << s1->name() << " is a monthly employee with no: " << s1->staffNumber() << endl;
	cout << h1->name() << " is a hourly employee with no: " << h1->staffNumber() << endl;
	cout << c1->name() << " is a commission employee with no: " << c1->staffNumber() << endl;

	cout << "Number of Employees is " << Employee::numberOfEmployees << endl;  //Note how the static member is used
	                                                                           //without needing an object

	//To demonstrate polymorphism create a pointer array of the abstract class type
	//Cannot create objects of an abstract class but we can create pointers and pointer arrays of its type

	Employee *empPtr[3];  //NB Cannot create dynamic arrays of the abstract class but can use polymorphism for eg
	                      // Employee *empPtr = New SalaryEmployee[3] is an eg of polymorphism but.....
	                      //..Employee *empPtr = New Employee[3] is NOT ALLOWED due to Abstract class pure vfs

	//Set wages of the 3 employees
	s1->setSalary(12000.50);
	

	h1->setHourlyRate(350.50);
	h1->setHoursWorked(48);

	c1->setBaseSalary(8000.50);
	c1->setRate(0.71);
	c1->setRevenue(16000.80);

	//Fill out array with sub class objects
	empPtr[0] = s1; //Abstract pointer array and objects were created using the pointer method
	empPtr[1] = h1;  //So no need to pass the sub class objects by reference to the abstract pointer array
	empPtr[2] = c1; //Can pass directly in this case

	//Display salary
	//Polymorphism demonstrated
	cout << endl;
	cout << s1->name() << " monthly salary is " << empPtr[0]->salary() << endl;
	cout << h1->name() << " monthly salary is " << empPtr[1]->salary() << endl;
	cout << c1->name() << " monthly salary is " << empPtr[2]->salary() << endl;
	cout << endl;

	//Get the total monthly salary

	totalSalary = empPtr[0]->salary() + empPtr[1]->salary() + empPtr[2]->salary();
	cout << "Total Salary for All Employees is: " << totalSalary << endl;

	//Demonstrating employee count downwards if object is destroyed
	//Polymorphism demonstrated
	for (int i = 0; i < 3; i++)
	{
		cout << endl;
		cout << "Firing " <<  empPtr[i]->name() << endl;
		delete empPtr[i];  //Can delete directly instead of reference since both sub class objects
		                   //and abstract pointer array were created using the pointer method
		cout << "Employee count: " << Employee::numberOfEmployees << endl;
	}

	system("PAUSE");
	return 0;
}