//TODO AUTHOR: Adam Biggs
//TODO Project 1 - Stereo System Payments
#include <iostream>
#include <string.h>
using namespace std;

//vars
float loanAmount;
float monthlyPayment;
float interestRate;

//background vars
float monthlyInterestRate;
float currBalance;
float currMonth;
float interestPaid;

//respond var
string response;

//Function Ref for calls
void LoanAmount();
void MonthlyPayment();
void InterestRate();
void ChangeValues();
void VerifyValues();
void VerifyPayments();
void Loop();

//TODO*****************************************************************************************************
//TODO main
int main() {

    //get values
    LoanAmount();
    MonthlyPayment();
    InterestRate();

    //verify them
    VerifyValues();
    VerifyPayments();

    //loop
    Loop();
}

//TODO*****************************************************************************************************
//TODO Loan Amount
void LoanAmount(){
    cout << "************************************" << endl;
    cout << "Enter Loan Amount" << endl;
    cout << "************************************" << endl;
    cin >> loanAmount;

    //check if loanAmount is negative
    if (loanAmount <= 0){
        //error
        cout << "Error: Please enter a number greater than 0" << endl;
        cin >> loanAmount;
    }
}

//TODO---------------------------------------------------------------
//TODO Monthly Payment
void MonthlyPayment(){
    cout << "************************************" << endl;
    cout << "Enter Monthly Payment Amount" << endl;
    cout << "************************************" << endl;
    cin >> monthlyPayment;

    //check if monthly payment is negative
    if (monthlyPayment <= 0){
        //error
        cout << "Error: Please enter a number greater than 0" << endl;
        cin >> monthlyPayment;
    }
}

//TODO---------------------------------------------------------------
//TODO Interest Rate
void InterestRate(){
    cout << "************************************" << endl;
    cout << "Enter Interest Rate (% per year)" << endl;
    cout << "************************************" << endl;
    cin >> interestRate;

    //check if interest rate is negative
    if (interestRate <= 0){
        //error
        cout << "Error: Please enter a number greater than 0" << endl;
        cin >> interestRate;
    }

    monthlyInterestRate = interestRate / 12;

}

//TODO---------------------------------------------------------------
//TODO Change Values
void ChangeValues(){
    cout << "************************************" << endl;
    cout << "Select Which Value To Change" << endl;
    cout << "(1) Loan Amount: $" + to_string(loanAmount) << endl;
    cout << "(2) Monthly Payment: $" + to_string(monthlyPayment) << endl;
    cout << "(3) Interest Rate: " + to_string(interestRate) + "%" << endl;
    cout << "************************************" << endl;
    cout << "Enter '1', '2', or '3'" << endl;
    cin >> response;

    //check which input
    if (response == "1"){
        LoanAmount();
        VerifyValues();
    } else if (response == "2"){
        MonthlyPayment();
        VerifyValues();
    } else if (response == "3"){
        InterestRate();
        VerifyValues();
    } else {
        //error
        ChangeValues();
    }
}

//TODO---------------------------------------------------------------
//TODO Verify values
void VerifyValues(){
    cout << "************************************" << endl;
    cout << "Loan Amount: $" + to_string(loanAmount) << endl;
    cout << "Monthly Payment: $" + to_string(monthlyPayment) << endl;
    cout << "Interest Rate: " + to_string(interestRate) + "%" << endl;
    cout << "************************************" << endl;
    cout << "Is The Above Info Correct (Y/N)" << endl;
    cin >> response;

    //check if y or n
    if (response != "y"  && response != "Y" && response != "N" && response != "n"){
        //error
        cout << "Error: Incorrect Input..." << endl;
        VerifyValues();
    }

    //check response for n
    if (response == "N" || response == "n"){
        //call change info function
        ChangeValues();
    }


}

//TODO---------------------------------------------------------------
//TODO Verify That Payments are > than interest amount
void VerifyPayments(){
    if (monthlyPayment <= (monthlyInterestRate / 100) * loanAmount){
        //error - redo values
        ChangeValues();
    }
}

//TODO---------------------------------------------------------------
//TODO Loop
void Loop() {
    //init
    currMonth = 0;
    interestPaid = 0;
    monthlyInterestRate /= 100;

    //create header and table
    cout << "**********************************************************" << endl;
    cout << "Month " <<  " Balance: " << " Payment: " << " Interest: " << " Principal: " << endl;


    while (loanAmount > 0) {

        //check
        while (monthlyPayment <= loanAmount * monthlyInterestRate) {
            cout << "Error: Monthly payment must be greater than monthly interest." << endl;
            ChangeValues();
            VerifyPayments();
        }

        //find out monthly interest
        float monthlyInterest = loanAmount * monthlyInterestRate;
        float principal = monthlyPayment - monthlyInterest;

        //modify principal
        if (principal > loanAmount) {
            principal = loanAmount;
            monthlyPayment = monthlyInterest + principal;
        }

        //subtract
        loanAmount -= principal;

        //total interest
        interestPaid += monthlyInterest;

        //fill table
        //TODO line up with word
        cout << "   " << currMonth << "   $" << loanAmount << "   $" << monthlyPayment << "   $" << monthlyInterest << "   $" << principal << endl;

        //add 1 to month
        currMonth++;
    }

    cout << "**********************************************************" << endl;
    cout << "It takes " << currMonth << " months to pay off the loan." << endl;
    cout << "Total interest paid is: $" << interestPaid << endl;
}