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

    //respond var
    string response;

    //TODO---------------------------------------------------------------
    //TODO Loan Amount
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
    //TODO Monthly Payment
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
    //TODO Interest Rate
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
    //TODO Verify values
    cout << "************************************" << endl;
    cout << "Loan Amount: $" + to_string(loanAmount) << endl;
    cout << "Monthly Payment: $" + to_string(monthlyPayment) << endl;
    cout << "Interest Rate: " + to_string(interestRate) + "%" << endl;
    cout << "************************************" << endl;
    cout << "Is The Above Info Correct (Y/N)" << endl;
    cin >> response;

    //check if y or n
    if (response != "y" || response != "Y" || response != "N" || response != "n"){
        //error
        
    }

    //check response for n
    if (response == "N" || response == "n"){
        //call change info function
    }





    return 0;
}
