//C++ Data Structures: Shunting Yard Project
//by Akhil Baidya

//Date of Submission: 3/7/24

/*Notes: In this project, an expression in infix (parentheses, ^, +, -, *, /, and single digit numbers are allowed) is read and is converted into postfix through the Shunting Yard algorithm. The user should end their expression, when entering into the program, with a '|' in order for the program to work.

The user will be shown this expression in postfix. This postfix expression will then be put into an expression tree, where the user will be prompted to print out the expression back in postfix, into infix, or into prefix. The user should input "post," "in," or "pre" to determine the reading method.
*/

/*Main sources:
Referred to Wikipedia article on Shunting Yard (https://en.wikipedia.org/wiki/Shunting_yard_algorithm). This taught me how numbers read in are added immediately to queue and how operators are initially added to a stack, in Shunting Yard. When an operator is added to the stack and the current stack head has a greater precedence, then the stack head is added to the queue and removed from the stack before adding the operator (this is looped until this difference in precedence is no longer the case). Additionally, the algorithm notes how after a right parenthesis is read in, every operator in the stack, until a left parenthesis is at the head, is moved to the queue. The queue is the postfix expression.

Referred to Wikipedia article on Binary Expression Tree (https://en.wikipedia.org/wiki/Binary_expression_tree). This taught me how the tree is created on a stack. Numbers read in are added to the stack. However, when an operator is read in, the most recent two numbers added to the stack are removed and made the children of the operator. The operator is then added to the stack.
*/

#include <iostream>
#include <cstring>
#include "stack.h"
#include "queue.h"

using namespace std;

//Function Prototypes for the Expression Tree:
void createTree(queue*, stack*); //creating the tree
void readPost(node*); //reading it out in postfix
void readInf(node*); //reading it out in infix
void readPre(node*); //reading it out in prefix

//MAIN FUNCTION:
/*In the main function, the user will input an expression in infix which is converted into postfix.
The user will also be prompted here to print out an expression tree in postfix, infix, or prefix.*/ 
int main() {

  queue* numbers = new queue(); //numbers are immediately added to a queue in Shunting Yard 
  stack* operators = new stack(); //operators are initially added to a stack in Shunting Yard
  
  //READ IN INFIX EXPRESSION FOLLOWING SHUNTING YARD:
  cout << "Please input a mathematical expression in infix seperated by spaces (use single digit integers and end your expression with |)" << endl;
  char input;
  
  while (cin >> input && input != '|') { //Program will read in characters one-by-one until encountering the "end of line" character (this was decided to be |)

    /*Note: Putting cin >> input in the loop's condition, to also perform the read in while continuing the loop, was suggested by Kevin.Additionally, I saw that this syntax is viable online at stack overflow (https://stackoverflow.com/questions/19483126/whats-the-difference-between-whilecin-and-whilecin-num) from user templatetypedef */
    
    //Create node out of input:
    node* toAdd = new node(input);
    toAdd -> setVal(input);
    

    //If the input is a number, immediately add it to the queue (based on Wikipedia algorithm for Shunting Yard - see link in comments at top of file):
    if ((int)input >= 48 && (int) input <= 57) { 

      //Note: Referred to Carnegie Mellon School of Computer Science's ASCII chart to understand what the ASCII values for numbers (as characters) are (https://www.cs.cmu.edu/~pattis/15-1XX/common/handouts/ascii.html)
    
      numbers -> enqueue(toAdd); //add to queue
    }

    //Otherwise:
    else if (input != ' ') {

      //If the input is a right parenthesis, add operators in the stack to the queue until encountering a left parenthesis in the stack (based on Wikipedia algorithm for Shunting Yard - see link in comments at top of file):
      if (input == ')' && operators -> peek() != NULL) {

	//Reason: if met with a right parenthesis, need to output everything (all operators) within the parenthesis (as they are typically solved first in infix)

	while (operators -> peek() -> getVal() != '(') { //while not encountering the left parenthesis,
	  node* op = new node();
	  op = operators -> pop(); //get head of stack 
	  numbers -> enqueue(op); //move to the queue
	}

	//Add the remaining left parenthesis to the queue, at the end of this loop:
	node* op = new node();
	op = operators -> pop();
	numbers -> enqueue(op);
	
	
      }

      //If the input is a regular operator, but the current head of the stack has higher or equal precedence, pop the head to the queue. Continue doing this until the head does not have higher or equal precedence and then add the input to the stack  (based on Wikipedia algorithm for Shunting Yard - see link in comments at top of file):
      else if (operators -> peek() != NULL && toAdd -> getOrd() <= operators -> peek() -> getOrd() && input != '(') { //does not apply to left parenthesis

	//Reason: otherwise, the head might have a lower precendence than the operator before it. It will be added to the right of the expression (when popping from the stack), in postfix, first and would be erroneously interpreted as having a higher precendence

	while (operators -> peek() != NULL && toAdd -> getOrd() <= operators -> peek() -> getOrd()) { //loop this check
	  node* op = new node();
	  op = operators -> pop();
	  numbers -> enqueue(op); //continue popping head of stack to queue if true
	}
	operators -> push(toAdd); //finally add the input to stack
      }

      //If the input is just an operator (based on Wikipedia algorithm for Shunting Yard - see link in comments at top of file):
      else {
	operators -> push(toAdd); //add it to the stack
      }
    }
  }

  //READ OUT USER INPUT IN POSTFIX NOTATION AFTER USING SHUNTING YARD:
  cout << "Here is the postfix notation (using Shunting Yard algorithm): ";
  node* toAddNum = new node();
  node* toAddOp = new node();
  queue* postFix = new queue(); //new queue to be used for an expression tree
  stack* tree = new stack(); //stack that will contain tree


  //Read out everything from the queue:
  while (numbers -> isEmpty() == false) {
    toAddNum = numbers -> dequeue(); //get next element in queue
    toAddNum -> setN(NULL);
    
    if (toAddNum -> getVal() != '(' && toAddNum -> getVal() != ')') { //don't read out parentheses in postfix
      cout << toAddNum -> getVal() << " "; //print
      postFix -> enqueue(toAddNum); //add to a new queue to be used with the expression tree!
    }
  }

  //Read out remaining operators in the stack:
  while (operators -> peek() != NULL) {
    toAddOp = operators -> pop(); //get next element in stack
    toAddOp -> setN(NULL);

    if(toAddOp -> getVal() != '(' && toAddOp -> getVal() != ')') { //don't read out parentheses (doesn't matter in postfix)
      cout << toAddOp -> getVal() << " "; //print
      postFix -> enqueue(toAddOp); //add to a new queue to be used with the expression tree!
    }
  }
  
  cout << endl;

  //CREATE EXPRESSION TREE:
  createTree(postFix, tree); //uses a queue and stack (based on Wikipedia algorithm for Expression Tree creation - see link in comments at top of file)

  //READ OUT EXPRESSION TREE:
  node* base = new node(); //get the remaining node in the stack containing the tree (the root)
  base = tree -> peek();

  char readOut[10];
  cout << "Would you like to print out the expression in postfix (post), infix (in), or prefix (pre)? " << endl;
  cin >> readOut;

  if (!strcmp(readOut, "post")) { 
    readPost(base); //read tree out in postfix
  }

  else if (!strcmp(readOut, "in")) {
    readInf(base); //read tree out in infix
  }

  else if (!strcmp(readOut, "pre")) {
    readPre(base); //read tree out in prefix
  }
  
  return 0;
}


