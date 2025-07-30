//Functions are reference types literals. Function is a reference type. A function itself is a value.
console.log((() => 0) == (() => 0))

//Using a function means applying a function with zero or more arguments. Applying a function returns always returns value.
console.log((() => 0)())

//We can also put expressions as return value instead of values.
console.log((() => 4 + 2)())
console.log((() => (() => 0)())())

//The comma operator takes n arguments, evaluates them both and itself evaluates to the value of the right-hand argument. Great when we want to do side effects.
console.log((1, 2, 3))

//Instead of putting an expression or a value on the right side of the arrow, we can also put a BLOCK. Blocks are zero or more statements, separated by a semicolon. All 3 of them evaluate to undefined, but the third form is preferred. There are various statement types like: if statement, const statement, expressions,
console.log(undefined)
console.log((() => {})()) //in JS, the absence of a value results in undefined. undefined are value types.
console.log(void 0); //in JS, we can use the void operator. The void operator takes any VALUE or expression and evaluates to undefined.

//To return something OUT of the block, we can make use of the return keyword, which is also called return staement.
console.log((() => { return 0; })())

//Functions can also evaluate back to the functions.
console.log((() => () => 2)()())

//Functions can also accept aguments, HAHAH. They are values that the function is APPLIED on.
// Function arguments, can either be passed by reference or passed by value. Any reference type variable, is passed by reference and value type is passed by value. The below function ALWAYS returns true. (Unless its NaN)

const alwaysTrue = (value) => ((arg1, arg2) => arg1 === arg2)(value, value)
console.log(alwaysTrue({ a: 2}))

/**
 * Closures:
 * 1. A free variable is one that is not bound within the function. Variables used inside a function can either be free or bound. Functions containing no free variables are called PURE functions. Functions containing one or more free variables are called closures.
 * 2. Pure functions always mean the same thing and do not cause ANY side effects.
 * 3. Whenever a function is applied with arguments, its environment ALWAYS has reference to its PARENT environment.
 */
 console.log(((x) => y => x)(1)(2))

//Functions are first class entities in JS. They can be bound to a name, can be passed around like any other value. Statements can only be written inside blocks.
console.log(((PI) => (diameter) => diameter * PI)(3.14)(2))
console.log(((diameter) => ((PI) => diameter * PI)(3.14))(2))

/**
 * 1. If statements is a statement and not an expression.
 * 2. Lexical scoping is a scoping where the function and its variables can be discovered by looking at the source code for the program.
 * 3. Const keyword does not get shadowed in the block scope. Let and const are block scoped. var is not.
 * 4. Also let and const are initialized but are in the temporal dead zone. var is initialized to undefined.
 */

const a = () => {
  const b = "Hi"

  if(true) {
    const b = "Hello World"
  }

  console.log(b);
}
a();


const a2 = () => {
  let b = "Hi"

  if(true) {
    let b = "Hello World"
  }

  console.log(b);
}
a2()


const a3 = () => {
  var b = "Hi"

  if(true) {
    var b = "Hello World"
  }

  console.log(b);
}
a3()

const double = function repeat(str) {
  return str + str;
}
console.log(double);

/**
 * 1. We can either do function expression, which retruns the value function back.
 * 2. Function declaration means, we use a function statement.
 * 3. Function declarations are hoisted on top of the function on which they occur.
 */
console.log((function trueData() {return true})) //This is a function expression, not a statement

/**
 * 1. Higher order functions are functions, that either take a function as an argument or return a function back. HOF are the basic building blocks of FP.
 * 2. Higher order pure functions that only take functions as arguments and return a function back.
 * 3. Function decorator is a higher order function that takes one function as an argument, retruns another function and the returned function
 */

/**
 * Apart from the arguments that are passed to a function, there are some magic names, that are available inside the scope of a function.
 * 1. arguments: This is an object of all the arguments passed to a function.
 * 2. this
 *
 * These magic names, differ in functionality for arrow functions and function declarations. Arrow functions were introduced in the spec to support lightweight function expressions.
 */
