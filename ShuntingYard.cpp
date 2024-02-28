#include <iostream>
#include <cstring>
#include "stack.h"
#include "queue.h"

using namespace std;

int main() {

  queue* numbers = new queue();
  stack* operators = new stack();

  cout << "Please input a mathematical expression seperated by spaces (use single digit integers)" << endl;

  while (cin) {
    char input;
    node* toAdd = new node();
    cin >> input;
    toAdd -> setVal(input);
    
    if ((int)input >= 0 && (int) input <= 9) { //a number
      numbers -> enqueue(toAdd);
    }

    else { //consider the input an operator
      operators -> push(toAdd);
    }
  }
  
  return 0;
}

