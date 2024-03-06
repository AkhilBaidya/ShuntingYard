#include <iostream>
#include <cstring>
#include "stack.h"
#include "queue.h"

using namespace std;

void createTree(queue*&, stack*&);
void readPost(node*);
void readInf(node*);
void readPre(node*);

int main() {

  queue* numbers = new queue();
  stack* operators = new stack();
  //node* toAdd;
  
  //READ IN INFIX NOTATION:
  cout << "Please input a mathematical expression in infix seperated by spaces (use single digit integers and end your expression with |)" << endl;
  char input;
  
  while (cin >> input && input != '|') { //putting cin>>input in the condition suggested by Kevin. Additionally, saw that this syntax is viable online at stack overflow (https://stackoverflow.com/questions/19483126/whats-the-difference-between-whilecin-and-whilecin-num) from user templatetypedef

    cout << "in loop" << endl;
    //if (numbers -> isEmpty() == false) {
      //cout << "Outputting previous queue member " << numbers -> dequeue() -> getVal() << endl;
    //}
    node* toAdd = new node(input);
    toAdd -> setVal(input);
    
    //https://www.cs.cmu.edu/~pattis/15-1XX/common/handouts/ascii.html (referred to this for ASCII conversions)
    
    if ((int)input >= 48 && (int) input <= 57) { //a number
      numbers -> enqueue(toAdd);
      cout << "added " << input << " to queue" << endl;
    }

    else if (input != ' ') { //consider the input an operator

      //referred to https://en.wikipedia.org/wiki/Shunting_yard_algorithm for revisions with algorithm Shunting Yard
      
      if (input == ')' && operators -> peek() != NULL) { //if met with a right parenthesis need to output everything (all operators) within the parenthesis (as they are typically solved first in infix)

	while (operators -> peek() -> getVal() != '(') {
	  node* op = new node();
	  op = operators -> pop();
	  numbers -> enqueue(op);
	}

	node* op = new node();
	op = operators -> pop();
	numbers -> enqueue(op); //add the left parenthesis at the end
	
	
      }
      
      else if (operators -> peek() != NULL && toAdd -> getOrd() <= operators -> peek() -> getOrd() && input != '(') { //if the operator we are adding is less in precedence, pop out the current head of stack to the queue (does not apply to left parenthesis)

	while (operators -> peek() != NULL && toAdd -> getOrd() <= operators -> peek() -> getOrd()) {
	  node* op = new node();
	  op = operators -> pop();
	  cout << "looking at " << op -> getVal() << "against the new " << input << endl;
	  numbers -> enqueue(op);
	  cout << "moved " << op -> getVal() << " to queue" << endl;
	}
	operators -> push(toAdd);
      }
      
      else {
	operators -> push(toAdd);
      }
      cout << "added " << input << " to stack" << endl;
    }
  }

  //cout << "Here is queue after loop: " << numbers -> dequeue() -> getVal() << endl;
  //READ OUT POSTFIX NOTATION:
  cout << "Here is the postfix notation (using Shunting Yard algorithm): ";
  node* toAddNum = new node();
  node* toAddOp = new node();
  queue* postFix = new queue();
  stack* tree = new stack();

  //cout << numbers -> dequeue() -> getVal(); 
  //cout the numbers

  cout << "from queue" << endl;
  
  while (numbers -> isEmpty() == false) {
  toAddNum = numbers -> dequeue();
  toAddNum -> setN(NULL);
  if (toAddNum -> getVal() != '(' && toAddNum -> getVal() != ')') {
    cout << toAddNum -> getVal() << " ";
    postFix -> enqueue(toAddNum);
  }
  }

  cout << "from stack" << endl;
  //cout the operators
  while (operators -> peek() != NULL) {
  toAddOp = operators -> pop();
  toAddOp -> setN(NULL);
  if(toAddOp -> getVal() != '(' && toAddOp -> getVal() != ')') {
    cout << toAddOp -> getVal() << " ";
    postFix -> enqueue(toAddOp);
  }
  }
  cout << endl;

  createTree(postFix, tree);    
  readPost(base);
  
  return 0;
}

void createTree(queue* &postFix, stack* &tree) {

  node* right = new node();
  node* left = new node();
  
  while (postFix -> isEmpty() == false) {

    if (tree -> peek() != NULL) {
    cout << "currently last in stack: " << tree -> peek() -> getVal();
    }
    
    node* entry = postFix -> dequeue();
    int val = (int)(entry -> getVal());
    //cout << entry -> getVal() << ": " << val << endl;
    while (val >= 48 && val <= 57) { //a number
      
      tree -> push(entry);
      cout << tree -> peek() -> getVal() << endl;
      entry = postFix -> dequeue();
      val = (int)(entry -> getVal());
      entry -> setN(NULL);
      cout << "push to tree" << endl;
    }

    cout << "done with nums" << endl;
    //pop out the last two elements of the stack and add it to entry
    //node* current = new node();
    entry -> setN(NULL);
    if (tree -> peek() != NULL && tree -> peek() -> getN() != NULL) {
      cout << "entered" << endl;

      //node* right = new node();
      right = tree -> pop();
      entry -> setR(right);
      cout << "set right of " << entry -> getVal() << "to be " << entry -> getR() -> getVal() << endl;

      //node* left = new node();
      left = tree -> pop();
      entry -> setL(left);
      cout << "set left of " << entry -> getVal() << "to be " << entry -> getL() -> getVal() << endl;
      tree -> push(entry);
      cout << "added to tree: " << tree -> peek() -> getVal() << endl;
      //cout << "to be" << tree -> peek() -> getL() -> getVal() << endl;
      //current = tree -> peek();
      //cout << "tree is not empty: " << tree -> peek() -> getN() -> getVal() << endl;
    }
  }
  
  cout << "done with tree making" << endl;
  return;
}

void readPost(node* current) {

  cout << current -> getVal() << " ";
  
  if (current -> getL() == NULL && current -> getR() == NULL) {
    //cout << current -> getVal() << " ";
  return; //if at end of left travel print
  }

  readPost(current -> getL()); //recurse left

    //if (current -> getR() == NULL) {
    //cout << current -> getVal() << " ";
    //return; //if at end of right travel print
    //}
    
    readPost(current -> getR()); //recurse right
    //cout << current -> getVal() << " ";
  return;
  
}
void readInf(node* current) {

}
void readPre(node* current) {

}

