/*C++ Data Structures: Queue Class
  by Akhil Baidya

  Date of Submission: 3/7/24

  Notes: This is the header file to the queue class. A queue, here, is a linked list of nodes, where nodes can be inputted and outputted in a "first in, first out" manner.

  Reference:
  Referred to https://web.cecs.pdx.edu/~karlaf/CS163_Slides/CS163_Topic4.pdf by Professor Fant (put on Canvas) to understand the "first in, first out" nature of queues.
 */

#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

class queue {

 public:
  queue(); //Constructor
  ~queue(); //Destructor

  //Functions:
  void enqueue(node*); //add to queue
  node* dequeue(); //remove from queue
  bool isEmpty(); //check if queue is empty
  
 private:
  node* header; //the head of the linked list
};
