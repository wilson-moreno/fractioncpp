/****************************************************************
 * The implementation file fraction.cpp defining the instance   *
 * member functions and helper functions for the Fraction class *
 ****************************************************************/

 #include <iostream>
 #include <cmath>
 #include <cassert>
 #include "fraction.h"
 using namespace std;

 /***************************************************************
  * The parameter constructor gets values for the numerator     *
  * and denominator, initializes the object, and normalizes the *
  * value of the numerator and the denominator according to the *
  * conditions defined in the class invariant.                  *
  ***************************************************************/
  Fraction::Fraction(int num, int den=1)
  :numerator(num), denominator(den){
    normalize();
  }

 /**************************************************************
  * The default constructor creates a fraction as 0/1. It does *
  * not need validation                                        *
  **************************************************************/
  Fraction::Fraction()
  :numerator(0), denominator(1){
  }

 /****************************************************************
  * The copy constructor creates a new fraction from an existing *
  * object. It does not need normalization because the source    *
  * object is already normalized             .                   *
  ****************************************************************/
  Fraction::Fraction(const Fraction& fraction)
  :numerator(fraction.numerator), denominator(fraction.denominator){
  }

  /**************************************************************
   * The destructor simply cleans up a fraction for recycling   *
   **************************************************************/
   Fraction::~Fraction(){}

  /*******************************************************************
   * The getNumerator function is an accessor function returning the *
   * numerator of the host object. It needs the const modifier       *
   *******************************************************************/
   int Fraction::getNumerator() const {
       return numerator;
   }

  /*********************************************************************
   * The getDenominator function is an accessor function returning the *
   * numerator of the host object. It needs the const modifier         *
   *********************************************************************/
   int Fraction::getDenominator() const {
        return denominator;
   }

  /*********************************************************************
   * The setNumerator is a mutator function that changes the numerator *
   * of an existing object. The object needs normalization             *
   *********************************************************************/
   void Fraction::setNumerator(int num){
       numerator = num;
       normalize();
   }

  /***********************************************************************
   * The setDenominator is a mutator function that changes the numerator *
   * of an existing object. The object needs normalization               *
   ***********************************************************************/
   void Fraction::setDenominator(int dem){
       denominator = dem;
       normalize();
   }

 /**************************************************************
  * Normalize function takes care of three fraction invariants *
  **************************************************************/
  void Fraction::normalize(){
    //Handling a denominator of zero
    if(denominator == 0){
        cout << "Invalid denominator. Need to quit." << endl;
        assert(false);
    }

    // Changing the sign of denominator
    if(denominator < 0){
        denominator *= -1;
        numerator *= -1;
    }

    // Dividing numerator and denominator by gcd
    int divisor = gcd(abs(numerator), abs(denominator));
    numerator /= divisor;
    denominator /= divisor;
  }

  /**************************************************************
   * The gcd function finds the greatest common divisor between *
   * the numerator and denominator                              *
   **************************************************************/
   int Fraction::gcd(int n, int m){
        int x = n;
        int y = m;
        int r{};

        while( y != 0){
            r = x % y;
            x = y;
            y = r;
        }

        return x;
   }

/****************************************************************
 * The print function is an accesor function with a side effect *
 * that display the fraction object in the form x/y             *
 ****************************************************************/
 void Fraction::print() const{
    cout << "The fraction is: " << numerator << "/" << denominator << endl;
 }

 /**************************************************************************
  * Overrides the + operator to get the sum of two Fraction objects        *
  **************************************************************************/
 const Fraction operator+ (const Fraction& left, const Fraction& right){
    int newNumerator = left.numerator * right.denominator + right.numerator * left.denominator;
    int newDenominator = left.denominator * right.denominator;
    Fraction result(newNumerator, newDenominator);
    return result;
 }

 /********************************************************************************
  * Overrides the - operator to get the difference of two Fraction objects       *
  ********************************************************************************/
 const Fraction operator- (const Fraction& left, const Fraction& right){
    int newNumerator = left.numerator * right.denominator - right.numerator * left.denominator;
    int newDenominator = left.denominator * right.denominator;
    Fraction result(newNumerator, newDenominator);
    return result;
 }

 /********************************************************************************
  * Overrides the * operator to get the product of two Fraction objects       *
  ********************************************************************************/
 const Fraction operator* (const Fraction& left, const Fraction& right){
    int newNumerator = left.numerator * right.numerator;
    int newDenominator = left.denominator * right.denominator;
    Fraction result(newNumerator, newDenominator);
    return result;
 }

  /********************************************************************************
  * Overrides the / operator to get the division of two Fraction objects          *
  *********************************************************************************/
 const Fraction operator/ (const Fraction& left, const Fraction& right){
    int newNumerator = left.numerator * right.denominator;
    int newDenominator = left.denominator * right.numerator;
    Fraction result(newNumerator, newDenominator);
    return result;
 }

 const bool operator< (const Fraction& left, const Fraction& right){
    return (left.numerator * right.denominator) < (right.numerator * left.denominator);
 }

 const bool operator> (const Fraction& left, const Fraction& right){
    return (left.numerator * right.denominator) > (right.numerator * left.denominator);
 }

 /********************************************************************************
  * Overrides the << operator to output the value of the Fraction object         *
  ********************************************************************************/

 ostream& operator<< (ostream& left, const Fraction& right){
    left << right.numerator << "/" << right.denominator;
    return left;
 }

  /************************************************************
   * The getDecimal function converts the fraction to decimal *
   * format                                                   *
   ************************************************************/
   double Fraction::getDecimal() const {
     return (double)numerator / (double)denominator;
   }

  /**************************************************************
   * The printDecimal function converts the fraction to decimal *
   * format and output the value                                *
   **************************************************************/
   void Fraction::printDecimal() const {
     cout << "The decimal equivalent of " << numerator << "/" << denominator << " is " << getDecimal() << endl;
   }

  /************************************************************
   * The isImproper function returns true if the numerator is *
   * greater than the denominator                             *
   ************************************************************/
   bool Fraction::isImproper() const {
        return numerator > denominator;
   }

