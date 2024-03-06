#include <iostream>
#include <cstring>
#include "stack.h"
#include "queue.h"

using namespace std;

void createTree(queue*&, stack*&);

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
  
  return 0;
}

void createTree(queue* &postFix, stack* &tree) {

  while (postFix -> isEmpty() == false) {

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
    
    if (tree -> peek() != NULL && tree -> peek() -> getN() != NULL) {
      cout << "entered" << endl;

      entry -> setL(tree -> pop());
      entry -> setR(tree -> pop());
      
      //current = tree -> peek();
      //cout << "tree is not empty: " << tree -> peek() -> getN() -> getVal() << endl;
    }
    
    /*while (current -> getN() -> getN() != NULL) {
      current = current -> getN();
      cout << "here an error" << endl;
    }

    entry -> setR(current -> getN());
    current -> setN(NULL);
    
    if (tree -> peek() != NULL) {
      current = tree -> peek();
    }

    while (current -> getN() -> getN() != NULL) {
      current = current -> getN();
    }

    entry -> setL(current -> getN());
    current -> setN(NULL);
    */
    //add entry to stack(
    tree -> push(entry);
  }

  cout << "done with tree making" << endl;
  return;
}

