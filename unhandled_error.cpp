#include <iostream>
#include <fstream>
using namespace std;

int main() {
    //We are trying to open a file called "missing_file.txt" which does not exist
    ifstream myFile ("missing_file.txt");

    //We are skipping the is_open() check

    string data;

    cout << "Attempting to read from missing file..." << endl;

    //Attempting to read from a failed stream
    myFile >> data;
    
    cout << "Data read: " << data << endl;
    cout << "Program continued running without crashing." << endl;

    return 0;
}