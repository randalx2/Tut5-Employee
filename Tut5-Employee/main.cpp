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
	//Creating objects of each of the subclasses
	//Using Dynamic Memory so we can remove objects as we desire to demonstrate employee count

	SalaryEmployee *s1 = new SalaryEmployee("Praneel", 202515355);
	HourlyEmployee *h1 = new HourlyEmployee("Salesh", 200600366);
	CommissionEmployee *c1 = new CommissionEmployee("Riana", 203400666);

	//Check if the number of employees are correct

	cout << s1->name() << " is a monthly employee with no: " << s1->staffNumber() << endl;
	cout << h1->name() << "is a hourly employee with no: " << h1->staffNumber() << endl;
	cout << c1->name() << "is a commission employee with no: " << c1->staffNumber() << endl;

	cout << "Number of Employees is " << Employee::numberOfEmployees << endl;



	system("PAUSE");
	return 0;
}