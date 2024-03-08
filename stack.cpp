/*C++ Data Structures: Stack Class
  by Akhil Baidya

  Date of Submission: 3/7/24

  Notes: These are the function definitions for the stack class. The constructor, destructor, push (adding to stack), pop (deleting from stack, and peek (returning head of stack) functions are defined.
  
  Reference:
  Referred to https://web.cecs.pdx.edu/~karlaf/CS163_Slides/CS163_Topic4.pdf by Professor Fant (put on Canvas) to understand the "first in, last out" nature of stacks.
 */

#include <iostream>
#include <cstring>
#include "stack.h"

using namespace std;

//Constructor
stack::stack(){
  header = NULL; //empty stack
}

//Destructor
stack::~stack(){
  while (header != NULL) {
    node* prevHead = header;
    header = header -> getN(); //shorten stack
    delete prevHead; //delete content of previous header
  }
  delete header; //delete remaining header
}

//Adding to Stack:
void stack::push(node* input){
  node* prevHead = header;
  header = input; //set input as the next header (and its next node as the previous header)
  header -> setN(prevHead);
}

//Deleting from Stack:
node* stack::pop(){

  node* prevHead;
  
  if (header -> getN() != NULL) {
    prevHead = header;
    header = header -> getN(); //set header as its next node (this original header will be returned)
    prevHead -> setN(NULL);
  }

  else { //if there is only a header in the linked list
    prevHead = header; //get the header
    header = NULL;
  }
  return prevHead; //return the original header 
}

//Getting head of the Stack:
node* stack::peek(){
  return header; //return the header
}
