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

// Functions

// "open_input" Function Will Read the Input File and Will Check Its Validity. It Returns One If the File Is Not Valid.
    
bool open_input ( string inputfilename, ifstream & ifs ) {
    ifs.open(inputfilename.c_str());

    // Check to Make Sure the File Is Opened Properly

    if ( !ifs.is_open() ) {
        return 1;
    }   
    return 0;
} 

// "open_file" Function Will Make a New File.
    
void open_file ( string filename, ofstream & ofs ) {
    ofs.open(filename.c_str());
    return;
} 

// "print_output" function Prints Messages on Files.

//void print_output( ofstream & ofs, string message) {
    //ofs << message;
    //return;
//}


// "warning" Function Will Send Error Messages to Terminal and Error-file
// 'a' Is the Number of Entry with Errors, 'b' Is Part of Entry That Has the Error and 'c' Is the Name of Output File for Error

//void warning ( int a, string b, string c ) {
    //cout << "Warning: There is a problem with the name of the station in entry " << a << " . " << b << " is not valid and is ignored" << endl;
    //c << "Warning: There is a problem with the name of the station in entry " << a << " . " << b << " is not valid and is ignored" << "\n" ;
    //c << endl;
    
    //return;
//}    


// Main Program.
// Return Zero on Success, Non-Zero in case of Failure.

int main () {

    // Defining Variables' Type

    int num_of_rows = 0, m = 0, n = 0, check = 0;
    float i = 0, j = 1;
    string inputfilename = "shima.in", outputfilename = "shima.out", errorfilename = "shima.err";

    // First Checking Messages.
    
    cout << "I was able to compile this code using the HPC at the University of Memphis. When I compiled it there, it did not produce any warning message. The HPC uses a GNU C++ compiler that can be considered a good up-to-date standard. I also version-controlled this code using git, and used a remote repository hosted by github. If I can do this, so can you!!!" << endl << endl;
    cout << "I am so cool, that I was also able to write a code that produces the first M numbers of the Fibonacci sequence. Here they are:" << endl << endl;

    
    // Open the Input File. 
    
    ifstream inputfile;
	check = open_input ( inputfilename, inputfile );
	if ( check == 1 ) {
	    cout << "Input file does not exist!" << endl;
	    
	    // Making error file When There Is Error

	    ofstream errorfile;
	    open_file ( errorfilename, errorfile );
        errorfile << "Input file does not exist!" << endl;
        return 1;
    }    
  
    //  Check the Validity of Input
    
    inputfile >> num_of_rows;
    if ( num_of_rows < 1 ) {
        cout << "Input for number of rows is not valid. It should be equal or more than one." << endl;
        ofstream errorfile;
        open_file ( errorfilename, errorfile );
        errorfile << "Input for number of rows is not valid. It should be equal or more than one." << endl;
        return 2;
    }    

    // Preparing output file
    
    ofstream outputfile;
    open_file ( outputfilename, outputfile );

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
 