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

    //---------------Loan Amount------------------------
    cout << "***********************" << endl;
    cout << "*  Enter Loan Amount  *" << endl;
    cout << "***********************" << endl;
    cin >> loanAmount;

    //check if loanAmount is negative
    if (loanAmount <= 0){
        //error
        cout << "Please enter a number greater than 0" << endl;
        cin >> loanAmount;
    }
    //---------------Monthly Payment--------------------


    //---------------Interest Rate----------------------




    return 0;
}
