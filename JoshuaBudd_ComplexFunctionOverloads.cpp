//Joshua Budd      Lab4   This program performs various complex number calculations and is commented on by the programmer.
#include<iostream>
//#include<cmath>  // This library is needed because imports a set of functions to compute common mathematical operations and transformations
using namespace std;
class Complex
{
public:
	Complex();   //There are no parameters because this is the default constructor that accepts no arguments
	Complex(double); //There is one parameter this is the one-argument constructor that accepts 1 argument of type double
	Complex(double, double);//There are two parameters this is the full argument constructor that accepts 2 arguments of type double
	double get_Real();
	void set_Real(double);
	double get_Imaginary();
	void set_Imaginary(double);
	friend ostream& operator << (ostream& out, Complex& r); //friend function that overloads the << operator 
	friend istream& operator >> (istream& in, Complex& r);//friend function that overloads the >> operator
private:
	double real;
	double imaginary;
};

const Complex operator + (Complex& cl, Complex& c2); //Overloaded function of the + operator that adds the two passed-in arguments instance variables
const Complex operator - (Complex& c1, Complex& c2); //Overloaded function of the - operator that suntracts the two passed-in arguments instance variables
const Complex operator * (Complex& c1, Complex& c2); //Overloaded function of the * operator that multiplies the two passed-in arguments instance variables
const Complex operator / (Complex& c1, Complex& c2); //Overloaded function of the / operator that subtracts the two passed-in arguments instance variables
bool operator == (Complex& c1, Complex& c2); //Overloaded function of the == operator that test for equality for the two passed-in arguments instance variables

Complex::Complex() // Default constructor definition that sets real and imaginary variables to 0
{
	real = 0;
	imaginary = 0;
}

Complex::Complex(double r, double i) // Full argument constructor definition that sets real to the passed in argument r and sets imaginary to the passed in argument i
{
	real = r; 
	imaginary = i;
}
Complex::Complex(double realPart) // 1 argument constructor definition that sets real to the passed in argument realPart and imaginary variable to 0
{
	real=realPart;
	imaginary = 0;
}

double Complex::get_Real() //Get method of the Complex class that returns the value of the variable real
{
	return real;
}

void Complex::set_Real(double r) //set method of the Complex class that sets the variable real to the value of the passed in argument r
{
	real = r;
}

double Complex::get_Imaginary() //Get method of the Complex class that returns the value of the variable imaginary
{
	return imaginary;
}

void Complex::set_Imaginary(double i) //set method of the Complex class that sets the variable imaginary to the value of the passed in argument i
{
	imaginary = i;
}

const Complex operator + (Complex& c1, Complex& c2)  //Constant function that adds the instance variables of two different Complex objects and returns the results
{
	double a = c1.get_Real() + c2.get_Real();
	double b = c1.get_Imaginary() + c2.get_Imaginary();
	return Complex(a,b);
}

const Complex operator - (Complex& c1, Complex& c2) //Constant function that subtracts the instance variables of two different Complex objects and returns the results
{
	double a = c1.get_Real() - c2.get_Real();
	double b = c1.get_Imaginary () - c2.get_Imaginary() ;
	return Complex(a,b);
}

const Complex operator * (Complex& c1, Complex& c2) //Constant function that multiplies the instance variables of two different Complex objects and returns the results
{
	double a = (c1.get_Real() * c2.get_Real()) - (c1.get_Imaginary() * c2.get_Imaginary());
	double b = (c1.get_Real() * c2.get_Imaginary()) + (c1.get_Imaginary() * c2.get_Real());
	return Complex(a,b);
}

const Complex operator / (Complex& c1, Complex& c2) //Constant function hat multiplies the instance variables of two different Complex objects and returns the results
{
	double b = c1.get_Imaginary() * c2.get_Real();
	double a = c1.get_Real() * c2.get_Imaginary();
	return Complex(a,b);
}

bool operator == (Complex& c1, Complex& c2) //function used to test the instance variables of two Complex objects and returns true if both have the same instance variables, returns false otherwise
{
	if ( c1.get_Real() == c2.get_Real() && c1.get_Imaginary() == c2.get_Imaginary() )
		return true;
	else
		return false;
}

ostream& operator << (ostream& out, Complex& r) //Friend function of the class Complex that tests various conditions of the passed in argument Complex r
{
	double a = r.get_Real();
	double b = r.get_Imaginary() ;

	if (a != 0)out << a;

	if (b < 0) out << "-" << abs(b) << "i";
	if (b > 0 && b!=1 ) out << "+" << b << "i";
	if ( b ==0) out << "0";
	if (b == 1 && a != 0 ) out << "+" << "i";
	if ( b == 1 && a == 0) out << "i";
	return out;
}

istream& operator >> (istream& in, Complex& r) //Friend function of the class Complex that test various conditions of the passed in argument Complex r 
{
	double a,b;
	char plus, i;
	in >> a;
	in >> plus;
	in >> b;
	in >> i;
	if ( plus != '+' && plus != '-' )
	{
		cout << "No plus or minus found " << endl;
	}
	if ( i != 'i')
	{
		cout << "no i found " << endl;
	}
	r.set_Real(a);
	r.set_Imaginary(b);
	return in;
}

void main()
{
	const Complex i(0,1);
	Complex c1;
	Complex c2;

	cout << "Enter complex 1 in ths format ---> #+#i " << endl;
	cin >> c1;
	cout << "Enter complex2" << endl;
	cin >> c2;

	cout << "\t c1 is: " << c1 << "\t c2 is:  " << c2 << endl << endl;
	cout << "Adding " << c1 << " plus " << c2 << endl;

	Complex t = c1 + c2;
	cout << c1 << " plus" << endl << c2 << endl << "equals \t" << t << endl << endl;

	cout << "Subtracting " << c1 << " minus " << c2 << endl;
	t = c1 - c2;
	cout << c1 << " minus" << endl << c2 << endl << "equals \t" << t << endl << endl;

	cout << "Multiplying " << c1 << " times " << c2 << endl;
	t = c1*c2;
	cout << c1 << " times" << endl << c2 << endl << "equals \t" << t << endl << endl;

	cout << "Evaluating ..." << endl;
	if ( c2 == c1) 
		cout << "They are equal" << endl;
	else
		cout << "They are not equal" << endl;

	return;
}

