//
// Created by w0456204 on 2022-11-17.
//
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <string>
#include "Rational.h"
using namespace std;



//Getting and setting the numerator and denominator
int Rational::getNumerator() const {


    return numerator;


}

void Rational::setNumerator(int thisNumerator) {


    numerator = thisNumerator;

}


int Rational::getDenominator() const {


    return denominator;

}

void Rational::setDenominator(int thisDenominator) {


    denominator = thisDenominator;


}

//Initializing the constructors
Rational::Rational() :numerator(), denominator(){

    cout<<"Default Constructor has been called"<<endl<<endl;

    this->numerator=0;
    this->denominator=1;

}//end constructor

Rational::Rational(int wholeNum){

    cout<<"Whole Number Constructor has been called"<<endl<<endl;

    this->numerator = wholeNum;

    this->denominator = 1;

}//end constructor

Rational::Rational(int numerator, int denominator) :numerator(numerator), denominator(denominator){

    cout<<"Two Argument Constructor has been called"<<endl<<endl;

}//end constructor



Rational::Rational(const std::string& s){

    cout<<"String Constructor has been called"<<endl<<endl;

        //split the fraction that was given in the string

        string n,d;

        int pnum = 0, dnum = 0;

        regex isFraction ("^[-|0-9][0-9]*(\\/)[-|0-9][0-9]*$");

        regex isWhole("^[-|0-9][0-9]*$");

        if(regex_match(s,isFraction)) {//split the fraction if it is a fraction
            string delimiter = "/";

            istringstream iss(s);

            getline(iss, n, '/');
            getline(iss, d);

            pnum = stoi(n);
            dnum = stoi(d);

            this->numerator = pnum;

            this->denominator = dnum;



        }else if(regex_match(s,isWhole))//assign the whole number to a denominator
        {

            istringstream iss(s);

            getline(iss, n);

            pnum = stoi(n);

            this->numerator = pnum;

            this->denominator = 1;


        }


    }//end string constructor

//implementing the function
Rational Rational::normalizeFraction(int one, int two) //https://www.geeksforgeeks.org/reduce-the-fraction-to-its-lowest-form/
{

    cout<<"Normalize Fraction Constructor has been called"<<endl<<endl;

    if(two == 0){two =1;}

    int d;
    d = __gcd( one,  two);

    one=  one / d;
    two = two / d;

    return  Rational(one,two);
}


//Overloading the operators
Rational Rational::operator+(Rational &rightObj) {

    cout<<"The + operator has been called."<<endl<<endl;//Printing a message to show that the constructor has been fired

    //Doing the calculations
    int one = this->numerator + rightObj.numerator;

    int two = this->denominator + rightObj.denominator;

    normalizeFraction(one,two);//calling the function to normalize the fraction


    return normalizeFraction(one,two);//return the normalized fraction




}//end + overload function

Rational Rational::operator-(Rational &rightObj) {

    cout<<"The - operator has been called."<<endl<<endl;//Printing a message to show that the constructor has been fired


    //Doing the calculations
    int one = this->numerator - rightObj.numerator;

    int two = this->denominator - rightObj.denominator;

    normalizeFraction(one,two);//calling the function to normalize the fraction

    return normalizeFraction(one,two);//return the normalized fraction



}//end - overload function

Rational Rational::operator*(Rational &rightObj) {

    cout<<"The * operator has been called."<<endl<<endl;//Printing a message to show that the constructor has been fired

    //Doing the calculations
    int one = this->numerator * rightObj.numerator;

    int two = this->denominator * rightObj.denominator;

    normalizeFraction(one,two);//calling the function to normalize the fraction

    return normalizeFraction(one,two);//return the normalized fraction



}//end - overload function

Rational Rational::operator/(Rational &rightObj) {

    cout<<"The / operator has been called."<<endl<<endl;//Printing a message to show that the constructor has been fired

    //Doing the calculations
    int one = this->numerator * rightObj.denominator;

    int two = this->denominator * rightObj.numerator;

    normalizeFraction(one,two);//calling the function to normalize the fraction

    return normalizeFraction(one,two);//return the normalized fraction


}

bool Rational::operator<(Rational &rightObj) {

    cout<<"The < operator has been called."<<endl<<endl;//Printing a message to show that the constructor has been fired


    //Finding the lcm
    int lcm = this->denominator * rightObj.denominator;

    //convert the fraction into equivalent fractions
    int num1 = this->numerator * rightObj.denominator;

    int num2 = this->denominator * rightObj.numerator;





    //compare the numerators
    if(num1 < num2) {

        return true;

    }
    else

        return false;




}

bool Rational::operator>(Rational &rightObj) {

    cout<<"The > operator has been called."<<endl<<endl;//Printing a message to show that the constructor has been fired

    //Finding the lcm
    int lcm = this->denominator * rightObj.denominator;

    //convert the fraction into equivalent fractions
    int num1 = this->numerator * rightObj.denominator;

    int num2 = this->denominator * rightObj.numerator;



    //compare the numerators
    if(num1 > num2) {

        return true;

    }
    else

        return false;




}

bool Rational::operator==(Rational &rightObj) {

    cout<<"The == operator has been called."<<endl<<endl;//Printing a message to show that the constructor has been fired


    int firstOp = this->numerator * rightObj.denominator;

    int secondOp = this->denominator * rightObj.numerator;

    //compare the numerators
    if(firstOp == secondOp) {

        return true;

    }
    else

        return false;




}



ostream& operator<<(ostream &output, Rational &num) {

    cout<<"The friend function has been called"<<endl<<endl; //Printing a message to show that the constructor has been fired

    output <<num.numerator << "/" << num.denominator;

    return output;

}


//end - overload function






