/************************************************************
* The interface file fraction.h defining the class Fraction *
*************************************************************/

#include <iostream>
#include <string>
using namespace std;


#ifndef FRACTION_H
#define FRACTION_H

class Fraction{
// Data members
private:
    int numerator;
    int denominator;

// Public member functions
public:
    // Constructors
    Fraction(int num, int den);
    Fraction();
    Fraction(const Fraction& fract);
    ~Fraction();
    // Accessors
    int getNumerator() const;
    int getDenominator() const;
    double getDecimal() const;
    void printDecimal() const;
    void print() const;
    bool isImproper() const;
    // Mutators
    void setNumerator(int num);
    void setDenominator(int num);

private:
    void normalize();
    int gcd(int n, int m);

friend const Fraction operator+ (const Fraction& left, const Fraction& right);
friend const Fraction operator- (const Fraction& left, const Fraction& right);
friend const Fraction operator* (const Fraction& left, const Fraction& right);
friend const Fraction operator/ (const Fraction& left, const Fraction& right);
friend const bool operator< (const Fraction& left, const Fraction& right);
friend const bool operator> (const Fraction& left, const Fraction& right);
friend ostream& operator<< (ostream&left, const Fraction& right);

};


#endif // FRACTION_H_INCLUDED
