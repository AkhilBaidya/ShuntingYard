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
