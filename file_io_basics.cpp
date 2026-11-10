#include <iostream>
#include <fstream> // required for file input/output
using namespace std;

int main() {
    //1. OPEN FILE FOR READING (INPUT)
    //ifstream stands for "input file stream"
    ifstream inputFile("numbers.txt");

    //Check if the file was opened successfully
    if (!inputFile.is_open()) {
        cout << "Error: Could not open numbers.txt for reading!" << endl;
        return 1; // Exit the error code
    }

    int num;
    int sum = 0;

    cout << "Reading numbers from file..." << endl;

    //2. READ DATA IN A LOOP
    //The '>>' operator extracts data from the filr just like 'cin'
    // It returns false when it reaches the end of the file.
    while (inputFile >> num) {
        cout << "Read: " << num << endl;
        sum += num;
    }

    //3. CLOSE THE FILE
    //Always close a file when you are done with it to free up system resources.
    inputFile.close();
}