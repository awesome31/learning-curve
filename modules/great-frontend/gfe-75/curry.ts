/**
 * Currying is the technique of converting a function that takes multiple arguments into a sequence of functions that each takes a single argument.

Implement the curry function which accepts a function as the only argument and returns a function that accepts single arguments and can be repeatedly called until at least the minimum number of arguments have been provided (determined by how many arguments the original function accepts). The initial function argument is then invoked with the provided arguments.
 */

function add(a: number, b: number) {
  return a + b;
}

function curry(func: Function): Function {
  return function curriedFunction(...args) {
    if (args.length >= func.length) {
      return func.apply(this, args);
    }

    return (arg) => {
      if (arg === undefined) {
        return curriedFunction.apply(this, args);
      } else {
        return curriedFunction.apply(this, [...args, arg]);
      }
    };
  };
}

const curriedAdd = curry(add);
console.log(curriedAdd(3)(4));

const alreadyAddedThree = curriedAdd(3);
console.log(alreadyAddedThree(4));
