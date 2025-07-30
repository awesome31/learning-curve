/**
 * Maybe Recipe means that if a function has arguments, and if ANY of the arguments are not defined, then it will just returns, else it will execute the function with the given arguments.
 */

const add = (a, b) => a + b;

//Self Implementation
const maybe = (fn) => function (...args) {
  if (args.length === 0) return;

  for(let i in args) {
    if(args[i] === undefined || args[i] === null) return;
  }

  return fn.call(this, ...args);
}

console.log(maybe(add)(1, 2));
console.log(maybe(add)(1, null));