//ADDITIONAL FUNCTIONS:

//This createTree function takes in a queue representing an expression in postfix and creates a binary expression tree on an empty stack:
void createTree(queue* postFix, stack* tree) {

  while (postFix -> isEmpty() == false) { //while the queue is not empty
    
    node* entry = postFix -> dequeue(); //get the value to add to the stack/tree
    int val = (int)(entry -> getVal()); //get its ASCII value

    //While the input is a number, by that ASCII value, add it to the stack (based on Wikipedia algorithm for Expression Tree creation - see link in comments at top of file):
    while (val >= 48 && val <= 57) {
      tree -> push(entry); //add 
      entry = postFix -> dequeue(); //get next value in queue
      val = (int)(entry -> getVal()); //check its ASCII
    }

    //Now that the while loop is over, the code has encountered an operator, the operator becomes a parent:
    if (tree -> peek() != NULL && tree -> peek() -> getN() != NULL) { //if there are at least two entries in the stack, make the most recent two the children of the operator, after removing them from the stack, and add the operator to the stack (based on Wikipedia algorithm for Expression Tree creation - see link in comments at top of file)

      //Set the first popped stack entry as the right child:
      node* right = tree -> pop();
      entry -> setR(right);

      //Set the second popped stack entry as the left child:
      node* left = tree -> pop();
      entry -> setL(left);

      //Add operator to stack:
      tree -> push(entry);
    }
  }
  return;
}


//This readPost function takes the root of an expression tree and reads it out in postfix using recursion:
void readPost(node* current) {

  if (current -> getL() == NULL && current -> getR() == NULL) { //If at the end of tree, print current value and return
    cout << current -> getVal() << " ";
    return;
  }

  //The pattern of printing left child, right child, and then parent (an operator) is needed for postfix:
  readPost(current -> getL()); //First recurse left down the tree  
  readPost(current -> getR()); //Then recurse right down the tree
  cout << current -> getVal() << " "; //Then print the current value
  return;
}

//This readInf function takes the root of an expression tree and reads it out in infix using recursion:
void readInf(node* current) {

  int val = (int)(current -> getVal()); //get the ASCII value of the current node 

  //If the current node contains an operator (based on its ASCII value), print out a "(" (this will encase every operation in parentheses to help with order of operations):
  if (val < 47 || val > 58) {
    cout << "( ";
  }

  //If at the end of the tree, print out the current value:
  if (current -> getL() == NULL) {
    cout << current -> getVal() << " ";
    return;
  }

  //The pattern of printing left child, parent (the operator), and then right child is needed for infix:
  readInf(current -> getL()); //First recurse left down the tree
  cout << current -> getVal() << " "; //Then print out the current value
  readInf(current -> getR()); //Then recurse right down the tree

  
  //If the current node contains an operator (based on its ASCII value), print out a ")" (this will encase every operation in parentheses to help preserve order of operations):
  if (val < 47 || val > 58) {
    cout << ") ";
  }
}

//This readPre function takes the root of an expression tree and reads it out in prefix using recursion:
void readPre(node* current) {

  //If at the end of the tree (no children), print out the current value:
  if (current -> getL() == NULL || current -> getR() == NULL) {
    cout << current -> getVal() << " ";
    return;
  }

  //The pattern of printing out the parent (an operator), the left child (number), and the right child (number) will form prefix notation:
  cout << current -> getVal() << " "; //First read out current value
  readPre(current -> getL()); //Then recurse left down the tree
  readPre(current -> getR()); //Then recurse right down the tree
}

