/*C++ Data Structures: Queue Class
  by Akhil Baidya

  Date of Submission: 3/7/24

  Notes: These are the function definitions for the queue class. This defines how nodes are added to the bottom of the queue and how only the head is removed from the queue (additionally, a constructor, destructor, and check for whether the linked list is empty are defined)

  Reference:
  Referred to https://web.cecs.pdx.edu/~karlaf/CS163_Slides/CS163_Topic4.pdf by Professor Fant (put on Canvas) to understand the "first in, first out" nature of queues.
 */

#include <iostream>
#include <cstring>
#include "queue.h"

using namespace std;

//Constructor:
queue::queue() {
  header = NULL; //queue is empty
}

//Destructor:
queue::~queue() {
  node* current = header;
  while (current -> getN() != NULL) {
    current = current -> getN();
    dequeue(); //remove each element from the queue (remove the head multiple times)
  }
}

//Add to Queue:
void queue::enqueue(node* input) { //add to the end of the linked list

  if (header == NULL) { //if the queue is empty just set the header to the input node
    header = input;
  }

  else if (header -> getN() == NULL) { //if the queue only has a header, set its next node to the input node
    header -> setN(input);
  }

  else { //otherwise...
    
    node* current = header;

    while (current -> getN() != NULL) { //loop to end of linked list
      current = current -> getN();
    }
    
    current -> setN(input); //add input to end
  }
}

//Remove head from the Queue:
node* queue::dequeue() {

  node* prevHead = new node();
  
  if (header -> getN() == NULL) { //in the case there is only a header in the queue, set the header to null and return a saved version of it:
    prevHead = header;
    header = NULL;
  }

  else {
    prevHead  = header;
    header = header -> getN(); //set the value after the header as the header (removing the header from the queue)
  }
  return prevHead; //return pointer equivalent to the original header
}

//Check if the Queue is empty:
bool queue::isEmpty(){
  if (header == NULL) {
    return true; //if the header is null, the queue is empty
  }

  return false;
}
