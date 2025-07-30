/**
 * Choice and Truthiness
 */

//true and false in JS are value types.
console.log(true === true)

// In JS these are FALSY values: false, 0, "", null, undefined, NaN. Everything else is TRUTHY.
//Ternary operators are not statements but expressions that evaluate to a value. Truthiness matters because, various logical operators depend on the truthiness value of a value NOT boolean values.
console.log(true? "Hello World": "Not so Hello World")

//Logical NOT ! is a unary operator that always returns a boolean value. But && and || operators do not return boolean values. && and || are control flow expressions instead of logical operators in their respective contexts.

const even = (n) => n === 0 || (n != 1 && even(n - 2));
console.log(even(42))

//Unlike expressions, function arguments are eagerly evaluated. This means that the arguments are evaluated before the function is called.
const or = (a, b) => a || b;
const and = (a, b) => a && b;
// const even2 = (n) => or(n === 0, and(n !== 1, even(n - 2)));
// console.log(even2())

// Check if function is ASYNC
const what = async (n) => n + 2;
const whatever = (n) => n + 2;
const isAsync = (fn) => fn.constructor.name === 'AsyncFunction';
console.log(isAsync(whatever));
