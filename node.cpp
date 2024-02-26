#include <iostream>
#include <cstring>

using namespace std;

class node {

public:

  //it's content
  void setValue(char);
  char getValue();

  //the content of the next node
  void setNext(node*);
  char getNext();

  //the content of the left node
  void setLeft(node*);
  char getLeft();

  void setRight(node*);
  char getRight();
  
private:
  node* left;
  node* right;
  node* next;
  char value;
};


