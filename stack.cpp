#include <iostream>
#include <cstring>
#include "stack.h"

using namespace std;

//constructor
stack::stack(){
  header = NULL;
}

//destructor
stack::~stack(){
  while (header != NULL) {
    node* prevHead = header;
    header = header -> getN(); //shorten stack
    delete prevHead;
  }
  delete header; //delete remaining header
}

//functions
void stack::push(node* &input){
  node* prevHead = header;
  header = input;
  header -> setN(prevHead); //keep on adding to the top
}

node* stack::pop(){
  node* prevHead = new node();
  prevHead = header;
  header = header -> getN(); //delete header
  return prevHead; //return header
}
node* stack::peek(){
  return header; //simply return the top
}
