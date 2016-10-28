#include "Rational.hpp"
#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

int main() {
	Rational a;
	Rational b;

	cout << "Please enter a rational number (example 2/3): " << endl;
	while (true) {
		try {
			cin >> a;
			break;
		}
		catch (exception& ex) {
			cout << "Invalid rational: " << ex.what() << endl;
		}
	}//end while
	cout << "Please enter another rational number (example 2/3): " << endl;
	while (true) {
		try {
			cin >> b;
			break;
		}
		catch (exception& ex) {
			cout << "Invalid rational: " << ex.what() << endl;
		}
	}//end while

	cout << a << " + " << b << " = " << a + b << endl;
	cout << a << " - " << b << " = " << a - b << endl;
	cout << a << " * " << b << " = " << a * b << endl;

	cout << a << " / " << b << " = ";
	try {
		cout << a / b << endl;
	}
	catch (...)
	{
		cout << "NaN" << endl;
	}

	cout << a << " < " << b << ": ";
	if (a < b) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}

	cout << a << " > " << b << ": ";
	if (a > b) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}

	cout << a << " == " << b << ": ";
	if (a == b) {
		cout << "true" << endl;
	}
	else
		cout << "false" << endl;

	_getch();


	return 0;
}