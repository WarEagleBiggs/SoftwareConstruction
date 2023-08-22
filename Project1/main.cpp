//AUTHOR: Adam Biggs
//Project 1 - Stereo System Payments
#include <iostream>
using namespace std;

//main
int main() {

    //vars
    int loanAmount;
    int monthlyPayment;
    int interestRate;

    //TODO---------------------------------------------------------------
    //Loan Amount
    cout << "************************************" << endl;
    cout << "Enter Loan Amount" << endl;
    cout << "************************************" << endl;
    cin >> loanAmount;

    //check if loanAmount is negative
    if (loanAmount <= 0){
        //error
        cout << "Please enter a number greater than 0" << endl;
        cin >> loanAmount;
    }

    //TODO---------------------------------------------------------------

    //Monthly Payment
    cout << "************************************" << endl;
    cout << "Enter Monthly Payment Amount" << endl;
    cout << "************************************" << endl;
    cin >> monthlyPayment;

    //check if monthly payment is negative
    if (monthlyPayment <= 0){
        //error
        cout << "Please enter a number greater than 0" << endl;
        cin >> monthlyPayment;
    }

    //TODO---------------------------------------------------------------
    //Interest Rate
    cout << "************************************" << endl;
    cout << "Enter Interest Rate (% per year)" << endl;
    cout << "************************************" << endl;
    cin >> interestRate;

    //check if interest rate is negative
    if (interestRate <= 0){
        //error
        cout << "Please enter a number greater than 0" << endl;
        cin >> interestRate;
    }

    //TODO---------------------------------------------------------------
    //Verify values





    return 0;
}
