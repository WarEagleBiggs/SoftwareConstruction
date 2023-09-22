//TODO AUTHOR: Adam Biggs
//TODO ID: ajb0217
//TODO Project 2 - Duel Simulation
/** References
 * https://auburn.instructure.com/courses/1517529/files/folder/Slides?preview=226110950
 * https://www.w3schools.com/cpp/cpp_pointers.asp
 * https://stackoverflow.com/questions/1571340/what-is-the-assert-function
 * https://en.cppreference.com/w/cpp/numeric/random/RAND_MAX
 * https://www.geeksforgeeks.org/understanding-nullptr-c/
 *
 * TODO - TO COMPILE USE (due to version)
 * g++ -std=c++0x main.cpp
 * TO RUN USE
 * ./a.out
 */

//imports
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <iomanip>
#include <limits>

using namespace std;

//constant vars -- gets probability
const int TOTAL_RUNS = 10000;
const double AARON_PROB = 1.0/3;
const double BOB_PROB = 1.0/2;
const double CHARLIE_PROB = 1.0;

//function prototypes -- for calls
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive);
void Aaron_shoots1(bool& B_alive, bool& C_alive);
void Bob_shoots(bool& A_alive, bool& C_alive);
void Charlie_shoots(bool& A_alive, bool& B_alive);
void Aaron_shoots2(bool& B_alive, bool& C_alive);
void test_at_least_two_alive();
void pause();

//TODO*****************************************************************************************************
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) {
    return (A_alive && B_alive) || (A_alive && C_alive) || (B_alive && C_alive);
}

//TODO*****************************************************************************************************
void Aaron_shoots1(bool &B_alive, bool &C_alive) {
    double hit = rand() / static_cast<double>(RAND_MAX);
    if (C_alive && hit < AARON_PROB) {
        C_alive = false;
    } else if (B_alive && hit < AARON_PROB) {
        B_alive = false;
    }
}


/*//TODO*****************************************************************************************************
void Bob_shoots1(bool &A_alive, bool &C_alive) {
    double hit = rand() / static_cast<double>(RAND_MAX);
    if (hit < BOB_PROB) {
        C_alive = false;
    } else {
        A_alive = false;
    }
}*/

//TODO*****************************************************************************************************
void Bob_shoots(bool &A_alive, bool &C_alive) {

    double hit = rand() / static_cast<double>(RAND_MAX);
    if (C_alive && hit < BOB_PROB) {
        C_alive = false;
    } else if (A_alive && hit < BOB_PROB) {
        A_alive = false;
    }
}

//TODO*****************************************************************************************************
void Charlie_shoots(bool &A_alive, bool &B_alive) {
    if (B_alive) {
        B_alive = false;
    } else if (A_alive) {
        A_alive = false;
    }
}

//TODO*****************************************************************************************************
void Aaron_shoots2(bool &B_alive, bool &C_alive) {

    double hit = rand() / static_cast<double>(RAND_MAX);
    if (!B_alive && hit < AARON_PROB) {
        C_alive = false;
    } else if (!C_alive && hit < AARON_PROB) {
        B_alive = false;
    }
}

//TODO*****************************************************************************************************
void test_at_least_two_alive() {
    //TODO USE ASSERT!!!!
    //4th attempt please work
    cout << "*** Welcome to Adam Biggs's Duel Simulator ***\n";

    cout << "Unit Testing 1: Function - at_least_two_alive()\n";

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

    cout << "Case 5: Aaron dead, Bob dead, Charlie alive\n";
    assert(!at_least_two_alive(false, false, true));
    cout << "Case passed ...\n";

    cout << "Case 6: Aaron dead, Bob alive, Charlie dead\n";
    assert(!at_least_two_alive(false, true, false));
    cout << "Case passed ...\n";

    cout << "Case 7: Aaron alive, Bob dead, Charlie dead\n";
    assert(!at_least_two_alive(true, false, false));
    cout << "Case passed ...\n";

    cout << "Case 8: Aaron dead, Bob dead, Charlie dead\n";
    assert(!at_least_two_alive(false, false, false));
    cout << "Case passed ...\n";

    pause();
}

//TODO*****************************************************************************************************
void test_Aaron_shoots1() {
    cout << "Unit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n";

    cout << "Case 1: Bob alive, Charlie alive\n";

    bool Bob_alive = true, Charlie_alive = true;
    Aaron_shoots1(Bob_alive, Charlie_alive);
    if (!Charlie_alive) cout << "Aaron is shooting at Charlie\n";
    else cout << "Aaron missed\n";

    cout << "Case 2: Bob dead, Charlie alive\n";

    Bob_alive = false; Charlie_alive = true;
    Aaron_shoots1(Bob_alive, Charlie_alive);
    if (!Charlie_alive) cout << "Aaron is shooting at Charlie\n";
    else cout << "Aaron missed\n";

    cout << "Case 3: Bob alive, Charlie dead\n";

    Bob_alive = true; Charlie_alive = false;
    Aaron_shoots1(Bob_alive, Charlie_alive);
    if (!Bob_alive) cout << "Aaron is shooting at Bob\n";
    else cout << "Aaron missed\n";

    pause();
}

