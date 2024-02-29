#include <iostream>
#include <cstring>
#include "stack.h"
#include "queue.h"

using namespace std;

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
	  node* op = operators -> pop();
	  numbers -> enqueue(op);
	}
	numbers -> enqueue(operators -> pop()); //add the left parenthesis at the end
	
	
      }
      
      else if (operators -> peek() != NULL && toAdd -> getOrd() <= operators -> peek() -> getOrd() && input != '(') { //if the operator we are adding is less in precedence, pop out the current head of stack to the queue (does not apply to left parenthesis)
	node* op = operators -> pop();
	cout << "looking at " << op -> getVal() << "against the new " << input << endl;
	numbers -> enqueue(op);
	cout << "moved " << op -> getVal() << " to queue" << endl;
      }
      operators -> push(toAdd);
      cout << "added " << input << " to stack" << endl;
    }
  }

  cout << "Here is queue after loop: " << numbers -> dequeue() -> getVal() << endl;
  //READ OUT POSTFIX NOTATION:
  cout << "Here is the postfix notation (using Shunting Yard algorithm): ";
  node* toAddNum;
  node* toAddOp;

  //cout << numbers -> dequeue() -> getVal(); 
  //cout the numbers
  //while (numbers -> isEmpty() == false) {
  //toAddNum = numbers -> dequeue();
  //cout << toAddNum -> getVal() << "queue";
  //}
  //cout the operators
  //while (operators -> peek() != NULL) {
  //toAddOp = operators -> pop();
  // cout << toAddOp -> getVal() << " ";
  //}
  //cout << endl;
  return 0;
}

