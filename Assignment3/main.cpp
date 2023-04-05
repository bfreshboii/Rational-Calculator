#include <iostream>
#include <string>
#include <sstream>
#include <regex>
#include "Rational.h"
using namespace std;


int main()
{
    //Declaring my strings
    string f1,f2;
    int wholeNum;

    //declaring the rational
    Rational RNA;

    //Declaring the regex
    regex r1 ("^[-|0-9][0-9]*(\\/)[-|0-9][0-9]*$");

    regex r2("^[-|0-9][0-9]*$");

    //Printing the title
    cout<<"Rational Driver"<<endl;



    //Using while loop sto validate the input
    while(!regex_match(f1,r1) && !regex_match(f1,r2)) {
        cout << "Please enter the first fraction: " << endl;
        getline(cin, f1);

    }
    Rational RN1(f1);//Sending the input to the string method

    while(!regex_match(f2,r1) && !regex_match(f2,r2)) {
        cout << "Please enter the second fraction: " << endl;
        getline(cin, f2);
    }

    Rational RN2(f2);//Sending the input to the string method

    //Testing the whole number constructor
    cout<<"This is a test of a whole number, please enter an integer: "<<endl;

    cin>>wholeNum;//reading in the integer

    RNA = Rational(wholeNum);//Calling the whole number constructor

    cout<<"Test of whole number constructor"<<endl<<endl;

    cout<<RNA<<endl;


    //Display the results for the mathematical operators
    cout << endl;

    cout << "This is the sum."<<endl;

    RNA = RN1 + RN2;

    cout <<"Sum = "<< RNA << endl<<endl;

    cout << "This is the difference."<<endl;

    RNA = RN1 - RN2;

    cout <<"Difference = "<< RNA << endl<<endl;

    cout << "This is the product."<<endl;

    RNA = RN1 * RN2;

    cout <<"Product = "<< RNA << endl<<endl;

    cout << "This is the quotient."<<endl;

    RNA = RN1 / RN2;

    cout <<"Quotient = "<< RNA << endl<<endl;

    cout << "This is to test whether the first fraction is less than the second."<<endl;


    //Using an if-else statement to check for the comparisons

    if(bool RNA = RN1 < RN2){

        cout<<"RNA = " << RN1 << " < " << RN2<<endl;

    }else {
        RNA = RN1 > RN2;
        if(RNA){

            cout << "This is to test whether the first fraction is greater than the second."<<endl;

            cout<<"RNA = " << RN1 << " > " << RN2<<endl;

        }else {
            RNA = RN1 == RN2;
            if(RNA){

                cout << "This is to test whether the first fraction is equivalent to the second."<<endl;

                cout<< RN1 << " == " << RN2<<endl;

            }else{


                cout<< "Nothing to show" <<endl;
            }
        }
    }













}