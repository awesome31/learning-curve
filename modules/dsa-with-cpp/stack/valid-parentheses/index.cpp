/**
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and
 ']', determine if the input string is valid.

 An input string is valid if:

 Open brackets must be closed by the same type of brackets.
 Open brackets must be closed in the correct order.
 Every close bracket has a corresponding open bracket of the same type.
 */

#include <iostream>
using namespace std;

bool isValid(string s) {
  stack<char> st;

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == ')' && !st.empty()) {
      char top = st.top();

      if (top != '(') {
        return false;
      }

      st.pop();
    } else if (s[i] == ']' && !st.empty()) {
      char top = st.top();

      if (top != '[') {
        return false;
      }

      st.pop();
    }

    else if (s[i] == '}' && !st.empty()) {
      char top = st.top();

      if (top != '{') {
        return false;
      }

      st.pop();
    }

    else {
      st.push(s[i]);
    }
  }

  if (st.empty()) {
    return true;
  }
  return false;
}

int main() {
  string s = "]";

  cout << isValid(s) << endl;
}
