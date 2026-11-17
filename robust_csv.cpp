#include <iostream>
#include <fstream>
#include <sstream> // required for stringstream (parsing CSV)
#include <string>
#include <stdexcept>
using namespace std;

int main(){
    //open file
    ifstream file("students.csv");

    //1. HANDLE MISSING FILE GRACEFULLY
    if (!file.is_open()){
        cout <<"Error: Could not find students.csv!"<< endl;
        return 1;
    }

    string line;
    cout <<"---Processing Student Records---"<< endl;

    //2. READ THE FILE LINE BY LINE
    while (getline(file, line)){
        //Skip empty lines
        if (line.empty()) continue;

        stringstream ss(line);
        string name;
        string scoreStr1, scoreStr2, scoreStr3;

        //Extract data separated by commas
        getline(ss, name, ',');
        getline(ss, scoreStr1, ',');
        getline(ss, scoreStr2, ',');
        getline(ss, scoreStr3, ',');

        //3. EXCEPTION HANDLING FOR MALFORMED DATA
        try {
            //stoi converts a string to an integer.
            //If the string is "Error", stoi will throw an exception.
            int s1 = stoi(scoreStr1);
            int s2 = stoi(scoreStr2);
            int s3 = stoi(scoreStr3);

            //Calculate average score
            double average = (s1 + s2 + s3) / 3.0;
            cout << name << "->Average: " << average << endl;

        }catch (const invalid_argument& e){
            //This block runs if stoi fails to convert the text to a number
            cout<<"WARNING: Skipping malformed record for " << name << "(Invalid score data)." << endl;
            // Because we caught the error, the loop continues to the next student!
        }
    }

    file.close();
    cout << "\n---proccessing Complete---" << endl;
    return 0;
}