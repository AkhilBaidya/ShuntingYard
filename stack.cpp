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

  node* popped = new node();
  
  if (header -> getN() != NULL) {
    node* prevHead = new node();
    prevHead = header;
    cout << "header value: " << prevHead -> getVal() << endl;
    popped -> setVal(prevHead -> getVal());
    cout << "value going to pop (should be same): " << popped -> getVal() << endl;
    cout << "header's next val: " << header -> getN() -> getVal() << endl;
    //node* toRet = new node(prevHead -> getVal()); 
    header = header -> getN(); //delete header
    cout << "header's moved to next (should be same): " << header -> getVal() << endl;
  
    cout << "going to delete the old header junk " << (*prevHead).getVal() << endl;
    prevHead -> setN(NULL);
    delete prevHead;
    cout << "then" << endl;
    cout << "checking return val: " << popped -> getVal() << endl;
  }

  else {
    popped -> setVal(header -> getVal());
    header = NULL;
  }
  return popped; //return header
}
node* stack::peek(){
  return header; //simply return the top
}
