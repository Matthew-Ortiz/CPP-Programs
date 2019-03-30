//         Course: CS2400-01 Computer Science II
//           Name: Ortiz, Matthew
//     Assignment: P6.1
//  Date assigned: 3/15/19
//       Date due: 3/27/19
// Date handed in: 3/27/19
//         Remark: This program swaps the values of two already declared variables.
//				   It displays the values before and after swap.                 



#include <iostream>
using namespace std;

class rational {

public:
	rational(); //"default" constructor, they don't need a return type.
    //rational(int = 0 , int = 1); // if you supply your own constructor, compiler won't supply the default one

	~rational(); // any class can have many constructors, but can only have one destrucor. Is provided by default by compiler.

	rational(int n, int d);
	// second constructor  
	// Postcondition: initialize numerator to n0 and denominator to d
	rational add(const rational &r2) const;
	// Version 1 of the add function
	// Postcondition: the sum of the calling object (*this) and r2 is returned
	void add(const rational &r1, const rational &r2);
	// Version 2 of the add function
	// Postcondition: the sum of r1 and r2 is stored in the calling object (*this)
	rational subtract(const rational &r2) const;
	// Version 1 of the subtract function
	// Postcondition: difference of the calling object (*this) - r2 is returned
	void subtract(const rational &r1, const rational &r2);
	// Version 2 of the add function
	// Postcondition: the difference of r1 - r2 is stored in the calling object (*this)
	rational multiply(const rational &r2) const;
	// Postcondition: the product of (*this) * r2 is returned
	rational divide(const rational &r2) const;
	// Postcondition: the quotient of (*this) / r2 is returned
	int compare(rational &r2) const; // returns 0 if . returns 1 if; 
	// Postcondition: returns 1, 0, or -1 if (*this), the calling object, is greater than, equal to, or less than r2, respectively.
	void inputRational();
	// Prompts the user to enter two integer values for the numerator and the denominator of a rational number
	// Postcondition: the calling rational object is loaded with values entered by the user
	void displayRational();
	// Postcondition: displays a rationa number lik 1/3, -7/11, 0, etc. (instead of 2/6, 7/-11, 0/5, etc.)
private:
	int GCD(int num, int denom) { // 5/15 tu	rns into 1/3, only use in display() function. Euclidean algorithm?

    if (denom == 0)  
    return num;  
  
  return GCD(denom, num % denom);  
}  

	int num;
	int denom;

};

int main () {

	int x;
	rational r1(1,4), r2(1,3);
	
	cout << "Using 2nd constructor, r1 is initialized to: ";
	r1.displayRational();
	cout << endl;
	cout << "Using 2nd constructor, r2 is initialized to: ";
	r2.displayRational();
	cout << endl << endl;

	cout << "Testing the arithmetic member functions:" << endl;
	cout << "r1 + r2 = ";
	r1.displayRational();
	cout << " + ";
	r2.displayRational();
	cout << " = ";
	r1.add(r2).displayRational();
	cout << endl;
	
	cout << "r1 - r2 = ";
	r1.displayRational();
	cout << " - ";
	r2.displayRational();
	cout << " = ";
	r1.subtract(r2).displayRational();
	cout << endl;
	
	cout << "r1 * r2 = ";
	r1.displayRational();
	cout << " * "; 
	r2.displayRational();
	cout << " = ";
	r1.multiply(r2).displayRational();
	cout << endl;
	
	cout << "r1 / r2 = ";
	r1.displayRational();
	cout << " / ";
	r2.displayRational();
	cout << " = ";
	r1.divide(r2).displayRational();
	cout << endl << endl;
	
	cout << "Testing the compare() functions" << endl;
	if (r1.compare(r2) == 1) {
	    r1.displayRational(); 
	    cout << " is less than ";
	    r2.displayRational();
	    cout << endl << endl;
	}
	    
	else if (r1.compare(r2) == -1) {
	    r2.displayRational();
	    cout << " is less than ";
	    r1.displayRational();
	    cout << endl << endl;
	 }
	    
	else {
	    r2.displayRational();
	    cout << " is equal to ";
	    r1.displayRational();
	    cout << endl << endl;
	}
	
	cout << "Reset r1 and r2 to new values using inputRational() function:"  << endl;
	cout << "-->";
	r1.inputRational();
	cout << "-->";
	r2.inputRational();
	cout << endl;
	
	cout << "Testing the arithmetic member functions:" << endl;
	r1.displayRational();
	cout << " + ";
	r2.displayRational();
	cout << " = ";
	rational sum1(0, 0); 
	sum1.add(r1, r2);
	sum1.displayRational();
	cout << endl;
	
	r1.displayRational();
	cout << " - ";
	r2.displayRational();
	cout << " = ";
	rational diff1(0, 0); 
	diff1.subtract(r1, r2);
	diff1.displayRational();
	cout << endl;
	
	r1.displayRational();
	cout << " * ";
	r2.displayRational();
	cout << " = ";
	r1.multiply(r2).displayRational();
	cout << endl;
	
	r1.displayRational();
	cout << " / ";
	r2.displayRational();
	cout << " = ";
	r1.divide(r2).displayRational();
	cout << endl << endl;
	
	if (r1.compare(r2) == 1) {
	    r1.displayRational(); 
	    cout << " is less than ";
	    r2.displayRational();
	    cout << endl << endl;
	}
	    
	else if (r1.compare(r2) == -1) {
	    r2.displayRational();
	    cout << " is less than ";
	    r1.displayRational();
	    cout << endl << endl;
	 }
	    
	else {
	    r2.displayRational();
	    cout << " is equal to ";
	    r1.displayRational();
	    cout << endl << endl;
	}
	
	
	cin >> x;
	return 0;
}

