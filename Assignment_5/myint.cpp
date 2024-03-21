/*
 Tevyn Payne
 COP 3330 Section 007
Homework 5
 My objective for this assignment is to create a class that can take in an integer of any size.
The current int can only hold up to a certain amount of space. I am to create a class object that
will allow the integer to be of any size.
 */

#include <iostream>
#include "myint.h"
#include <cstring>

using namespace std;


ostream& operator << (ostream& a, const MyInt& e)
{

	//cout << "e.size is " << e.size << endl;
	for(int i = 0; i < e.size; i++)
	{
		a << e.universe[i];	
	}

	return a;

}

istream& operator >> (istream& a, MyInt& e)
{	


	char *digits;
	int len = 0;
	char c;
	char * temp;

	a >> c;
	while(isdigit(c))
	{	
		
		len += 1;
		temp = new char [len];
		for (int i = 0; i < len-1; i++)
		{	
			temp[i] = digits[i];
		}
		
		temp[len -1]= c;	
		digits = temp;

		a>>noskipws>>c;
	}
	a >> skipws;
	a.putback(c);
	

	e.universe = new int [len];
	for(int j= 0; j < len; j++)
	{
		e.universe[j] = C2I(digits[j]);
	}
		
	e.size = len;

	return a;

}


MyInt operator+ (const MyInt& x, const MyInt& y)
{
	MyInt lhs, rhs;

	int *new_lhs;
	int * result;

	if(x.size != y.size)
	{
		if(x < y)
		{
			lhs = x;
			rhs = y;
		}
		else
		{
			lhs = y;
			rhs = x;
		}

		new_lhs = new int[rhs.size];  // new "universe"

		for(int i = 0; i < rhs.size; i++)
		{
			new_lhs[i] = 0;
		}

		for(int j = 0; j < lhs.size; j++) 
		{
			new_lhs[rhs.size-j-1] = lhs.universe[lhs.size-j-1];
		}

	}
	else
	{
		new_lhs = x.universe;
		rhs = y;
	}


	result = new int[rhs.size + 1];
	for(int i = 0; i < rhs.size+1; i++)
		result[i] = 0;

	int overflow = 0;

	for(int m = rhs.size - 1; m >= 0; m--)
	{
		int sum = rhs.universe[m] + new_lhs[m] + overflow;
		int digit = sum % 10;
		result[m+1] = digit ;
		overflow = sum/10;
	}
	result[0] += overflow;


	// convert result[] to an MyInt
	char * result_as_str = new char[rhs.size+1];

	if ( result[0] == 0 ) 
	{
		for (int i=1; i < rhs.size+1; i++ )
		{
			result_as_str[i-1] = I2C( result[i] );
		}
	}

	 else
	{
		for (int i=0; i < rhs.size+1; i++ ) 
			result_as_str[i] = I2C( result[i] );
	}

	MyInt return_me(result_as_str);
	return return_me;

}

MyInt operator* (const MyInt& x, const MyInt& y)
{

	int* lhs;
	int* rhs;
	int new_size = x.size + y.size;

	lhs = x.padded(new_size);
	rhs = y.padded(new_size);
			

	int * new_universe;
	new_universe = new int [new_size];

	for(int i = 0; i < new_size; i++)
		new_universe[i] = 0;
	
	int k = 0;
	int overflow = 0;
	int addition_overflow = 0;

	for(int i = new_size -1; i >= 0;i--)
	{
		k = i;
		for(int j = new_size -1; j >= 0;j--)
		{

			int product = lhs[j] * rhs[i];

			
			int digit = (product + overflow)  % 10 ;

			overflow = product / 10;

			int old_digit = new_universe[k];

			new_universe[k] += digit + addition_overflow;	


			if ( new_universe[k] > 9 ) 
			{
				int addition_digit = new_universe[k] % 10;
				addition_overflow = new_universe[k] / 10;
	
				new_universe[k] = addition_digit;

			}
			k = k -1;
			if(k < 0)
				break;
		}

	} 

	
	char * result_as_str = new char[new_size];

	int start_pos = new_size-1;
	for ( int j=0; j < new_size; j++ ) 
	{
		if ( new_universe[j] != 0 )
		{
			start_pos = j;
			break;
		}
	}


	// when you get here, start_pos == first non zero digit in new_universe

	for (int i=0; i + start_pos < new_size; i++ ) 
	{
		result_as_str[i] = I2C( new_universe[start_pos + i] );
	}


	MyInt sval(result_as_str);
	return sval;

}

