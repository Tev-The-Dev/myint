#include <iostream>

#include "myint.h"

using namespace std;

MyInt Fibonnaci(MyInt num);

int main()
{
	// cout << "going to the integer constructor" << endl;
	//MyInt x(12345), y("9876543210123456789"), r1(-1000), r2 = "14H67", r3;	
	//cout << " y is " << y << endl;
	//cout << " x is " << x << endl;

	//cout << " r1 is " << r1 << endl;
	//cout << " r2 is " << r2 << endl;
	//cout << " r3 is " << r3 << endl;
	//cout << "Changing the value of r1" << endl;
	
/*
 
 	MyInt r1;
	//cin >> r1 ;
	MyInt x, y;
	char ch; 
	cin >> x >> y >> ch; 
	
	cout << "x is: "<< x << "y is: " << y << "ch is: " << ch << endl;  

	// cout << " r1 is " << r1 << endl;
*/


	cout << endl;
	cout << endl;

	// MyInt r1(99), r2(3), r3(5032);
	// MyInt r1(252), r2(248), r3(5032);
	MyInt x(89), y(112), r3;
	cout << "x is " << x << " and y is " << y << endl;
	r3 = x * y;

	cout << "In driver.cpp, r3 = " << r3 << endl;


	return 0;	
}
