#include <iostream>
#include <fstream>
#include <stdexcept> // required for standard exceptions
using namespace std;

// Method 1: using Return Codes (The old C way)
// Returns true if successful, false if failed.
bool readFileWithReturnCode(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        //We must manually pass the error back up
        return false;
    }
    // read file
    return true;
}

//Method 2: Using Exceptions (The modern C++ way)
void readFileWithException(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        //We actively throw an error. The program will immediately stop
        //looking for the file and jump to the catch block.
        throw runtime_error("File not found: " + filename);
    }
    // read file
}

int main() {
    cout << "---Testing Return Code Strategy---" << endl;
    if (readFileWithReturnCode("data.txt")== false){
        cout << "Return Code: Handled error gracefully. Program continues." << endl;
    }

    cout <<"\n---Testing Exception Strategy---" << endl;
    //We put the dangerous code in a 'try' block
    try{
        readFileWithException("data.txt");
    }
    //If an exception is thrown, the 'catch' block handles it.
    catch (const runtime_error& e){
        cout <<"Exception Caught: " << e.what() << endl;
        cout <<"Exception Strategy: Forced us to handle the error!" << endl;

    }

    return 0;
}