
#ifndef NODE
#define NODE

#include <iostream>
#include <cstring>

using namespace std;

class node {

 public:

  //constructor and destructor
  node(char);
  ~node();
  
  //content of itself
  void setVal(char);
  char getVal();

  //content of left node
  void setL(node*);
  node* getL();

  //content of right node
  void setR(node*);
  node* getR();

  //content of next node
  void setN(node*);
  node* getN();

 protected:
  node* left;
  node* right;
  node* next;
  char val;
};

#endif
