#include <iostream>
#include <cstring>
#include "stack.h"
#include "queue.h"

using namespace std;

int main() {

  queue* numbers = new queue();
  stack* operators = new stack();

  cout << "Please input a mathematical expression seperated by spaces (use single digit integers and end your expression with |)" << endl;
  char input;
  
  while (cin >> input && input != '|') { //putting cin>>input in the condition suggested by Kevin. Additionally, saw that this syntax is viable online at stack overflow (https://stackoverflow.com/questions/19483126/whats-the-difference-between-whilecin-and-whilecin-num) from user templatetypedef
    
    cout << "in loop " << endl;
    
    node* toAdd = new node(input);
    cout << "read in " << input << endl;
    
    if ((int)input >= 0 && (int) input <= 9) { //a number
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
  
  return 0;
}

