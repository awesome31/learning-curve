/**
 * Given a string str consisting of characters such as '(', ')', '{', '}', '[' and ']', determine if the input string is properly balanced.

A string is considered balanced if:

Each opening bracket bracket is closed by the same type of bracket (e.g., ( with ), { with }, and [ with ])
Open brackets are closed in the correct order (e.g., ([]) is valid, but ([)] is not)
Any subset of brackets enclosed within a matched pair must also form a valid matched pair (e.g., {[(])} is not balanced because the contents inside { and } are unbalanced).
Input
str: string: A string
 */

function isBalancedBrackets(str: string): boolean {
  const stack = [];

  if (str.length === 0) {
    return true;
  } else {
    stack.push(str[0]);
  }

  const leftBalanced = ["{", "[", "("];
  const rightBalanced = ["}", "]", ")"];

  for (let i = 1; i < str.length; i++) {
    if (leftBalanced.includes(str[i])) {
      stack.push(str[i]);
    } else if (rightBalanced.includes(str[i])) {
      const currentElement = stack[stack.length - 1];

      if (str[i] === "}" && currentElement !== "{") {
        return false;
      } else if (str[i] === "]" && currentElement !== "[") {
        return false;
      } else if (str[i] === ")" && currentElement !== "(") {
        return false;
      }

      stack.pop();
    }
  }

  if (stack.length === 0) {
    return true;
  }

  return false;
}

console.log(isBalancedBrackets("([]){}"));
