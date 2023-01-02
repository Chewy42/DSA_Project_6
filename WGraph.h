/*
Name: Matt Favela
Student ID #: 2390407
Email: mfavela@chapman.edu
Course Number and Section: CPSC350-03
Assignment: PA6

Brief Overview:
This file defines the WGraph class. It contains the adjacency matrix and the connection matrix. It also contains the functions to process the file and compute the MST.
High Level Decisions Used:
None
*/

#ifndef WGraph_H
#define WGraph_H

#include <iostream>
#include <limits>


class WGraph{
public:
  WGraph();
  WGraph(std::string filename); // Takes in a file name as a string
  ~WGraph();
  void computeMST(); // Computes the MST
private:
  double** m_adj;
  double** m_conn;
  unsigned int m_size;
  std::string m_filename;
  void processFile(); // Process the file
};






#endif
