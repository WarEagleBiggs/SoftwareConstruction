//TODO AUTHOR: Adam Biggs
//TODO ID: ajb0217
//TODO Project 3 - File Merging Program

/** References:
 * https://auburn.instructure.com/courses/1517529/external_tools/9744
 * https://en.cppreference.com/w/cpp/io/basic_ifstream
 * https://en.cppreference.com/w/cpp/io/basic_ofstream
 *
 * TODO - TO COMPILE USE (due to version)
 * g++ -std=c++0x project3_Biggs_ajb0217.cpp
 * TO RUN USE
 * ./a.out
 */
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

// Vars
const int MAX_SIZE = 100;
int inputArray1[MAX_SIZE], inputArray2[MAX_SIZE], outputArray[2 * MAX_SIZE];
int inputArray1_size, inputArray2_size, outputArray_size;
string filename1, filename2, outputFilename;

// Function Ref for calls
void ReadFirstFile();
void ReadSecondFile();
void SortAndMerge();
void WriteToFile();
void DisplaySortedNumbers();

//TODO*****************************************************************************************************
//TODO main
int main() {
    cout << "*** Welcome to Adam's sorting program ***" << endl;

    // Get values and process
    ReadFirstFile();
    ReadSecondFile();
    SortAndMerge();
    DisplaySortedNumbers();
    WriteToFile();

    cout << "*** Goodbye. ***" << endl;
    return 0;
}

//TODO*****************************************************************************************************
//TODO Read First File
void ReadFirstFile(){
    cout << "************************************" << endl;
    cout << "Enter the first input file name:" << endl;
    cin >> filename1;
    ifstream inStream1(filename1.c_str());
    if (inStream1.fail()) {
        cout << "Error: Failed to open " << filename1 << endl;
        return;
    }
    int index = 0;
    cout << "The list of numbers in file " << filename1 << " is:" << endl;
    while (inStream1 >> inputArray1[index]) {
        cout << inputArray1[index] << endl;
        index++;
    }
    inputArray1_size = index;
    inStream1.close();
}

//TODO---------------------------------------------------------------
//TODO Read Second File
void ReadSecondFile(){
    cout << "************************************" << endl;
    cout << "Enter the second input file name:" << endl;
    cin >> filename2;
    ifstream inStream2(filename2.c_str());
    if (inStream2.fail()) {
        cout << "Error: Failed to open " << filename2 << endl;
        return;
    }
    int index = 0;
    cout << "The list of numbers in file " << filename2 << " is:" << endl;
    while (inStream2 >> inputArray2[index]) {
        cout << inputArray2[index] << endl;
        index++;
    }
    inputArray2_size = index;
    inStream2.close();
}

//TODO---------------------------------------------------------------
//TODO Sort And Merge
void SortAndMerge(){
    int i = 0, j = 0, k = 0;
    while (i < inputArray1_size && j < inputArray2_size) {
        if (inputArray1[i] < inputArray2[j]) {
            outputArray[k++] = inputArray1[i++];
        } else {
            outputArray[k++] = inputArray2[j++];
        }
    }
    while (i < inputArray1_size) {
        outputArray[k++] = inputArray1[i++];
    }
    while (j < inputArray2_size) {
        outputArray[k++] = inputArray2[j++];
    }
    outputArray_size = k;
}

//TODO---------------------------------------------------------------
//TODO Display Sorted Numbers
void DisplaySortedNumbers(){
    cout << "The sorted list of numbers is: ";
    for (int m = 0; m < outputArray_size; m++) {
        cout << outputArray[m] << " ";
    }
    cout << endl;
}

//TODO---------------------------------------------------------------
//TODO Write to File
void WriteToFile(){
    cout << "************************************" << endl;
    cout << "Enter the output file name:" << endl;
    cin >> outputFilename;
    ofstream outStream(outputFilename.c_str());
    if (outStream.fail()) {
        cout << "Error: Failed to open " << outputFilename << " for writing" << endl;
        return;
    }
    for (int i = 0; i < outputArray_size; i++) {
        outStream << outputArray[i] << endl;
    }
    outStream.close();
    cout << "*** Please check the new file - " << outputFilename << " ***" << endl;
}