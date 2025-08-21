/**
 * Whenever we want to do infix to postfix conversion, we should first
 * paranthisis the expression. Infix and postfix are used in various
 * applications such as compiler design, expression evaluation, and parsing.
 *
 * There are 2 things that we need to understand:
 * 1. Associativity: This helps the compiler to determine the order of
 * operations. Some operators are left-associative, meaning that they are
 * evaluated from left to right, while others are right-associative, meaning
 * that they are evaluated from right to left. Power operator is
 * right-associative. Even negate unary operator is right-associative.
 * 2. Unary operators: Unary operators are operators that take only one operand.
 * They are right-associative. For example, -5 is evaluated as -(5). They
 * usuallu have highest precedence.
 */

#include <iostream>
#include <stack>
using namespace std;

string infixToPostfix(string s) {
  string res = "";
  stack<char> st;

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '-' || s[i] == '+') {
      while (!st.empty()) {
        res += st.top();
        st.pop();
      }

      st.push(s[i]);
    } else if (s[i] == '*' || s[i] == '/') {
      st.push(s[i]);
    } else {
      res += s[i];
    }
  }

  while (!st.empty()) {
    res += st.top();
    st.pop();
  }

  return res;
}

int main() {
  // Let us assume we have this expression.
  string s = "3+4*5-6/3";
  int a = 3 + 4 * 5 - 6 / 3;
  char *b;

  cout << infixToPostfix(s) << endl;
  cout << a << endl;
}
