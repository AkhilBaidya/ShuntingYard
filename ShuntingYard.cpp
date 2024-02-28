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
    
    cout << "in loop " << endl;
    
    node* toAdd = new node(input);
    cout << "read in " << (int)input << endl;

    //https://www.cs.cmu.edu/~pattis/15-1XX/common/handouts/ascii.html (referred to this for ASCII conversions)
    
    if ((int)input >= 48 && (int) input <= 57) { //a number
      cout << "adding to queue" << endl;
      numbers -> enqueue(toAdd);
      cout << "added to queue" << endl;
    }

    else if (input != ' ') { //consider the input an operator
      operators -> push(toAdd);
      cout << "added to stack" << endl;
    }

    cout << "still in loop" << endl;
  }

  cout << "done" << endl;


  //READ OUT POSTFIX NOTATION:
  cout << "Here is the postfix notation (using Shunting Yard algorithm): ";
  node* toAddNum;
  node* toAddOp;

  //cout the numbers
  cout << "Going to read out the queue" << endl;
  while (numbers -> isEmpty() == false) {
    cout << "trying" << endl;
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

