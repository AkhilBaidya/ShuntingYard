#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

//constructor
node::node(char input) {
  left = NULL;
  right = NULL;
  next = NULL;
  val = input;
  precedence = 10;

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

//destructor
node::~node() { //delete pointers
  delete left;
  delete right;
  delete next;
}

//its own content:
void node::setVal(char input) {\
  val = input;
  
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

char node::getVal() {
  return val;
}

//the left node's content:
void node::setL(node* input) {
  left = input;
}

node* node::getL() {
  return left;
}

//the right node's content:
void node::setR(node* input) {
  right = input;
}

node* node::getR() {
  return right;
}

//the next node's content:
void node::setN(node* input) {
  next = input;
}

node* node::getN() {
  return next;
}

int node::getOrd() {
  return precedence;
}
