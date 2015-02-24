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
#include <sstream>
using namespace std;

// Function Prototype

bool open_input ( string, ifstream & );
void open_file ( string, ofstream & );
void print_file ( string, string, ofstream & );
void print_file ( string, double, ofstream & );

// Main Program.
// Return Zero on Success, Non-Zero in case of Failure.

int main () {

    // Defining Variables' Type

    int num_of_rows = 0, m = 0, n = 0, check = 0;
    double i = 0, j = 1;
    string inputfilename = "shima.in", outputfilename = "shima.out", errorfilename = "shima.err", message;

    // First Checking Messages.
    
    cout << "I was able to compile this code using the HPC at the University of Memphis. When I compiled it there, it did not produce any warning message. The HPC uses a GNU C++ compiler that can be considered a good up-to-date standard. I also version-controlled this code using git, and used a remote repository hosted by github. If I can do this, so can you!!!" << endl << endl;
    cout << "I am so cool, that I was also able to write a code that produces the first M numbers of the Fibonacci sequence. Here they are:" << endl << endl;

    
    // Open the Input File. 
    
    ifstream inputfile;
	check = open_input ( inputfilename, inputfile );
	if ( check == 1 ) {
	    message = "Input file does not exist!";
	    
	    // Making error file When There Is Error

	    ofstream errorfile;
	    open_file ( errorfilename, errorfile );
	    print_file ( errorfilename, message, errorfile );
        return 1;
    }    
  
    //  Check the Validity of Input
    
    inputfile >> num_of_rows;
    if ( num_of_rows < 1 ) {
        message = "Input for number of rows is not valid. It should be equal or more than one.";
        ofstream errorfile;
        
        // Making error file When There Is Error

        open_file ( errorfilename, errorfile );
	    print_file ( errorfilename, message, errorfile );
        return 2;
    }    

    // Preparing output file
    
    ofstream outputfile;
    open_file ( outputfilename, outputfile );

    // Producing Fibonacci Series. In Math It Starts from 1, But in Modern Usage It Starts from 0. We Choose 0 as a Starting Point.

    for ( n = 1; n <= num_of_rows; n++ ) {
        m = 0;
        while ( m < 10 ) {
            print_file ( outputfilename, i, outputfile );
            print_file ( outputfilename, j, outputfile );
            i = i + j;
            j = j + i;
            m = m + 2;
        }
        print_file ( outputfilename, "\n", outputfile );
    }
    
    inputfile.close ();
    outputfile.close ();
    
    return 0;
}


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

// This "print_file" function Prints Messages on Files and Terminal. Message Is of String Type.

void print_file ( string filename, string message, ofstream & ofs ) {
    ofs << message;
    cout << message << endl;
    return;
}

// This "print_file" function Prints Outputs for This Program. Output Is Double Type.

void print_file ( string filename, double number, ofstream & ofs ) {
    ofs << setw (20) << left << number; // Less than 20 Digits Assumed for Numbers
    cout << setw (20) << left << number;
    return;
}

 