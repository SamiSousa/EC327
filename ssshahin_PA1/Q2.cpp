/*
ssshahin_PA1
Q2.cpp
Converting Units
Convert 
*/

#include <iostream>
#include <iomanip>
//#include <cstdlib>

using namespace std;

//declare functions

//functions for temperature conversion
double celciusToFahrenheit(double ctemp);
double celciusToKelvin(double ctemp);

double fahrenheitToCelcius(double ftemp);
double fahrenheitToKelvin(double ftemp);

double kelvinToCelcius(double ktemp);
double kelvinToFahrenheit(double ktemp);

//function for rounding decimals
double threeDecimals(double num);

//The following main function will take user's input for which conversion the user wants
//Then it will prompt the user to input a temperature
//prints the resulting conversion

int main(){
	//declaring variables
	double convertType = -1;
    
    //int loop_counter = 0;
	
    double inputTemp, convertedTemp;

	//guide for conversion types
	cout<<"Celcius to Fahrenheit\t(enter 0)"<<endl;
	cout<<"Celcius to Kelvin\t(enter 1)"<<endl;
	cout<<"Fahrenheit to Celcius\t(enter 2)"<<endl;
	cout<<"Fahrenheit to Kelvin\t(enter 3)"<<endl;
	cout<<"Kelvin to Celcius\t(enter 4)"<<endl;
	cout<<"Kelvin to Fahrenheit\t(enter 5)"<<endl;
    
    cout<<"Conversion type: ";
    
    do /*&& loop_counter < 10*/{
		
		//user input, number between 0 and 5 inclusive
		cin>>convertType;
        //eat feed
        cin.ignore();
        
		if ( (convertType < 0 || convertType > 5) && ((int) convertType != convertType )){
			cout<<"Wrong input, try again: ";
			//loop_counter++;
		}
		/*
		if (loop_counter >= 10){
			cout<<"Too many failed attempts. Exiting program."<<endl;
			break;
		}
		*/
	} while ((convertType > 5 || convertType < 0) && ((int) convertType != convertType));
    
    
	if (convertType == 0 || convertType == 1)
		cout<<"Enter the amount in Celsius: ";

	else if (convertType == 2 || convertType == 3)
		cout<<"Enter the amount in Fahrenheit: ";

	else if (convertType == 4 || convertType == 5)
		cout<<"Enter the amount in Kelvin: ";
	
	else{
		//checking for issues in code
		cout<<"Well the input isn't working.";
	}

	//user input temperature of given units
	cin>>inputTemp;
	
	//eating remains of input feed
    cin.ignore();
	
	if (convertType == 0){
		//Celcius to Fahrenheit
		convertedTemp = celciusToFahrenheit(inputTemp);

		//round to three decimal places
		convertedTemp = threeDecimals(convertedTemp);

		//outputs
		cout<< setiosflags(ios::fixed)<<setprecision(3)<<inputTemp<<" Celcius is "<<convertedTemp<<" Fahrenheit."<<endl;

	}else if (convertType == 1){
		//Celcius to Kelvin
		convertedTemp = celciusToKelvin(inputTemp);

		//round to three decimal places
		convertedTemp = threeDecimals(convertedTemp);

		//outputs
		cout<< setiosflags(ios::fixed)<<setprecision(3)<<inputTemp<<" Celcius is "<<convertedTemp<<" Kelvin."<<endl;

	}else if (convertType == 2){
		//Fahrenheit to Celcius
		convertedTemp = fahrenheitToCelcius(inputTemp);

		//round to three decimal places
		convertedTemp = threeDecimals(convertedTemp);

		//outputs
		cout<< setiosflags(ios::fixed)<<setprecision(3)<<inputTemp<<" Fahrenheit is "<<convertedTemp<<" Celcius."<<endl;

	}else if (convertType == 3){
		//Fahrenheit to Kelvin
		convertedTemp = fahrenheitToKelvin(inputTemp);

		//round to three decimal places
		convertedTemp = threeDecimals(convertedTemp);

		//outputs
		cout<< setiosflags(ios::fixed)<<setprecision(3)<<inputTemp<<" Fahrenheit is "<<convertedTemp<<" Celcius."<<endl;

	}else if (convertType == 4){
		//Kelvin to Celcius
		convertedTemp = kelvinToCelcius(inputTemp);

		//round to three decimal places
		convertedTemp = threeDecimals(convertedTemp);

		//outputs
		cout<< setiosflags(ios::fixed)<<setprecision(3)<<inputTemp<<" Kelvin is "<<convertedTemp<<" Celcius."<<endl;

	}else if (convertType == 5){
		//Kelvin to Fahrenheit
		convertedTemp = kelvinToFahrenheit(inputTemp);

		//round to three decimal places
		convertedTemp = threeDecimals(convertedTemp);

		//outputs
		cout<< setiosflags(ios::fixed)<<setprecision(3)<<inputTemp<<" Kelvin is "<<convertedTemp<<" Fahrenheit."<<endl;

	}else{
		//this shouldn't appear; just a test
		cout<<"I messed up this one. My bad."<<endl;
	}

	//pause for reading results
	//system("PAUSE");

	return 0;
}

//celsius to other
double celciusToFahrenheit(double ctemp){
	double ftemp;

	//converts celcius to fahrenheit
	ftemp = (ctemp * 9.0 / 5.0) + 32.0;

	return ftemp;
}

double celciusToKelvin(double ctemp){
	double ktemp;

	//conversion is a simple addition of 273.15
	ktemp = ctemp + 273.15;

	return ktemp;
}

//fahrenheit to other
double fahrenheitToCelcius(double ftemp){
	double ctemp;

	//converts fahrenheit to celcius
	ctemp = (ftemp - 32.0) * 5.0 / 9.0;

	return ctemp;
}

double fahrenheitToKelvin(double ftemp){
	double ktemp;

	//converts fahrenheit to celcius to kelvin, using these functions
	ktemp = celciusToKelvin( fahrenheitToCelcius(ftemp) );

	return ktemp;
}

//kelvin to other
double kelvinToCelcius(double ktemp){
	double ctemp;

	//conversion is subtraction of 273.15
	ctemp = ktemp - 273.15;

	return ctemp;
}

double kelvinToFahrenheit(double ktemp){
	double ftemp;

	//converts from kelvin to celcius to fahrenheit, using these functions
	ftemp = celciusToFahrenheit( kelvinToCelcius(ktemp) );

	return ftemp;
}



//function for reducing a decimal to three decimal places, rounded to nearest thousandth. 
//copied from my Q1.cpp submission
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
