//         Course: CS2400-01 Computer Science II
//           Name: Ortiz, Matthew
//     Assignment: P9
//  Date assigned: 4/08/19
//       Date due: 4/17/19
// Date handed in: 4/17/19
//         Remark: 

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string.h>
using namespace std;
ifstream in_stream;
ofstream out_stream;

class rational
{	
	friend istream& operator>>(istream &in, rational &r);
	// The user is prompted to enter two integer values for the numerator and denominator of a rational number
	// Postcondition: the calling rational object is assigned with values entered by the user

	friend ostream& operator<<(ostream &out, rational &r);
	// Postcondition: The rational object referenced by r is display as “a / b”, e.g., 1 / 2,  -5 /9 (not 5 / -9), 1 / 4 (not 2 / 8, etc.).
	
	friend ofstream& operator<<(ofstream &out, rational &r);
	
	friend int operator>>(ifstream &fin, rational r[]);

public:
	rational();
	// Postcondition:	declared rational number is initialized to 0 / 1.
	
	rational(int num, int denom);
	// Postcondition:	declared rational number is initialized to aa / bb.

	void set(int num, int denom);
	// Postcondition: the calling rational object is set to aa / bb.		

	rational operator-(const rational &r2) const;
	// Postcondition: returns the difference of subtracting r2 from the calling rational object.

	bool operator>(const rational&r2) const;
	// Postcondition: returns 1 if the calling object is greater than r2; 0 if it is equal to r2; -1 is it is less than r2 

	rational subtract(const rational &r2) const;
	// Version 1 of the subtract function
	// Postcondition: difference of the calling object (*this) - r2 is returned
	
	void setBoth();
	
	int numerator, denominator;

private:
	int GCD(int num, int denom) const;
	// A helper member function. You must use the Euclidean algorithm. https://en.wikipedia.org/wiki/Euclidean_algorithm
	// Postcondition: returns the "greatest common divisor" between the numerator and denominator of the calling rational object

	int num;	// numerator part of a rational number a / b
	int denom;	// denominator part of a rational number a / b

	};

	int operator>>(ifstream &fin, rational r[]);
	// Precondition: 1) user must prepare and name an input data file stored on disk to be read by the main() function
	//	             2) The "cleint" of the class (main function writer) must declare and specify the size of the rational array  
	// Postcondition: rational array r[] is filled with n rational numbers read from a disk file where n <= SIZE
	
	void writeToDisk(rational r[], int n);
	// Precondition: n <= SIZE, the size or capacity of the rational array where SIZE is specified in the main() function

	//ofstream& operator<<(ofstream &out, rational &r);
	// Postcondition: The rational object referenced by r is written to an output disk file name "sorted.txt" one rational number per line


int main( ) {

	//const int SIZE = 10;
	//rational r[SIZE];
	int n;
	cout << "You may enter up to 10 rational numbers to be sorted. How many?: ";
	cin >> n;

	rational r[n];

    if (in_stream.fail( ))
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }

    char x[16];
	cout << "Load array with rational numbers from a disk file..." << endl;
	cout << "Enter the name of the input data file with no embedded space: ";
	cin >> x;

	if(strcmp(x, "inputData.txt") != 0) {
		cout << "*** Data file named '" << x << "' cannot be found! Program is terminated!" << endl;
		exit(1); 

	}
	

	in_stream.open(x);
	cout << "Disk file successfully opened and reading the the file begins.." << endl;
 	writeToDisk(r, n);


    out_stream.open("sorted.txt");
    if (out_stream.fail( ))
    {
        cout << "Output file opening failed.\n";
        exit(1);
    }

    //in_stream >> array;

    //out_stream << sortedArray;

    in_stream.close( );
    out_stream.close( );

    return 0;
}

rational::rational() {
    num = 0;
    denom = 1;
}

bool rational::operator>(const rational &obj) const{

	rational diff = *this - obj;

	if (static_cast<double>(diff.num) / static_cast<double>(diff.denom) > 0)
		return true;
	else
		return false;

}	

rational rational::operator-(const rational &r2) const {

	rational diff;	

	diff.num = num * r2.denom - r2.num * denom;
	diff.denom = denom * r2.denom;
	
	return diff;
}

int rational::GCD(int num, int denom) const {
    
    if(denom < 0)
		denom=abs(denom);

    if (denom == 0)  
    return num;  
  
  return GCD(denom, num % denom);  
    
}

ostream& operator<<(ostream &fout, rational &obj) {	
									
	if (obj.denom < 0) {

		obj.denom = -obj.denom;
		obj.num = -obj.num;

	}

	fout << obj.num << "/" << obj.denom;

	return fout;
}

int operator>>(ifstream &fin, rational r[]) {

	int n;

	cout << "You may enter up to 10 rational numbers to be sorted. How many?: ";
	cin >> n;

	for(int i = 0; i < n; i++) {

		in_stream >> r[i].num >> r[i].denom;

	}

	return n; 

}

void writeToDisk(rational r[], int n) {


	for(int i = 0; i < n; i++) {

		out_stream << r[i];

	}

}

ofstream& operator<<(ofstream &out, rational &r) {

    r.setBoth();
	int gcd = r.GCD(r.num, r.denom);

    if(r.denom < 0) {
        r.denom = abs(r.denom);
        r.num = r.num *(-1);
    }

    if (gcd < 2) {
    	cout << r.num << "/" << r.denom;
    }
    	
    else {
        cout << (r.num/gcd) << "/" << (r.denom/gcd);
    }

    return out;
}

void rational::setBoth() {
 
    num = numerator;
    denom = denominator;
    
}