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

    cout << "Total Sum: " << sum << endl;

    //4. OPEN FILE FOR WRITING (OUTPUT)
    //ofstream stands for "output file stream"
    // If sum.txt dosen't exist, it craetes it. If ot does, it overwrites it!
    ofstream outputFile("sum.txt");

    if (!outputFile.is_open()) {
        cout << "Error: Could not create sum.txt for writing!" << endl;
        return 1;
    }

    //5. WRITE DATA TO FILE
    // The '<<" operator writes to the file just like 'cout' writes to the screen.
    outputFile << "The total sum is: " << sum << endl;
    outputFile << "Calculated automatically by the C++ program." << endl;

    //6. CLOSE THE FILE
    outputFile.close();

    cout << "Result successfully saved to sum.txt!" << endl;

    return 0;
}