/*
Name: Matt Favela
Student ID #: 2390407
Email: mfavela@chapman.edu
Course Number and Section: CPSC350-03
Assignment: PA6

Brief Overview:
This file contains the main function for the program. It creates a new instance of the WGraph class and runs the program.
High Level Decisions Used:
None
*/

#include "WGraph.h"
#include <fstream>


using namespace std;

// main function
int main(int argc, char* argv[]){
    WGraph wg(argv[1]); // Create graph with file name
    wg.computeMST(); //Computes MST Here
    return 0;
}