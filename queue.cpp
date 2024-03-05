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

void queue::enqueue(node* &input) { //add to the end of the linked list

  if (header == NULL) {
    header = input;
  }

  else {

    node* current = header;

    cout << "entering while loop" << endl;
    while (current -> getN() != NULL) {
      current = current -> getN();
    }
    cout << "out" << endl;
    current -> setN(input); //add to end
  }

  //node** current  = &header;
  //if ((*current) == NULL) {
  //(*current) = input;
  //}

  //else {
  //while ((*current) -> getN() != NULL) {
  //node* prevHead = (*current);
  //(*current) = prevHead -> getN();
  //} //point to the point where the next node is null
  //(*current) -> setN(input); //put input there
  //}
}

node* queue::dequeue() {
  node* prevHead = new node();
  prevHead  = header;
  //prevHead -> setN(NULL);

  //node* toRet = new node(prevHead -> getVal());
  header = header -> getN(); //set next as the header (removing the header)
  //delete prevHead;


  //cout << "Going to return " << toRet -> getVal() << endl;
  return prevHead; //return the previous top
}

bool queue::isEmpty(){
  if (header == NULL) {
    return true;
  }

  return false;
}
