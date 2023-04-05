//
// Created by w0456204 on 2022-11-17.
//

#ifndef ASSIGNMENT3_RATIONAL_H
#define ASSIGNMENT3_RATIONAL_H

#include <conio.h>
#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>
#include <regex>
#include <utility>

using namespace std;

class Rational{

    //declaring the member variables
private:
    int numerator;
    int denominator;


public:
    Rational();//Default constructor

    explicit Rational(int wholeNum);//Constructor for just one number

    Rational(int pNumerator, int pDenominator);//Constructor with both numerator and denominator

    explicit Rational(const string& s);//Constructor for the string provided


    //Overloading the operators
    Rational operator+ ( Rational &rightObj);

    Rational operator/ ( Rational &rightObj);

    Rational operator- ( Rational &rightObj);

    Rational operator* ( Rational &rightObj);

    bool operator< ( Rational &rightObj);

    bool operator> ( Rational &rightObj);

    bool operator== ( Rational &rightObj);


    //Adding friend functions

    //friend void operator>> (istream &input, Rational &num);

    friend ostream& operator<<(ostream &output, Rational &num);


    //Declaring my getters and setter
    int getNumerator() const;
    void setNumerator(int thisNumerator);

    int getDenominator() const;
    void setDenominator(int thisDenominator);

    //creating a method to normalize the fraction
    static Rational normalizeFraction(int one, int two);//https://www.geeksforgeeks.org/reduce-the-fraction-to-its-lowest-form/

};

#endif //ASSIGNMENT3_RATIONAL_H
