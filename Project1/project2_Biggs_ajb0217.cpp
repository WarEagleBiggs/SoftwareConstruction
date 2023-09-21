//TODO AUTHOR: Adam Biggs
//TODO ID: ajb0217
//TODO Project 2 - Duel Simulation
/** References
 * https://auburn.instructure.com/courses/1517529/files/folder/Slides?preview=226110950
 * https://www.w3schools.com/cpp/cpp_pointers.asp
 * https://stackoverflow.com/questions/1571340/what-is-the-assert-function
 *
 * TODO - TO COMPILE USE (due to version)
 * g++ -std=c++0x main.cpp
 * TO RUN USE
 * ./a.out
 */

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <iomanip>

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
void pause();

//TODO*****************************************************************************************************
//TODO Check If At Least Two are Alive
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) {
    return (A_alive && B_alive) || (A_alive && C_alive) || (B_alive && C_alive);
}

//TODO*****************************************************************************************************
//TODO Aaron Shoots Strategy 1
void Aaron_shoots1(bool &B_alive, bool &C_alive) {
    double hit = rand() / static_cast<double>(RAND_MAX);
    if (C_alive && hit < AARON_PROB) {
        C_alive = false;
    } else if (B_alive && hit < AARON_PROB) {
        B_alive = false;
    }
}

//TODO*****************************************************************************************************
//TODO Bob Shoots
void Bob_shoots(bool &A_alive, bool &C_alive) {
    double hit = rand() / static_cast<double>(RAND_MAX);
    if (C_alive && hit < BOB_PROB) {
        C_alive = false;
    } else if (A_alive && hit < BOB_PROB) {
        A_alive = false;
    }
}

//TODO*****************************************************************************************************
//TODO Charlie Shoots
void Charlie_shoots(bool &A_alive, bool &B_alive) {
    if (B_alive) {
        B_alive = false;
    } else if (A_alive) {
        A_alive = false;
    }
}

//TODO*****************************************************************************************************
//TODO Aaron Shoots Strategy 2
void Aaron_shoots2(bool &B_alive, bool &C_alive) {
    double hit = rand() / static_cast<double>(RAND_MAX);
    if (!B_alive && hit < AARON_PROB) {
        C_alive = false;
    } else if (!C_alive && hit < AARON_PROB) {
        B_alive = false;
    }
}

//TODO*****************************************************************************************************
//TODO Test Function for at_least_two_alive
void test_at_least_two_alive() {
    cout << "Unit Testing 1: Function – at_least_two_alive()\n";
    cout << "Case 1: Aaron alive, Bob alive, Charlie alive\n";
    assert(at_least_two_alive(true, true, true));
    cout << "Case passed ...\n";
    cout << "Case 2: Aaron dead, Bob alive, Charlie alive\n";
    assert(at_least_two_alive(false, true, true));
    cout << "Case passed ...\n";
    cout << "Case 3: Aaron alive, Bob dead, Charlie alive\n";
    assert(at_least_two_alive(true, false, true));
    cout << "Case passed ...\n";
    cout << "Case 4: Aaron alive, Bob alive, Charlie dead\n";
    assert(at_least_two_alive(true, true, false));
    cout << "Case passed ...\n";
    pause();
}

//TODO*****************************************************************************************************
//TODO Pause Function
void pause() {
    cout << "Press Enter to continue...";
    cin.ignore().get();
}

int main() {
    test_at_least_two_alive();
    int Aaron_wins1 = 0, Bob_wins = 0, Charlie_wins = 0;
    for (int i = 0; i < TOTAL_RUNS; ++i) {
        bool A_alive = true, B_alive = true, C_alive = true;
        while (at_least_two_alive(A_alive, B_alive, C_alive)) {
            if (A_alive) {
                Aaron_shoots1(B_alive, C_alive);
            }
            if (B_alive) {
                Bob_shoots(A_alive, C_alive);
            }
            if (C_alive) {
                Charlie_shoots(A_alive, B_alive);
            }
        }
        if (A_alive) {
            ++Aaron_wins1;
        } else if (B_alive) {
            ++Bob_wins;
        } else {
            ++Charlie_wins;
        }
    }

    cout << "Simulation results after " << TOTAL_RUNS << " duels:\n";
    cout << "Aaron wins with strategy 1: " << Aaron_wins1 << " (" << setprecision(2)
         << (double) Aaron_wins1 / TOTAL_RUNS * 100 << "%)\n";
    cout << "Bob wins: " << Bob_wins << " (" << setprecision(2) << (double) Bob_wins / TOTAL_RUNS * 100 << "%)\n";
    cout << "Charlie wins: " << Charlie_wins << " (" << setprecision(2) << (double) Charlie_wins / TOTAL_RUNS * 100
         << "%)\n";

    return 0;
}