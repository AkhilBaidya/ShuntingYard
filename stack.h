/*C++ Data Structures: Stack Class
  by Akhil Baidya

  Date of Submission: 3/7/24

  Notes: This is the header file to the stack class. A stack, here, is a linked list of nodes, where nodes and can inputted and outputted in a "first in, last out" manner (the most recent addition is outputted first).

  Reference:
  Referred to https://web.cecs.pdx.edu/~karlaf/CS163_Slides/CS163_Topic4.pdf by Professor Fant (put on Canvas) to understand the "first in, last out" nature of stacks.
 */

#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

class stack {
  
 public:
  stack(); //Constructor
  ~stack(); //Destructor

  //Functions:
  void push(node*); //add to stack
  node* pop(); //remove from stack
  node* peek(); //get stack's head node
  
 private:
  node* header; //head of linked list
};

