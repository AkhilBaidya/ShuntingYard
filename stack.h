#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

class stack {
 public:
  stack(); //constructor
  ~stack(); //destructor

  //functions:
  void push(node*);
  node* pop();
  node* peek();
  
 private:
  node* header;
};

