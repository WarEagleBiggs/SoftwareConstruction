//TODO AUTHOR: Adam Biggs
//TODO ID: ajb0217
//TODO FILENAME: project3_Biggs_ajb0217.cpp
//TODO Project 3 - File Merging Program

/** References:
 * https://auburn.instructure.com/courses/1517529/external_tools/9744
 * https://en.cppreference.com/w/cpp/io/basic_ifstream
 * https://en.cppreference.com/w/cpp/io/basic_ofstream
 * https://stackoverflow.com/questions/8412347/combining-c-header-files
 * https://www.codesdope.com/blog/article/program-to-merge-contents-of-two-files-in-third/
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

// Maximum size constant
const int MAX_SIZE = 100;

//TODO STRUCTURE FOR FILE DATA
//to keep small
struct FileData {
    int data[MAX_SIZE];
    int size;
    string filename;
};

//only 3 global vars
FileData input1, input2, outputData;

// Function Ref for calls
void ReadFile(FileData &fileData);
void SortAndMerge();
void DisplaySortedNumbers();
void WriteToFile();

//TODO*****************************************************************************************************
//TODO main
int main() {
    //basic format
    cout << "*** Welcome to Adam's sorting program ***" << endl;

    // Get values and process
    ReadFile(input1);
    ReadFile(input2);
    SortAndMerge();
    DisplaySortedNumbers();
    WriteToFile();

    //end
    cout << "*** Goodbye. ***" << endl;
    return 0;
}

//TODO*****************************************************************************************************
//TODO Read file
void ReadFile(FileData &fileData){
    cout << "************************************" << endl;
    cout << "Enter the input file name:" << endl;
    cin >> fileData.filename;
    ifstream inStream(fileData.filename.c_str());
    if (inStream.fail()) {
        cout << "Error: Failed to open " << fileData.filename << endl;
        return;
    }
    int index = 0;
    cout << "The list of numbers in file " << fileData.filename << " is:" << endl;
    while (inStream >> fileData.data[index]) {
        cout << fileData.data[index] << endl;
        index++;
    }
    fileData.size = index;
    inStream.close();
}

//TODO---------------------------------------------------------------
//TODO Sort and merge
void SortAndMerge(){
    int i = 0, j = 0, k = 0;
    while (i < input1.size && j < input2.size) {
        if (input1.data[i] < input2.data[j]) {
            outputData.data[k++] = input1.data[i++];
        } else {
            outputData.data[k++] = input2.data[j++];
        }
    }
    while (i < input1.size) {
        outputData.data[k++] = input1.data[i++];
    }
    while (j < input2.size) {
        outputData.data[k++] = input2.data[j++];
    }
    outputData.size = k;
}

//TODO---------------------------------------------------------------
//TODO Display sorted numbers
void DisplaySortedNumbers(){
    cout << "The sorted list of numbers is: ";
    for (int m = 0; m < outputData.size; m++) {
        cout << outputData.data[m] << " ";
    }
    cout << endl;
}

//TODO---------------------------------------------------------------
//TODO Write to file
void WriteToFile(){
    cout << "************************************" << endl;
    cout << "Enter the output file name:" << endl;
    cin >> outputData.filename;
    ofstream outStream(outputData.filename.c_str());
    if (outStream.fail()) {
        cout << "Error: Failed to open " << outputData.filename << " for writing" << endl;
        return;
    }
    for (int i = 0; i < outputData.size; i++) {
        outStream << outputData.data[i] << endl;
    }
    outStream.close();

    cout << "*** Please check the new file - " << outputData.filename << " ***" << endl;
}