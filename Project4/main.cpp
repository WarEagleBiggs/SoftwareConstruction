//TODO AUTHOR: Adam Biggs
//TODO ID: ajb0217
//TODO FILENAME: project4_Biggs_ajb0217.cpp
//TODO Trivia Quiz Game

/** References:
 * https://en.cppreference.com/w/cpp/container/list
 * https://www.cplusplus.com/reference/string/string/getline/
 */

#include <iostream>
#include <string>
#include <cctype>
#include <limits>
using namespace std;

//TODO CONSTANTS
const int NOT_INITIALIZED = -1;

//TODO STRUCTURE FOR TRIVIA DATA
struct TriviaNode {
    string question;
    string answer;
    int points;
    TriviaNode* next;

    TriviaNode(): next(nullptr), points(NOT_INITIALIZED) {}
    TriviaNode(const string& q, const string& a, int p, TriviaNode* n = nullptr)
            : question(q), answer(a), points(p), next(n) {}
};

//TODO GLOBAL VARIABLES
TriviaNode* triviaStart = nullptr;

//TODO FUNCTION DECLARATIONS
TriviaNode* initializeTrivia();
void addTrivia(TriviaNode*& head, const string& q = "", const string& a = "", int p = NOT_INITIALIZED);
int askQuestion(TriviaNode* head, int numberOfQuestions);
#ifdef UNIT_TESTING
void testDriver(TriviaNode* head);
#else
void productionVersion(TriviaNode* head);
#endif
void cleanup(TriviaNode*& head);
string normalize(const string& str);

//TODO*****************************************************************************************************
//TODO main function
int main() {
    cout << "*** Welcome to Adam's Trivia Quiz Game ***" << endl;

    triviaStart = initializeTrivia();

#ifdef UNIT_TESTING
    testDriver(triviaStart);
#else
    productionVersion(triviaStart);
#endif

    cleanup(triviaStart);
    cout << "*** Thank you for playing. Goodbye! ***" << endl;
    return 0;
}

//TODO*****************************************************************************************************
//TODO Initialize trivia
TriviaNode* initializeTrivia() {
    addTrivia(triviaStart, "How long was the shortest war on record? (Hint: how many minutes)", "38", 100);
    addTrivia(triviaStart, "What was Bank of America’s original name? (Hint: Bank of Italy or Bank of Germany)", "Bank of Italy", 50);
    addTrivia(triviaStart, "What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sports)?", "Wii Sports", 20);

    return triviaStart;
}

//TODO---------------------------------------------------------------
//TODO Add trivia
void addTrivia(TriviaNode*& head, const string& q, const string& a, int p) {
    TriviaNode* newNode = new TriviaNode(q, a, p);

    if (!head) {
        head = newNode;
    } else {
        TriviaNode* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

//TODO---------------------------------------------------------------
//TODO Ask questions
int askQuestion(TriviaNode* head, int numberOfQuestions) {
    TriviaNode* current = head;
    int correctCount = 0;
    string userAnswer;

    for (int i = 1; i <= numberOfQuestions && current; i++) {
        cout << "Question: " << current->question << "\nAnswer: ";
        getline(cin, userAnswer);

        if (normalize(userAnswer) == normalize(current->answer)) {
            cout << "Correct! You've earned " << current->points << " points.\n";
            correctCount += current->points;
        } else {
            cout << "Sorry, the correct answer was: " << current->answer << "\n";
        }

        current = current->next;
    }

    return correctCount;
}

#ifdef UNIT_TESTING
//TODO*****************************************************************************************************
//TODO Testing Driver
void testDriver(TriviaNode* head) {
    //... [Rest of the test driver logic here]
}
#endif

#ifndef UNIT_TESTING
//TODO*****************************************************************************************************
//TODO Production Version
void productionVersion(TriviaNode* head) {
    int numberOfQuestions;
    cout << "How many questions would you like to answer? ";
    cin >> numberOfQuestions;
    cin.ignore(); // clear newline from buffer

    int score = askQuestion(head, numberOfQuestions);
    cout << "Your total points: " << score << endl;
}
#endif

//TODO---------------------------------------------------------------
//TODO Cleanup memory
void cleanup(TriviaNode*& head) {
    TriviaNode* temp;

    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

//TODO---------------------------------------------------------------
//TODO Normalize string
string normalize(const string& str) {
    string normalized;
    for (char c : str) {
        if (!isspace(c)) {
            normalized += tolower(c);
        }
    }
    return normalized;
}