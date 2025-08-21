/**
 * You are given an array of strings tokens that represents an arithmetic
 expression in a Reverse Polish Notation.

 Evaluate the expression. Return an integer that represents the value of the
 expression.

 Note that:

 The valid operators are '+', '-', '*', and '/'.
 Each operand may be an integer or another expression.
 The division between two integers always truncates toward zero.
 There will not be any division by zero.
 The input represents a valid arithmetic expression in a reverse polish
 notation. The answer and all the intermediate calculations can be represented
 in a 32-bit integer.

 The reason postfix notation is used is because it allows for easier evaluation
 of expressions without the need for parentheses.
 */

#include <iostream>
#include <stack>
using namespace std;

int evalRPN(vector<string> &tokens) {
  // We need to create a stack.
  stack<string> s;

  for (int i = 0; i < tokens.size(); i++) {
    if (tokens[i] == "*") {
      int a = stoi(s.top());
      s.pop();
      int b = stoi(s.top());
      s.pop();
      s.push(to_string(a * b));
    } else if (tokens[i] == "+") {
      int a = stoi(s.top());
      s.pop();
      int b = stoi(s.top());
      s.pop();
      s.push(to_string(a + b));
    } else if (tokens[i] == "-") {
      int a = stoi(s.top());
      s.pop();
      int b = stoi(s.top());
      s.pop();
      s.push(to_string(b - a));
    } else if (tokens[i] == "/") {
      int a = stoi(s.top());
      s.pop();
      int b = stoi(s.top());
      s.pop();
      s.push(to_string(b / a));
    } else {
      s.push(tokens[i]);
    }
  }

  // Return the final result.
  return stoi(s.top());
}

int main() {
  vector<string> tokens;
  // 345*+63/-

  tokens.push_back("3");
  tokens.push_back("4");
  tokens.push_back("5");
  tokens.push_back("*");
  tokens.push_back("+");
  tokens.push_back("6");
  tokens.push_back("3");
  tokens.push_back("/");
  tokens.push_back("-");

  cout << evalRPN(tokens) << endl;
}
