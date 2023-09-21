//TODO AUTHOR: Adam Biggs
//TODO ID: ajb0217
//TODO Project 2 - Duel Simulation
/** References
 *
 * TODO - TO COMPILE USE (due to version)
 * g++ -std=c++0x main.cpp
 * TO RUN USE
 * ./a.out
 */
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <iomanip>
#include <limits>

using namespace std;

//constant vars
const int TOTAL_RUNS = 10000;
const double AARON_PROB = 1.0/3;
const double BOB_PROB = 1.0/2;
const double CHARLIE_PROB = 1.0;  // always hits

//function prototypes
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive);
void Aaron_shoots1(bool& B_alive, bool& C_alive);
void Bob_shoots(bool& A_alive, bool& C_alive);
void Charlie_shoots(bool& A_alive, bool& B_alive);
void Aaron_shoots2(bool& B_alive, bool& C_alive);
void test_at_least_two_alive();

//ref
void pause();

int main() {
    //main logic
    test_at_least_two_alive();


    return 0;
}

//TODO*****************************************************************************************************
//TODO Check If At Least Two are Alive
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) {
    return (A_alive && B_alive) || (A_alive && C_alive) || (B_alive && C_alive);
}

//TODO*****************************************************************************************************
//TODO Aaron Shoots Strategy 1
void Aaron_shoots1(bool& B_alive, bool& C_alive) {
    double hit = rand() / static_cast<double>(RAND_MAX);

    // if Charlie is alive, he's the target, else Bob
    if(C_alive && hit < AARON_PROB) {
        C_alive = false;
    } else if(B_alive && hit < AARON_PROB) {
        B_alive = false;
    }
}

//TODO*****************************************************************************************************
//TODO Bob Shoots
void Bob_shoots(bool& A_alive, bool& C_alive) {
    double hit = rand() / static_cast<double>(RAND_MAX);

    // if Charlie is alive, he's the target, else Aaron
    if(C_alive && hit < BOB_PROB) {
        C_alive = false;
    } else if(A_alive && hit < BOB_PROB) {
        A_alive = false;
    }
}

//TODO*****************************************************************************************************
//TODO Charlie Shoots
void Charlie_shoots(bool& A_alive, bool& B_alive) {
    // Charlie never misses
    if(B_alive) {
        B_alive = false;
    } else if(A_alive) {
        A_alive = false;
    }
}

//TODO*****************************************************************************************************
//TODO Aaron Shoots Strategy 2
void Aaron_shoots2(bool& B_alive, bool& C_alive) {
    // TODO: Implement the logic for Strategy 2 for Aaron
}

//TODO*****************************************************************************************************
//TODO Test Function for at_least_two_alive
void test_at_least_two_alive() {
    cout << "Unit Testing 1: Function – at_least_two_alive()\n";
    cout << "Case 1: Aaron alive, Bob alive, Charlie alive\n";
    assert(at_least_two_alive(true, true, true));
    cout << "Case passed ...\n";
    // ... add more tests ...
    pause();
}

//TODO*****************************************************************************************************
//TODO Pause Function
void pause() {
    cout << "Press Enter to continue...";
    cin.ignore().get();
}