rational::rational() { // this function gets called automatically whenever you initialize a new class

	num = 0;
	(*this).denom = 1; // '*' is called a "dereference" operator, (*this) isn't necessary. Dot operator is a member accessor.
	// this->denom // to the left of arrow must be a pointer. '->' is a member accessor.

}

rational::~rational() { // this function gets called automatically whenever you initialize a new class



}

rational::rational(int n, int d) {

	num = n;
	denom = d;

}

rational rational::add(const rational &r2) const { // use const in parameters so they won't be changed during function call. Second const prevents calling object from being changed in function.

    rational sum(0, 0);
    
	sum.denom = (*this).denom * r2.denom;
	sum.num = ((num*r2.denom) + (denom*r2.num));

	return sum;

}

void rational::add(const rational &r1, const rational &r2) {
    
    if (r1.denom == r2.denom) {
        (*this).denom = r1.denom;
        (*this).num = r1.num * r2.denom;
    }
    else if (r1.denom != r2.denom) {
	(*this).denom = (r1.denom * r2.denom);
	(*this).num = ((r1.num*r2.denom) + (r1.denom*r2.num));
    }
    
	

}

rational rational::subtract(const rational &r2) const {

	rational diff(0,0);

	if (denom == r2.denom)
		diff.denom = denom;
	else 
		diff.denom = (denom * r2.denom);

	diff.num = ((num * r2.denom) - (denom * r2.num));

	return diff;

}

void rational::subtract(const rational &r1, const rational &r2) {

    if (r1.denom == r2.denom)
		(*this).denom = r1.denom;
	
    else {
	(*this).denom = (r1.denom * r2.denom);
    }
    
	(*this).num = ((r1.num*r2.denom) - (r2.num*r1.denom));	

}

rational rational::multiply(const rational &r2) const {

	rational product(0,0);

	product.denom = ((*this).denom * r2.denom);
	product.num = ((*this).num * r2.num);


	return product;
}

rational rational::divide(const rational &r2) const {

	rational quotient(0,0);
	
	quotient.denom = ((*this).denom * r2.num);
	quotient.num = ((*this).num * r2.denom);

	return quotient;

}

int rational::compare(rational &r2) const {

	rational diff(0,0);
	double x;
	diff = (*this).subtract(r2);

	x = static_cast<double>(diff.num) / static_cast<double>(diff.denom);

	if (x < 0)
		return 1;
	else if (x == 0)
		return 0;
	else
		return -1;

}

void rational::inputRational() {

	cout << "Please enter a numerator and denominator integer value, respectively: ";
	cin >> num >> denom;
	
}

void rational::displayRational() {

    int gcd = GCD(num, denom);

    if(denom < 0) {
        denom = abs(denom);
        num = num *(-1);
    }

    if (gcd < 2) {
    	cout << num << "/" << denom;
    }
    	
    else {
        cout << (num/gcd) << "/" << (denom/gcd);
    }

} 



