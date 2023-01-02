/*
Name: Matt Favela
Student ID #: 2390407
Email: mfavela@chapman.edu
Course Number and Section: CPSC350-03
Assignment: PA6

Brief Overview:
This file is the implementation for the WGraph class. It contains the adjacency matrix and the connection matrix. It also contains the functions to process the file and compute the MST.
High Level Decisions Used:
Using Kruskal's algorithm to compute the MST
*/

#include "WGraph.h"
#include <iostream>
#include <fstream>

using namespace std;


// Default constructor
WGraph::WGraph(){
  m_size = 0;
  m_conn = NULL;
  m_adj = NULL;
}

// Overloaded constructor that takes in a file name as a string
WGraph::WGraph(std::string filename){
  m_filename = filename;
  m_conn = NULL;
  m_adj = NULL;
  processFile(); // Process the file
}

// Destructor
WGraph::~WGraph(){
    for(int i = 0; i < m_size; ++i){
        delete[] m_adj[i];
        delete[] m_conn[i];
    }
}

/*
input file: 
9
0 4 0 0 0 0 0 8 0
4 0 8 0 0 0 0 11 0
0 8 0 7 0 4 0 0 2
0 0 7 0 9 14 0 0 0
0 0 0 9 0 10 0 0 0
0 0 4 14 10 0 2 0 0
0 0 0 0 0 2 0 1 6
8 11 0 0 0 0 1 0 7
0 0 2 0 0 0 6 7 0

output:
Adjacency matrix
0 4 0 0 0 0 0 0 0 
4 0 8 0 0 0 0 0 0 
0 8 0 7 0 4 0 0 2 
0 0 7 0 9 0 0 0 0 
0 0 0 9 0 0 0 0 0 
0 0 4 0 0 0 2 0 0 
0 0 0 0 0 2 0 1 0 
0 0 0 0 0 0 1 0 0 
0 0 2 0 0 0 0 0 0 
Total cost: 37
*/

// Method to compute the MST
void WGraph::computeMST() {
    // Initialize the minimum spanning tree to be empty
    double total = 0.0;
    // Loop through the adjacency matrix
    for (int i = 0; i < m_size; ++i) {
        // set the lowest cost and col
        double lowestCost = std::numeric_limits<double>::max();
        int lowestCol = -1;
        // loop through the adjacency matrix 2nd dimension
        for (int j = 0; j < m_size; ++j) {
            // if the cost is less than the lowest cost and the connection is not already made
            if (i > j) {
                // if the cost is 0, then it is not connected
                if (m_adj[i][j] == 0) {
                    continue;
                }
                // if the cost is less than the lowest cost and the connection is not already made
                if (m_adj[i][j] < lowestCost) {
                    // if the lowest col is not -1, then set the connection to 0
                    if (lowestCol != -1) {
                        m_adj[i][lowestCol] = 0;
                        m_adj[lowestCol][i] = 0;
                    }
                    // then set the lowest cost and col
                    lowestCost = m_adj[i][j];
                    lowestCol = j;
                } else {
                    // if not then set the connection to 0
                    m_adj[i][j] = 0;
                    m_adj[j][i] = 0;
                }
            }
        }
        // if the lowest col is not -1, add the lowest cost to the total
        if (lowestCol != -1) {
            total += lowestCost;
        }
    }
    // print out the matrix and the total cost
    cout << "Adjacency matrix" << endl;
    for (int i = 0; i < m_size; ++i) {
        for (int j = 0; j < m_size; ++j) {
            cout << m_adj[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Total cost: " << total << endl;
}


// Method to process the file
void WGraph::processFile(){
  ifstream infile(m_filename.c_str()); // take in the file 
  infile >> m_size; // get the size
  // Create the adjacency matrix
  m_adj = new double*[m_size];
  m_conn = new double*[m_size];
  // Loop through the adjacency matrix
  for(int i = 0; i < m_size; ++i){
    // Initialize the adjacency matrix
    m_adj[i] = new double[m_size];
    m_conn[i] = new double[m_size];
  }
  // Loop through the adjacency matrix
  for(int i = 0; i < m_size; ++i){
    // Loop through the adjacency matrix 2nd dimension
    for(int j = 0; j < m_size; ++j){
      // Set the adjacency matrix to what we got from the file
      infile >> m_adj[i][j];
    }
  }
  // Loop through the adjacency matrix
  for(int i = 0; i < m_size; ++i){
    // Loop through the adjacency matrix 2nd dimension
    for(int j = 0; j < m_size; ++j){
      // Set the connection matrix to what we got from the file
      infile >> m_conn[i][j];
    }
  }
}