MyInt& MyInt::operator++()    // prefix increment
{
	MyInt rhs(1);
	*this = *this + rhs;
	return *this;
}
MyInt MyInt::operator++(int x)  // postfix increment
{
	MyInt rhs(1),temp;
	temp = *this;
	*this = *this + rhs;
	return temp;;
}

MyInt::MyInt(int n)
{

	if(n <= 0)
	{
		counter = 0;
		size = 1;
		universe = new int[size];
		universe[0] = 0;
	}
	//change the incoming number to a 1 digit in through or loop and store 
	//individually butbackwards
	else
	{
	value = n;
	 	digit = 0;
		size = 0;
		counter = 0;
		do
		{
			digit = value % 10;
			value /= 10;

			size +=  1;
		}while(value!=0);

		universe = new int[size];
		
		value = n;
		

		for(int k = size -1; k >= 0; k--)
		{
			digit = value % 10;
			value /= 10;
			universe[k] = digit;
		}
	}
}

MyInt::MyInt(const char * n)
{

	char cset[] = "1234567890";

	if(n == NULL || (strspn(n,cset)!= strlen(n)) )
	{
		counter = 0;
		size = 1;
		universe = new int[size];
		universe[0] = 0;
	}
	else
	{
		counter = 0;
		size = strlen(n);
		universe = new int[size];

		for(int i = 0; i < size; i++)
		{
			universe[i] = C2I(n[i]);
		}
	}

}

MyInt::~MyInt()
{
	delete [] universe;

}

MyInt::MyInt(const MyInt & steven)
{

	size = steven.size;
	for(int i = 0; i < size; i++)
		universe[i] = steven.universe[i]; 
}

MyInt& MyInt::operator= (const MyInt & D)
{
// assignment operator (a member function)
// does a similar task to that of the copy constructor
//  but is not a new object, so must delete any existing allocation
//  and must return the assigned value (i.e. this object, *this)

	if (this != &D)		// only make the copy if the original is
	{				//  not this same object

		// first, delete the existing array
		delete [] universe;

	// now do the copy.  Same way we did copy constructor
		size = D.size;
		universe = new int[size];
		for (int i = 0; i < size; i++)
			universe[i] = D.universe[i];
	}

	return *this;		// return this object
	

}

bool operator< (const MyInt& a, const MyInt& b)
{

	if(a.size != b.size)
	{
		if(a.size < b.size)
			return true;
		return false;
	}

	for(int k = 0; k < a.size; k++)
	{
		if(a.size != b.size)
		{
			if(a.universe[k] < b.universe[k])
				return true;
			return false;
		}
	}
	return false;

}

bool operator> (const MyInt& a, const MyInt& b)
{
	if(a < b)
		return false;
	if(a == b) 
		return false;
	return true;
}

bool operator<= (const MyInt& a, const MyInt& b)
{
	if(a < b)
		return true;
	if(a == b)
		return true;
	return false;

}

bool operator>= (const MyInt& a, const MyInt& b)
{
	if(a > b)
		return true;
	if(a == b) 
		return true;
	return false;
}

bool operator== (const MyInt& a, const MyInt& b)
{
	if(a.size != b.size)
		return false;
	for(int i = 0; i < a.size; i++)
		if(a.universe[i] != b.universe[i])
			return false;
	return true;	
}

bool operator!= (const MyInt& a, const MyInt& b)
{
	if(a == b)
		return false;
	return true;
}


int C2I(char c)
// converts character into integer (returns -1 for error)
	{
		if (c < '0' || c > '9')	return -1;	// error
			return (c - '0');				// success
	}

char I2C(int x)
	// converts single digit integer into character (returns '\0' for error)
	{
		if (x < 0 || x > 9)		return '\0';	// error
			return (static_cast<char>(x) + '0'); 	// success
	}

	// Add in operator overload and member function definitions 

int MyInt::U2I(MyInt& s)
{
	int val = 0;
	for(int i = 0; i < s.size; i++)
	{
		val += s.universe[i];
		val *= 10;
	}
	val /= 10;

	return val;
}


int * MyInt::padded(int len)const
{
	if ( len < this->size ) {
		// logic ERROR, should never happen
	}


	int * return_me = new int[len];
	for(int i = 0; i < len; i++)
		return_me[i] = 0;	

	for(int j = 0; j < this->size; j++)
		return_me[len-j- 1] = this->universe[this->size - j-1];
	
	return(return_me);

}

