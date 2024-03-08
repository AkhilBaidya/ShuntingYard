/*C++ Data Structures: Expression Tree (and Stack/Queue) Node Class
  by Akhil Baidya

  Date of Submission: 3/7/24

  Notes: This is the header file to the node class. A node object will contain a character and also pointers to a right child, left child, and next node.
 */

#ifndef NODE
#define NODE

#include <iostream>
#include <cstring>

using namespace std;

class node {

 public:

  //Note: Referred to article at https://www.learncpp.com/cpp-tutorial/header-guards/, written by user Alex, for how to write a header guard
  
  //Constructors
  node();
  node(char);

  //Destructor
  ~node();
  
  //Content of itself (get/set value):
  void setVal(char);
  char getVal();

  //Left node (get/set node):
  void setL(node*);
  node* getL();

  //Right node (get/set node): 
  void setR(node*);
  node* getR();

  //Next node (get/set node):
  void setN(node*);
  node* getN();

  //Get precendence of the value contained by the node:
  int getOrd();

 protected:
  //connected nodes:
  node* left;
  node* right;
  node* next;

  //content
  char val;

  //precendence of content (if expression)
  int precedence;
};

#endif
