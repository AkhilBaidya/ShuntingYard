/*C++ Data Structures: Expression Tree (and Stack/Queue) Node Class
  by Akhil Baidya

  Date of Submission: 3/7/24

  Notes: These are the function defintions for the node class. This defines how the left, right, and next nodes will be get/set, how the node is constructed or destroyed, and how the content and precedence of the node is set and gotten respectively.
 */

#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

//Constructor:
node::node() {
  left = NULL; //all pointers are null and there is no precedence
  right = NULL;
  next = NULL;
  precedence = 0;
}

//Constructor w/ initial value given:
node::node(char input) {
  left = NULL; //the only change is that value of the node is to the input and the precedence changes accordingly
  right = NULL;
  next = NULL;
  val = input;
  precedence = 0;

  if (val == '^') {
    precedence = 3; //highest precedence
  }
  else if (val == '/' || val == '*') {
    precedence = 2; //second highest
  }
  else if (val == '+' || val == '-') {
    precedence = 1; //third highest (operators hold precedence over all other characters)
  }
  
}

//Destructor:
node::~node() { //delete pointers
  delete left;
  delete right;
  delete next;
}

//Set the node's value:
void node::setVal(char input) {\
  val = input;

  //Set precedence:
  if (val == '^') {
    precedence = 3;
  }
  else if (val == '/' || val == '*') {
    precedence = 2;
  }
  else if (val == '+' || val == '-') {
    precedence = 1;
  }
}

//Get the node's value:
char node::getVal() {
  return val;
}

//Set the left node:
void node::setL(node* input) {
  left = input;
}

//Get the left node:
node* node::getL() {
  return left;
}

//Set the right node:
void node::setR(node* input) {
  right = input;
}

//Get the right node:
node* node::getR() {
  return right;
}

//Set the next node:
void node::setN(node* input) {
  next = input;
}

//Get the next node:
node* node::getN() {
  return next;
}

//Get the precedence of the node:
int node::getOrd() {
  return precedence;
}
