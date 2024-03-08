# ShuntingYard
Converting Infix Notation to Postfix using the Shunting Yard Algorithm. Using an Expression Tree to convert between Postfix and a) Infix b) Postfix c) Prefix

In this project, an expression in infix (parentheses, ^, +, -, *, /, and single digit numbers are allowed) is read and is converted into postfix through the Shunting Yard algorithm. The user should end their expression, when entering into the program, with a '|' in order for the program to work.

The user will be shown this expression in postfix. This postfix expression will then be put into an expression tree, where the user will be prompted to print out the expression back in postfix, into infix, or into prefix. The user should input "post," "in," or "pre" to determine the reading method.

ADDITIONALLY: The user should avoid inputting only singular-digit numbers as the entire expression (such as only '1') in this program.

Main sources:
Referred to Wikipedia article on Shunting Yard (https://en.wikipedia.org/wiki/Shunting_yard_algorithm). This taught me how numbers read in are added immediately to queue and how operators are initially added to a stack, in Shunting Yard. When an operator is added to the stack and the current stack head has a greater precedence, then the stack head is added to the queue and removed from the stack before adding the operator (this is looped until this difference in precedence is no longer the case). Additionally, the algorithm notes how after a right parenthesis is read in, every operator in the stack, until a left parenthesis is at the head, is moved to the queue. The queue is the postfix expression.

Referred to Wikipedia article on Binary Expression Tree (https://en.wikipedia.org/wiki/Binary_expression_tree). This taught me how the tree is created on a stack. Numbers read in are added to the stack. However, when an operator is read in, the most recent two numbers added to the stack are removed and made the children of the operator. The operator is then added to the stack.
