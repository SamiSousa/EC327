/*
ssshahin_PA1
Q4.cpp
Letter Conversion
Take character, and nonnegative offset, output new ASCII 

*/

#include <iostream>

using namespace std;

//declare functions
bool isAlphabet(char a);
//returns true if character is alphabetic

bool isUpperCase(char a);
//returns true if character is uppercase letter, false otherwise

char changeCase(char a);
//change case of character a. If not a letter, returns the letter

int main(){
	
	//declare variables
	char input, output;

	int offset;

	cout<<"Enter character: ";
	cin>>input;
	cin.ignore();

	cout<<"Offset (enter 0 to convert case): ";
	cin>>offset;
	cin.ignore();

	if (offset < 0)
		cout<<"Error. Negative offset."<<endl;
	else if ( input + offset > 127)
		cout<<"Error. Our of range."<<endl;
	else{
		if( offset == 0 )
			output = changeCase(input);
		else
			output = input + offset;

		cout<<"New character: "<<output<<endl;

	}

	return 0;
}


//changes lowercase letters to uppercase, and vice versa. If not a letter, do nothing
char changeCase(char a){
	char changed;

	if (isAlphabet(a)){
		if(isUpperCase(a)){
			changed = (char) ( a + 32 );
		}else{
			changed = (char) ( a - 32 );
		}
	}else{
		changed = a;
	}

	return changed;
}

//returns true if character is a letter
bool isAlphabet(char a){
	return ( ( a >= 97 && a <=122 ) || ( a >= 65 && a <= 90 ) );
}

bool isUpperCase(char a){
	return ( a >= 65 && a <= 90 );
}