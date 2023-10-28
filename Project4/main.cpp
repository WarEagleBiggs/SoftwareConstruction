//TODO AUTHOR: Adam Biggs
//TODO ID: ajb0217
//TODO FILENAME: project4_Biggs_ajb0217.cpp
//TODO Trivia Quiz Game
//TODO COMPILE: g++ -o trivia project4_Biggs_ajb0217.cpp

/** References:
 * https://en.cppreference.com/w/cpp/container/list
 * https://www.cplusplus.com/reference/string/string/getline/
 * https://stackoverflow.com/questions/35670235/linked-list-c-node
 * https://stackoverflow.com/questions/21508088/linked-list-difference-between-node-head-new-node-and-node-head
 */

#include <iostream>
#include <string>
#include <cctype>
#include <limits>
//basic
using namespace std;

//TODO CONST
const int NOT_INITIALIZED = -1;

//TODO STRUCT
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
TriviaNode * triviaStart = nullptr;

//TODO FUNCTION DECLARATIONS
TriviaNode * initializeTrivia();
void addTrivia(TriviaNode*& head, const string& q = "", const string& a = "", int p = NOT_INITIALIZED);
int askQuestion(TriviaNode* head, int numberOfQuestions);

#ifdef UNIT_TESTING

void testDriver(TriviaNode* head);

#else

void productionVersion(TriviaNode* head);

#endif

void cleanup(TriviaNode *& head);

string normalize(const string& str);

//TODO*****************************************************************************************************
//TODO main function
int main() {
    cout << "*** Welcome to Adam's Trivia Quiz Game. ***" << endl;

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
//TODO initialize trivia
TriviaNode* initializeTrivia() {

    addTrivia(triviaStart, "How long was the shortest war on record? (Hint: how many minutes)", "38", 100);
    addTrivia(triviaStart, "What was Bank of America’s original name? (Hint: Bank of Italy or Bank of Germany)", "Bank of Italy", 50);
    addTrivia(triviaStart, "What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sports)?", "Wii Sports", 20);

    return triviaStart;
}

//TODO---------------------------------------------------------------
//TODO add trivia
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
//TODO ask questions
int askQuestion(TriviaNode* head, int numberOfQuestions) {
    //please work
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
//TODO testing driver
//tests cases. Hopefully works
void testDriver(TriviaNode * head) {
    cout << "Running the test driver...\n";

    // Test Case 1: All Correct Answers
    cout << "Test Case 1: Answer all questions correctly\n";
    int score1 = askQuestion(head, 3);
    if (score1 == 170) {
        cout << "Test Case 1 Passed!\n";
    } else {
        cout << "Test Case 1 Failed! Expected 170 but got " << score1 << "\n";
    }

    // Test Case 2: Some Correct Answers
    cout << "Test Case 2: Answer first two questions correctly, third one incorrectly\n";
    // You have to manually provide these answers when testing
    int score2 = askQuestion(head, 3);
    if (score2 == 150) {
        cout << "Test Case 2 Passed!\n";
    } else {
        cout << "Test Case 2 Failed! Expected 150 but got " << score2 << "\n";
    }

    // Test Case 3: No Correct Answers
    cout << "Test Case 3: All answers are incorrect\n";
    // You have to manually provide wrong answers for each question when testing
    int score3 = askQuestion(head, 3);
    if (score3 == 0) {
        cout << "Test Case 3 Passed!\n";
    } else {
        cout << "Test Case 3 Failed! Expected 0 but got " << score3 << "\n";
    }

    // Test Case 4: Asking More Questions Than Available
    cout << "Test Case 4: Asking more questions than available in the list\n";
    int score4 = askQuestion(head, 5);  // We only have 3 questions
    if (score4 == score1) {  // Should just get the score for the 3 questions
        cout << "Test Case 4 Passed!\n";
    } else {
        cout << "Test Case 4 Failed! Expected " << score1 << " but got " << score4 << "\n";
    }

    // Test Case 5: Testing Case Sensitivity
    cout << "Test Case 5: Answering with different cases but correct answer\n";
    // Manually provide the correct answers but with different cases
    int score5 = askQuestion(head, 3);
    if (score5 == 170) {
        cout << "Test Case 5 Passed!\n";
    } else {
        cout << "Test Case 5 Failed! Expected 170 but got " << score5 << "\n";
    }
}
#endif

#ifndef UNIT_TESTING
//TODO*****************************************************************************************************
//TODO production version
void productionVersion(TriviaNode* head) {

    char choice;

    cout << "Do you want to add a new trivia? (Y/N) ";
    cin >> choice;

    //wipe
    cin.ignore();

    while (toupper(choice) == 'Y') {

        string newQuestion, newAnswer;
        int newPoints;

        cout << "Enter your question: ";
        getline(cin, newQuestion);
        cout << "Enter the correct answer: ";
        getline(cin, newAnswer);
        cout << "Enter the point value for this question: ";
        cin >> newPoints;
        cin.ignore();

        addTrivia(triviaStart, newQuestion, newAnswer, newPoints);

        cout << "Do you want to add another trivia? (Y/N) ";
        cin >> choice;
        cin.ignore();
    }

    // Calculate total number of questions in the list
    int numberOfQuestions = 0;
    TriviaNode* temp = head;
    while (temp) {
        numberOfQuestions++;
        temp = temp->next;
    }

    int score = askQuestion(head, numberOfQuestions);
    cout << "Your total points: " << score << endl;
}
#endif

//TODO---------------------------------------------------------------
//TODO cleanup memory
void cleanup(TriviaNode*& head) {
    TriviaNode* temp;

    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

//TODO---------------------------------------------------------------
//TODO normalize string
string normalize(const string& str) {
    string normalized;
    for (char c : str) {
        if (!isspace(c)) {
            normalized += tolower(c);
        }
    }
    return normalized;
}