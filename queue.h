#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

class queue {

 public:
  queue(); //constructor
  ~queue(); //destructor

  //functions:
  void enqueue(node*);
  node* dequeue();
  bool isEmpty();
  
 private:
  node* header;
};
