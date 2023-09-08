//TODO AUTHOR: Adam Biggs
//TODO ID: ajb0217
//TODO Project 1 - Stereo System Payments
/** References
 * https://en.cppreference.com/w/cpp/io/manip/setw
 * https://auburn.instructure.com/courses/1517529/external_tools/9744
 * https://stackoverflow.com/questions/5131647/why-would-we-call-cin-clear-and-cin-ignore-after-reading-input
 *
 * TODO - TO COMPILE USE (due to version)
 * g++ -std=c++0x main.cpp
 * TO RUN USE
 * ./a.out
 */
#include <iostream>
#include <string.h>
#include <iomanip>
#include <limits>
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
    InterestRate();
    MonthlyPayment();


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
    if (cin.fail() || loanAmount <= 0){
        //error
        cout << "Error: Invalid loan" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        return;
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
    if (cin.fail() || monthlyPayment <= 0){
        //error
        cout << "Error: Invalid payment" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        return;
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
    if (cin.fail() || interestRate < 0){
        //error
        cout << "Error: Invalid interest rate" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        return;
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
    float monthlyInterest = loanAmount * (interestRate / 12 / 100);
    //check
    if (monthlyPayment <= monthlyInterest) {
        cout << "Warning: Monthly payment may not cover monthly interest." << endl;
    }
}

//TODO---------------------------------------------------------------
//TODO Loop
void Loop() {
    //init
    currMonth =0;
    interestPaid = 0;
    monthlyInterestRate /= 100;

    //create header and table
    cout << "**********************************************************" << endl;
    cout << "\tAmortization Table" << endl;
    cout << "**********************************************************" << endl;
    cout << "Month" << setw(10) << "Balance" << setw(10) << "Payment" << setw(10) << "Rate"
         << setw(12) << "Interest" << setw(11) << "Principal" << endl;

    //first blank row
    cout << fixed << setprecision(2) << setw(5) << currMonth << setw(4) << "$" << loanAmount
         << setw(5) << "N/A" << setw(13) << "N/A" << setw(8) << "N/A" << setw(10) << "N/A"
         << endl;

    //attempt 4 to fix double print bug
    currMonth = 1;

    while (loanAmount > 0) {

        //check
        while (monthlyPayment <= loanAmount * monthlyInterestRate) {
            cout << "Error: Insufficient payment" << endl;
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
        cout << setw(5) << currMonth << setw(4) << "$" << loanAmount << setw(4) << "$"
             << monthlyPayment << setw(11) << monthlyInterestRate * 100 << setw(5) << "$"
             << monthlyInterest << setw(5) << "$" << principal << endl;

        //add 1 to month
        currMonth++;
    }

    cout << "**********************************************************" << endl;
    cout << "It takes " << currMonth - 1 << " months to pay off the loan." << endl;
    cout << "Total interest paid is: $" << interestPaid << endl;
}