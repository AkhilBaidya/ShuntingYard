#include <iostream>
#include <cstring>
#include "stack.h"
#include "queue.h"

using namespace std;

int main() {

  queue* numbers = new queue();
  stack* operators = new stack();

  //READ IN INFIX NOTATION:
  cout << "Please input a mathematical expression in infix seperated by spaces (use single digit integers and end your expression with |)" << endl;
  char input;
  
  while (cin >> input && input != '|') { //putting cin>>input in the condition suggested by Kevin. Additionally, saw that this syntax is viable online at stack overflow (https://stackoverflow.com/questions/19483126/whats-the-difference-between-whilecin-and-whilecin-num) from user templatetypedef
    node* toAdd = new node(input);
    //https://www.cs.cmu.edu/~pattis/15-1XX/common/handouts/ascii.html (referred to this for ASCII conversions)
    
    if ((int)input >= 48 && (int) input <= 57) { //a number
      numbers -> enqueue(toAdd);
      cout << "added to queue" << endl;
    }
    else if (input != ' ') { //consider the input an operator

      //referred to https://en.wikipedia.org/wiki/Shunting_yard_algorithm for revisions with algorithm Shunting Yard
      
      if (input == ')') { //if met with a right parenthesis need to output everything (all operators) within the parenthesis (as they are typically solved first in infix)

	while (operators -> peek() -> getVal() != '(') {
	  node* op = operators -> pop();
	  numbers -> enqueue(op);
	}
	numbers -> enqueue(operators -> pop()); //add the left parenthesis at the end
	
	
      }
      
      else if (toAdd -> getOrd() <= operators -> peek() -> getOrd() && input != '(') { //if the operator we are adding is less in precedence, pop out the current head of stack to the queue (does not apply to left parenthesis)
	node* op = operators -> pop();
	numbers -> enqueue(op);
      }
      operators -> push(toAdd);
      cout << "added to stack" << endl;
    }
  }

  //READ OUT POSTFIX NOTATION:
  cout << "Here is the postfix notation (using Shunting Yard algorithm): ";
  node* toAddNum;
  node* toAddOp;

  //cout the numbers
  while (numbers -> isEmpty() == false) {
    toAddNum = numbers -> dequeue();
    cout << toAddNum -> getVal() << " ";
  }
  //cout the operators
  while (operators -> peek() != NULL) {
    toAddOp = operators -> pop();
    cout << toAddOp -> getVal() << " ";
  }
  cout << endl;
  return 0;
}

