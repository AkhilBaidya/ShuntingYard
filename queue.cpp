#include <iostream>
#include <cstring>
#include "queue.h"

using namespace std;

queue::queue() {
  header = NULL; //constructor
}

queue::~queue() {
  node* current = header;

  while (current -> getN() != NULL) {
    current = current -> getN();
    dequeue();
  } //remove all elements from the list
}

void queue::enqueue(node* input) { //add to the end of the linked list
  node** current  = &header;
  cout << "got head" << endl;
  
  while ((*current) != NULL) {
    node* prevHead = *current;
    (*current) -> setN(NULL);
    cout << "saved current" << endl;
    *current = prevHead -> getN();
    cout << "moving on" << endl;
  } //point to the point where the next node is null

  cout << "set the input " << input -> getVal() << endl;
  *current = input; //put input there
}

node* queue::dequeue() {
  node* prevHead = header;
  header = header -> getN(); //set next as the header (removing the header)
  cout << "new header: " << header -> getVal() << endl;
  return prevHead; //return the previous top
}

bool queue::isEmpty(){
  if (header == NULL) {
    return true;
  }

  return false;
}