//TODO*****************************************************************************************************
void test_Bob_shoots() {
    cout << "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)\n";

    cout << "Case 1: Aaron alive, Charlie alive\n";

    bool Aaron_alive = true, Charlie_alive = true;
    Bob_shoots(Aaron_alive, Charlie_alive);
    if (!Charlie_alive) cout << "Bob is shooting at Charlie\n";
    else cout << "Bob missed\n";

    cout << "Case 2: Aaron dead, Charlie alive\n";

    Aaron_alive = false; Charlie_alive = true;
    Bob_shoots(Aaron_alive, Charlie_alive);
    if (!Charlie_alive) cout << "Bob is shooting at Charlie\n";
    else cout << "Bob missed\n";

    cout << "Case 3: Aaron alive, Charlie dead\n";

    Aaron_alive = true; Charlie_alive = false;
    Bob_shoots(Aaron_alive, Charlie_alive);
    if (!Aaron_alive) cout << "Bob is shooting at Aaron\n";
    else cout << "Bob missed\n";

    pause();
}

//TODO*****************************************************************************************************
void test_Charlie_shoots() {
    cout << "Unit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)\n";

    cout << "Case 1: Aaron alive, Bob alive\n";

    bool Aaron_alive = true, Bob_alive = true;
    Charlie_shoots(Aaron_alive, Bob_alive);
    if (!Bob_alive) cout << "Charlie is shooting at Bob\n";

    cout << "Case 2: Aaron dead, Bob alive\n";

    Aaron_alive = false; Bob_alive = true;
    Charlie_shoots(Aaron_alive, Bob_alive);
    if (!Bob_alive) cout << "Charlie is shooting at Bob\n";

    cout << "Case 3: Aaron alive, Bob dead\n";

    Aaron_alive = true; Bob_alive = false;
    Charlie_shoots(Aaron_alive, Bob_alive);
    if (!Aaron_alive) cout << "Charlie is shooting at Aaron\n";

    pause();
}

//TODO*****************************************************************************************************
void test_Aaron_shoots2() {
    cout << "Unit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)\n";

    cout << "Case 1: Bob alive, Charlie alive\n";

    bool Bob_alive = true, Charlie_alive = true;
    Aaron_shoots2(Bob_alive, Charlie_alive);
    cout << "Aaron intentionally misses his first shot\n";
    cout << "Both Bob and Charlie are alive.\n";

    cout << "Case 2: Bob dead, Charlie alive\n";

    Bob_alive = false; Charlie_alive = true;
    Aaron_shoots2(Bob_alive, Charlie_alive);
    if (!Charlie_alive) cout << "Aaron is shooting at Charlie\n";
    else cout << "Aaron missed\n";

    cout << "Case 3: Bob alive, Charlie dead\n";

    Bob_alive = true; Charlie_alive = false;
    Aaron_shoots2(Bob_alive, Charlie_alive);
    if (!Bob_alive) cout << "Aaron is shooting at Bob\n";
    else cout << "Aaron missed\n";

    pause();
}


//TODO*****************************************************************************************************
void pause() {
    //for linux
    cout << "Press any key to continue...";
    cin.ignore().get();
}

//TODO*****************************************************************************************************
int main() {
    //rand
    srand(time(nullptr));

    //calls to functions
    test_at_least_two_alive();
    test_Aaron_shoots1();
    test_Bob_shoots();
    test_Charlie_shoots();
    test_Aaron_shoots2();

    //strat 1-------------------------------------------------
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

    //output results
    cout << "Ready to test strategy 1 (run 10000 times):\n";
    pause();
    cout << "Aaron won " << Aaron_wins1 << "/10000 duels or " << setprecision(2)
         << (double)Aaron_wins1 / TOTAL_RUNS * 100 << "%\n";
    cout << "Bob won " << Bob_wins << "/10000 duels or " << setprecision(2)
         << (double)Bob_wins / TOTAL_RUNS * 100 << "%\n";
    cout << "Charlie won " << Charlie_wins << "/10000 duels or " << setprecision(2)
         << (double)Charlie_wins / TOTAL_RUNS * 100 << "%\n";

    //strat 2--------------------------------------------------
    int Aaron_wins2 = 0;
    Bob_wins = 0;
    Charlie_wins = 0;
    for (int i = 0; i < TOTAL_RUNS; ++i) {
        bool A_alive = true, B_alive = true, C_alive = true;
        while (at_least_two_alive(A_alive, B_alive, C_alive)) {
            if (A_alive) {
                Aaron_shoots2(B_alive, C_alive);
            }
            if (B_alive) {
                Bob_shoots(A_alive, C_alive);
            }
            if (C_alive) {
                Charlie_shoots(A_alive, B_alive);
            }
        }
        if (A_alive) {
            ++Aaron_wins2;
        } else if (B_alive) {
            ++Bob_wins;
        } else {
            ++Charlie_wins;
        }
    }

    cout << "Ready to test strategy 2 (run 10000 times):\n";
    pause();
    cout << "Aaron won " << Aaron_wins2 << "/10000 duels or " << setprecision(2)
         << (double)Aaron_wins2 / TOTAL_RUNS * 100 << "%\n";
    cout << "Bob won " << Bob_wins << "/10000 duels or " << setprecision(2)
         << (double)Bob_wins / TOTAL_RUNS * 100 << "%\n";
    cout << "Charlie won " << Charlie_wins << "/10000 duels or " << setprecision(2)
         << (double)Charlie_wins / TOTAL_RUNS * 100 << "%\n";


    //final determination
    if (Aaron_wins2 > Aaron_wins1) {
        cout << "Strategy 2 is better than strategy 1.\n";
    } else {
        cout << "Strategy 1 is better than strategy 2.\n";
    }

    //blank return
    return 0;
}