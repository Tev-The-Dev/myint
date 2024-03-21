/*
	Tevyn Payne
	COP 3330 Section 007
  Homework 5	
 	My objective for this assignment is to create a class that can take in an integer of any size.
	The current int can only hold up to a certain amount of space. I am to create a class object that
	will allow the integer to be of any size.
*/
#include <iostream>

using namespace std;
int C2I(char c); 
char I2C(int); 

class MyInt
{
	// these overload starters are declared as friend functions
	friend MyInt operator+ (const MyInt& x, const MyInt& y);
	friend MyInt operator* (const MyInt& x, const MyInt& y);
	//add in multiplication, as well
 
	// add in the other comparison overloads, as well
   
	// declare overloads for input and output (MUST be non-member functions)
	//  you may make them friends of the class
   
	friend istream& operator >> (istream& a, MyInt& e);
	friend ostream& operator<< (ostream& a, const MyInt& e);
	friend bool operator< (const MyInt&, const MyInt&);
	friend bool operator> (const MyInt&, const MyInt&);
	friend bool operator<= (const MyInt&, const MyInt&);
	friend bool operator>= (const MyInt&, const MyInt&);
	friend bool operator== (const MyInt&, const MyInt&);
	friend bool operator!= (const MyInt&, const MyInt&);
	public:
		MyInt(int n = 0);		// first constructor
		MyInt(const char * n);
		~MyInt();
		MyInt(const MyInt & steven);		// copy constructor
		MyInt& operator= (const MyInt &);	// assignment operator
	// be sure to add in the second constructor, and the user-defined 
	//  versions of destructor, copy constructor, and assignment operator
	MyInt& operator++();	// prefix increment
	MyInt operator++(int);	// postfix increment
	MyInt& operator--();	// prefix decrement	
	MyInt operator--(int);	// postfix decrement 
	
	void print_array(const MyInt&); //testing the prints of the object
	void print_universe(const int*, int)const; //testing the prints of the object

	private:
	// member data (suggested:  use a dynamic array to store the digits)
		int * padded(int)const;
		int U2I(MyInt&);
		int * universe;
		int counter, size, value, digit;
		//string infinite; 
   };
