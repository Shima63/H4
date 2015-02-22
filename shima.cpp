/*
 * H4 Program, Fibonacci Sequence
 * To Demonstrate That You Have Secured Access to the Computer Resources necessary to be Successful in the Course,
 * And How to Design and Use Functions
 * By Shima Azizzadeh-Roodpish
 * 22 Feb 2015
 * No Copyright
 * Github account: https://github.com/Shima63/H4.git
 */
 
// External Libraries
 
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

// Main Program.
// Return Zero on Success, Non-Zero in case of Failure.

int main () {

    // Defining Variables' Type

    int num_of_rows = 0, m = 0, n = 0;
    float i = 0, j = 1;
    string inputfilename = "shima.in", outputfilename = "shima.out";

    // First Checking Messages.
    
    cout << "I was able to compile this code using the HPC at the University of Memphis. When I compiled it there, it did not produce any warning message. The HPC uses a GNU C++ compiler that can be considered a good up-to-date standard. I also version-controlled this code using git, and used a remote repository hosted by github. If I can do this, so can you!!!" << endl;
    cout << endl << "I am so cool, that I was also able to write a code that produces the first M numbers of the Fibonacci sequence. Here they are:" << endl;

    
    // Open the Input File.

    ifstream inputfile;
    inputfile.open(inputfilename.c_str());

    // Check to Make Sure the File Is Opened Properly

    if ( !inputfile.is_open() ) {
        cout << "Input file does not exist!" << endl;
        return 1;
    }   
    
    inputfile >> num_of_rows;
    
    //  Check the Validity of Input
    
    if ( num_of_rows < 1 ) {
        cout << endl << "Input for number of rows is not valid. It should be equal or more than one" << endl;
        return 2;
    }    

    // Preparing Output File
    
    ofstream outputfile;
    outputfile.open(outputfilename.c_str());

    // Producing Fibonacci Series. In Math It Starts from 1, But in Modern Usage It Starts from 0. We Choose 0 as a Starting Point.
    

    for ( n = 1; n <= num_of_rows; n++ ) {
        m = 0;
        while ( m < 10 ) {
            cout << setw (20) << left << i; // Less than 20 Digits Assumed for Numbers
            cout << setw (20) << left << j;
            outputfile << setw (20) << left << i;
            outputfile << setw (20) << left << j;
            i = i + j;
            j = j + i;
            m = m + 2;
        } 
        cout << endl;
        outputfile << endl;   
    }
    
    inputfile.close ();
    outputfile.close ();
    
    return 0;
}
 