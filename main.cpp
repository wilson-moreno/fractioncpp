#include <iostream>
#include "fraction.h"
#include "fracqsort.h"

using namespace std;


void driverProgram1(){
   int numerator1{};
   int denominator1{};
   int numerator2{};
   int denominator2{};

   cout << "Welcome to Fractions Arithmetic!" << endl << endl;
   cout << "Please enter values for the numerator and denominator." << endl << endl;
   cout << "First Fraction" << endl;
   cout << "Numerator: ";
   cin >> numerator1;
   cout << "Denominator: ";
   cin >> denominator1;
   cout << endl;
   cout << "Second Fraction" << endl;
   cout << "Numerator: ";
   cin >> numerator2;
   cout << "Denominator: ";
   cin >> denominator2;
   cout << endl;

   Fraction fraction1(numerator1, denominator1);
   Fraction fraction2(numerator2, denominator2);
   fraction1.print();
   fraction2.print();


   cout << "The decimal value of the first fraction is " << fraction1.getDecimal() << endl;
   cout << "The decimal value of the second fraction is " << fraction2.getDecimal() << endl;
   cout << "The sum of the fractions is " << fraction1 + fraction2 << endl;
   cout << "The difference of the fractions is " << fraction1 - fraction2 << endl;
   cout << "The product of the fractions is " << fraction1 * fraction2 << endl;
   cout << "The division of the fractions is " << fraction1 / fraction2 << endl;
}

void driverProgram2(){
   cout << "Welcome to Fraction Quick Sort Driver Program!" << endl << endl;
   cout << "Generating a set of fractions...." << endl << endl;
   FractionQuicksort fracqsort(10);

   cout << "Fraction set: ";
   fracqsort.printArray();
   cout << "Equivalent decimal set: ";
   fracqsort.printDecimalArray();

   cout << endl << "Starting Quick Sort...." << endl << endl;

   fracqsort.sort();

   cout << "Sorted fraction set: ";
   fracqsort.printArray();

   cout << "Sorted equivalent decimal set: ";
   fracqsort.printDecimalArray();
}

int main()
{
   cout << "Welcome to Fraction class drivers program!" << endl << endl;

   cout << "Please select the driver program you want to run." << endl << endl;
   cout << "1. Arithmetic operations on Fraction objects." << endl;
   cout << "2. Sorting a set of Fraction objects using Quick Sort." << endl;
   cout << "3. Exit." << endl;

   int selection{0};

   do{
      cout << "\nEnter your choice: ";
      cin >> selection;
   }while(selection < 1 || selection > 3);

   switch(selection){
        case 1: cout << endl; driverProgram1(); break;
        case 2: cout << endl; driverProgram2(); break;
        case 3: cout << "Thank you for using the program!" << endl; break;
   }



   return 0;
}

