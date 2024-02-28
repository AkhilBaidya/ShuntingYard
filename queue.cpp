#include <iostream>
#include <cstring>
#include "queue.h"

using namespace std;

queue::queue() {
  header = NULL; //constructor
}

queue::~queue() {
}

void queue::enqueue(node* input) { //add to the end of the linked list
  node* current = header;

  while (current -> next != NULL) {
    current = current -> next;
  } //point to the point where the next node is null

  current -> next = input; //put input there
}
