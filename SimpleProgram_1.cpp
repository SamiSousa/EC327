/*
Sami Shahin
September 7, 2015
SimpleProgram_1.cpp
gotta get some practice in
*/

#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    double radius;
    double area;
    
    //Step 1: read in radius
    cout << "Enter a radius: ";
    cin >> radius;
    //radius = 20;
    
    //Step 2: Compute area
    area = radius * radius * 3.14159;
    
    //Step 3: Display area
    cout << "The area is " << area << endl;
    
    system("PAUSE");
    return 0;
}
