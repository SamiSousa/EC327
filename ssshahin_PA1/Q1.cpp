/*
ssshahin_PA1
Q1
Perimeter and area of triangles
*/

#include <iostream>	//included for output input stream
//#include <cstdlib>	//included for system("PAUSE")
#include <math.h>	//included for square root
using namespace std;

bool isTriangle(double a, double b, double c);
double triangleArea(double a, double b, double c);
double trianglePerimeter(double a, double b, double c);
double threeDecimals(double num);


//takes in three numbers for triangle side lengths
//outputs the area and perimeter of triangle, unless triangle impossible

int main(){
	//declaring variables
	double side1, side2, side3;

	//ask for user input
	cout<<"Enter the dimensions of the triangle:"<<endl;
	cout<<"Side-1: ";
	cin>>side1;
	
	cout<<"Side-2: ";
	cin>>side2;
	
	cout<<"Side-3: ";
	cin>>side3;

	if( ! isTriangle(side1, side2, side3)){
		//for case where triangle is NOT possible to make
		//such as case where short sides don't add up to more than large side
		//or at least one side is negative
		cout<<"Dimensions "<<side1<<", "<<side2<<", "<<side3<<" do not form a triangle."<<endl;

	}else{
		//for case where triangle IS possible
		//for the following, rounds each result to three decimals
		double area = threeDecimals( triangleArea(side1, side2, side3) );
		double perimeter = threeDecimals( trianglePerimeter(side1, side2, side3) );

		cout<<"This triangle's area is "<<area<<" square-units and it's perimeter is "<<perimeter<<" units."<<endl;

	}
	//system("PAUSE");
	return 0;
}

//function for checking if triangle is possible
bool isTriangle(double a, double b, double c){
	//boolean possible is set to true if all sides are positive, false otherwise
	bool possible = (a > 0 && b > 0 && c > 0);

	//if the two shorter sides don't add to be greater than the larger side, triangle isn't possible, otherwise true

	if (a >= b && a >= c){
		if ( b + c <= a ){
			possible = false;
		}
	}else if (b >= a && b >= c){
		if ( a + c <= b ){
			possible = false;
		}
	}else{
		if ( a + b <= c){
			possible = false;
		}
	}


	return possible;
}

//function for finding triangle area
double triangleArea(double a, double b, double c){
	double area, avglength;

	//using Heron's formula, finding area
	avglength = (a + b + c)/2;

	area = sqrt(avglength * (avglength - a) * (avglength - b) * (avglength - c));

	return area;
}

//function for finding triangle perimeter
double trianglePerimeter(double a, double b, double c){
	double perimeter;

	//perimeter is the sum of the side lengths

	perimeter = a + b + c;

	return perimeter;
}

//function for reducing a decimal to three decimal places, rounded to nearest thousandth.
double threeDecimals(double num){
	int thousand_fold, ten_thousand_fold;
	double decimal;
	//holds double times 10,000 cast as an int, preserving some decimals 
	ten_thousand_fold = (int) 10000 * num;

	//holds double times 1,000 cast as int
	thousand_fold = (ten_thousand_fold / 10);

	//rounding to nearest thousandth
	int rounding = ten_thousand_fold % 10;
	if (rounding >= 5){
		//adds one if tenthousandth place is 5 or greater
		thousand_fold += 1;
	}

	decimal = ((double) thousand_fold )/ 1000.0;

	return decimal;

}