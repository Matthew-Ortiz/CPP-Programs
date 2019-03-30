//         Course: CS2400-01 Computer Science II
//           Name: Ortiz, Matthew
//     Assignment: P6.2
//  Date assigned: 3/15/19
//       Date due: 3/27/19
// Date handed in: 3/27/19
//         Remark: This program swaps the values of two already declared variables.
//				   It displays the values before and after swap.                 


#include <iostream>
using namespace std;

class rational {

public:
	int compare(rational &r2); // returns 0 if . returns 1 if; 
	// Postcondition: returns 1, 0, or -1 if (*this), the calling object, is greater than, equal to, or less than r2, respectively.
	void inputRational();
	// Prompts the user to enter two integer values for the numerator and the denominator of a rational number
	// Postcondition: the calling rational object is loaded with values entered by the user
	void displayRational();
	// Postcondition: displays a rationa number lik 1/3, -7/11, 0, etc. (instead of 2/6, 7/-11, 0/5, etc.)
	rational subtract(const rational &r2) const;
	// Version 1 of the subtract function
	// Postcondition: difference of the calling object (*this) - r2 is returned
	void setNum();
	//Postcondition: This function is used to set the num values as the numerator value.
	void setDenom();
	//Postconditin: This function is used to assign the denominator value to private member variable denom.
	
	int numerator;
	int denominator;
private:
	int GCD(int num, int denom) { // 5/15 tu	rns into 1/3, only use in display() function. Euclidean algorithm?

    if (denom == 0)  
    return num;  
  
  return GCD(denom, num % denom);  
}   
 
	int num;
	int denom;
};

void sort(rational r[], int n);
//Postcondition: When called, this function sorts an array of rationals, using the swap and compare function.
void display(rational r[], int n);
//Postcondition: Using a for loop, this function calls the displayRational() member function to display the rationals.
int fillArray(rational r[], int SIZE);
//Precondition: An array of rationals and the expected number of inputs are passed in.
//Postcondition: The rationals in the array are assigned numerator and denominator values.
void swap(rational r[], rational, int i);
//Postcondition: This function swaps two values.

int main () {

int n;
const int SIZE = 10;
rational r[SIZE];

n = fillArray(r, SIZE);
display(r, n);
sort(r, n);
cout << endl;
display(r, n);

}

int rational::compare(rational &r2)  {

	rational diff;
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

rational rational::subtract(const rational &r2) const {

	rational diff;

	if (denom == r2.denom)
		diff.denom = denom;
	else 
		diff.denom = (denom * r2.denom);

	diff.num = ((num * r2.denom) - (denom * r2.num));

	return diff;

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

void rational::setNum() {
 
    num = numerator;
       
}

void rational::setDenom() {
    
    denom =  denominator;
    
}

void sort(rational r[], int n) {

	/*for(int i = 0; i < n; i++) {
		if(r[i+1].compare(r[i]) == 1) {
			//rational[i] = rational[i-1];
			//rational[i-1] = rational[i];
			swap(r[i], r[i+1]);
		}
	}*/
	int i, j, min_idx; 
  
    // One by one move boundary of unsorted subarray 
    for (i = 0; i < n-1; i++) { 
        // Find the minimum element in unsorted array 
        min_idx = i; 
        for (j = i+1; j < n; j++) {
          if (r[j].compare(r[min_idx]) == 1) 
            min_idx = j; 
  		}
        // Swap the found minimum element with the first element 
        swap(r[min_idx], r[i]); 
    }

}

void swap(rational r[], int i){

	rational temp;
	temp = r[i];
	r[i] = r[i+1];
	r[i+1] = temp;

}

void display(rational r[], int n) {

	for(int i = 0; i < n; i++) {
		r[i].displayRational();
		cout << "  ";
	}


}

int fillArray(rational r[], int SIZE) {

    int inputs;
	cout << "You may enter up to 10 rational numbers. How many?: ";
	cin >> inputs;

	for(int i = 0; i < inputs; i++) {

		cout << "r[" << i << "]: Enter values for numerator and denominator --> ";
		cin >> r[i].numerator >> r[i].denominator;
		
		r[i].setNum();
		r[i].setDenom();

	}

	return inputs;


}